#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <gmpxx.h>
#include <exception>

#define VALUE_TYPE(VAL, CLASS)  (VAL->getType().compare(CLASS::type) == 0)
/* 
Explicit type checking implementation rules:
1) Every subclass of Value must have a "static const string type" attribute
2) getType() method of each subclass should return type attribute.
*/

#define NULL_VAL_STR    "#<null>"

using namespace std;



class Value {
    public:
        virtual ~Value();
        virtual string toString() = 0;
        virtual string getType() = 0;
};

class IntVal : public Value {
    public:
        IntVal(int n);
        IntVal(string s);
        ~IntVal();
        long getCLong();
        IntVal *add(IntVal *val);
        IntVal *sub(IntVal *val);
        IntVal *mul(IntVal *val);
        IntVal *div(IntVal *val);
        IntVal *rem(IntVal *val);
        IntVal *neg();
        bool equ(IntVal *val);
        bool neq(IntVal *val);
        bool lot(IntVal *val);
        bool grt(IntVal *val);
        bool grt(int n);
        bool leq(IntVal *val);
        bool geq(IntVal *val);
        string toString();
        string getType();
        static const string type;
    private:
        IntVal(mpz_class z);
        mpz_class z;
};

class BoolVal : public Value {
    public:
        BoolVal(bool b);
        bool getCBool();
        BoolVal *And(BoolVal *val);
        BoolVal *Or(BoolVal *val);
        bool equ(BoolVal *val);
        BoolVal *Not();
        string toString();
        string getType();
        static const string type;
    private:
        bool b;
};

class StrVal : public Value {
    public:
        StrVal(string s);
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
    private:
        string s;
};

class CharVal : public Value {
    public:
        CharVal(char c);
        CharVal *add(int n);
        int sub(CharVal *val);
        int compare(CharVal *val);
        string toString();
        string getType();
        static const string type;
    private:
        char c;
};

class ArrayVal : public Value {
    public:
        ArrayVal(size_t size);
        ~ArrayVal();
        void set(size_t i, Value *val);
        Value *get(size_t i);
        size_t getSize();
        string toString();
        string getType();
        static const string type;
    private:
        Value **arr;
        size_t size;
};



class ValueException : public exception {
    public:
        ValueException(string err);
        const char* what();
    private:
        string err;
};


#endif