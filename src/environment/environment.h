#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <garbageCollector.h>

#include <string>
#include <iostream>
#include <map>

using namespace std;


template <typename V>
class Environment : public GarbageCollector::Item
{
    public:
        Environment(GarbageCollector *gc, Environment *next);
        ~Environment();
        V apply(string var);
        void extend(string var, V val);
        void set(string var, V val);
        void print(int n = 1); // For debugging
        std::set<GarbageCollector::Item *> getRefs();
    private:
        map<string, V> bMap;
        Environment *next;
};

class EnvException : public exception {
    public:
        EnvException(string err) {
            this->err = "Environment Error: " + err;
        }
        virtual const char* what() const throw() {
            return err.c_str();
        }
    private:
        string err;
};



template <typename V>
Environment<V>::Environment(GarbageCollector *gc, Environment *next) : GarbageCollector::Item::Item(gc) {
    this->next = next;
    bMap = map<string, V>();
}

template <typename V>
Environment<V>::~Environment() {}

template <typename V>
V Environment<V>::apply(string var) {
    V val;
    try {
        val = bMap.at(var);
    } catch (out_of_range &exc) {
        if (next) val = next->apply(var);
        else throw EnvException("Variable \"" + var + "\" does not exist");
    }
    return val;
}

template <typename V>
void Environment<V>::extend(string var, V val) {
    pair<typename map<string, V>::iterator, bool> ret;
    ret = bMap.insert(pair<string, V>(var, val));
    if (ret.second == false) {
        throw EnvException("Variable \"" + var + "\" already exists");
    }
}

template <typename V>
void Environment<V>::set(string var, V val) {
    try {
        bMap.at(var);
    } catch (out_of_range &exc) {
        if (next) {
            next->set(var, val);
            return;
        }
        else throw EnvException("Variable \"" + var + "\" does not exist");
    }
    bMap[var] = val;
}

template <typename V>
void Environment<V>::print(int n) {
    cout << "Frame" << n << " = {";
    for(pair<string, V> p : bMap) cout << "(" << p.first << " " << p.second << ")";
    cout << "}" << endl;

    if (next) next->print(n + 1);
}

template <typename V>
std::set<GarbageCollector::Item *> Environment<V>::getRefs() {
    std::set<GarbageCollector::Item *> refs = std::set<GarbageCollector::Item *>();
    refs.insert(next);
    for (pair<string, V> p : bMap) {
        refs.insert(p.second);
    }
    return refs;
}



#endif

