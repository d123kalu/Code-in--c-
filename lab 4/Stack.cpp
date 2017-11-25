#include "Stack.h"
#include "Buffer.h"
#include <cstdlib>

Stack::Stack()
{
   topofStack = 0;
}

Stack::~Stack()
{
  while(!isEmpty())
  pop();
}

void Stack::push(char a)
{
  Buffer::m[topofStack] = a;
  topofStack++;

}

char Stack::pop()
{
  if (!isEmpty())
  {
    topofStack--;
    return Buffer::m[topofStack];
  }
  else
  {
    cout << "You can't pop from an empty stack!" << endl;
    return 0;
  }
}

bool Stack::isEmpty()
{
  return (topofStack == 0);
}

ostream& operator<< (ostream& os, const Stack& s)
{
  cout << "Stack = " << s.topofStack << "/" << s.size() << "[";
  s.write(cout);
  cout << "]";
  return os;
}

int Stack::write(ostream& os) const
{
  return write(os, topofStack);
}

int Stack::write(ostream& os, int n) const
{
  n = (n < topofStack) ? n : topofStack;

  for (int i=0; i<n; ++i)
  {
    os << Buffer::m[i];
  }
  return n;
}

int Stack::read(istream& os)
{
  int i = 0;
  while (i < sz)
  {
    os >> Buffer::m[i];

    if (os.good() && !os.eof())
    {
      ++i;
      continue;
    }
    break;
  }
  topofStack = i;
  return i;
}
