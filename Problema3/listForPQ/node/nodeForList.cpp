#include ".\nodeForList.h"
#include<iostream>
using namespace std;

template<class T, class Q>
NodeL<T, Q> :: NodeL(){

}


template<class T, class Q>  //not needed
NodeL<T, Q>::NodeL(T priority, NodeL<T, Q>* next){
    this->priority = priority;
    this->next = next;
    //cola se crea por defecto y se crea vacia
}

template<class T, class Q>  //not needed
NodeL<T, Q>::~NodeL(){
    this->next = nullptr;//next to null before to delete as a prec measure
    this->cola.~Queue();    //hace ambas ref's (head y tail--> null)
}  

template<class T, class Q>   
T NodeL<T, Q>::getPriority(){
    return this->priority;
}
template<class T, class Q>
void NodeL<T, Q>::setPriority(T priority){
    this->priority = priority;
}

template<class T, class Q>
NodeL<T, Q>* NodeL<T, Q>::getNext(){
    return this->next;
}

template<class T, class Q>
void NodeL<T, Q>::setNext(NodeL<T, Q>* next){
    this->next = next;
}

/*
template<class T, class Q>
void NodeL<T, Q>::print(){  // cuando se invoca el print de un nodo, resulta en imprimir el valor del dato y la direccion del siguiente
   cout<<this->priority<<endl;
   cout<<this->next<<endl;
}
*/

template<class T, class Q>
void NodeL<T, Q>:: printPrio(){
    cout<<"Priority: "<<this->priority<<endl;
    cola.printMine();
} 

template<class T, class Q>
Queue<Q>  NodeL<T, Q>::getCola(){
    return this->cola;
}
