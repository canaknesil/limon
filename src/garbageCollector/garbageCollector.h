#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include <set>
#include <exception>
#include <string>

using namespace std;


class GarbageCollector {
    public:
        virtual ~GarbageCollector();
        class Item {
            public:
                Item(GarbageCollector *gc);
                virtual ~Item();
                virtual set<Item *> getRefs() = 0;
            protected:
                GarbageCollector *gc;
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
        TriColorGC();
        ~TriColorGC();
        void collect(set<Item *> roots);
    private:
        set<Item *> *white;
        set<Item *> *grey;
        set<Item *> *black;
        void add(Item *item);
        void prepare(set<Item *> roots);
        void mark();
        void sweep();
        void white2grey(Item *item);
        int allocN = 0;
        int freeN = 0;
};


class GCException : exception {
    public:
        GCException(string s);
        virtual const char* what() const throw();
    private:
        string s;
};


#endif