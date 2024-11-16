#include "..\..\queueForPQ\queue\queueForPQ.cpp"

template<class T, class Q>
class NodeL{
    private:
        T priority; //etiqueta de prioridad
        NodeL<T, Q>* next = nullptr;    //ptr al next o a siguiente prioridad
        Queue<Q> cola;  // se inicializa con head, tail -> null y length=0
    public:
        NodeL(T, NodeL<T, Q>*);  //NOTNEEDED//constructor |
        ~NodeL();    //NOT NEEDED//destrcutor   |
        T getPriority();    //retorna dato tipo T|
        void setPriority(T);    //lo configura |
        NodeL<T, Q>* getNext(); //retorna direcc al siguiente
        void setNext(NodeL<T, Q>*); //lo configura
        //void print();   //print| No longer useful
        
        //added in p3 hwk
        NodeL();    // constructor por defecto  |
        void printNodeList();   // imprime prio y su cola respectiva 
        Queue<Q>* getCola(); //retorna la cola en un nodo de la lista

};