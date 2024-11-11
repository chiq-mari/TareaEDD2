#include<iostream>
#include "./queue.h"

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
                length++; //BUGFIX
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
        cout<<actual<<endl;
        while(actual!=nullptr){
            cout<<actual->getData()<<endl;
            actual=actual->getNext();
        }
}

//constructor por defecto para dar valor por default a los elementos del array inicializada
template<class T>
Queue<T>::Queue(){
        //nada
}