#include <iostream>

using namespace std;

class complexNum
{
private:
    float real,imag;



  public:
      complexNum(float re=0,float im=0){real=re; imag=im;}
       friend complexNum operator +(complexNum const & c1, complexNum const & c2);
      friend complexNum operator -(complexNum const & c1, complexNum const & c2);
      friend complexNum  operator * (complexNum const & c1, complexNum const & c2);
       friend complexNum operator / (complexNum const & c1, complexNum const & c2);
       void print(){cout<<real<<"+"<<imag<<"i"<<endl;}


};

complexNum operator + (complexNum const & c1, complexNum const & c2)

{
    return complexNum(c1.real+c2.real,c1.imag+c2.imag);


}

complexNum operator - (complexNum const & c1, complexNum const & c2)

{
    return complexNum(c1.real-c2.real,c1.imag-c2.imag);


}

complexNum operator * (complexNum const & c1, complexNum const & c2)

{
    return complexNum(c1.real*c2.real,c1.imag*c2.imag);


}

complexNum operator / (complexNum const & c1, complexNum const & c2)

{
    return complexNum(c1.real/c2.real,c1.imag/c2.imag);


}











int main()
{ float a,b,c,d;
   cout<<"Enter first complex number"<<endl;
   cin>>a;
   cin>>b;
   complexNum c1(a,b);
   cout<<"Enter second complex number"<<endl;
   cin>>c;
   cin>>d;
   complexNum c2(c,d);

complexNum c3= c1/ c2;
     c3.print();

    return 0;
}
