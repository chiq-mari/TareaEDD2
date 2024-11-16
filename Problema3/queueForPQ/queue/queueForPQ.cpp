#include<iostream>
#include "./queueForPQ.h"

using namespace std;

//Comprobar si esta vacia
template<class T>
bool Queue<T>::isEmpty(){
    return this->head==NULL;
}
//constructor por defecto para dar valor por default
template<class T>
Queue<T>::Queue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}


//Crea cola con nodo inicial, si se la pasa null la cola se le pasa el primer elemento
template<class T>
Queue<T>::Queue(T data,NodeQ<T>* node){

        NodeQ <T> *newNode = new NodeQ<T>(data,node);
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
        NodeQ <T> *node = new NodeQ<T>(data,nullptr);
        if(isEmpty()){
                head = node;
                tail = node;
                length++;//BUGFIX
                return;
        }
        this->tail->setNext(node);
        this->tail=node;
        this->length++;
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
        if(isEmpty()){
            cout<<"No se pueden remover elementos de una cola vacia\n";
            return data;
        } 
        NodeQ <T> *node = head; //temp->head
        head=head->getNext();   
        data = node->getData();
       
        delete node;
        this->length--;
        return data;
}

//imprime los elementos de la cola y los elimina
template<class T>
void Queue<T>::print(){

      while(!isEmpty()) {
       std::cout<<pop()<<endl;
      }
}

//length
template<class T>
int Queue<T>::getLength(){
    return this->length;
}

//////////////////////////////////////in review

template<class T>       //imprime sin eliminar nada
void Queue<T>:: printMine(){
        if(isEmpty()){
            return;
        }
        NodeQ<T>* actual= head;
        cout<<"Queue:\n";
        //cout<<actual<<endl;
        while(actual!=nullptr){
            actual->print();
            actual=actual->getNext();
        }
}