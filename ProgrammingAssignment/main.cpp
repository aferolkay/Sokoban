#include "Sokoban.h"
//#include "StackQueue.h"
//#include "INTRO.h"
#include <iostream>
using namespace std;
#include <fstream>
#include "DoubleLinked.h"
#include "DoubleLinkStorage.h"

int main(){
    Sokoban PUZZLE("sample_puzzle.txt");
    DoubleLinkStorage<Sokoban> HISTORY;
    char input;

    HISTORY.Add(PUZZLE);
    PUZZLE.print_puzzle();

    while(1){
        cout<<"Please enter your move:";
        cin>>input;
        cout<<endl;
        switch(input){
            case('w'):
                cout<<endl<<"Moving Up"<<endl<<endl;
                PUZZLE.move_up();
                PUZZLE.print_puzzle();
                HISTORY.Add(PUZZLE);
                break;
            case('a'):
                cout<<endl<<"Moving Left"<<endl<<endl;
                PUZZLE.move_left();
                PUZZLE.print_puzzle();
                HISTORY.Add(PUZZLE);
                break;
            case('s'):
                cout<<endl<<"Moving Down"<<endl<<endl;
                PUZZLE.move_down();
                PUZZLE.print_puzzle();
                HISTORY.Add(PUZZLE);
                break;
            case('d'):
                cout<<endl<<"Moving Right"<<endl<<endl;
                PUZZLE.move_right();
                PUZZLE.print_puzzle();
                HISTORY.Add(PUZZLE);
                break;
            case('z'):
                HISTORY.Undo();
                break;
            case('r'):
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





//    INTRO intro;
//    intro.rolltheintro();
//    Sokoban PUZZLE("sample_puzzle.txt");
//    StackQueue<Sokoban> HISTORY;
//    Sokoban temp;
//    char input;
//
//    HISTORY.push_front(PUZZLE);
//    PUZZLE.print_puzzle();
//    while(1){
//        cout<<"Please enter your move:";
//        cin>>input;
//        cout<<endl;
//        switch(input){
//            case('w'):
//                cout<<endl<<"Moving Up"<<endl<<endl;
//                PUZZLE.move_up();
//                PUZZLE.print_puzzle();
//                HISTORY.push_front(PUZZLE);
//                break;
//            case('a'):
//                cout<<endl<<"Moving Left"<<endl<<endl;
//                PUZZLE.move_left();
//                PUZZLE.print_puzzle();
//                HISTORY.push_front(PUZZLE);
//                break;
//            case('s'):
//                cout<<endl<<"Moving Down"<<endl<<endl;
//                PUZZLE.move_down();
//                PUZZLE.print_puzzle();
//                HISTORY.push_front(PUZZLE);
//                break;
//            case('d'):
//                cout<<endl<<"Moving Right"<<endl<<endl;
//                PUZZLE.move_right();
//                PUZZLE.print_puzzle();
//                HISTORY.push_front(PUZZLE);
//                break;
//            case('z'):
//                HISTORY.pop_front();
//                //*****************************************************
//                PUZZLE=HISTORY.peek();
//                //*****************************************************
//                PUZZLE.print_puzzle();
//                break;
//            case('r'):
//                  HISTORY.print_SQ();
//                  break;
//            case('q'):
//                cout<<endl<<"Leaving Game"<<endl;
//                return 0;
//            default:
//                cout<<endl<<"invalid input"<<endl;
//        }
//    if(PUZZLE.is_solved()) cout<<endl<<"Congratulations!"<<endl;
//    }
}

