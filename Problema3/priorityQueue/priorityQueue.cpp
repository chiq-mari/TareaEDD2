#include ".\priorityQueue.h"

template<class T, class Q>
priorityQueue<T, Q> ::priorityQueue(){
    //la lista se crea por defecto
    this->length=0;
}

template<class T, class Q>
ListPQ<T, Q>* priorityQueue<T, Q> ::getList(){
    return &prioQueue;
}

template<class T, class Q>
int priorityQueue<T, Q> ::getLength(){
    return length;
}

//va a pushear un valor(data a una cola dada su prioridad, si no esta se la crea--> pushea por la cola de la queue del nodo de la lista)
template<class T, class Q>
void priorityQueue<T, Q>::push(Q data, T priority){
    //accesa al atributo listaPQ a traves de un puntero
    ListPQ<T, Q>* colaDePrioridad=this->getList();

    //trata de encontrar el nodo de dicha prioridad
    NodeL<T, Q>* actual= colaDePrioridad->findPrio(priority);

    // si no existe la crea
    if(actual==nullptr){
      colaDePrioridad->insert(priority); //inserta un nodo con dato prioridad, y queue vacia 
      actual= colaDePrioridad->findPrio(priority);   //y halla su nodo
      this->length++;
    }

    //obtiene la cola para la insercion dado el nodo
    Queue<Q>* colaParaInsercion=actual->getCola();
    colaParaInsercion->push(data);   //pushea el dato
    return;
}

template<class T, class Q>
Q priorityQueue<T, Q>::pop(T priority){
    Q datoEliminado;

    //accesa primero a la lista
    ListPQ<T, Q>* colaDePrioridad=this->getList();

    //halla la prioridad
    NodeL<T, Q>* actual= colaDePrioridad->findPrio(priority);

    //si actual es null, no existe la prioridad y no hace nada
    if(actual==nullptr){
        return  datoEliminado; //salirse
    }

    //Del resto si existe la prioridad y utilizamos el queue de su nodo
    Queue<Q>* colaParaBorrado=actual->getCola();

    //elimina el dato y lo recupera
    datoEliminado= colaParaBorrado->pop();
    
    //una vez eliminado, si la colaParaInsercion quedo vacia, eliminar nodo, del resto queda igual
    if(colaParaBorrado->isEmpty()){
        colaDePrioridad->remove(priority);
        this->length--;
    }
    return datoEliminado;
}

template<class T, class Q>
void priorityQueue<T, Q>::printByPrio( T priority){ //imprime dada la prioridad y no elimina
    
    //accesa a la lista
    ListPQ<T, Q>* colaDePrioridad=this->getList();

    //halla la prioridad
    NodeL<T, Q>* actual= colaDePrioridad->findPrio(priority);

    //si esta es la prioridad imprime, si no no
    if(actual==nullptr){
        return;
    }
    //imprime
    actual->printNodeList();
    return;
}


template<class T, class Q>
void priorityQueue<T, Q>:: printAllQueue(){ //imprime toda la cola de prioridad sin eliminar
    //obtiene la gran cola de prioridad
    ListPQ<T, Q>* colaDePrioridad=this->getList();
    //e imprime 
    colaDePrioridad->printMine();
}

