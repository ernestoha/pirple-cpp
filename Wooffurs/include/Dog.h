#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

using namespace std;

class Dog
{
    public:
        Dog();
        Dog(string name,
            string breed,
            int age,
            int weigth,
            bool subjectToDiscount);

        void showInfo();
        int getPremium();
        float getbRW();
        float gethRW();
        void setbRW(float bRW);
        void sethRW(float hRW);

        virtual ~Dog();

    protected:
        int getBasePremium();
        float bRW; //Below RW
        float hRW; //RW or Higher

    private:
        string name;
        string breed;
        int age;
        int weigth;
        bool subjectToDiscount;
};

#endif // DOG_H
