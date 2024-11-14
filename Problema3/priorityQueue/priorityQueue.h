#include "..\listForPQ\list\listForPQ.cpp"
using namespace std;

template<class T, class Q>
class priorityQueue{
    private:
        List<T, Q> prioQueu;
        int length=0;
    public:
        void push(Q, T); //pushea dato de tipo Q en prioridad T
        Q pop(T); //pops dato de tipo Q en prioridad T
        priorityQueue();    //constructor por defecto
        void printByPrio( T ); //imprime dada la prioridad
        void printAllQueue(); //imprime toda la cola de prioridad

        //para accesar a los atributos
        List<T, Q> getList();
        int getLength();
};
