#ifndef STACKQUEUE_H_INCLUDED
#define STACKQUEUE_H_INCLUDED
#include <iostream>
using namespace std;
#include <fstream>
 template<class T>
 class StackQueue{

    private:
        int MaxSize=100;
        T List[100];
        int front;
        int rear;
        // how many member
        int count;

    public:
        StackQueue();
        //input
        void push_front(T input);
        //leave from front
        T pop_front();
        //leave from rear
        T pop_rear();
        //look at the front
        T peek();

        bool is_full();
        bool is_empty();
        int size();
        //iterates between all members and if they are sakoban, prints
        void print_SQ();

 };
 template<class T>
 StackQueue<T>::StackQueue(){
    front=rear=count=0;
 }

 template<class T>
 void StackQueue<T>::push_front(T input){
     List[front]=input;
     front=(front+1)%MaxSize;
     count++;
 }

 template<class T>
 T StackQueue<T>::pop_front(){
     if(count==1){
        cerr<<"No previous moves"<<endl<<endl;
        return List[0] ;
     }
     front=(front-1)%MaxSize;
     count--;
     return List[front-1];
 }

 template<class T>
 T StackQueue<T>::pop_rear(){
    rear=(rear+1)%MaxSize;
    count--;
    return List[rear];
 }

 template<class T>
 T StackQueue<T>::peek(){
    return List[(front-1)%MaxSize];
 }

 template<class T>
 bool StackQueue<T>::is_full(){
    if(count==MaxSize) return true;
    return false;
 }

 template<class T>
 bool StackQueue<T>::is_empty(){
    if(count==0) return true;
    return false;
 }

 template<class T>
 int StackQueue<T>::size(){
     return (count);
 }

 template<class T>
 void StackQueue<T>::print_SQ(){
     //if not empty
     if(count>0){
     cout<<endl<<"Replays from oldest to newest:"<<endl<<endl;
     //iterate all maps
     for (int i=0;i<count;i++ )
        List[i].print_puzzle();
     }
     else cerr<<"No history yet";
 }

#endif // STACKQUEUE_H_INCLUDED
