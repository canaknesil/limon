#include <value.h>

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>

using namespace std;



Value::Value(GarbageCollector *gc) : GarbageCollector::Item(gc) {}

Value::~Value() {}

bool Value::equal(Value *val) {
  if (getType().compare(val->getType()) == 0) {
    return equalIntern(val);
  } else {
    return false;
  }
}




NullVal::NullVal(GarbageCollector *gc) : Value::Value(gc) {
  add2gc();
}

string NullVal::toString() {
  return "#<null>";
}

string NullVal::getType() {
  return type;
}

string NullVal::getLimonType() {
  return limonType;
}

const string NullVal::type = "NullValue";
const string NullVal::limonType = "null";

bool NullVal::equalIntern(Value *val) {
  return true;
}

set<GarbageCollector::Item *> NullVal::getRefs() {
  return set<GarbageCollector::Item *>();
}







IntVal::IntVal(GarbageCollector *gc, long n) : Value::Value(gc) {
  z = n;
  add2gc();
}

IntVal::IntVal(GarbageCollector *gc, string s, int base) : Value::Value(gc) {
  z = mpz_class(s, base);
  add2gc();
}

IntVal::IntVal(GarbageCollector *gc, mpz_class z) : Value::Value(gc) {
  this->z = z;
  add2gc();
}

IntVal::~IntVal() {}

long IntVal::getCLong() {
  return z.get_si();
}

FloatVal *IntVal::getFloatVal() {
  return new FloatVal(gc, mpf_class(z));
}

IntVal *IntVal::add(IntVal *val) {
  return new IntVal(gc, z + val->z);
}

IntVal *IntVal::sub(IntVal *val) {
  return new IntVal(gc, z - val->z);
}

IntVal *IntVal::mul(IntVal *val) {
  return new IntVal(gc, z * val->z);
}

IntVal *IntVal::div(IntVal *val) {
  return new IntVal(gc, z / val->z);
}

IntVal *IntVal::rem(IntVal *val) {
  return new IntVal(gc, z % val->z);
}

IntVal *IntVal::neg() {
  return new IntVal(gc, -z);
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

string IntVal::getLimonType() {
  return limonType;
}

const string IntVal::type = "IntegerValue";
const string IntVal::limonType = "integer";

bool IntVal::equalIntern(Value *val) {
  return z == ((IntVal *) val)->z;
}

set<GarbageCollector::Item *> IntVal::getRefs() {
  return set<GarbageCollector::Item *>();
}





FloatVal::FloatVal(GarbageCollector *gc, float f) : Value::Value(gc) {
  this->f = mpf_class(f);
  add2gc();
}

FloatVal::FloatVal(GarbageCollector *gc, string s, int base, size_t prec) : Value::Value(gc) {
  if (prec == 0) f = mpf_class(s, mpf_get_default_prec(), base);
  else {
    double rate = log(10) / log(2);
    size_t p2 = ceil(prec * rate);
    size_t def = mpf_get_default_prec();
    f = mpf_class(s, (p2 > def ? p2 : def), base);
  }
    
  add2gc();
}

FloatVal::FloatVal(GarbageCollector *gc, mpf_class f) : Value::Value(gc) {
  this->f = mpf_class(f);
  add2gc();
}

FloatVal::~FloatVal() {}

IntVal *FloatVal::getIntVal() {
  return new IntVal(gc, mpz_class(f));
}

FloatVal *FloatVal::add(FloatVal *val) {
  return new FloatVal(gc, f + val->f);
}

FloatVal *FloatVal::sub(FloatVal *val) {
  return new FloatVal(gc, f - val->f);
}

FloatVal *FloatVal::mul(FloatVal *val) {
  return new FloatVal(gc, f * val->f);
}

FloatVal *FloatVal::div(FloatVal *val) {
  return new FloatVal(gc, f / val->f);
}

FloatVal *FloatVal::neg() {
  return new FloatVal(gc, -f);
}

bool FloatVal::lot(FloatVal *val) {
  return f < val->f;
}

bool FloatVal::grt(FloatVal *val) {
  return f > val->f;
}

bool FloatVal::leq(FloatVal *val) {
  return f <= val->f;
}

bool FloatVal::geq(FloatVal *val) {
  return f >= val->f;
}

string FloatVal::toString() {
  double rate = log(2) / log(10);
  size_t p10 = ceil(f.get_prec() * rate);
  stringstream ss;
  ss << setprecision(p10) << f;
  return ss.str();
}

string FloatVal::getType() {
  return type;
}

string FloatVal::getLimonType() {
  return limonType;
}

const string FloatVal::type = "FloatValue";
const string FloatVal::limonType = "float";

bool FloatVal::equalIntern(Value *val) {
  return f == ((FloatVal *) val)->f;
}

set<GarbageCollector::Item *> FloatVal::getRefs() {
  return set<GarbageCollector::Item *>();
}






BoolVal::BoolVal(GarbageCollector *gc, bool b) : Value::Value(gc) {
  this->b = b;
  add2gc();
}

bool BoolVal::getCBool() {
  return b;
}

BoolVal *BoolVal::And(BoolVal *val) {
  bool res = b && val->b;
  return new BoolVal(gc, res);
}

BoolVal *BoolVal::Or(BoolVal *val) {
  return new BoolVal(gc, b || val->b);
}

BoolVal *BoolVal::Not() {
  return new BoolVal(gc, !b);
}

string BoolVal::toString() {
  string s = string("#<") + (b ? "true" : "false") + ">";
  return s;
}

string BoolVal::getType() {
  return type;
}

string BoolVal::getLimonType() {
  return limonType;
}

const string BoolVal::type = "BooleanValue";
const string BoolVal::limonType = "bool";

bool BoolVal::equalIntern(Value *val) {
  return b == ((BoolVal *) val)->b;
}


set<GarbageCollector::Item *> BoolVal::getRefs() {
  return set<GarbageCollector::Item *>();
}




StrVal::StrVal(GarbageCollector *gc, string s) : Value::Value(gc) {
  this->s = s;
  add2gc();
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
  return new StrVal(gc, s + val->s);
}

StrVal *StrVal::concat(string s) {
  return new StrVal(gc, this->s + s);
}

StrVal *StrVal::concatInv(string s) {
  return new StrVal(gc, s + this->s);
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

string StrVal::getLimonType() {
  return limonType;
}

const string StrVal::type = "StringValue";
const string StrVal::limonType = "string";

bool StrVal::equalIntern(Value *val) {
  return s.compare(((StrVal *) val)->s) == 0;
}

set<GarbageCollector::Item *> StrVal::getRefs() {
  return set<GarbageCollector::Item *>();
}




SymbolVal::SymbolVal(GarbageCollector *gc, string sym_str) : Value::Value(gc) {
  if (sym_str.length() > 0 && sym_str[0] == UNIQUE_SYMBOL_START_CHAR) {
    throw ValueException(type,
			 "Symbol starting with '" +
			 string(1, UNIQUE_SYMBOL_START_CHAR) +
			 "'. This character is used to start unique symbols.");
  }
  this->sym_str = sym_str;
  add2gc();
}

SymbolVal::SymbolVal(GarbageCollector *gc) : Value::Value(gc) {
  this->sym_str = string(1, UNIQUE_SYMBOL_START_CHAR) + to_string(uniqueSymbolCount++);
  add2gc();
}

long SymbolVal::uniqueSymbolCount = 0;

string SymbolVal::toString() {
  return ":" + sym_str;
}

string SymbolVal::getType() {
  return type;
}

string SymbolVal::getLimonType() {
  return limonType;
}

const string SymbolVal::type = "SymbolValue";
const string SymbolVal::limonType = "symbol";

bool SymbolVal::equalIntern(Value *val) {
  return sym_str.compare(((SymbolVal *) val)->sym_str) == 0;
}

set<GarbageCollector::Item *> SymbolVal::getRefs() {
  return set<GarbageCollector::Item *>();
}




CharVal::CharVal(GarbageCollector *gc, char c) : Value::Value(gc) {
  this->c = c;
  add2gc();
}

char CharVal::getCChar() {
  return c;
}

CharVal *CharVal::add(int n) {
  return new CharVal(gc, c + n);
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

string CharVal::getLimonType() {
  return limonType;
}

const string CharVal::type = "CharacterValue";
const string CharVal::limonType = "char";

bool CharVal::equalIntern(Value *val) {
  return c == ((CharVal *) val)->c;
}

set<GarbageCollector::Item *> CharVal::getRefs() {
  return set<GarbageCollector::Item *>();
}




ArrayVal::ArrayVal(GarbageCollector *gc, size_t size) : Value::Value(gc) {
  try {
    arr = new Value *[size];
  } catch (exception &exc) {
    throw ValueException(type, "Allocation error: " + string(exc.what()));
  }
  for (size_t i=0; i<size; i++) arr[i] = new NullVal(gc);
  this->size = size;

  add2gc();
}

ArrayVal::ArrayVal(GarbageCollector *gc, vector<Value *> il) : ArrayVal(gc, il.size()) {
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

string ArrayVal::getLimonType() {
  return limonType;
}

const string ArrayVal::type = "ArrayValue";
const string ArrayVal::limonType = "array";

bool ArrayVal::equalIntern(Value *_val) {
  ArrayVal *val = (ArrayVal *) _val;
  if (size != val->size) return false;
  Value **arr2 = val->arr;
  for (size_t i=0; i<size; i++) {
    if (!(arr[i]->equal(arr2[i])) ) return false;
  }
  return true;
}

set<GarbageCollector::Item *> ArrayVal::getRefs() {
  std::set<GarbageCollector::Item *> refs = std::set<GarbageCollector::Item *>();
  for (size_t i=0; i<size; i++) refs.insert(arr[i]);
  return refs;
}




ValueException::ValueException(string type, string err) {
  this->err = type + ": " + err;
}

const char* ValueException::what() const throw() {
  return err.c_str();
}
