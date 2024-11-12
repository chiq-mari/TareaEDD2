#include<iostream>
using namespace std;

class Person{
    private:
        char lastNameInitial;
        string name;
        int age;
    public:
        Person(); //constructor por defecto
        Person(char, string, int);
        char getLastNameInitial();
        string getName();
        int getAge();
        void printPerson();
};