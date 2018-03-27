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



BoolVal::BoolVal(bool b) {
    this->b = b;
}

BoolVal *BoolVal::And(BoolVal *val) {
    return new BoolVal(b && val->b);
}

BoolVal *BoolVal::Or(BoolVal *val) {
    return new BoolVal(b || val->b);
}

bool BoolVal::equ(BoolVal *val) {
    return b == val->b;
}

BoolVal *BoolVal::Not() {
    return new BoolVal(!b);
}

void BoolVal::print() {
    cout << "#<" << (b ? "true" : "false") << ">";
}




StrVal::StrVal(string s) {
    this->s = s;
}

size_t StrVal::getSize() {
    return s.size();
}

char StrVal::getCharAt(size_t i) {
    return s[i];
}

void StrVal::setChatAt(size_t i, char c) {
    s[i] = c;
}

StrVal *StrVal::concat(StrVal *val) {
    return new StrVal(s + val->s);
}

int StrVal::compare(StrVal *val) {
    return s.compare(val->s);
}

void StrVal::print() {
    cout << s;
}




CharVal::CharVal(char c) {
    this->c = c;
}

CharVal *CharVal::add(int n) {
    return new CharVal(c + n);
}

int CharVal::sub(CharVal *val) {
    return c - val->c;
}

int CharVal::compare(CharVal *val) {
    if (c < val->c) return -1;
    else if (c > val->c) return 1;
    else return 0;
}

void CharVal::print() {
    cout << c;
}




ArrayVal::ArrayVal(size_t size) {
    arr = new Value *[size];
}

ArrayVal::~ArrayVal() {
    delete[] arr;
}

void ArrayVal::set(size_t i, Value *val) {
    arr[i] = val;
}

Value *ArrayVal::get(size_t i) {
    return arr[i];
}