#include<iostream>
#include ".\nodeForQueue.h"
using namespace std;
//same template as in classN4

template<class T>   //added in p3 hwk
NodeQ<T> :: NodeQ(){
    this->next=nullptr;
    //data del nodo cola se va por defecto
}

template<class T>
NodeQ<T>::NodeQ(T data, NodeQ<T>* next){
    this->data = data;
    this->next = next;
}

template<class T>
NodeQ<T>::~NodeQ(){
    this->next = nullptr; 
}

template<class T>
T NodeQ<T>::getData(){
    return this->data;
}
template<class T>
void NodeQ<T>::setData(T data){
    this->data = data;
}

template<class T>
NodeQ<T>* NodeQ<T>::getNext(){
    return this->next;
}

template<class T>
void NodeQ<T>::setNext(NodeQ<T>* next){
    this->next = next;
}

template<class T>
void NodeQ<T>::print(){           //impresion de un nodo --> da el dato en cola
    //cout<<"Data:\n";
   cout<<this->data<<endl;                      
}

