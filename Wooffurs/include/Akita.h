#ifndef AKITA_H
#define AKITA_H

#include <Dog.h>

using namespace std;

class Akita : public Dog
{
    public:
        Akita();
        Akita(string name, int age, int weigth);
        virtual ~Akita();

    protected:

    private:
};

#endif // AKITA_H
