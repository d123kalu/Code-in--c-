#ifndef __StackInt_h__
#define __StackInt_h__

#include <iostream>
using namespace std;
#include "Stack.h"

class StackInt : public Stack
{
public:
  StackInt();
  ~StackInt();
  int top;
  void push(int d);
  int pop();
  bool isEmpty();
  int read(istream& os);
  int write(ostream& os) const;
  int write(ostream& os, int n) const;
  friend ostream& operator<< (ostream& os, const StackInt& s);

};
#endif
