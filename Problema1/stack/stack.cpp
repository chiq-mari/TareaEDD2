#include<iostream>
#include "./stack.h"

using namespace std;

//Comprobar si esta vacia

template<class T> 
bool Stack<T>::isEmpty(){       //si la cabeza esta apuntando a null
    return this->head==NULL;
}

//Crea pila con nodo inicial, si se la pasa null la pila se crea inicializa vacia
template<class T>
Stack<T>::Stack(T data,Node<T>* node){ //args como en constructor de nodo
                                        // crea nodo con dato y ref indicada y lo pone como head
        Node <T> *newNode = new Node<T>(data,node);
        head=newNode;
        this->length++;   
}

//Destructor, asegura que head quede sin apuntar a nada
template<class T>
Stack<T>::~Stack(){
        this->head = nullptr;   //hace que head no apunte a nada
}

//Insertar nodo en tope
// 1. Crear nuevo nodo
// 2. Hacer Apuntar el nuevo nodo a head.
// 3. Hacer que head sea el nuevo nodo.
// 4. Aumentar el contador de la pila
template<class T>
void Stack<T>::push(T data){
        Node <T> *node = new Node<T>(data,head);
        head=node;
        this->length++;   
}

//sacar nodo del tope de la pila (la acción elimina el nodo y recupera el dato)
// 1. Si la pila esta vacia se devuelve el valor por defecto del tipo de dato.
// 2. Creamos un nodo temporal a head.
// 3. Apuntamos head a su nodo siguiente.
// 4. Recuperamos el dato del nodo temporal (El que se va a sacar de la cola).
// 5. Liberamos memoria (delete node)
// 6. Reducimos tamaño de la cola
// 7. retornamos dato del nodo.
template<class T>
T Stack<T>::pop(){
        T data;
        if(isEmpty()){
            cout<<"Cannot remove from an empty list\n";
        return data;     //si la pila esta vacia, se devuelve el valor por defecto del tipo T
        }
        Node <T> *node = head;          //crea temporal 
        head=head->getNext();           //lo asigna al siguiente
        data = node->getData();         //obtiene el dato del nodo a eliminar
        delete node;                    //Lo elimina
        this->length--;                 //decrece el tamaño
        return data;                    //retorna el dato
}
template<class T>
void Stack<T>::print(){ //mientras este vacia saca cada elemento e imprimelo// no importan las direccioes de memoria

      while(!isEmpty()) {
       std::cout<<pop()<<endl;
      }
}
template<class T>
int Stack<T>::getLength(){
    return this->length;
}
//////////////////////////////////////////

template<class T>
void Stack<T>:: printMine(){
        if(isEmpty()){  
            return;
        }
        Node<T>* actual=head;   //crea actual
        cout<<actual<<endl;     //imprime cabecera
        while(actual!=nullptr){ //mientras no se haya llegado al fin de la pila 
                cout<<"Data: "<<actual->getData()<<endl;        //imprime 
                actual=actual->getNext();       // y mueve a next
        }
}

template<class T>
void Stack<T>:: clearStack(){
        if(isEmpty()){  //si esta vacia no hacer nada
                return;
        }
        while(!isEmpty()){      //si no esta vacia hacer pop() hasta que lo este
                pop();
        }
}

////////////////////////////////////////////////////////////////////////////////// added in p1
template<class T>
Stack<T>::Stack(){
        this->head = nullptr;
        this->length=0;
}

template<class T>
void Stack<T>:: reverseOrder(){
        if(isEmpty()){
            return;
        }
        Stack<T> alternative1;
        Stack<T> alternative2;
        T dataAlt;

        //saca a pila alternativa 1 y cambia su orden(orden inverso)   
        while(this->head!=nullptr){     //mientras el head de la pila no este vacia
                dataAlt=pop();
            alternative1.push(dataAlt); //saca su head y eliminalo/ Anadelo a la pila alternativa1  
        }
        // de 1 pasa a pila alternativa2 y cambia su orden (orden original)
        while(alternative1.isEmpty()==0){     //mientras no este vacia
            dataAlt=alternative1.pop();
            alternative2.push(dataAlt); //saca head y eliminalo/ Anadelo a la pila  
        }
        //devuelve a orden inverso pero en pila original
        while(alternative2.isEmpty()==0){     //mientras no este vacia
            dataAlt=alternative2.pop();
            this->push(dataAlt); //saca head y eliminalo/ Anadelo a la pila original(orden inverso)  
        }
}