#include <iostream>
#include <environment.h>

using namespace std;


int main() {

    int a1 = 1;
    int b = 2;
    int c = 3;
    int a2 = 4;

    Environment<int> *e1 = new Environment<int>(nullptr);
    Environment<int> *e2 = new Environment<int>(e1);

    e2->print();

    e1->extend("a", a1);
    e1->extend("b", b);
    cout << e1->apply("a") << endl;
    cout << e1->apply("b") << endl;

    cout << e2->apply("a") << endl;
    cout << e2->apply("b") << endl;

    e2->print();

    e2->extend("a", a2);
    e2->extend("c", c);

    cout << e2->apply("a") << endl;
    cout << e2->apply("b") << endl;
    cout << e2->apply("c") << endl;

    e2->print();

    e2->set("a", 5);
    e2->set("b", 6);
    e2->set("c", 7);

    cout << e2->apply("a") << endl;
    cout << e2->apply("b") << endl;
    cout << e2->apply("c") << endl;

    e2->print();

    try {
        e2->set("d", 8);
        e2->extend("a", 8);
        int d = e2->apply("d");
    } catch (EnvException &e) {
        cout << e.what() << endl;
    }
    


    delete e1;
    delete e2;

    return 0;
}