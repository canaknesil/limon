#include <garbageCollector.h>

#include <string>

using namespace std;



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





TriColorGC::TriColorGC() {
    white = new set<Item *>();
    grey = new set<Item *>();
    black = new set<Item *>();
}

TriColorGC::~TriColorGC() {
    delete white;
    delete grey;
    delete black;
}

void TriColorGC::collect(set<Item *> roots) {
    prepare(roots);
    mark();
    sweep();
}

void TriColorGC::add(Item *item) {
    black->insert(item);
}

void TriColorGC::prepare(set<Item *> roots) {
    set<Item *> *temp = black;
    black = white;
    white = temp;
    for (Item *item : roots) white2grey(item);
}

void TriColorGC::mark() {
    while (!grey->empty()) {
        Item *item = *(grey->begin());
        grey->erase(item);
        black->insert(item);
        for (Item *ref : item->getRefs()) white2grey(ref);
    }
}

void TriColorGC::sweep() {
    for (Item *item : *white) {
        white->erase(item);
        delete item;
    }
}

void TriColorGC::white2grey(Item *item) {
    if (white->erase(item) != 1) throw GCException("Item " + to_string((unsigned long long) item) + " is not added to Garbage Collector");
    grey->insert(item);
}





GCException::GCException(string s) {
    this->s = "Garbage Coolector Error: " + s;
}

const char* GCException::what() const throw() {
    return s.c_str();
}