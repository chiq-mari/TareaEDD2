#include ".\priorityQueue.h"

template<class T, class Q>
priorityQueue<T, Q> ::priorityQueue(){
    //la lista se crea por defecto
    this->length=0;
}

template<class T, class Q>
List<T, Q> priorityQueue<T, Q> ::getList(){
    return this->prioQueu;
}

template<class T, class Q>
int priorityQueue<T, Q> ::getLength(){
    return this->length;
}

//va a pushear un valor(data a una cola dada su prioridad, si no esta se la crea--> pushea por la cola de la queue del nodo de la lista)
template<class T, class Q>
void priorityQueue<T, Q>::push(Q data, T priority){
    List<T, Q> colaDePrioridad=this->getList();
    NodeL<T, Q>* actual= colaDePrioridad.findPrio(priority);

    // si no existe la crea
    if(actual==nullptr){
      colaDePrioridad.insert(priority); //inserta un nodo con dato prioridad, y queue vacia 
      actual= colaDePrioridad.findPrio(priority);   //y halla su nodo
    }

    //obtiene la cola para la insercion dado el nodo
    Queue<Q> colaParaInsercion=actual->getCola();
    colaParaInsercion.push(data);   //pushea el dato
}

