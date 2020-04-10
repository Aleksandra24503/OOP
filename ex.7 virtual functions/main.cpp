#include <iostream>
#include <cmath>
#include<cstdlib>
#include<limits>

using namespace std;
bool isValid();
class Shape
{

protected:
    int x,y;
    double length;
public:


    virtual double area() const { return 0.0; }
    virtual double volume() const { return 0.0; }
    virtual void printShapeName() const = 0;
    virtual void print() const = 0;
    Shape(int x, int y, double length): x(x),y(y), length(length){}
};


class Twodimensional : public Shape
{
    protected:

    double width;
public:
    Twodimensional(int x, int y, double length, double width):Shape(x,y,length), width(width){}
};



class Circle :public Shape
{
public:
    Circle(int x, int y, int length): Shape(x,y,length) {};
     double area() const;
    void printShapeName() const;
    void print() const;
};
double Circle ::area() const
{
     return length*length*3.14;
}
void Circle ::printShapeName() const
{
    cout<<"Circle !"<<endl;
}
void Circle :: print() const
{
    cout<<"Circle centered at point ("<<x<<","<<y<<") with radius = "<<length<<endl;
}

class Triangle : public Twodimensional
{
protected:
    double side3;

public:
    Triangle(int x, int y, double length, double width, double side3):Twodimensional(x,y,length, width),side3(side3){;}
     double area() const;
     double halfperimeter() const;
     void printShapeName() const;
     void print() const;
};
double Triangle::halfperimeter() const
{
    return ((length+width+side3)/2);
}
double Triangle::area() const
{

    return sqrt(halfperimeter()*(halfperimeter()-length)*(halfperimeter()-width)*(halfperimeter()-side3));
}
void Triangle::printShapeName() const
{
    cout<<"Triangle"<<endl;

}
void Triangle::print() const
{
    cout<<"First coordinate"<<endl;
    cout<<"("<<x<<","<<y<<")"<<endl;

}


class Square :public Shape
{
public:
        Square(int x, int y, double length):Shape(x,y,length){}
        double area() const;
        void printShapeName() const;
        void print () const;
};
double Square::area() const
{
    return length*length;
}
void Square::printShapeName() const
{
    cout<<"A square"<<endl;
}
void Square:: print() const
{
     cout<<"The coordinates are : "<<endl;
     cout<<"("<<x<<","<<y<<")"<<endl;
     cout<<"("<<x+length<<","<<y<<")"<<endl;
     cout<<"("<<x+length<<","<<y-length<<")"<<endl;
     cout<<"("<<x<<","<<y-length<<")"<<endl;
}
class Rectangle :public Twodimensional
{
public:
    Rectangle(int x,int y, double length, double width):Twodimensional(x,y,length,width){}
    double area()const;
    void  printShapeName() const;
    void  print() const;
};
double Rectangle ::area() const
{
    return length*width;
}
void Rectangle::printShapeName() const
{
    cout<<"Rectangle"<<endl;

}
void Rectangle::print() const
{
    cout<<"The coordinates are : "<<endl;
     cout<<"("<<x<<","<<y<<")"<<endl;
     cout<<"("<<x+length<<","<<y<<")"<<endl;
     cout<<"("<<x+length<<","<<y-width<<")"<<endl;
     cout<<"("<<x<<","<<y-width<<")"<<endl;
}
class Threedimensional : public Twodimensional

{
protected:
    int z;
    double height;
    public:
    Threedimensional(int x, int y,int z , double length, double width, double height):Twodimensional(x,y,length,width),z(z),height(height){}
};



int main()
{


    while (true)
    {


int x;
   do{
       		cout<<"1.To create a circle and get information on it"<<endl;
            cout<<"2.To create a square and get information on it "<<endl;
          	cout<<"3.To create a rectangle and get information on it "<<endl;
          	cout<<"4.To create triangle and get information on it"<<endl;
			cout<<"5.to exit "<<endl;
            cin>>x;

 }while(!(isValid()) || x<1 ||x >5);

            if(x==1)


            {      system("cls");
                int a,b;
                double d;

               do{
                cout<<"Enter centre coordinate - x, y, and diameter "<<endl;
                cin>>a;
                cin>>b;
                cin>>d;
               }while(!(isValid()));
                Circle c (a,b,d);

                cout<<"Area = ";
                cout<<c.area()<<endl;
                c.printShapeName();
                cout<<endl;
                c.print();
                cout<<endl;

            }

           else if(x==2)
            {

                system("cls");
              int x, y;
              double a;
do{
              cout<<"Enter coordinates- x,y and length "<<endl;
              cin>>x;
              cin>>y;
              cin>>a;
             } while(!(isValid()));

               Square d (x,y,a);
              cout<<"Area = "<<d.area();
              cout<<endl;
              d.printShapeName();
              cout<<endl;
              d.print();
              cout<<endl;

            }

            else if(x==3)

            {        system("cls");
                    int x,y;
                    double length, width;


            do{
                cout<<"Enter coordinates -x,y and length and width"<<endl;
                cin>>x;
                cin>>y;
                cin>>length;
                cin>>width;
            }while(!(isValid()));
                 Rectangle c(x,y,length,width);
                cout<<"Area ="<<c.area();
                cout<<endl;
                c.printShapeName();
                cout<<endl;
                c.print();
                cout<<endl;



            }
            else if(x==4)
            { system("cls");
             int x;
            int y;
            double a,b,c;


                do{
                cout<<"Enter coordinate x, y"<<endl;
                cin>>x;
                cin>>y;

                cout<<"enter first, second and third side"<<endl;
                cin>>a;
                cin>>b;
                cin>>c;
                }while(!(a+b>c && a+c>b && b+c>a) || !(isValid()) );
                 Triangle t (x,y,a,b,c);
                cout<<"Area = "<<t.area();
                cout<<endl;
                t.printShapeName();
                cout<<endl;
                t.print();
                cout<<endl;






            }

     else if(x==5)
     break;
    }


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
