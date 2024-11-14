#include "../node/nodeForQueue.cpp"
template<class T>
class Queue{
    private:
        NodeQ<T>* head = nullptr;
        NodeQ<T>* tail = nullptr;
        int length = 0;
    public:
        ~Queue();           //destructor
        Queue(T,NodeQ<T>*);  //constructor no por defecto
        Queue();            //Necesario para la declaracion de arreglos de colas
        T pop();            //elimina dato en head
        void push(T);       //añade dato en tail
        bool isEmpty();     //empty?
        int getLength();    //lenght
        void print();       // imprime los datos de la cola y los procesa

        //added in review
        void printMine();   //imprima sin eliminar
};