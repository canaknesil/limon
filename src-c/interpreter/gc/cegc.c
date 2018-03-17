#include "cegc.h"
#include "stdlib.h"

struct garbageList
{
    void *obj;
    void (* delete)(void *);
    struct garbageList *next;
};

struct garbageList *list;

void CEGC_initialize()
{
    list = NULL;
}

void CEGC_add(void *obj, void (* delete)(void *obj))
{
    struct garbageList *rest = list;
    list = malloc(sizeof(struct garbageList));

    list->obj = obj;
    list->delete = delete;
    list->next = rest;
}


static void deleteAllRec(struct garbageList *list)
{
    if (list == NULL) return;

    struct garbageList *next = list->next;
    list->delete(list->obj);
    free(list);
    deleteAllRec(next);
}

void CEGC_deleteAllAndFinalize()
{
    deleteAllRec(list);
}