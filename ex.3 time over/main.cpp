#include <iostream>
#include <cstdlib>

using namespace std;

bool validateTime(int, int);
class Time{

private:
    int hours;
    int minutes;



public:
    void sethours(int h){hours=h;}
    void setminutes(int m){minutes=m;}

  Time(int h=0, int m =0){hours=h; minutes=m;}

   void normalize();

 Time operator + ( Time &t2)
 {
     Time res;


     res.hours=(hours+t2.hours);
     res.minutes=(minutes+t2.minutes);
     res.normalize();
     return res;

 }


  Time operator - ( Time &t2)
 {
     Time res;


     res.hours=(hours-t2.hours);
     res.minutes=(minutes-t2.minutes);
     res.normalize();
     return res;
 }


friend  ostream& operator<<(ostream & cout ,Time arg);
friend  istream& operator>>(istream & cin ,Time & arg);

};

ostream& operator<<(ostream & cout, Time arg)
{
cout << arg.hours<< ":" << arg.minutes;
return cout;
}

istream& operator>>(istream & cin, Time&arg)  {
int h, m;
cin>>h;
cin>>m;
arg.sethours(h);
arg.setminutes(m);
return cin;
}





void Time::normalize()
{

    if(minutes<0)
    {

        minutes=60+minutes;

        hours=hours-1;


    }
    if(minutes>60)
    {
        minutes =minutes%60;

        hours=hours+1;
    }


}






int main()
{
    Time t1,t2;
int h, m, a,b;
    do{


    cout<<"Enter first time two times for correctness"<<endl;
    cin>>h;
    cin>>m;


    }while(!(validateTime(h,m)));
    cin>>t1;

     do{


    cout<<"Enter second time 2x for correctness"<<endl;
    cin>>a;
    cin>>b;


    }while(!(validateTime(a,b)));

    cin>> t2;

    cout<<t1<<endl;
    cout<<t2<<endl;
    cout<<"Addition: "<<endl;
    Time t3= t1+t2;


    cout<<t3<<endl;
    cout<<"Subtraction"<<endl;
    Time t4=t1-t2;
    cout<<t4<<endl;

    return 0;
}
bool validateTime(int h,int m)
{
 if(h<0 || h>24 || m<0 ||m>60)
 {
        return false;
 }
        else
            return true;

}
