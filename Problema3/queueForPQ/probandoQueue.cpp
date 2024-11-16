#include"queue\queueForPQ.cpp"

int main(){
    Queue<int> colaDePrueba;

    colaDePrueba.push(5);
    colaDePrueba.push(8);
    colaDePrueba.push(4);
    colaDePrueba.push(-1);
    colaDePrueba.push(0);

    colaDePrueba.printMine();   
    
    cout<<colaDePrueba.pop();

    int k=colaDePrueba.pop();
    cout<<k;

    colaDePrueba.printMine();



}