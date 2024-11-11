/*2. Realizar un programa que procese los datos (Hacer algo con ellos, imprimir, jugar, etc.) 
de una cola normal siguiendo un orden de prioridad (No utilizar colas de prioridad). Ejemplo:
COLA:
inicio-> (B, "Daniel"), (C, "Pablo"), (D, "Coraline"), (A, " Alfonzo" ), (C, "Lara"), (A, "Paula"), (A, "Chancho"), (A, "Luz")<- fin
Procesar primero las A, después B, entonces C y D*/

#include <iostream>
#include "queue.cpp"
using namespace std;

int main(){
    Queue<char> miCola;

    
    miCola.push('D');
    miCola.push('B');
    miCola.push('A');

    cout<<"Cola original"<<miCola.getLength()<<endl;

    
   miCola.print();

    cout<<endl<<endl;
    miCola.push('X');
    cout<<"Valor sacado: "<<miCola.pop()<<endl;
    miCola.push('Y');
    miCola.push('Z');

    miCola.printMine();
    miCola.print();

    
}