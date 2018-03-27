#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <gmpxx.h>
#include <exception>

using namespace std;


class Value {
    public:
        virtual ~Value();
        virtual void print() = 0;
};

class IntVal : public Value {
    public:
        IntVal(int n);
        IntVal(string s);
        ~IntVal();
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
        bool leq(IntVal *val);
        bool geq(IntVal *val);
        void print();
    private:
        IntVal(mpz_class z);
        mpz_class z;
};

class BoolVal : public Value {
    public:
        BoolVal(bool b);
        BoolVal *And(BoolVal *val);
        BoolVal *Or(BoolVal *val);
        bool equ(BoolVal *val);
        BoolVal *Not();
        void print();
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
        int compare(StrVal *val);
        void print();
    private:
        string s;
};

class CharVal : public Value {
    public:
        CharVal(char c);
        CharVal *add(int n);
        int sub(CharVal *val);
        int compare(CharVal *val);
        void print();
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