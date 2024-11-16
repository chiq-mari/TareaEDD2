template<class T>
class NodeQ{
    private:
        T data; //etiqueta
        NodeQ<T>* next = nullptr; //ref al siguiente
    public:
        NodeQ(T, NodeQ<T>*);  //constructor no por defecto
        ~NodeQ();    //destructor
        T getData();    //obtiene dato
        void setData(T);    //configurarlo
        NodeQ<T>* getNext(); // obtiene ref al siguiente
        void setNext(NodeQ<T>*); //configura ref
        void print();
        //added
        NodeQ(); //constructor por defecto |
};