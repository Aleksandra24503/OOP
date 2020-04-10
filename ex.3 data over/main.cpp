#include <iostream>
#include <ctime>

#include <cstdlib>
#include <limits>
using namespace std;
bool isValid();
bool isdayValid(int, int, int);
class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int , int , int);
    bool isleap();
    void printmonth();
    void printday();
    void diffBetNow();
    void info();
};

void Date::info()
{   cout<<"Information on date: "<<endl;

    cout<<day<<"/"<<month<<"/"<<year<<endl;
    printday();
    cout<<" "<<day<<" ";
    printmonth();
    cout<<" "<<year;

}
Date::Date(int day, int month, int year)
{

    this->year=year;

    this->month=month;
    this->day=day;


}

void Date::diffBetNow()
{


 time_t now = time(NULL);

   tm *ltm = localtime(&now);


int YY1 = (ltm->tm_year+1900-1) % 100;
int C1 = (ltm->tm_year+1900-1) - YY1;
int G1 = YY1 + YY1/4;
int dayofWeekJanuary1=(((((C1 / 100) % 4) * 5) + G1) % 7);
int gendaysofyear1[12]={0,31,59,90,120,151,181,212,243,273,304,334};
int realdayofyear1;
int diff;



if(ltm->tm_mon>2 && isleap())
{
    realdayofyear1=ltm->tm_mday+gendaysofyear1[1 + ltm->tm_mon-1] + 1;
}
else
    {
        realdayofyear1=ltm->tm_mday+gendaysofyear1[1 + ltm->tm_mon-1];
    }


int YY = (year-1) % 100;
int C = (year-1) - YY;
int G = YY + YY/4;
int dayofWeekJanuary=(((((C / 100) % 4) * 5) + G) % 7);
int gendaysofyear[12]={0,31,59,90,120,151,181,212,243,273,304,334};
int realdayofyear;
int D = (ltm->tm_year+1900)- year;


if(month>2 && isleap())
{
    realdayofyear=day+gendaysofyear[month-1] + 1;
}
else
    {
        realdayofyear=day+gendaysofyear[month-1];
    }



    if(year==ltm->tm_year+1900&&month==1 + ltm->tm_mon)
    {
            if(day==ltm->tm_mday)
                cout<<"No difference between give date and todays date";
            else
                cout<<"Difference  between given date and todays date is = "<<((ltm->tm_mday)-day)<<"days"<<endl;
    }
    else

    {
        if(month<=(1 + ltm->tm_mon))
        {
            cout<< "Given date is  = "<<realdayofyear1-realdayofyear<<"days and "<< D <<"year before todays date"<<endl;

        }
        else if(month>(1 + ltm->tm_mon))
        {
            cout<<"Difference is = "<<realdayofyear-realdayofyear1<<"days and "<< D <<"minus "<<realdayofyear-realdayofyear1<<"days before"<<endl;
        }



    }


}

void Date::printday( )

{

int YY = (year-1) % 100;
int C = (year-1) - YY;
int G = YY + YY/4;
int dayofWeekJanuary=(((((C / 100) % 4) * 5) + G) % 7);
int gendaysofyear[12]={0,31,59,90,120,151,181,212,243,273,304,334};
int realdayofyear;
int dayy;


if(month>2 && isleap())
{
    realdayofyear=day+gendaysofyear[month-1] + 1;
}
else
    {
        realdayofyear=day+gendaysofyear[month-1];
    }

dayy =((dayofWeekJanuary+realdayofyear - 1) % 7);

switch (dayy)
 {case 0:
     cout<<"Monday";
break;
 case 1:
    cout<< "Tuesday";
    break;
 case 2:
    cout<< "Wednesday";
    break;
 case 3:
    cout<<"Thursday";
    break;
 case 4:
    cout<< "Friday";
    break;
 case 5:
    cout<< "Saturday";
    break;
 case 6:
    cout<<"Sunday";
    break;
 default :
    cout<<"wrong input";
 }

}

bool Date::isleap()
{
    if((year%4==0&&year%100!=0)|| year%400==0)
        return true;
    else
        return false;
}




void Date::printmonth( )

{

    switch(month)
    {
    case 1:
    cout<<"January";
    break;
    case 2:
        cout<<"February";
        break;
    case 3:
        cout<<"March";
        break;
    case 4:
        cout<<"April";
        break;
    case 5:
        cout<<"May";
        break;
    case 6:
        cout<<"June";
        break;
    case 7:
        cout<<"July";
        break;
    case 8 :
        cout<<"August";
        break;
    case 9:
        cout<<"September";
        break;
    case 10:
        cout<<"October";
        break;
    case 11:
        cout<<"November";
        break;
    case 12:
        cout<<"December";
        break;
    default:
        cout<<"Wrong input";
        break;
    }


}







int main()
{
// Date a;



while (true)
{



    int a;

    do{


    cout<<"To get information about todays date press 1."<<endl;
    cout<<"To get information about entered date press 2."<<endl;
    cout<<"To exit press 3"<<endl;

    cin>>a;
    //system("cls");
    }while(!(isValid()) || a>3 ||a<1  );


    if(a==1)
    {

 time_t now = time(NULL);

   tm *ltm = localtime(&now);
   Date a (ltm->tm_mday,1 + ltm->tm_mon,ltm->tm_year+1900);
    a.info();
    cout<<endl;
  if( a.isleap())
    cout<<"Today is a leap year"<<endl;
  else
    cout<<"Todays is not a leap year"<<endl;



    }
    if(a==2)
     {

         int b,c,d;
     do{
     cout<<"Enter in the following order- day of month(1-31), month(1-12),year"<<endl;
      cin>>b;
      cin>>c;
      cin>>d;
      } while(b<1 || b>31 || c<1 || c>12 || d<0  || (!(isdayValid(b,c,d)))|| (!(isValid())));
         Date a(b,c,d);

         a.info();
         cout<<endl;

         if(a.isleap())
            cout<<"Leap year"<<endl;
         else
            cout<<"Not a leap year"<<endl;

         a.diffBetNow();
     }
     if(a==3)
        return 0;



}


    return 0;
}

bool isdayValid(int d,int m, int y)
{

    if(m==2)
{

        if((y%4==0&&y%100!=0)|| y%400==0)
        {

            if(d<1 || d>29)
                return false;
            else return true;
        }


    else if(!((y%4==0&&y%100!=0)|| y%400==0))
    {

            if(d<1 || d>28)
                return false;
                else
                    return true;
        }
}

    else return true;


}

bool isValid()

{
    if(cin.rdstate())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        return false;

    }
    return true;
}
