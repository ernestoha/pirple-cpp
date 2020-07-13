#include "Dog.h"

Dog::Dog()
{
}

Dog::Dog(string name,
         string breed,
         int age,
         int weigth,
         bool subjectToDiscount)
{
    //ctor
    this->name = name;
    this->breed = breed;
    this->age = age;
    this->weigth = weigth;
    this->subjectToDiscount = subjectToDiscount;
}

void Dog::showInfo()
{
    cout << "The Dog: " << this->name << " is " << this->age << " years old, breed " << this->breed << " and weigth " << this->weigth << " pounds. Discount is " << (this->subjectToDiscount==true ? "True" : "False") << "." << endl;
}

float Dog::getbRW()
{
    return this->bRW;
}

float Dog::gethRW()
{
    return this->hRW;
}

void Dog::setbRW(float bRW)
{
    this->bRW = bRW;
}

void Dog::sethRW(float hRW)
{
    this->hRW = hRW;
}

int Dog::getBasePremium()
{
    return 1;
}

int Dog::getPremium()
{
    return 11;
}

Dog::~Dog()
{
    //dtor
}
