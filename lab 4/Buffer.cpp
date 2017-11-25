#include "Buffer.h"

Buffer::Buffer(const char* contents)
{
  sz = strlen(contents);
  m = new char[sz];
  strcpy(m, contents);
}

Buffer::Buffer(int _sz) : sz(_sz)
{
  m = new char[sz];
}

Buffer::~Buffer()
{
  delete[] m;
}

const int& Buffer::size() const
{
  return sz;
}

void Buffer::resize(int _sz)
{
  char* tmp = new char[_sz];
  int n = (sz < _sz) ? sz : _sz;
  for (int i=0; i<n; ++i) tmp[i] = m[i];

  delete[] m;
  m = tmp;
  sz = _sz;
}

int Buffer::write(ostream& os) const
{
  return write(os, sz);
}

int Buffer::write(ostream& os, int n) const
{
  n = (n < sz) ? n : sz;

  for (int i=0; i<n; ++i) {
    os << m[i];
  }
  return n;
}

int Buffer::read(istream& is) {
  int i=0;
  while (i<sz) {
    is >> m[i];
    if (is.good() && !is.eof()) {
      ++i;
      continue;
    }
    break;
  }
  return i;
}

ostream& operator<< (ostream& os, const Buffer& buf)
{
  cout << "Buffer = " << buf.size() << "[";
  buf.write(cout);
  cout << "]";
  return os;
}
