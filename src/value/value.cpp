#include <value.h>

#include <iostream>
#include <sstream>

using namespace std;


Value::~Value() {}




IntVal::IntVal(long n) : Value::Value() {
    z = n;
}

IntVal::IntVal(string s) : Value::Value() {
    z = s;
}

IntVal::~IntVal() {}

long IntVal::getCLong() {
    return z.get_si();
}

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

IntVal *IntVal::neg() {
    return new IntVal(-z);
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

bool IntVal::grt(int n) {
    return z > n;
}

bool IntVal::leq(IntVal *val) {
    return z <= val->z;
}

bool IntVal::geq(IntVal *val) {
    return z >= val->z;
}

string IntVal::toString() {
    stringstream ss;
    ss << z;
    return ss.str();
}

string IntVal::getType() {
    return type;
}

const string IntVal::type = "IntegerValue";



BoolVal::BoolVal(bool b) {
    this->b = b;
}

bool BoolVal::getCBool() {
    return b;
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

string BoolVal::toString() {
    string s = string("#<") + (b ? "true" : "false") + ">";
    return s;
}

string BoolVal::getType() {
    return type;
}

const string BoolVal::type = "BooleanValue";




StrVal::StrVal(string s) {
    this->s = s;
}

size_t StrVal::getSize() {
    return s.size();
}

char StrVal::getCharAt(size_t i) {
    if (i>=s.size()) throw ValueException("StrVal::setCharAt() index out of range");
    return s[i];
}

void StrVal::setCharAt(size_t i, char c) {
    if (i>=s.size()) throw ValueException("StrVal::getCharAt() index out of range");
    s[i] = c;
}

StrVal *StrVal::concat(StrVal *val) {
    return new StrVal(s + val->s);
}

StrVal *StrVal::concat(string s) {
    return new StrVal(this->s + s);
}

StrVal *StrVal::concatInv(string s) {
    return new StrVal(s + this->s);
}

int StrVal::compare(StrVal *val) {
    return s.compare(val->s);
}

string StrVal::toString() {
    return s;
}

string StrVal::getType() {
    return type;
}

const string StrVal::type = "StringValue";




CharVal::CharVal(char c) {
    this->c = c;
}

char CharVal::getCChar() {
    return c;
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

string CharVal::toString() {
    return string(1, c);
}

string CharVal::getType() {
    return type;
}

const string CharVal::type = "CharacterValue";




ArrayVal::ArrayVal(size_t size) {
    try {
        arr = new Value *[size];
    } catch (...) {
        throw ValueException("Unappropriate array size");
    }
    for (size_t i=0; i<size; i++) arr[i] = nullptr;
    this->size = size;
}

ArrayVal::ArrayVal(vector<Value *> il) {
    size_t size = il.size();
    arr = new Value *[size];
    for (size_t i=0; i<size; i++) arr[i] = il[i];
    this->size = size;
}

ArrayVal::~ArrayVal() {
    delete[] arr;
}

void ArrayVal::set(size_t i, Value *val) {
    if (i>=size) throw ValueException("ArrayVal::set() index out of range");
    arr[i] = val;
}

Value *ArrayVal::get(size_t i) {
    if (i>=size) throw ValueException("ArrayVal::get() index out of range");
    return arr[i];
}

size_t ArrayVal::getSize() {
    return size;
}

string ArrayVal::toString() {
    stringstream ss;
    ss << "{";
    if (size > 0) {
        if (arr[0]) ss << arr[0]->toString();
        else ss << NULL_VAL_STR;
    }
    for (size_t i=1; i<size; i++) {
        ss << ", ";
        if (arr[i]) ss << arr[i]->toString();
        else ss << NULL_VAL_STR;
    }
    ss << "}";
    return ss.str();
}

string ArrayVal::getType() {
    return type;
}

const string ArrayVal::type = "ArrayValue";




ValueException::ValueException(string err) {
    this->err = err;
}

const char* ValueException::what() const throw() {
    return err.c_str();
}
