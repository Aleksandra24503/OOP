#include <iostream>
#include <cmath>
#include<cstdlib>


using namespace std;

class Rectangle
{
protected:
    float length;
    float width;
public:

    Rectangle(float , float);
    Rectangle(float);
    float recArea();
    float recDiag();

};
float Rectangle::recDiag()
{
    return sqrt(length*length + width*width);
}

float Rectangle::recArea()
{
    return length*width;
}

Rectangle::Rectangle(float l)
{
        length=l;
        width=l;
}

Rectangle::Rectangle(float l, float w)
{
        length=l;
        width=w;
}


class Cuboid:public Rectangle
{
protected:
float height;

public :
Cuboid (float,float,float);
Cuboid(float);
float cublateral();
float cubarea();
float cubdiag();


};
float Cuboid::cubdiag()
{

    return (sqrt(recDiag()*recDiag()+height*height));
}
float Cuboid::cubarea()
{
    return (2*recArea()+cublateral());
}
float Cuboid::cublateral()
{
    return (2*length*height +2*width*height);

}
Cuboid::Cuboid(float l,float w,float  h): Rectangle(l, w)
{
    height=h;
}

Cuboid::Cuboid (float l):Rectangle(l)
{
    height=length;

}




int main()

{







int x;
int a,b,c;

Cuboid *cub=NULL;

Rectangle*rec=NULL;

    while(true)
    {   cout<<endl;
        cout<<"Press:"<<endl;
        cout<<"1.Create a rectangle "<<endl;
        cout<<"2.Create a square"<<endl;
        cout<<"3.Calculate diagonal of rectangle"<<endl;
        cout<<"4.Calculate area of rectangle"<<endl;
        cout<<"5.Create a cuboid"<<endl;
        cout<<"6.Calculate area of cuboid"<<endl;
        cout<<"7.Calculate diagonal of cuboid"<<endl;
        cout<<"8.Create a cube"<<endl;
        cout<<"9.exit"<<endl;
        cin>>x;

        if(x==1)
        {

            delete rec;
           cout<<"Type length and width of rectangle"<<endl;
           cin>>a;
           cin>>b;
            rec=new Rectangle(a,b);


        }

        if(x==2)
        {

            delete rec;
            cout<<"Type length of square"<<endl;
            cin>>a;
            rec= new Rectangle(a);

        }
        if(x==3)
        {
            if(rec==NULL)
               {
                   cout<<"You haven't created a rectangle yet"<<endl;
               }
               else
                cout<<"Rectangle diagonal = "<<rec->recDiag()<<endl;

        }
        if(x==4)
        {
            if (rec==NULL)
            {
            cout<<"You havent created a rectangle yet";
            }
            else

            cout<<"Area = "<<rec->recArea()<<endl;
        }
        if(x==5)
        {
            delete cub;
            cout<<"Enter length, width, height"<<endl;
            cin>>a;
            cin>>b;
            cin>>c;
            cub=new Cuboid(a,b,c);

        }
        if(x==6)
        {


            if(cub==NULL)
                cout<<"You haven't created a cuboid yet"<<endl;
            else
                cout<<"Cuboid area = "<<cub->cubarea();
        }
        if(x==7)
        {
            if(cub==NULL)
                cout<<"You haven't created a cuboid yet"<<endl;
            else
                cout<<"Cuboid diagonal = "<<cub->cubdiag();

        }
        if(x==8)
        {
            delete cub;
            cout<<"Enter length of cuboid"<<endl;

            cub=new Cuboid(a);

        }
        if(x==9)
        {
            return 0;
        }





    }

    return 0;
}
