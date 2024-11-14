#include ".\listForPQ.h"
#include <iostream>

using namespace std;

template<class T, class Q>
List<T, Q>::List(NodeL<T, Q>* node){ //constructor inicializaba la cabeza a apuntar a un objeto del tipo nodo
    this->head=node;
}

template<class T, class Q>
bool List<T, Q>::isEmpty(){
    return this->head == nullptr;   //si senala a nulo
}

template<class T, class Q>
void List<T, Q>::insertFirst(T priority){ //inserta prioridad
    if(isEmpty()){
        this->head = new NodeL<T, Q>(priority,nullptr);  //vacio --> da a head espacio nuevo e inicializa
        return;
    }
    NodeL<T, Q>* temp =this->head;            //no vacio
    this->head = new NodeL<T, Q>(priority,temp); 
    temp = nullptr;
}

template<class T, class Q> // al crear el nodo a insertar, el stack lo hace por default vacio
void List<T, Q>::insert(T priority){
    if(isEmpty() || priority<head->getPriority()){
       insertFirst(priority);
       this->length++;     // si no se anade, no cuenta dicho elemento  
       return;
    }

    NodeL<T, Q> *newNode =new NodeL<T, Q>(priority,nullptr);
    NodeL<T, Q> *actual = head;
    NodeL<T, Q> *prev = nullptr;
      
    while(actual!=nullptr && actual->getPriority() < priority) {
         prev = actual;
         actual = actual->getNext();
    }
      
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
    this->length++;
}

//se puede usar al hacer pop en un queue de 1 elemento
template<class T, class Q>
bool List<T, Q>::remove(T priority){   //se supone que cuando se desee remover un nodo
// es decir una prioridad, ya su queue debe estar vacia
   if(isEmpty()){
      return false;
   }

   NodeL<T, Q>* NodeToDelete=head;

   NodeL<T, Q>* prev=nullptr;

   
   while (NodeToDelete!=nullptr && NodeToDelete->getData()!=data)
   {
      prev=NodeToDelete;
      NodeToDelete=NodeToDelete->getNext();
   }

   if(NodeToDelete!=nullptr){ //se encontro
      if(prev==nullptr){   //sie era el primero
         head=NodeToDelete->getNext();
      }
      else{
         prev->setNext(NodeToDelete->getNext());   //se encontro pero no era el primero
      }

      this->length--;
      delete NodeToDelete;
      return true;
   }
   
   return false;  // se llego al final y NodeToDelete= nullptr
}
//------------

// Update no es necesario
/*
template<class T>
bool List<T>::update(int n, T data){   //posicion en la que se actualiza
   if(isEmpty() || n >=this->length){  //si la posic es mayor o esta vacia no se puede hacer la actualizacion
      return false;
   }
   Node<T> *nodeToUpdate = head;
   Node<T> *last = NULL;
   Node<T> *next = NULL;

   //ubicamos el nodo para actualizar
   for (int i = 0; i < n; i++)      // es como si estuviese indexado teniendo por [0]a head y que llegase a [n] en nodeToUpdate
   {
      last=nodeToUpdate;
      nodeToUpdate = nodeToUpdate->getNext();
   }

   //Comprobamos si al modificar el dato se altera el orden de la lista.

   T oldData= nodeToUpdate->getData(); //asigna datos T a oldData, nextData, lastData
   next=nodeToUpdate->getNext();
   T nextData;
   T lastData;
   if(next==NULL){   // en caso de que el a actualizar sea e ultimo
      
      lastData=last->getData();
      if(lastData>data){   //si el dato es menor al last 
         remove(oldData);  //remover old e insertar data
         insert(data);
         
      }else{
         nodeToUpdate->setData(data);  //dato es mayor o igual que lastData-->simplemente cambiar el dato de nodeToUpdate
      }
      return true;
   }

   if(last==NULL){      //en caso de que el a actualizar seaa el primero
      nextData=next->getData();  //halla el valor del siguiente
      if(nextData<data){   //si es menor elimina el primero e inserta
         remove(oldData);
         insert(data);
         
      }else{      // del resto el siguiente es mayor o igual y simplemente cambia el valor
         nodeToUpdate->setData(data);
      }

      return true;
   }
   // del resto, el a actualizar esta entre dos nodos
   lastData=last->getData();
   nextData=next->getData();

   if(lastData<=data && data<=nextData){ // si los valores cuadran, simplemente actualiza el valor de nodeToUpdate
      nodeToUpdate->setData(data);
    
     
   }else{      //si los valores no cuadran, remuevelo, e inserta el dato
   
      remove(oldData);
      insert(data);
   
   }
  
   return true;
}
*/
//--------------------
template<class T, class Q>
void List<T, Q>::print(){
    NodeL<T, Q>* actual = head;
    while (actual != nullptr)
    {
       actual->printPrio();
       actual = actual->getNext();
       cout<<endl;
    }   
}
//----------------------
/*
template<class T>
bool List<T>::update(int n, T data){   //posicion en la que se actualiza
   if(isEmpty() || n > this->length){  //si la posic es mayor o esta vacia no se puede hacer la actualizacion
      return false;
   }
   Node<T> *nodeToUpdate = head;

   //ubicamos el nodo para actualizar
   for (int i = 0; i < n; i++)      // es como si estuviese indexado teniendo por [0]a head y que llegase a [n] en nodeToUpdate
   {
      nodeToUpdate = nodeToUpdate->getNext();
   }
   this->remove(nodeToUpdate->getData());
   this->insert(data);   
   return true;
}
*/

//added in p3 hwk

template<class T, class Q>
List<T, Q>::List(){
   this->head=nullptr;
   length=0;
}


template<class T, class Q>
NodeL<T, Q>* List<T, Q>:: findPrio(T priority){
   NodeL<T, Q>* actual= this->head;
   while(actual!= nullptr && actual->getPriority()!=priority){
      actual=actual->getNext();
   }
   return actual; //retorna null si la prioridad no esta y su direccion de memoria si si
}