#include "./Person.h"

Person:: Person(){
    this->lastNameInitial =' ';
    this->name="";
    this->age=0;
}

Person:: Person(char lastNameInitial, string name, int age){
    this->lastNameInitial =lastNameInitial;
    this->name=name;
    this->age=age;
}

char Person :: getLastNameInitial(){
    return this->lastNameInitial;
};

string Person:: getName(){
    return this->name;
}

int Person:: getAge(){
    return this->age;
}

void Person:: printPerson(){
    cout<<"Initial: "<<this->lastNameInitial<<endl;
    cout<<"Name: "<<this->name<<endl;
    cout<<"Age: "<<this->age<<endl;
}


