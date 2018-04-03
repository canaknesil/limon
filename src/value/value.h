#ifndef VALUE_H
#define VALUE_H

#include <garbageCollector.h>

#include <string>
#include <gmpxx.h>
#include <exception>
#include <vector>

#define COMMA   ,
#define VALUE_TYPE(VAL, CLASS)  (VAL->getType().compare(CLASS::type) == 0)
/* 
Explicit type checking implementation rules:
1) Every subclass of Value must have a "static const string type" attribute
2) getType() method of each subclass should return type attribute.
*/

using namespace std;



class Value : public GarbageCollector::Item {
    public:
        Value(GarbageCollector *gc);
        virtual ~Value();
        virtual string toString() = 0;
        virtual string getType() = 0; // This should return the "type" attribute
        bool equal(Value *val);
        virtual bool equalIntern(Value *val) = 0;
    protected:
        set<GarbageCollector::Item *> getRefs() = 0;
};

class NullVal : public Value {
    public:
        NullVal(GarbageCollector *gc);
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        set<GarbageCollector::Item *> getRefs();
};

class IntVal;
class FloatVal;

class IntVal : public Value {
    public:
        IntVal(GarbageCollector *gc, long n);
        IntVal(GarbageCollector *gc, string s, int base); // For larger integers
        IntVal(GarbageCollector *gc, mpz_class z); // only for FloatExp. Should not be exported
        ~IntVal();
        long getCLong(); // Returns the last portion fitting into a long
        FloatVal *getFloatVal();
        IntVal *add(IntVal *val);
        IntVal *sub(IntVal *val);
        IntVal *mul(IntVal *val);
        IntVal *div(IntVal *val);
        IntVal *rem(IntVal *val);
        IntVal *neg();
        bool lot(IntVal *val);
        bool grt(IntVal *val);
        bool leq(IntVal *val);
        bool geq(IntVal *val);
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        mpz_class z;
        set<GarbageCollector::Item *> getRefs();
};

class FloatVal : public Value {
    public:
        FloatVal(GarbageCollector *gc, float f);
        FloatVal(GarbageCollector *gc, string s, int base, size_t prec); // For larger integers
        FloatVal(GarbageCollector *gc, mpf_class f); // only for IntExp. Should not be exported
        ~FloatVal();
        float getCFloat();
        FloatVal *add(FloatVal *val);
        FloatVal *sub(FloatVal *val);
        FloatVal *mul(FloatVal *val);
        FloatVal *div(FloatVal *val);
        FloatVal *neg();
        bool lot(FloatVal *val);
        bool grt(FloatVal *val);
        bool leq(FloatVal *val);
        bool geq(FloatVal *val);
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        mpf_class f;
        set<GarbageCollector::Item *> getRefs();
};

class BoolVal : public Value {
    public:
        BoolVal(GarbageCollector *gc, bool b);
        bool getCBool();
        BoolVal *And(BoolVal *val);
        BoolVal *Or(BoolVal *val);
        BoolVal *Not();
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        bool b;
        set<GarbageCollector::Item *> getRefs();
};

class StrVal : public Value {
    public:
        StrVal(GarbageCollector *gc, string s);
        size_t getSize();
        char getCharAt(size_t i);
        void setCharAt(size_t i, char c);
        StrVal *concat(StrVal *val);
        StrVal *concat(string s);
        StrVal *concatInv(string s);
        int compare(StrVal *val);
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        string s;
        set<GarbageCollector::Item *> getRefs();
};

class CharVal : public Value {
    public:
        CharVal(GarbageCollector *gc, char c);
        char getCChar();
        CharVal *add(int n);
        int sub(CharVal *val);
        int compare(CharVal *val);
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        char c;
        set<GarbageCollector::Item *> getRefs();
};

class ArrayVal : public Value {
    public:
        ArrayVal(GarbageCollector *gc, size_t size);
        ArrayVal(GarbageCollector *gc, vector<Value *> il);
        ~ArrayVal();
        void set(size_t i, Value *val);
        Value *get(size_t i);
        size_t getSize();
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        Value **arr;
        size_t size;
        std::set<GarbageCollector::Item *> getRefs();
};


template<typename N, typename E>
class ProcVal : public Value {
    public:
        ProcVal(GarbageCollector *gc, vector<string> paramList, N body, E env);
        ~ProcVal();
        vector<string> getParamList();
        N getBody();
        E getEnv();
        string toString();
        string getType();
        static const string type;
        bool equalIntern(Value *val);
    private:
        vector<string> paramList;
        N body;
        E env;
        set<GarbageCollector::Item *> getRefs();
};

template<typename N, typename E>
ProcVal<N, E>::ProcVal(GarbageCollector *gc, vector<string> paramList, N body, E env) : Value::Value(gc) {
    this->paramList = paramList;
    this->body = body;
    this->env = env;
}

template<typename N, typename E>
ProcVal<N, E>::~ProcVal() {
    delete body;
}

template<typename N, typename E>
vector<string> ProcVal<N, E>::getParamList() {
    return paramList;
}

template<typename N, typename E>
N ProcVal<N, E>::getBody() {
    return body;
}

template<typename N, typename E>
E ProcVal<N, E>::getEnv() {
    return env;
}

template<typename N, typename E>
string ProcVal<N, E>::toString() {
    return "#<procedure>";
}

template<typename N, typename E>
string ProcVal<N, E>::getType() {
    return type;
}

template<typename N, typename E>
const string ProcVal<N, E>::type = "ProcedureValue";

template<typename N, typename E>
bool ProcVal<N, E>::equalIntern(Value *val) {
    return this == val;
}

template<typename N, typename E>
set<GarbageCollector::Item *> ProcVal<N, E>::getRefs() {
    set<GarbageCollector::Item *> refs = set<GarbageCollector::Item *>();
    refs.insert(env);
    return refs;
}



class ValueException : public exception {
    public:
        ValueException(string type, string err);
        virtual const char* what() const throw();
    private:
        string err;
};




#endif