#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include <set>

using namespace std;


class GarbageCollector {
    public:
        virtual ~GarbageCollector();
        class Item {
            public:
                virtual ~Item();
                Item(GarbageCollector *gc);
        };
    private:
        virtual void add(Item *item) = 0;
};


class EndGC : public GarbageCollector {
    public:
        void collect();
    private:
        void add(Item *item);
        set<Item *> pool;
};


class TriColorGC : public GarbageCollector {
    public:
        ~TriColorGC();
        void collect(set<Item *> root);
    private:
        set<Item *> white;
        set<Item *> grey;
        set<Item *> black;
        set<Item *> pool;
        void add(Item *item);
        void del(Item *item);
};


#endif