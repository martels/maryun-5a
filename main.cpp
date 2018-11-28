// Project 5

#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include "maze.h"

using namespace std;

int main()
{
   char x;
   ifstream fin;

   // Read the maze from the file.
   string fileName = "maze1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {

      graph g;
      while (fin && fin.peek() != 'Z')
      {
         maze m(fin);
         m.print(4, 4, 5, 4);
      }
   }
   catch (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
   catch (rangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
}
