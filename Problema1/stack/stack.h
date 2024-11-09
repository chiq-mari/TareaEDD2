#include "../node/node.cpp"
template<class T>
class Stack{
    private:
        Node<T>* head = nullptr;
        int length = 0;
    public:
        Stack(T,Node<T>*); // constructor-->toma args como constructor de nodo, el cual sera el primero
        ~Stack();   //destructor de la pila
        void push(T);   //agrega un dato en la cabeza
        T pop();    //remueve un dato y lo retorna
        bool isEmpty(); //indica si la pila esta vacía
        int getLength();    //da la longitud
        void print();   //imprime  pilas  y las deja vacias
        ///added in review
        void printMine();   //print pila sin dejarla vacia
        void clearStack(); //empties the stack
        ///added in p1
        void reverseOrder();
        Stack();    //constructor de pila



};