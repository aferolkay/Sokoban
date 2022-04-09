#ifndef DOUBLELINKED_H_INCLUDED
#define DOUBLELINKED_H_INCLUDED
#include <iostream>
#include "stdlib.h"
#include "stddef.h"

template<class T>
 class DoubleLinked{
private:
    //to reach the previous and next blocks
    DoubleLinked<T> *Prev,*Next;
public:
    //to store data
    T data;
    //constructor
    DoubleLinked();
    //gives the location of the DoubleLinked
    DoubleLinked<T> *give_location();
    //constructs with given data
    DoubleLinked(const T& item);
    //adds another DoubleLinked
    DoubleLinked<T> *AddAfter(const T& item);
    //deletes the following DoubleLinked and connects other if they exist
    DoubleLinked<T> *DeleteAfter(void);
    //gives location of the previous
    DoubleLinked<T> *GetPrev(void);
    //gives the location of the following
    DoubleLinked<T> *GetNext(void);


 };

 template<class T>
 DoubleLinked<T>* DoubleLinked<T>::give_location(){
    return this;
 }

 template<class T>
 DoubleLinked<T>::DoubleLinked(){
    //I don't want to create circular so they point to nothing initially
    Next=Prev=NULL;
 }

 template<class T>
 DoubleLinked<T>::DoubleLinked(const T& item){
    data=item;
    Next=Prev=NULL;
 }

 template<class T>
 DoubleLinked<T> *DoubleLinked<T>::AddAfter(const T& item){
    DoubleLinked<T> *tempPtr = Next;
    Next = new DoubleLinked;
    Next->Prev=this;
    Next->data=item;
    Next->Next=tempPtr;
    //If there isn't a successor don't point back
    if(!(tempPtr==nullptr)) tempPtr->Prev=Next;
    return Next;
 }

 template<class T>
 DoubleLinked<T>* DoubleLinked<T>::DeleteAfter(void){
    DoubleLinked<T> *tempPtr = Next;

	// if there isn't a successor, return NULL
    if (Next == NULL)
        return NULL;

    Next = tempPtr->Next;
    tempPtr->Next=NULL;
    //If there isn't a successor don't point back
    if (!(Next==NULL)) Next->Prev=this;
    tempPtr->Prev=NULL;

	// return the pointer to the unlinked node
    return tempPtr;
 }

 template<class T>
 DoubleLinked<T>* DoubleLinked<T>::GetPrev(void){
    return Prev;
 }
 template<class T>
 DoubleLinked<T>* DoubleLinked<T>::GetNext(void){
    return Next;
 }


#endif // DOUBLELINKED_H_INCLUDED
