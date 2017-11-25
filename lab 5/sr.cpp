#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//#define DEBUG

int main(int argc, char** argv)
{

ifstream myfile;
myfile.open(argv[1]);
int c =0;
string words1;
string word(argv[2]);
while (!myfile.eof())
{
  while (myfile>>words1)
  {
    std::size_t found = words1.find(word);
    if (found!=std::string::npos)
      c++;
  }

}
myfile.close();
cout << word << "\tAppears\t" << c << "times" << endl;


  return 0;

}
