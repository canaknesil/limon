#include <value.h>


class IntVal : public Value {
    public:
        IntVal(int n);
        IntVal(string s);
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
    private:
        vector<int> vec;
};

IntVal::IntVal(int n) {
    vec = vector<int>(1, n);
}

IntVal::IntVal(string s) {
    vec = vector<int>(1, 0);
}