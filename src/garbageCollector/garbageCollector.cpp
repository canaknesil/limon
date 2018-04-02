#include <garbageCollector.h>



GarbageCollector::~GarbageCollector() {}




GarbageCollector::Item::Item(GarbageCollector *gc) {
    if (gc) gc->add(this);
}

GarbageCollector::Item::~Item() {}





void EndGC::collect() {
    for (Item *item : pool) delete item;
    pool.clear();
}

void EndGC::add(Item *item) {
    pool.insert(item);
}





TriColorGC::~TriColorGC() {}

void TriColorGC::collect(set<Item *> root) {

}

void TriColorGC::add(Item *item) {
    pool.insert(item);
}

void TriColorGC::del(Item *item) {
    delete item;
}