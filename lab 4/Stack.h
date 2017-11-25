#ifndef __Stack_h__
#define __Stack_h__

#include <iostream>
using namespace std;
#include "Buffer.h"

class Stack : public Buffer
{

public:
    Stack();
    ~Stack();
    int topofStack;
    void push(char a);
    char pop();
    int read(istream& os);
    int write(ostream& os) const;
    int write(ostream& os, int n) const;
    friend ostream& operator<< (ostream& os, const Stack& s);
    bool isEmpty();

};
#endif
