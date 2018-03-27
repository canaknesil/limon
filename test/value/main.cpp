#include <iostream>
#include <value.h>

using namespace std;


static void printVal(Value *val) {
    val->print();
    cout << endl;
}

static void printb(bool b) {
    cout << (b ? "true" : "false") << endl;
}

static void IntValTest() {
    IntVal *a = new IntVal("10000000000000000000000000000000000000000000000000000000000000000000000000");
    IntVal *b = new IntVal("29999999999999999999999999999999999999999999999999999999999999999999999999");
    IntVal *c;

    c = a->add(b);
    printVal(c);

    c = a->sub(b);
    printVal(c);

    c = a->mul(b);
    printVal(c);

    c = a->div(b);
    printVal(c);

    c = a->rem(b);
    printVal(c);

    bool pred;

    pred = a->equ(b);
    printb(pred);

    pred = a->neq(b);
    printb(pred);

    pred = a->lot(b);
    printb(pred);

    pred = a->grt(b);
    printb(pred);

    pred = a->leq(b);
    printb(pred);

    pred = a->geq(b);
    printb(pred);
    
}

static void strTest() {

    StrVal *s = new StrVal("can");
    try {
        s->setCharAt(5, 'b');
    } catch (ValueException &e) {
        cout << e.what() << endl;
    }
    
    s->print();
    delete s;

}

int main() {
    IntValTest();
    strTest();
    return 0;
}