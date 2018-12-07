#include "main.h"
#include <fstream>
#include <iostream>
#include <limits.h>
#include <list>


using namespace std;

int main()
{
  char x;
  ifstream fin;
  string fileName = "maze1.txt";

  cout << "Enter the file name" << endl;
  getline(cin, fileName);
  // Read the maze from the file.

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
      m.print(m.rows-1, m.cols-1, 0, 0);
      cout << "Press (r) to solve recursively. Press (n) to solve Non-recursively." << endl;
      cin >> x;
      switch(x)
      {
        case 'r':
        case 'R':
          cout << "Solving Recursively." << endl;
          solveMazeDFS(m, g);
          break;
        
        case 'N':
        case 'n':
          cout << "Solving Non-recursively." << endl;
          solveMazeDFSR(m, g);
          break;
        
        default:
          cout << "Invalid input restart program." << endl;
          break;
      }
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