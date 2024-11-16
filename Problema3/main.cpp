/*Crear un template para una cola de prioridad utilizando 
listas enlazadas simples, en vez de arreglos como en la practica*/

#include ".\priorityQueue\priorityQueue.cpp"

int main(){
    priorityQueue<char, int> miColaDePrioridad;

    miColaDePrioridad.push(4, 'b');
    miColaDePrioridad.push(5, 'c');
    miColaDePrioridad.push(3, 'd');
    miColaDePrioridad.push(1, 'a');
    miColaDePrioridad.push(9, 'c');
    miColaDePrioridad.push(4, 'a');
    miColaDePrioridad.push(-1, 'a');

    miColaDePrioridad.printByPrio('d');

    miColaDePrioridad.printAllQueue();

    miColaDePrioridad.pop('a');
    miColaDePrioridad.pop('c');

    cout<<"cola de prioridad:\n";

    miColaDePrioridad.printAllQueue();

    miColaDePrioridad.pop('b');
    miColaDePrioridad.pop('a');
    miColaDePrioridad.pop('a');

    cout<<"cola de prioridad:\n";
    miColaDePrioridad.printAllQueue();

}