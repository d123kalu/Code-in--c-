#include "StackInt.h"
#include <cstdlib>

StackInt::StackInt()
{
  top = 0;
}

StackInt::~StackInt()
{
  while(!isEmpty())
  pop();
}

void StackInt::push(int d)
{
  Buffer::m[top] = d;
  top++;
}

int StackInt::pop()
{
  if (!isEmpty())
  {
    top--;
    return Buffer::m[top];
  }
  else
  {
    cout << "You can't pop from an empty stack!" << endl;
    return 0;
  }
}

bool StackInt::isEmpty()
{
  return (top == 0);
}

ostream& operator<< (ostream& os, const StackInt& s)
{
  cout << "StackInt = " << s.top << "/" << s.size() << "[";
  s.write(cout);
  cout << "]";
  return os;
}

int StackInt::write(ostream& os) const
{
  return write(os, top);
}

int StackInt::write(ostream& os, int n) const
{
  n = (n < top) ? n : top;

  for (int i=0; i<n; ++i)
  {
    os << int(Buffer::m[i]);
  }
  return n;
}


int StackInt::read(istream& os)
{
  int i=0;
  while (i<sz)
  {
    os >> Buffer::m[i];
    if (os.good() && !os.eof())
    {
      ++i;
      continue;
    }
    break;
  }
  top = i;
  return i;
}
