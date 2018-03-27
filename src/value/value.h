#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <gmpxx.h>

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


#endif