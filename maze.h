#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include "graph.h"

using namespace std;

struct direction
{
   int dir[5]; //left, right, up, down, not available
};

class maze
{
 public:
   maze(ifstream &fin);
   void print(int, int, int, int);
   bool isLegal(int i, int j);

   void setMap(int i, int j, int n);
   int getMap(int i, int j) const;
   void mapMazeToGraph(graph &g);
   void getDir();

 private:
   int rows; // number of rows in the maze
   int cols; // number of columns in the maze
   int numVisitable;

   matrix<direction> possibleDir;
   matrix<bool> value;
   matrix<int> map; // Mapping from maze (i,j) values to node index values
};

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j) to graph node n.
{
   map[i][j] = n;
}

int maze ::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
   return map[i][j];
}

maze::maze(ifstream &fin) : numVisitable(0)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
   fin >> rows;
   fin >> cols;

   char x;

   value.resize(rows, cols);
   for (int i = 0; i <= rows - 1; i++)
      for (int j = 0; j <= cols - 1; j++)
      {
         fin >> x;
         if (x == 'O')
            value[i][j] = true;
         else
            value[i][j] = false;
      }

   map.resize(rows, cols);
   possibleDir.resize(rows, cols);
}

void maze::getDir()
{
   for (int i = 0; i < cols; i++)
      for (int k = 0; k < rows; k++)
         for(int j = 0; j < 5; j++)
         {
            possibleDir[i][k].dir[j] = 0;
         }

   for (int i = 0; i < cols; i++)
      for (int k = 0; k < rows; k++)
      {
         possibleDir[i][k].dir[4] = 0;
         if (value[i][k] == false)
         {
            numVisitable++;
            if (value[i][k - 1] && k-1 >= 0)
               possibleDir[i][k].dir[0] = 1;
            else
               possibleDir[i][k].dir[0] = 0;

            
            if (value[i][k + 1] && k+1 <= rows)
               possibleDir[i][k].dir[1] = 1;
            else
               possibleDir[i][k].dir[1] = 0;

            
            if (value[i - 1][k] && i-1 >= 0)
               possibleDir[i][k].dir[2] = 1;
            else
               possibleDir[i][k].dir[2] = 0;
            

            if (value[i + 1][k] && i+1 <= cols)
               possibleDir[i][k].dir[3] = 1;
            else
               possibleDir[i][k].dir[3] = 0;
            
         }
         else 
            possibleDir[i][k].dir[4] = 1;
      }

   return;
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
   cout << endl;

   if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
      throw rangeError("Bad value in maze::print");

   if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
      throw rangeError("Bad value in maze::print");

   for (int i = 0; i <= rows - 1; i++)
   {
      for (int j = 0; j <= cols - 1; j++)
      {
         if (i == goalI && j == goalJ)
            cout << "*";
         else if (i == currI && j == currJ)
            cout << "+";
         else if (value[i][j])
            cout << " ";
         else
            cout << "X";
      }
      cout << endl;
   }
   cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze.
{
   if (i < 0 || i > rows || j < 0 || j > cols)
      throw rangeError("Bad value in maze::isLegal");

   return value[i][j];
}

void maze::mapMazeToGraph(graph &g)
// Create a graph g that represents the legal moves in the maze m.
{
   int i = 0, j = 0;
   map[i][j] = 1; //unsure if indexed from one or zero
   while (i != rows - 1)
   {
      while(j != cols - 1)
      {
         
      }
   }
}
