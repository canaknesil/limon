#include <value.h>

#include <iostream>
#include <sstream>

using namespace std;


Value::~Value() {}

bool Value::equal(Value *val) {
    if (getType().compare(val->getType()) == 0) {
        return equalIntern(val);
    } else {
        return false;
    }
}




NullVal::NullVal() {}

string NullVal::toString() {
    return "#<null>";
}

string NullVal::getType() {
    return type;
}

const string NullVal::type = "NullValue";

bool NullVal::equalIntern(Value *val) {
    return true;
}





IntVal::IntVal(long n) : Value::Value() {
    z = n;
}

IntVal::IntVal(string s) : Value::Value() {
    z = s;
}

IntVal::IntVal(mpz_class z) {
    this->z = z;
}

IntVal::~IntVal() {}

long IntVal::getCLong() {
    return z.get_si();
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

string IntVal::toString() {
    stringstream ss;
    ss << z;
    return ss.str();
}

string IntVal::getType() {
    return type;
}

const string IntVal::type = "IntegerValue";

bool IntVal::equalIntern(Value *val) {
    return z == ((IntVal *) val)->z;
}




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

bool BoolVal::equalIntern(Value *val) {
    return b == ((BoolVal *) val)->b;
}




StrVal::StrVal(string s) {
    this->s = s;
}

size_t StrVal::getSize() {
    return s.size();
}

char StrVal::getCharAt(size_t i) {
    if (i>=s.size()) throw ValueException(type, "Getting character with index out of range");
    return s[i];
}

void StrVal::setCharAt(size_t i, char c) {
    if (i>=s.size()) throw ValueException(type, "Setting character with index out of range");
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

bool StrVal::equalIntern(Value *val) {
    return s.compare(((StrVal *) val)->s) == 0;
}




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

bool CharVal::equalIntern(Value *val) {
    return c == ((CharVal *) val)->c;
}




ArrayVal::ArrayVal(size_t size) {
    try {
        arr = new Value *[size];
    } catch (exception &exc) {
        throw ValueException(type, "Allocation error: " + string(exc.what()));
    }
    for (size_t i=0; i<size; i++) arr[i] = new NullVal();
    this->size = size;
}

ArrayVal::ArrayVal(vector<Value *> il) : ArrayVal(il.size()) {
    for (size_t i=0; i<size; i++) arr[i] = il[i];
}

ArrayVal::~ArrayVal() {
    delete[] arr;
}

void ArrayVal::set(size_t i, Value *val) {
    if (i>=size) throw ValueException(type, "Set with index out of range");
    arr[i] = val;
}

Value *ArrayVal::get(size_t i) {
    if (i>=size) throw ValueException(type, "Get with index out of range");
    return arr[i];
}

size_t ArrayVal::getSize() {
    return size;
}

string ArrayVal::toString() {
    stringstream ss;
    ss << "{";
    if (size > 0) {
        ss << arr[0]->toString();
    }
    for (size_t i=1; i<size; i++) {
        ss << ", " << arr[i]->toString();
    }
    ss << "}";
    return ss.str();
}

string ArrayVal::getType() {
    return type;
}

const string ArrayVal::type = "ArrayValue";

bool ArrayVal::equalIntern(Value *_val) {
    ArrayVal *val = (ArrayVal *) _val;
    if (size != val->size) return false;
    Value **arr2 = val->arr;
    for (size_t i=0; i<size; i++) {
        if (!(arr[i]->equal(arr2[i])) ) return false;
    }
    return true;
}




ValueException::ValueException(string type, string err) {
    this->err = type + ": " + err;
}

const char* ValueException::what() const throw() {
    return err.c_str();
}
