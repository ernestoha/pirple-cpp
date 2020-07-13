#include "Akita.h"

Akita::Akita()
{
    //ctor
}

Akita::Akita(string name, int age, int weigth) : Dog(name, "Akita", age, weigth, false) //super class initialization
{
    //ctor
}


Akita::~Akita()
{
    //dtor
}
