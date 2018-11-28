#include <iostream>

using namespace std;

struct dir
{
    int direction[4];
};


int main()
{
    dir array[8];

    array[2].direction[0] = 1;
    array[2].direction[1] = 4;
    array[2].direction[2] = 2;
    array[2].direction[3] = 9;

    for(int i = 0; i < 4; i++)
    {
        cout << array[2].direction[i] << endl;
    }

}