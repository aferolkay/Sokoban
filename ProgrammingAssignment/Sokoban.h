#ifndef SOKOBAN_H_INCLUDED
#define SOKOBAN_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;
#include <fstream>
class Sokoban{
private:
    int Row=6;
    int Column=8;
    char Map[6][8];
    int P_cursor[2]; //{player's Row,player's Column}
public:
    Sokoban(); //Constructor
    Sokoban(const Sokoban &old_Sokoban);// copy constructor
    Sokoban operator=(const Sokoban &old_Sokoban); //copy assignment OPERATORUN BAŞINDAN & KALDIRDIM
    Sokoban(string Path);//Constructor from file

    bool possible(int ax,int ay);//takes in a vector and determines if it is possible to move in that direction.
    bool is_Target(char *p);//Determines whether a tile is target.
    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();
    void Move(int ax,int ay); //When only player moves
    void Push(int ax,int ay); //When player pushes box
    void Change(char &x);     //Switches between target and normal form
    bool is_solved();         //Checks if the puzzle is solved
    void print_puzzle();      //Prints map
    void find_player();//locates the Player
    //Queue<char> GetMap(); // Gets the map into an queue
};

Sokoban::Sokoban(){
    for(int i=0 ; i<Row ; i++ )
        for(int j=0 ; j<Column ; j++ ){
                Map[i][j]='#';
        }
}
Sokoban::Sokoban(const Sokoban &old_Sokoban){
    for(int i=0 ; i<Row ; i++ )
        for(int j=0 ; j<Column ; j++ ){
            this->Map[i][j]=old_Sokoban.Map[i][j];
        }
}
Sokoban Sokoban::operator=(const Sokoban &old_Sokoban){//BURAYLA OYNADUM OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    for(int i=0 ; i<Row ; i++ )
        for(int j=0 ; j<Column ; j++ ){
            Map[i][j]=old_Sokoban.Map[i][j];
        }
}
Sokoban::Sokoban(string Path){
    char dummy;
    ifstream file;
    file.open(Path);
    for(int i=0; i<6; ++i){
        for(int j=0; j<8; ++j){
            file >> noskipws >> Map[i][j];
        }
     file >> noskipws >> dummy;
    }
    file.close();
}

void Sokoban::print_puzzle(){
    for(int i=0 ; i<Row ; i++ ){
        for(int j=0 ; j<Column ; j++ ){
                cout<<Map[i][j]<<' ' ;
        }
        cout<<endl;
        }
}
bool Sokoban::is_solved(){
    for(int i=0 ; i<Row ; i++ )
        for(int j=0 ; j<Column ; j++ )
            if(Map[i][j]=='.'||Map[i][j]=='+') return false;

    return true;
}

bool Sokoban::possible(int ax,int ay){
    char p1=Map[P_cursor[0]-ay][P_cursor[1]+ax];
    char p2=Map[P_cursor[0]+(-2)*ay][P_cursor[1]+2*ax];

    if( p1=='#' ){
        cerr<<"invalid input"<<endl;
        return false;
    }
    else if( p1=='$'|| p1=='*'){
        if( p2=='#' || p2=='$'|| p2=='*' ){
            cerr<<"invalid  input"<<endl;
            return false;
        }
        else return true;
    }
    return true;
}
void Sokoban::Move(int ax,int ay){
    char*p[2]={ &Map[P_cursor[0]][P_cursor[1]],&Map[(P_cursor[0]-ay)][(P_cursor[1]+ax)]};
    int isTarget[2]={is_Target(p[0]),is_Target(p[1])};
    int k=0;
    *p[1]='@';
    *p[0]=' ';

    for(int x : isTarget){
        if(x) Change(*p[k]);
        k++;
    }
}
void Sokoban::Push(int ax,int ay){
    char*p[3]={ &Map[P_cursor[0]][P_cursor[1]],&Map[(P_cursor[0]-ay)][(P_cursor[1]+ax)],&Map[P_cursor[0]+(-2)*ay][P_cursor[1]+2*ax]};
    int isTarget[3]={is_Target(p[0]),is_Target(p[1]),is_Target(p[2])};
    int k=0;
    *p[2]='$';
    *p[1]='@';
    *p[0]=' ';

    for(int x : isTarget){
        if(x) Change(*p[k]);
        k++;
    }
}
bool Sokoban::is_Target(char* p){
    if(*p=='.'||*p=='*'||*p=='+') return true;
    else return false;
}
void Sokoban::Change(char &x){
    switch(x){
        case ' ':
            x  =  '.';
            break;
        case '.':
            x  =  ' ';
            break;
        case '$':
            x  =  '*';
            break;
        case '*':
            x  =  '$';
            break;
        case '@':
            x  =  '+';
            break;
        case '+':
            x  =  '@';
            break;
    }
}
void Sokoban::find_player(){
    for(int i=0 ; i<Row ; i++ )
        for(int j=0 ; j<Column ; j++ )
            if (Map[i][j]=='@'||Map[i][j]=='+'){
                P_cursor[0]=i;
                P_cursor[1]=j;
                return;
            }
}

bool Sokoban:: move_up(){
    find_player();
    if(possible(0,1)==false)   return false;
    else if(Map[P_cursor[0]-1][(P_cursor[1]+0)]=='$'||Map[(P_cursor[0]-1)][(P_cursor[1]+0)]=='*'){ //box is being pushed
        Push(0,1);
    }
        else{ //only player moves
            Move(0,1);
         }
    return true;
}
bool Sokoban:: move_down(){
    find_player();
    if(possible(0,-1)==false)   return false;
    else if(Map[P_cursor[0]+1][(P_cursor[1]+0)]=='$'||Map[P_cursor[0]+1][P_cursor[1]+0]=='*'){ //box is being pushed
        Push(0,-1);
    }
        else{ //only player moves
            Move(0,-1);
         }
    return true;
}
bool Sokoban:: move_right(){
    find_player();
    if(possible(1,0)==false)   return false;
    else if(Map[P_cursor[0]][(P_cursor[1]+1)]=='$'||Map[(P_cursor[0])][(P_cursor[1]+1)]=='*'){ //box is being pushed
        Push(1,0);
    }
        else{ //only player moves
            Move(1,0);
         }
    return true;
}
bool Sokoban:: move_left(){
    find_player();
    if(possible(-1,0)==false)   return false;
    else if(Map[P_cursor[0]][P_cursor[1]-1]=='$'||Map[P_cursor[0]][P_cursor[1]-1]=='*'){ //box is being pushed
        Push(-1,0);
    }
        else{ //only player moves
            Move(-1,0);
         }
    return true;
}
#endif // SOKOBAN_H_INCLUDED
