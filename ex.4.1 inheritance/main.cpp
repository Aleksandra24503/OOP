#include <iostream>
#include "vehice.h"
#include "car.h"
#include"bus.h"
#include <cstdlib>
using namespace std;

int main()
{

car a;
cout<<"enter year production of your car "<<endl;
int b;
cin>>b;
a.set_yearOfProduction(b);

cout<<"enter weight of your car"<<endl;

float d,c,e,f,g;
cin>>c;
a.set_weight(c);

cout<<"type max acceptable weight given by producer "<<endl;
cin>>d;

cout<<" enter price for petrol per litre"<<endl;
cin>>e;
a.set_pricePerl(e);
cout<<"enter your cars mileage per year"<<endl;
cin>>f;
a.set_mileage_per_year(f);
cout<<"enter fuel consumption per 100 km"<<endl;
cin>>g;
a.set_fuel_consumption(g);
cout<<"enter car brand"<<endl;
string x;

cin>>x;
cout<<"enter car colour"<<endl;
string y;
cin>>y;
a.set_carBrand_colour(x, y);
cout<<"Enter km to calculate the cost of journey for your car"<<endl;

float  h;
cin>>h;


system("cls");

cout<<a.getbrand()<<" " <<a.getcolour()<<endl;
cout<<"weight - "<<a.get_weight()<<endl;
cout<<"Your cars max load "<<"="<<a.maxload(d)<<endl;
cout<<"Year production - " <<a.get_yearOfProduction()<<endl;
cout<<"Your cars age - "<<a.ageOfVehicle()<<endl;
cout<<"your cars expected mileage"<<"="<<a.expected_mileage()<<endl;
cout<<"cost of journey for "<<h<<"km" <<"="<< a.costOfJourney(h)<<endl;



    return 0;
}
