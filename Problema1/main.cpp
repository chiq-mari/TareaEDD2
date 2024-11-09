#include "./stack/stack.cpp"
/*Crear un programa que invierta el orden de
una pila guardando los datos con el orden invertido
dentro de la misma pila*/

int main(){
    Stack<int> myStack(2, nullptr);
    myStack.push(4);
    myStack.push(3);
    myStack.push(9);
    myStack.push(0);
    myStack.push(23);
    myStack.push(12);
    myStack.push(1);

    cout<<"Original Stack: \n";
    myStack.printMine();
    myStack.reverseOrder();
    myStack.printMine();
}

