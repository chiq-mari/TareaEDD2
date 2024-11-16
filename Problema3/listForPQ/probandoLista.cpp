/*      //NODO FUNCIONAL
#include ".\node\nodeForList.cpp"
int main(){
    NodeL<char, int> nodeLPrueba('a', nullptr);

    Queue<int>* colaDePrueba=nodeLPrueba.getCola();
    
    colaDePrueba->push(5);
    colaDePrueba->push(8);
    colaDePrueba->push(4);
    colaDePrueba->push(-1);
    colaDePrueba->push(0);

    colaDePrueba->printMine();   
    
    cout<<colaDePrueba->pop();

    int k=colaDePrueba->pop();
    cout<<k;

    colaDePrueba->printMine();

    nodeLPrueba.printNodeList();
}
*/

#include ".\list\listForPQ.cpp"

int main(){

    ListPQ<char, int> listaPQPrueba;
    listaPQPrueba.insert('f');
    listaPQPrueba.insert('w');
    listaPQPrueba.insert('d');
    listaPQPrueba.insert('a');

    listaPQPrueba.printMine();

    NodeL<char, int>* nodeLPrueba=listaPQPrueba.findPrio('d');

    Queue<int>* colaDePrueba=nodeLPrueba->getCola();
    
    colaDePrueba->push(5);
    colaDePrueba->push(8);
    colaDePrueba->push(4);
    colaDePrueba->pop();

    nodeLPrueba=listaPQPrueba.findPrio('a');
    colaDePrueba=nodeLPrueba->getCola();

    colaDePrueba->push(-1);
    colaDePrueba->push(0);

    listaPQPrueba.printMine();   
    
}