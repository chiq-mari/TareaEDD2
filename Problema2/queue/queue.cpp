#include<iostream>
#include "./queue.h"
#include "../Person/Person.cpp"

using namespace std;

//Comprobar si esta vacia
template<class T>
bool Queue<T>::isEmpty(){
    return this->head==NULL;
}

//Crea cola con nodo inicial, si se la pasa null la cola se crea inicializa vacia
template<class T>       //pasa args los args del constructor de un nodo, para crear el nodo 1
Queue<T>::Queue(T data,Node<T>* node){
        Node <T> *newNode = new Node<T>(data,node);
        head=newNode;
        tail=head;
        this->length++;
}

//Destructor, asegura que head y tail queden sin apuntar a nada
template<class T>
Queue<T>::~Queue(){
        this->head = nullptr;
        this->tail = nullptr;
}

//Insertar nodo en tope
// 1. Crear nodo
//      1.1. Si la cola esta vacia, head y tail apuntan al mismo nodo
//        (el error de la clase estaba que se me olvido colocar el
//          return para que no siguiera con el resto del codigo)
// 2. Apuntar el siguiente de tail al nuevo nodo
// 3. Apuntar tail al nuevo nodo.
// 4. Aumentar el contador de la cola
template<class T>
void Queue<T>::push(T data){
        Node <T> *node = new Node<T>(data,nullptr);     //creacion del nodo nuevo
        if(isEmpty()){  // si estaba vacio, head y tail van a apuntar al nuevo
                head = node;
                tail = node;
                this->length++; //BUGFIX
                return;
        }
        this->tail->setNext(node);      //hace que ultimo apunte al nodo nuevo
        this->tail=node;        //rueda tail
        this->length++;         //aumenta la cola
}

//sacar nodo del inicio de la cola (la acción elimina el nodo y recupera el dato)
// 1. Si la cola esta vacia se devuelve el valor por defecto del tipo de dato.
// 2. Creamos un nodo temporal a head.
// 3. Apuntamos head a su nodo siguiente.
// 4. Recuperamos el dato del nodo temporal (El que se va a sacar de la cola).
// 5. Liberamos memoria (delete node)
// 6. Reducimos tamaño de la cola
// 7. retornamos dato del nodo.
template<class T>
T Queue<T>::pop(){
        T data;
        if(isEmpty())   //caso vacia
        {   cout<<"No se pueden remover elementos de una cola vacia\n";
            return data;
        }
        Node <T> *node = head;  //temp a head
        head=head->getNext();   //rueda head
        data = node->getData(); //recupera el dato
       
        delete node;    //elimina el nodo
        this->length--; //disminuye la longitud
        return data;    //retorna el dato
}

/// no se usa en main con T=person
template<class T>       //imprime elementos y los elimina
void Queue<T>::print(){
      while(!isEmpty()) {
       std::cout<<pop()<<endl;
      }
}

template<class T>
int Queue<T>::getLength(){
    return this->length;
}
///////////////////

template<class T>       //imprime sin eliminar nada
void Queue<T>:: printMine(){
        if(isEmpty()){
            return;
        }
        Node<T>* actual= head;
        int j=1;
        while(actual!=nullptr){
            cout<<"Dato "<<j<<endl;
            actual->getData().printPerson();
            cout<<endl;
            actual=actual->getNext();
            j++;
        }
}

//////////////////////added in p2/hwk

template<class T>
Queue<T>::Queue(){
        this->head = nullptr;
        this-> tail = nullptr;
        this-> length = 0;
}

template<class T>
char Queue<T>:: getHighestPrio(){    //obtiene el dato de tipo T1 (la primera prioridad a procesar)
        char priority;
        Node<T>* actual=head;
        if(isEmpty()){  // si esta vacia, no hay nada que priorizar
            cout<<"Queue is empty\n";
            return priority;
        }
        //si no esta vacia recorrer empezando desde head
        priority=this->head->getData().getLastNameInitial();    //toma la prioridad de head
        while(actual!= nullptr){
                if(priority>actual->getData().getLastNameInitial()){    //si encuentra una prioridad menor la sutituye
                    priority= actual->getData().getLastNameInitial();  
                }
                actual=actual->getNext();       //rueda actual
        }
        return priority;
}

/* pushea en queueForPrio data con la prioridad dada y deja el resto en la cola actual
*/
template<class T>
void Queue<T>::queueWithPrio(char prioTested, Queue<T>& queueForPrio){
        Node<T>* actual= this->head;    
        int lengthNow= this->getLength();       //obtiene longitud de cola actual

        for(int i=0; i<lengthNow; i++){         
                actual=this->head;      //se ubica en la cabeza
                if(actual->getData().getLastNameInitial()==prioTested){ //si esta en la prioridad dada pushear a queueForPrio
                        queueForPrio.push(actual->getData());
                }else{
                        this->push(actual->getData());  //sino a mi mismo
                }
                this->pop();    //elimina la cabeza y va con el siguiente
        }
}


template<class T>
void Queue<T>:: processByPriority(){   //imprime de acuerdo a prioridad
        if(isEmpty()){  //si se esta vacio no hay nada que procesar
            return;
        }
        char priority;
        Queue<T> queueForPrio;
        while(isEmpty()==0){ //hasta que la lista este vacia
                priority=this->getHighestPrio();        //obtener prioridad
                queueWithPrio(priority, queueForPrio);  //insertar elementos de tal prioridad en la cola nueva y dejar el resto en mi
        }
        queueForPrio.printMine();
}
