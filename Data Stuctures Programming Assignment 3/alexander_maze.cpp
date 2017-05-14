//  Michael Alexander
//  Data Stuctures Programming Assignment 3
//  alexander_maze.cpp
#include <iostream>
#include "outputhelp.h"
#include "position.h"
using namespace ds_maze;

void find_path(std::vector<std::vector<int>> maze);

int main(int argc, char * argv[]) {

    std::vector<std::vector<int>> maze;

    for(int i=1; i < argc; i++) {
        if(readMaze(argv[i], maze)){
            find_path(maze);
            maze.clear();
        }
    }
}
void find_path(std::vector<std::vector<int>> maze)
{
    std::stack<position> mazeStack;
    
    position start(1,1,0); // set starting point for mazes
    
    mazeStack.push(start);
    
    position current;
    int x, y, steps;
   
    while(!mazeStack.empty())
    {
        current = mazeStack.top();
        x = current.row();
        y = current.col();
        steps = current.steps();
        
        if(x == maze.size() - 2 && y == maze[0].size() - 2) // if maze is at exit, break out of loop
            break;
        
      // if adjacent postition is zero, move specified direction
        if(maze[x+1][y] != 1)
        {
            maze[x+1][y] = 1;
            position right(x+1, y, steps+1); //move right
            mazeStack.push(right);
        }
        else if(maze[x][y+1] != 1)
        {
            maze[x][y+1] = 1;
            position down(x, y+1, steps+1); // move down
            mazeStack.push(down);
        }
        else if(maze[x][y-1] != 1)
        {
            maze[x][y-1] = 1;
            position up(x, y-1, steps+1); // move up
            mazeStack.push(up);
        }
        else if(maze[x-1][y] != 1)
        {
            maze[x-1][y] = 1;
            position left(x-1, y, steps+1);// move left
            mazeStack.push(left);
        }
        else  //else backtrack
            mazeStack.pop();
        }
    OutputPath(mazeStack); //output maze path
}
