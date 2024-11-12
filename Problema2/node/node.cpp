#include<iostream>
#include "node.h"
using namespace std;

//Nodo es generico--> Va tanto como para pila como para cola

template<class T>   //constructor/No hay por default
Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}

template<class T>
Node<T>::~Node(){
    this->next = nullptr; 
}

template<class T>
T Node<T>::getData(){
    return this->data;
}

template<class T>
void Node<T>::setData(T data){
    this->data = data;
}

template<class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template<class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

template<class T>       //no esta imprimiendo la direccion del siguiente nodo
void Node<T>::print(){
   this->data.printPerson();
   cout<<endl;
}

