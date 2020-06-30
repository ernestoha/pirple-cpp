#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int rotateLeft (int value, int amount)
{
    //four bit rotate left

    const int OVERFLOW = 0b10000;
        while (amount > 0)
        {
            value = value << 1;
            if (((value & OVERFLOW) == OVERFLOW))
            {
           value = value & 0b1111;  //remove overflow bit
                value = value | 0b0001;  //set the rightmost bit
    }
    amount--;
    }
    return value;
}

void display(string message, int value)
{
    bitset<4> myBitset(value);
    cout << message;
    cout << myBitset.to_string() << " (" << myBitset.to_ulong() << ")" << endl;
}

void testRotate(int inValvesOpen, int outValvesOpen, int pistonUp, int cylinderFire)
{
    // inValvesOpen <<= 5;
    display("test1.1: ", inValvesOpen);
    // inValvesOpen = 1;
    inValvesOpen = rotateLeft(inValvesOpen, 5);
    display("test1.2: ", inValvesOpen);
    inValvesOpen = rotateLeft(inValvesOpen, 1);
    display("test1.3: ", inValvesOpen);
    display("test2: ", outValvesOpen+3);
}

int getPosition(int c){
    switch(c){
        case 1: 
            return 9;
        case 2: 
            return 18;
        case 3: 
            return 27;
        default:
            return 0;
    }
}

int getSecuence(int f){ //1,3,2,4
    /*
    8=1pos
    4=2pos
    2=3pos
    1=4pos
    */
    if (f==1)
        return rotateLeft(f, 7);
    else
        if (f==2)
            return f<<=1;
        else
            return f>>=2;
}

int main()
{
    int inValvesOpen=0, outValvesOpen=0, pistonUp=0, cylinderFire=0;
    string d1 = "     1        2        3        4     ";
    string d2 = "    ___      ___      ___      ___    ";
    string d3 = "  x|   |x  x|   |x  x|   |x  x|   |x  ";
    string d4 = "   |   |    |   |    |   |    |   |   ";
    string d5 = "    ---      ---      ---      ---    ";
    string d6 = "     ?        ?        ?        ?     ";
    // testRotate(inValvesOpen, outValvesOpen, pistonUp, cylinderFire);
    int positionMask = 1;
    int secEHA = 8;//8,4,2,1
    int posEHA = 1;//1,9,18, 27
    for (int f=0; f<5; f++)
    {
        // cylinderFire = secEHA;
        switch(f){
            case 0: //fireon1
                cylinderFire = 1;
                break;
            case 1: //fireon3
                inValvesOpen = 1;
                cylinderFire = 0;
                break;
            case 2: //fireon2
                outValvesOpen = 0;
                inValvesOpen = 0;
                cylinderFire = 0;
                break;
            case 3:
                outValvesOpen = 1;
                cylinderFire = 0;
                break;
            case 4://fireon1
                cylinderFire = 1;
                break;
        }
        for (int c=0; c<4; c++)
        {
            posEHA = getPosition(c);
            int offset = c;
            char stateLabel = 'C';// (Compression)
            char inValve = 'x';
            char outValve = 'x';
            char upPiston = ' ';
            char downPiston = 'T';
            char chamber = ' ';

            // positionMask >>=c;
            
            // display("test1.2: ", positionMask);        
            
            // cout << "positionMask:" << positionMask << endl;

            if (cylinderFire == 1){//Is it Firing
                stateLabel = 'P';
                upPiston = 'T';
                downPiston = ' ';
                chamber = '*';
                cylinderFire = 0;
                outValvesOpen = 1;
            } else {
                if (outValvesOpen == 1){//E open
                    stateLabel = 'E';
                    outValve = 'o';
                    outValvesOpen = 0;
                    inValvesOpen = 1;
                } else {
                    if (inValvesOpen == 1){//Checking state of the current cylinder and position of the piston
                        stateLabel = 'I';
                        inValve = 'o';
                        upPiston = 'T';
                        downPiston = ' ';
                        inValvesOpen = 0;
                    } else {
                        cylinderFire = 1;
                    }
                }
            }

            d3[2+posEHA] = inValve;
            d3[4+posEHA] = chamber;
            d3[5+posEHA] = upPiston;
            d3[6+posEHA] = chamber;
            d3[8+posEHA] = outValve;
            d4[5+posEHA] = downPiston;
            d6[5+posEHA] = stateLabel;
            
            // cout << endl << endl;

            //if (positionMask==1)
            //    positionMask = 8;
            //else
            //    positionMask >>=c; //>>c
        }
        cout << d1 << endl << d2 << endl << d3 << endl;
        cout << d4 << endl << d5 << endl << d6 << endl;
        cout << endl;
        secEHA = getSecuence(secEHA); //1,3,2,4
    }
    // cout << getSecuence(8);
    // display("test: ", getSecuence(4));
    // 8 4 2 1
    // 1 2 3 4
    return 0;
}
