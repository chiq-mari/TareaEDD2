/*2. Realizar un programa que procese los datos (Hacer algo con ellos, imprimir, jugar, etc.) 
de una cola normal siguiendo un orden de prioridad (No utilizar colas de prioridad). Ejemplo:
COLA:
inicio-> (B, "Daniel"), (C, "Pablo"), (D, "Coraline"), (A, " Alfonzo" ), (C, "Lara"), (A, "Paula"), (A, "Chancho"), (A, "Luz")<- fin
Procesar primero las A, después B, entonces C y D*/

#include <iostream>
#include "queue/queue.cpp"
using namespace std;

int main(){
    Queue<Person> miCola;
    Person persona1('B', "Daniel", 24);
    Person persona2('C', "Pablo", 10);
    Person persona3('D', "Coraline", 16);
    Person persona4('A', "Alfonzo", 20);
    Person persona5('C', "Lara", 14);
    Person persona6('A', "Paula", 34);
    Person persona7('B', "Luis", 24);
    Person persona8('B', "Miguel", 28);

    
    miCola.push(persona1);
    miCola.push(persona2);
    miCola.push(persona3);
    miCola.push(persona4);
    miCola.push(persona5);
    miCola.push(persona6);
    miCola.push(persona7);
    miCola.push(persona8);

    cout<<"Cola original:"<<endl;
    miCola.printMine();

    cout<<"Cola procesada de acuerdo a prioridad: \n";
    miCola.processByPriority();
    
    
}