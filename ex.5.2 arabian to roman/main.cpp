#include <iostream>

using namespace std;

class Arabian
{
protected:
    unsigned int value;
public:
    Arabian(unsigned int v):value(v){}
    void printArab();

};
void Arabian::printArab()
{
    cout<<"In arabian-  "<<value<<endl;
}


class Roman:public Arabian
{

public:
    void printRom();
    Roman(unsigned int v):Arabian(v){}


};

void Roman::printRom()
{
    int decval[13] = {1000,  900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
        string romval[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for(int i=0;i<13;i++)
        {
            while(value>=decval[i])
            {
                cout<<romval[i];
                value=value-decval[i];

            }

        }
        cout<<endl;

}


int main()
{
while(true)
{
    cout<<"enter number"<<endl;
    int a;
    cin>>a;
    Arabian ar(a);
    ar.printArab();
    cout<<endl;
    cout<<"In roman -  ";
    Roman Ro(a);
   Ro.printRom();

}


    return 0;
}
