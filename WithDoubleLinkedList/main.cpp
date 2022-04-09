#include "Sokoban.h"
#include <iostream>
using namespace std;
#include <fstream>
#include "DoubleLinked.h"
#include "DoubleLinkStorage.h"
// TIME SPENT: APPROXIMATELY 25 HOURS
int main(){
    //read file
    Sokoban PUZZLE("sample_puzzle.txt");
    // to store history
    DoubleLinkStorage<Sokoban> HISTORY;
    char input;
    //store initial state
    HISTORY.Add(PUZZLE);
    PUZZLE.print_puzzle();

    while(1){
        cout<<"Please enter your move:";
        cin>>input;
        cout<<endl;
        switch(input){
            case('w'):
                cout<<endl<<"Moving Up"<<endl<<endl;
                //player move
                if(PUZZLE.move_up())
                    HISTORY.Add(PUZZLE);
                PUZZLE.print_puzzle();
                //new state is stored
                break;
            case('a'):
                cout<<endl<<"Moving Left"<<endl<<endl;
                //player move
                if(PUZZLE.move_left())
                    HISTORY.Add(PUZZLE);
                PUZZLE.print_puzzle();
                //new state is stored
                break;
            case('s'):
                cout<<endl<<"Moving Down"<<endl<<endl;
                //player move
                if(PUZZLE.move_down())
                    HISTORY.Add(PUZZLE);
                PUZZLE.print_puzzle();
                //new state is stored

                break;
            case('d'):
                cout<<endl<<"Moving Right"<<endl<<endl;
                //player move
                if(PUZZLE.move_right())
                    HISTORY.Add(PUZZLE);
                PUZZLE.print_puzzle();
                //new state is restored

                break;
            case('z'):
                //undo move
                HISTORY.Undo(PUZZLE);
                break;
            case('r'):
                //prints all past map states
                  HISTORY.print_SQ();
                  break;
            case('q'):
                cout<<endl<<"Leaving Game"<<endl;
                return 0;
            default:
                cout<<endl<<"invalid input"<<endl;
        }
    if(PUZZLE.is_solved()) cout<<endl<<"Congratulations!"<<endl;
    }




}

