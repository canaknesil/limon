#include <value.h>

#include <iostream>

using namespace std;


Value::~Value() {}




IntVal::IntVal(int n) : Value::Value() {
    z = n;
}

IntVal::IntVal(string s) : Value::Value() {
    z = s;
}

IntVal::~IntVal() {}

IntVal::IntVal(mpz_class z) {
    this->z = z;
}

IntVal *IntVal::add(IntVal *val) {
    return new IntVal(z + val->z);
}

IntVal *IntVal::sub(IntVal *val) {
    return new IntVal(z - val->z);
}

IntVal *IntVal::mul(IntVal *val) {
    return new IntVal(z * val->z);
}

IntVal *IntVal::div(IntVal *val) {
    return new IntVal(z / val->z);
}

IntVal *IntVal::rem(IntVal *val) {
    return new IntVal(z % val->z);
}

bool IntVal::equ(IntVal *val) {
    return z == val->z;
}

bool IntVal::neq(IntVal *val) {
    return z != val->z;
}

bool IntVal::lot(IntVal *val) {
    return z < val->z;
}

bool IntVal::grt(IntVal *val) {
    return z > val->z;
}

bool IntVal::leq(IntVal *val) {
    return z <= val->z;
}

bool IntVal::geq(IntVal *val) {
    return z >= val->z;
}

void IntVal::print() {
    cout << z;
}