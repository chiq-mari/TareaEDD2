template<class T>
class Node{
    private:    //nodo de pila y cola
        T data; //solo requiere de dato y ref
        Node<T>* next = nullptr;    //al siguiente
    public:
        Node(T, Node<T>*);  //constructor de un nodo
        ~Node();    //destructor de un nodo
        T getData();    //devuelve el dato
        void setData(T);    //configura el dato
        Node<T>* getNext();     //devuelve ref al siguiente
        void setNext(Node<T>*); //configura ref al siguiente
        void print();   //imprime datos
};