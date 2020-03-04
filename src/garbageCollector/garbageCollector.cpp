#include <garbageCollector.h>

#include <string>
#include <iostream>

#define DEBUG 0
#define DEB if (DEBUG)

using namespace std;



GarbageCollector::~GarbageCollector() {}





GarbageCollector::Item::Item(GarbageCollector *gc) {
    this->gc = gc;
    //if (gc) gc->add(this);
}

GarbageCollector::Item::~Item() {}

void GarbageCollector::Item::add2gc() {
    if (gc) gc->add(this);
}





void EndGC::collect() {
    for (Item *item : pool) {
        //cout << item << endl;
        delete item;
    }
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

void TriColorGC::collect()
{
  collect(set<GarbageCollector::Item *>());
}

void TriColorGC::collect(set<Item *> roots) {
    prepare(roots);
    mark();
    sweep();
    DEB cout << endl << "TCGC: Allocation: " << allocN << endl;
    DEB cout <<         "TCGC: Deletion:   " << freeN << endl;
}

void TriColorGC::add(Item *item) {
    //cout << "Add: " << item << endl;
    black->insert(item);
    allocN++;
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
        //white->erase(item);
        //cout << "Del: " << item << endl;
        delete item;
        freeN++;
    }
    white->clear();
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
