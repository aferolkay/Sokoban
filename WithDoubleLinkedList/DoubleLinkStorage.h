#ifndef DOUBLELINKSTORAGE_H_INCLUDED
#define DOUBLELINKSTORAGE_H_INCLUDED

#include <iostream>
using namespace std;
#include <fstream>
#include "DoubleLinked.h"

 template<class T>
 class DoubleLinkStorage{

    private:
        // for creating a reference with no content
        DoubleLinked<T> HEAD;
        //points to the last link
        DoubleLinked<T>* curr;

    public:
        //initally curr points to HEAD
        DoubleLinkStorage():curr(HEAD.give_location()){} ;

        //Adds a link which contains the input
        void Add(T input);
        //Deletes the last link and points curr to the new last link
        void Undo(T& input);
        //Determines if its empty or not
        bool is_empty();
        //prints all links from first to last link content
        void print_SQ();

 };

 //Adds a link which contains the input
 template<class T>
 void DoubleLinkStorage<T>::Add(T input){
     //points to the new last link
     curr=curr->AddAfter(input);

 }

  //Determines if its empty or not by checking if last link equal to reference
 template<class T>
 bool DoubleLinkStorage<T>::is_empty(){
    if(*curr==HEAD) return true;
    return false;
 }

  //prints all links from first to last link content
 template<class T>
 void DoubleLinkStorage<T>::print_SQ(){
    //to start from the first link
     DoubleLinked<T>* temp=&HEAD;
     //stops when last link points to null
     while(!(temp->GetNext()==NULL)){
        //printing the content
        temp->GetNext()->data.print_puzzle();
        //switching links
        temp=temp->GetNext();
     }

 }

//Deletes the last link and points curr to the new last link
template<class T>
 void DoubleLinkStorage<T>::Undo(T& input){
     //pointer backs out 1 link
     curr=curr->GetPrev();
     //puzzle turns old state
     input=curr->data;
     //last link removed
     curr->DeleteAfter();
     //printing the new last link
     curr->data.print_puzzle();

 }

#endif // DOUBLELINKSTORAGE_H_INCLUDED
