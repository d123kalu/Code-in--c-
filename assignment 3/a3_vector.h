#ifndef __a3_vector_h__
#define __a3_vector_h__
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <map>

using namespace std;
namespace a3
{
  template<class T>
class vector
{
  public:

    class iterator
     {
      public:
      int index_;
      int numof;
      vector* a_;

      iterator() : index_(-1), a_(0){}
      iterator (int index, vector* a, int vectorsize) : index_(index), a_(a), numof(vectorsize)
      {

      }

      iterator& operator=(const iterator& itr)
      {
        a_ = itr.a_;
        index_ = itr.index_;
        return *this;
      }
      friend bool operator==(const iterator& itr1, const iterator& itr2)
      {
        return (itr1.index_ == itr2.index_ && itr1.a_ == itr2.a_);
      }
      friend bool operator!=(const iterator& itr1, const iterator& itr2)
      {
        return !(itr1 == itr2);
      }
      iterator& next()
      {
        index_++;
        return *this;
      }
      iterator& operator++()
        {
          return next();
        }
      T& operator*() { return (*a_)[index_]; }
    };

  //overloading needed for copy()
  vector operator=(const vector& v)
  {
    capofarr = v.capofarr;
    a = v.a;
    numof = v.numof;
    b_ = v.b_;
    e_ = v.e_;
    return *this;
  }



  vector(int n): numof(n), b_(0, this, n), e_(n, this, n)
  {
    a = new T[n];

    numof = n;
    capofarr = n;
  }

  ~vector()
  {
    delete[] a;
  }
  const T& operator[](T i) const
  {
     return a[i];
  }
  T& operator[](int i)
  {
    return a[i];
  }

  const int& size() const
  {
    return numof;
  }

  const iterator& begin()
  {
    return b_;
  }
  const iterator& end()
  {
    return e_;
  }

   const iterator& find(T& p)
  {
    for(int i = 0; i < numof; i++)
    {
      if (a[i] == p)
      {
        return b_;
      }
    }
  }

  void remove_duplicates()
  {
    std::map<T, int> dup;
    for (int i=0; i<numof; i++)
    {

      if (dup.count(a[i]) == 0)
      {
        dup[a[i]] = 1;
      } else {
        dup[a[i]]++;
      }
    }
    for (auto const& d : dup)
    {
      cout << d.first << " : " << d.second << endl;
    }

    for (auto const& d : dup)
    {
      if(d.second > 1)
      {
        for (int i=0; i<d.second-1; i++)
        {
          erase(d.first);
        }
      }
    }
  }

  vector copy()
  {
    cout << "ya mon" << endl;
    return vector(*this);
  }


  int size()
  {
    return numof;
  }

  int capacity()
  {
    return capofarr;
  }

  void clear()
  {
    while(!empty())
    pop();
  }
  void pop()
  {
    if (!empty())
    {
      numof--;
      return a[numof];
    }
    else
    {
      cout << "You can't pop from an empty stack!" << endl;
      return 0;
    }
  }
  void insert(T n)
  {
    T* temp_arr = new T[numof+1];
    for (int i=0; i<numof; i++)
    {
        temp_arr[i] = a[i];
    }
    temp_arr[numof] = n;
    a = temp_arr;
    numof++;
    e_ = iterator(numof, this, numof);
    capofarr++;

  }

  bool empty()
  {
    return (numof == 0);
  }

  void swap(T& o, T& p)
  {
    T temp;
    temp =o;
    o=p;
    p= temp;
  }

  void erase_all(T p)
  {
    int numtimes = 0;

    for(int i=0;i<numof;i++)
    {
       if(p == a[i])
       {
         numtimes++;
       }
    }

     for(int i= 0; i < numtimes;i++)
     {
       erase(p);
     }
  }
  void erase(T p)
  {
    T* check;
    for(int i=0;i<numof-1;i++)
    {
      if(p == a[i])
      {
        swap(a[i],a[i+1]);
      }
    }
    check = new T [numof -1];
    for(int i=0;i < numof-1;i++)
    {
      check[i] = a[i];
    }
   a = check;
   numof--;
   e_ = iterator(numof, this, numof);

  }

  void shrink()
  {
    e_ = iterator(numof, this, numof);
    capofarr = numof;
   }

 int count (T v)
 {
   int f = 0;
   for(int i = 0; i < numof; i++)
   {
     if (a[i] == v)
     {
       f++;
     }
   }
   return f;
 }

private:
  T* a;
  int capofarr;
  int numof;
  iterator b_;
  iterator e_;
  iterator find_;
};
}
#endif
