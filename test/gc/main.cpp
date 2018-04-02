#include <garbageCollector.h>
#include <iostream>

using namespace std;


class Val : public GarbageCollector::Item {
    public:
        Val(GarbageCollector *gc) : GarbageCollector::Item::Item(gc) {
            c = count++;
            cout << "Val" << c << " allocation" << endl;
        }
        ~Val() {
            cout << "Val" << c << " deletion" << endl;
        }
    private:
        static int count;
        int c;
};

int Val::count = 1;


int main() {

    EndGC gc;

    Val *v1 = new Val(&gc);
    Val *v2 = new Val(&gc);

    gc.collect();

    return 0;
}