#ifndef CEGC_H
#define CEGC_H

/* Collect at the End Garbage Collector (CEGC) */
void CEGC_initialize();
void CEGC_add(void *obj, void (* delete)(void *obj));
void CEGC_deleteAllAndFinalize();

#endif
