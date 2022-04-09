#ifndef SOKOBAN_H_INCLUDED
#define SOKOBAN_H_INCLUDED
#include "queue.h"
#include "stack.h"


class Sokoban{
private:
    Row=6
    Column=8
    char Map[Row][Column];

public:
    Sokoban(); //Constructor
    Sokoban(const Sokoban &old_Sokoban);// copy constructor
    Sokoban &operator=(const &old_Sokoban); //copy assignment
    Sokoban(string Path);//Constructor from file

    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();
    bool is_solved();
    void print_puzzle();
    Queue<char> GetMap();
};

Sokoban::Sokoban(){ //initalizes all map to walls if there is no input
    for( i=0 ; i<row ; i++ )
        for( j=0 ; j<column ; i++ ){
                Map[i][j]='#';
        }
}
Sokoban::Sokoban(const Sokoban &old_Sokoban){ //takes old  map into a queue and pops it into the new one UNCLEAR
    Queue<char> newMap=old_sokoban.GetMap();
    for( i=0 ; i<row ; i++ )
        for( j=0 ; j<column ; i++ ){
            this.Map[i][j]=newMap.QDelete();
        }
}
Sokoban::Sokoban &operator=(const Sokoban &old_Sokoban){ //takes old  map into a queue and replaces it into the current one UNCLEAR
    Queue<char> newMap=old_sokoban.GetMap();
    for( i=0 ; i<row ; i++ )
        for( j=0 ; j<column ; i++ ){
            Map[i][j]=newMap.QDelete();
        }
}
Sokoban::Sokoban(string Path)




Sokoban::Queue<char> GetMap(){
    for( i=0 ; i<row ; i++ )
        for( j=0 ; j<column ; i++ ){
            this.Qinsert(Map[i][j]);
        }
}

#endif // SOKOBAN_H_INCLUDED
