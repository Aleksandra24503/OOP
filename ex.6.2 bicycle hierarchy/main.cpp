#include <iostream>
#include <ctime>
#include <string>
#include<cstdlib>
#include <limits>

using namespace std;
bool isValid();

class object
{
protected:
    string material;
    float weight;
public:
    object(string m, float w):material(m),weight(w){}
    void objinfo()
    {
        cout<<material<<endl;
        cout<<"Its weight = "<<weight<<endl;
    }

};

class tyre
{   protected:
    string category;
    public:
    tyre(string c ):category(c){}

};
class wheel :public tyre
{
protected:
 float diameter;
 public:
     wheel(float d, string e): tyre(e){diameter=d;}
     void wheelinfo()
     {

         cout<<"Category of tyre is "<<category<<endl;
         cout<<"Diameter of wheel is = "<<diameter<<endl;
     }
};



class bicycle :public wheel, public object
{
public:
    bicycle(string m,float w ,float d, string e) : object(m,w), wheel(d,e) {}
     void bicycleinfo()
     {
        cout<<"This bicycle is made out of ";
        objinfo();
        wheelinfo();
     }


};


int main()
{
    string mat;
    float w;
    string cat;
    float diam;
do
{


cout<<"Type information about bicycle in following order- material, weight.Then information about tyres-diameter, category"<<endl;

cin>>mat;
cin>>w;
cin>>diam;
cin>>cat;
}while(!(isValid()));
       bicycle b (mat,w,diam,cat);
       b.bicycleinfo();


    return 0;
}



bool isValid()
{
    if (cin.rdstate())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system ("cls");
        return false;
    }

    return true;
}
