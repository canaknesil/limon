#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <garbageCollector.h>
#include <limonException.h>

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
  string envErrorStr();
  string envErrorStr(string msg);
  map<string, V> bMap;
  Environment *next;
};




template <typename V>
string Environment<V>::envErrorStr()
{
  return "Environment error.";
}

template <typename V>
string Environment<V>::envErrorStr(string msg)
{
  return "Environment error: " + msg + ".";
}




template <typename V>
Environment<V>::Environment(GarbageCollector *gc, Environment *next) : GarbageCollector::Item::Item(gc) {
  this->next = next;
  bMap = map<string, V>();

  add2gc();
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
    else throw ExceptionStack(envErrorStr("Variable \"" + var + "\" does not exist"));
  }
  return val;
}

template <typename V>
void Environment<V>::extend(string var, V val) {
  pair<typename map<string, V>::iterator, bool> ret;
  ret = bMap.insert(pair<string, V>(var, val));
  if (ret.second == false) {
    throw ExceptionStack(envErrorStr("Variable \"" + var + "\" already exists"));
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
    else throw ExceptionStack(envErrorStr("Variable \"" + var + "\" does not exist"));
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

