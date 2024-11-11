#include "../node/node.cpp"
template<class T>
class Queue{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int length = 0;
    public:
        Queue(T,Node<T>*);  //constructor de la lista, para primer elemento. Toma args del constructor del nodo y lo pne de primero
        ~Queue();
        Queue();
        void push(T);   //agrega elemento desde la cola
        T pop();    //remueve elemento desde la cabeza
        bool isEmpty(); //dice si la cola esta vacia
        int getLength();    //longitud de la cola
        void print();   //imprime los datos en la cola y los elimina
        void printMine();   //imprima sin eliminar

        ///added in homework
        void printByPriority();
};