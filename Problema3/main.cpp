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

    cout<<"Prueba push: \n";
    miColaDePrioridad.printAllQueue();

    miColaDePrioridad.pop('a');
    miColaDePrioridad.pop('c');
    miColaDePrioridad.pop('b');
    miColaDePrioridad.pop('a');

    cout<<"Prueba pop: \n";
    miColaDePrioridad.printAllQueue();

}