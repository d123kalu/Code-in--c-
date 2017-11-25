#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

//#define DEBUG

int main(int argc, char** argv)
{
  int c = 0;
  int pos = 0;
  string w;
  for(int i=1;i < argc;i++)
  {
    int totfound = 0;
    cout << argv[i] << ":" << endl;
    ifstream myfile;
    myfile.open("db.txt");
    string word(argv[i]);
    string words1;
    while(!myfile.eof())
    {
      string n;
      getline(myfile, n);
      ifstream newfile;
      newfile.open(n.c_str());
      int linefound = 0;
      int linecount =0;
      string line;
      int numfound = 0;
      while (getline(newfile, words1))
       {
          linecount++;
          if(words1 == "")
          {
            break;
          }
          istringstream iss(words1);
           while(iss>> w)
          {
            if(w == word)
            {
              numfound++;
              if(linefound == 0)
              {
                linefound = linecount;
              }
            }
          }
        }



      if(numfound==1)
      {
        cout << "\tFound in " << n << " in line " << linefound << endl;
      }
      if(numfound > 1)
      {
        cout << "\tFound in "<< n <<" in line "<< linefound <<"("<< numfound<<") times"<< endl;
      }
      if(numfound==0)
      {
        numfound = totfound;
      }

    newfile.close();
    }
    if(totfound == 0)
    {
      cout << word << " was not found" << endl;
    }
  }
  return 0;
}
