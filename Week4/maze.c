#include <stdio.h>
#include<stdbool.h>
void printMaze(char **maze, const int HT, const int WD); // prints the maze

bool solveMaze(char **maze, const int HT, const int WD, int x, int y); // draws a path to the exit on the maze string



int main(){
    char mazeStr[] ="  ##############"
            "#     #     ####"
            "# ####* ### ####"
            "#    ###### ####"
            "#### # #### ####"
            "#    # #### ####"
            "#### # #### ####"
            "####        ####"
            "################";

    const int HT = 9;
    const int WD = 16; 
    char *maze[HT];

    for (int i=0; i<HT ; i++)       // filling the 2D char array
    maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0); 
    
    printMaze(maze, HT, WD);
    return 0;
}

//Assume starting point at 0,0
//Assume borders as #
//Assume correct path filling with .
//Assume the destination as *


bool solveMaze(char **maze, const int HT, const int WD, int x, int y){
    if(x<0 || x>=WD || y<0 || y>=HT){
        return false;                 //if x,y outside of maze return false
    }

        if(maze[y][x]=='*'){
            return true;             //if x,y reached destination return true
    }
        if(maze[y][x]=='#' || maze[y][x]=='.'){
        return false;                //if x,y is blocked by '#' or '.' return false
    }

    maze[y][x]='.';    //draws path with '.'

    if(solveMaze(maze, HT, WD, x, y+1)==true){
        return true;  //South
    }
    if(solveMaze(maze, HT, WD, x+1, y)==true){
        return true;  //East
   }
    if(solveMaze(maze, HT, WD, x, y-1)==true){
        return true;  //North
    }
    if(solveMaze(maze, HT, WD, x-1, y)==true){
        return true;  //West
    }

    maze[y][x]=' ';  // replaces '.' with ' ' if '*' is not found

    return 0;


    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes
    // pay attention to the bounds of the arrays
    // make sure you don't enter an infinite recursion

}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
    for(int j=0; j<WD-1; j++)
      printf("%c",maze[i][j]);
    printf("%c\n",maze[i][WD-1]);
    }
}




