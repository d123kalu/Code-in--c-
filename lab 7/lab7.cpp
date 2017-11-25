#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

using namespace std;

class Student
{
private:

  // You need to implement the following four methods
  static std::string gen_name()
  {
    std::string n;
    char alpha[] ={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    int size;
    size = rand() % (12-6)+6;
    for(int i=0;i<size;i++)
    {
      int s;
      s = rand() % 62;
      n += alpha[s];
    }
     return n;
  }
  static int gen_number()
  {
    int s;
    s = rand()% (201600000-201100000) + 201100000;
    return s;
  }
  static int gen_grade()
  {
    int s;
    s = rand()% (100 - 70) + 70;
    return s;
  }
   double compute_average()
  {
    int sum;
    double a;
    sum = (g1 + g2 + g3 + g4 + g5);
    a = sum/5.0;
    return a;
  }

  public:
    std::string name_;
    int number_;
    //std::vector<int> grades_;
    int num_courses_;
    int g1,g2,g3,g4,g5;
    double ave_;

  Student()
  {
     name_ = gen_name();
     number_ = gen_number();
     g1 = gen_grade();
     g2 = gen_grade();
     g3 = gen_grade();
     g4 = gen_grade();
     g5 = gen_grade();
     ave_ = compute_average();
  }

  Student(const std::string& name, int number, double ave) : name_(name),ave_(ave), number_(number), num_courses_(5)
  {
    /*
    for (int i=0; i<num_courses_; ++i)
    {
      int num = gen_grade();
      grades_.push_back(num);
    }
    */
  }

  friend std::ostream& operator<<(std::ostream& os, const Student& s)
  {
    os << "Name = " << s.name_ << ", Number = " << s.number_ << " Grades = "
    << s.g1 <<","<<s.g2<<","<<s.g3<<","<<s.g4<<","<<s.g5<< " Average grade " << s.ave_ << endl;
    return os;
  }

/*
  void print_grades(std::ostream& os) const
  {
    os << "Grades = ";
    for (int i=0; i<num_courses_; ++i) {
      os << grades_[i] << ", ";
    }
  }
  */
};

#include <iostream>
#include <vector>
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <algorithm> // min_element(), max_element(), sort()
#include <string>
using namespace std;

bool sort(int i, int j) { return (i<j);}

bool operator<(const Student &lhs, const Student &rhs) {
              return lhs.name_ < rhs.name_;
          }

  int main(int argc,char* argv[])
  {
      srand(time(0));
      int numofStudents;
      if(argv[1]!= NULL)
      {numofStudents= atoi(argv[1]);}
      else
      {numofStudents = 1;}
      std::vector<Student> x;
      Student *f1;
      for(int i=0;i<numofStudents;i++)
      {
        f1 = new Student;
        f1-> name_;
        f1-> number_;
        f1-> g1;
        f1-> g2;
        f1-> g3;
        f1-> g4;
        f1-> g5;
        f1-> ave_;
        x.push_back(*f1);
      }
      
      for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++)
        {
           std::cout << *xi << std::endl;
        }

    std::cout << "Organized by Number" << endl;
    std::sort(x.begin(),x.end());
    for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++)
      {
         std::cout << *xi << std::endl;
      }

    std::cout << "ORGANISED VECTOR BY NAME" << endl;
   std::stable_sort(x.begin(), x.end());
   for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++) {
      std::cout << *xi << std::endl;
}

    std::cout << " VECTOR BY AVERAGE lowest to highest" << endl;
    for (std::vector<Student>::iterator xi = x.begin(); xi != x.end(); xi++) {
        std::cout << *xi << std::endl;
      }
    return 0;
  }
