#include <garbageCollector.h>
#include <iostream>

using namespace std;


class Val : public GarbageCollector::Item {
    public:
        Val(GarbageCollector *gc) : GarbageCollector::Item::Item(gc) {
            c = count++;
            cout << "Val" << c << " allocation" << endl;
            this->v = nullptr;
        }
        ~Val() {
            cout << "Val" << c << " deletion" << endl;
        }
        void setV(Val *v) {
            this->v = v;
        }
    private:
        set<Item *> getRefs() {
            set<Item *> refs = set<Item *>();
            if (v) refs.insert(v);
            return refs;
        }
        static int count;
        int c;
        Val *v;
};

int Val::count = 1;


int main() {

    TriColorGC gc;

    Val *v1 = new Val(&gc);
    Val *v2 = new Val(&gc);
    Val *v3 = new Val(&gc);
    Val *v4 = new Val(&gc);
    Val *v5 = new Val(&gc);
    Val *v6 = new Val(&gc);
    Val *v7 = new Val(&gc);
    Val *v8 = new Val(&gc);
    Val *v9 = new Val(&gc);

    v1->setV(nullptr);
    v2->setV(v1);
    v3->setV(v1);
    v4->setV(v5);
    v5->setV(v4);
    v6->setV(v7);
    v7->setV(v8);
    v8->setV(nullptr);
    v9->setV(nullptr);

    set<GarbageCollector::Item *> roots = set<GarbageCollector::Item *>();
    roots.insert(v3);
    roots.insert(v6);
    roots.insert(v9);

    gc.collect(roots);

    return 0;
}