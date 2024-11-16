#include "../node/nodeForList.cpp"

template<class T, class Q>
class ListPQ{
    private:
        NodeL<T, Q>* head = nullptr; // se compone de tanto el ptr a head
        int length = 0;         //tambien de la longitud para agg la funcion miembro update
    public:
        ListPQ(T, NodeL<T, Q>*);    //|1  constructor por args    
        void insert(T);     //4|  insertar una prioridad/deja queue vacio
        void insertFirst(T);    //3 |same
        bool remove(T);         //|remover prioridad /y vaciar su cola
        bool isEmpty(); //|2     
        void printMine();           //imprimir la lista/ de una es la cola de prioridades
        //bool update(int, T);    //cambiar cierta posicion int por T; //No Update

        //added in p3 hwk
        ListPQ(); //constructor por defecto
        NodeL<T, Q>* findPrio(T);   //delvuelve la direccion de memoria dada una prioridad

};