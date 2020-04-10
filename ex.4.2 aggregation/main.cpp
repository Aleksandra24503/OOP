#include <iostream>
#include "vehice.h"
#include "car.h"
#include"bus.h"
#include <cstdlib>
using namespace std;

int main()
{
/*
bus b;
    cout<<"To get information about age of bus type year of production of vehicle"<<endl;
 int a;
 cin>>a;
b.set_yearOfProduction2(a);
 cout<<"Age of bus - "<<b.ageOfVehicle2()<<endl;
*/

vehicle v;
car a;
a.set_price2v(v,50);
cout<<a.get_p2();
/*

cout<<"to count max load of your car enter your cars weight"<<endl;
float e;
cin>>e;
d.set_weight2(e);
cout<<"enter max weight given by producer"<<endl;
float g;
cin>>g;
cout<<"Your cars max load = "<< d.maxload2(g)<<endl;

cout<<"your car weighs "<<d.get_weight2()<<endl;


*/


    return 0;
}
