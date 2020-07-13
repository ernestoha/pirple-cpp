#include <iostream>
#include <iomanip>
#include <string>
#include "Dog.h"
#include "Akita.h"

using namespace std;

int main()
{
    int dogCount = 0;
    float totalPremium = 0;

    cout << setiosflags(ios::fixed);
    cout << setprecision(2);

    cout <<  "Please enter the number of dogs in your household: ";
    cin >> dogCount;
    // cin.ignore();
    float basePremium, actualPremium;
    int weight, age;
    bool subjectToDiscount;
    char breedCode;
    string dogName;
    string breed;
    int riskWeight;
    float bRW, hRW;
    //Dog dogs[dogCount];
    for(int n=0; n<dogCount; n++){
        cin.ignore(); //to clear the input buffer
        cout << "Enter the name of dog #" << n+1 << ": ";
        getline(cin, dogName);
        cout << "Enter the current age for " << dogName << ": ";
        cin >> age;
        cout << "Enter the current weight for " << dogName << ": ";
        cin >> weight;
        cout << "Enter the breed code for " << dogName << ": ";
        cin >> breedCode;
        switch(breedCode){
            case 'p' :
                breed = "Pitbull";
                riskWeight = 20;
                subjectToDiscount = false;
                bRW = 30.20;
                hRW = 35.15;
                break;
            case 'd' :
                breed = "Doberman";
                riskWeight = 35;
                subjectToDiscount = true;
                bRW = 28.16;
                hRW = 30.00;
                break;
            case 'r' :
                breed = "Rottweiler";
                riskWeight = 45;
                subjectToDiscount = false;
                bRW = 28.00;
                hRW = 29.75;
                break;
            case 'g' :
                breed = "German Shepperd";
                riskWeight = 30;
                subjectToDiscount = true;
                bRW = 27.50;
                hRW = 29.75;
                break;
            case 'c' :
                breed = "Chow Chow";
                riskWeight = 24;
                subjectToDiscount = true;
                bRW = 25.10;
                hRW = 27.50;
                break;
            case 't' :
                breed = "Great Dane";
                riskWeight = 55;
                subjectToDiscount = true;
                bRW = 25.10;
                hRW = 25.20;
                break;
            case 's' :
                breed = "Presa Canario";
                riskWeight = 45;
                subjectToDiscount = false;
                bRW = 20.01;
                hRW = 20.55;
                break;
            case 'k' :
                breed = "Akita";
                riskWeight = 0;
                subjectToDiscount = false;
                bRW = 0;
                hRW = 19.75;
                break;
            case 'm' :
                breed = "Alaskan Malamute";
                riskWeight = 38;
                subjectToDiscount = true;
                bRW = 15.50;
                hRW = 18.15;
                break;
            case 'h' :
                breed = "Husky";
                riskWeight = 20;
                subjectToDiscount = true;
                bRW = 9.95;
                hRW = 12.00;
                break;
            case 'b' :
                breed = "Other Breed";
                riskWeight = 35;
                subjectToDiscount = true;
                bRW = 4.95;
                hRW = 8.95;
                break;
            default:
                cout << "Sorry. That is not a valid breed code. Please re- enter this dog’s information." << endl;
                n--;
                basePremium = 0;
                continue;
        }

        if (breedCode=='k'){
            Akita ak(dogName, age, weight);
            ak.sethRW(hRW);
            ak.showInfo();
            cout << ak.gethRW() << endl << endl;
            //basePremium = hRW;
            //actualPremium = basePremium;
            actualPremium = ak.gethRW();
        } else {
            //dogs[n].setName ....
            Dog dog(dogName, breed, age, weight, subjectToDiscount);
            //dog.showInfo();
            if (weight<=riskWeight) {
                basePremium = bRW;
            } else {//if (weigth>riskWeight) {
                basePremium = hRW;
            }
            actualPremium = basePremium;
            if (subjectToDiscount==true && age>13)
                actualPremium -= actualPremium * 0.2; //actualPremium = basePremium - basePremium * 0.2;
            if (weight > 50)
                actualPremium *= 1.25;
        }
        totalPremium += actualPremium;
        //cout << dogName << " is a " << breed << endl;
        cout << "The monthly premium for "<< dogName <<  " (" << breed << ")" << " is " << actualPremium << endl;

        /* segment of code to ask only for breed and ask again (loop) if it is invalid
        bool ask4bread = false;
        do{
            cout << "Enter the breed code for " << dogName << ":";
            cin >> breedCode;
            switch(breedCode){
                case 'p' :
                    cout << "**Pitbull**" << endl;
                    break;
                default:
                    cout << "**Incorrect**" << endl;
                    ask4bread = true;
            }
        } while(ask4bread == true);
        */
    }
    cout << "The total monthly premium for " << ((dogCount>1) ? "all dogs" : "the dog") << " is " << totalPremium << ".";
    return 0;
}
