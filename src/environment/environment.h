#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <iostream>

using namespace std;


template <typename V>
class Environment 
{
    public:
        Environment(Environment *next);
        ~Environment();
        V apply(string var);
        void extend(string var, V val);
        void set(string var, V val);
        void print(int n = 1);
    private:
        class Binding {
            public:
                Binding(string var, V val, Binding *next);
                ~Binding();
                static bool apply(Binding *b, string var, V *val);
                static Binding *extend(Binding *b, string var, V val);
                static bool set(Binding *b, string var, V val);
                void print();
            private:
                string var;
                V val;
                Binding *next;
        };
        Binding *binding;
        Environment *next;
};

class EnvException : public exception {
    public:
        EnvException(string err) {
            this->err = err;
        }
        virtual const char* what() const throw() {
            return err.c_str();
        }
    private:
        string err;
};



template <typename V>
Environment<V>::Environment(Environment *next) {
    this->next = next;
    binding = nullptr;
}

template <typename V>
Environment<V>::~Environment() {
    if (binding) delete binding;
}

template <typename V>
V Environment<V>::apply(string var) {
    V val;
    if (Binding::apply(binding, var, &val)) return val;
    else if (next) return next->apply(var);
    else throw EnvException("Variable \"" + var + "\" does not exist");
}

template <typename V>
void Environment<V>::extend(string var, V val) {
    Binding *b = Binding::extend(binding, var, val);
    if (!b) throw EnvException("Variable \"" + var + "\" already exists");
    else binding = b;
}

template <typename V>
void Environment<V>::set(string var, V val) {
    if (Binding::set(binding, var, val)) return;
    else if (next) next->set(var, val);
    else throw EnvException("Variable \"" + var + "\" does not exist");
}

template <typename V>
void Environment<V>::print(int n) {
    cout << "Frame" << n << " = {";
    if (binding != nullptr) binding->print();
    cout << "}" << endl;
    if (next) next->print(n + 1);
}





template <typename V>
Environment<V>::Binding::Binding(string var, V val, Binding *next) {
    this->var = var;
    this->val = val;
    this->next = next;
}

template <typename V>
Environment<V>::Binding::~Binding() {
    if (next) delete next;
}

template <typename V>
bool Environment<V>::Binding::apply(Binding *b, string var, V *val) {
    if (!b) return false;
    else if (b->var.compare(var) == 0) {
        if (val) *val = b->val;
        return true;
    }
    else return apply(b->next, var, val);
}

template <typename V>
typename Environment<V>::Binding *Environment<V>::Binding::extend(Binding *b, string var, V val) {
    if (apply(b, var, nullptr)) return nullptr;
    else return new Binding(var, val, b);
}

template <typename V>
bool Environment<V>::Binding::set(Binding *b, string var, V val) {
    if (!b) return false;
    else if (b->var.compare(var) == 0) {
        b->val = val;
        return true;
    }
    else return set(b->next, var, val);
}

template <typename V>
void Environment<V>::Binding::print() {
    cout << "(" << var << ", " << val << ")";
    if (next != nullptr) {
        cout << ", ";
        next->print();
    }
}




#endif

