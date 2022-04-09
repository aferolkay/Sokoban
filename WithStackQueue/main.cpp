#include "Sokoban.h"
#include "StackQueue.h"
#include <iostream>
using namespace std;
#include <fstream>
// TIME SPENT: APPROXIMATELY 25 HOURS

int main(){
    //read file
    Sokoban PUZZLE("sample_puzzle.txt");
    //to store previous moves
    StackQueue<Sokoban> HISTORY;
    char input;
    //store initial state
    HISTORY.push_front(PUZZLE);
    PUZZLE.print_puzzle();
    while(1){
        cout<<"Please enter your move:";
        cin>>input;
        cout<<endl;
        switch(input){

            case('w'):
                cout<<endl<<"Moving Up"<<endl<<endl;
                //player moves if possible
                if(PUZZLE.move_up())
                    //to store the new condition
                    HISTORY.push_front(PUZZLE);
                PUZZLE.print_puzzle();

                break;
            case('a'):
                cout<<endl<<"Moving Left"<<endl<<endl;
                //player moves if possible

                if(PUZZLE.move_left())
                    //to store the new condition
                    HISTORY.push_front(PUZZLE);
                PUZZLE.print_puzzle();
                break;

            case('s'):
                cout<<endl<<"Moving Down"<<endl<<endl;
                //player moves if possible
                if(PUZZLE.move_down())
                    //to store the new condition
                    HISTORY.push_front(PUZZLE);
                PUZZLE.print_puzzle();

                break;
            case('d'):
                cout<<endl<<"Moving Right"<<endl<<endl;
                //player moves if possible
                if(PUZZLE.move_right())
                    //to store the new condition
                    HISTORY.push_front(PUZZLE);
                PUZZLE.print_puzzle();


                break;
            case('z'):
                //deletes the last state
                HISTORY.pop_front();
                //now the previous state is the PUZZLE
                PUZZLE=HISTORY.peek();
                PUZZLE.print_puzzle();
                break;
            case('r'):
                //prints all states
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

