#include <iostream>
#include <ctime>
#include <string>
#include<cstdlib>
#include<limits>
using namespace std;

bool isValid();
class vehicle
{
protected:
    float weight;
    float length;
    int   year_of_production;
    float max_load;
    float  pricePerl;



public:


    void set_yearOfProduction(int);
    int get_yearOfProduction() {return year_of_production;}
    float maxload(float);
    int  ageOfVehicle();
    void set_weight(float);
    float get_weight() {return weight;}
    void set_pricePerl(float);

};


int vehicle::ageOfVehicle()
{

    time_t rt;

    time(&rt);

    return 1900 + localtime(&rt)->tm_year - year_of_production;
}


void vehicle::set_pricePerl(float pricePerl)
{
    this->pricePerl=pricePerl;

}

void vehicle::set_yearOfProduction(int year_of_production)
{
    this->year_of_production=year_of_production;
}

void vehicle::set_weight(float weight)
{
    this->weight=weight;
}


float vehicle ::maxload(float producermax)
{

    return producermax-(this->weight);

}


//................................................................................................................................


class car : virtual public vehicle
{
protected:


    float fuel_consumption;
    float mileage_per_year;
    std::string carBrand;
    std::string colour;

public:
    //car(int, int, int, std::string, int);
    // car (int);

    void set_mileage_per_year(float);
    void set_fuel_consumption(float);
    void set_carBrand_colour(std::string,std::string);
    float expected_mileage();
    float costOfJourney(float);
    std::    string getbrand(){return carBrand;}
     std::  string getcolour(){return colour;}

};




void car::set_mileage_per_year(float mileage_per_year)
{
    this->mileage_per_year=mileage_per_year;
}


float car:: costOfJourney(float km)
    {

        return (this->fuel_consumption) * km * this->pricePerl;
    }


float car::expected_mileage()

{
     return this->year_of_production*this->mileage_per_year;
}
void car::set_carBrand_colour (std::string carBrand,std::string colour)
{
    this->carBrand=carBrand;
    this->colour=colour;
}

void car::set_fuel_consumption(float fuel_consumption)
{
    this->fuel_consumption=fuel_consumption;
}


//..............................................................................................................................


class boat : virtual public vehicle


{
protected:
    int nrOfPassengers;
    int max_ppl;
    int ticket_price;

public:

    int count_income(int );
    void set_ticket_price(int);
    void set_max_ppl(int);
    void set_nrOfPassengers(int);
    float total_weight();



};


int boat::count_income(int nrOfpassengers)
    {
        return ticket_price * nrOfpassengers;
    }



void  boat::set_nrOfPassengers(int nrOfPassengers)
{
    this->nrOfPassengers=nrOfPassengers;
}


void boat::set_max_ppl(int max_ppl)
{
    this->max_ppl=max_ppl;
}



void boat::set_ticket_price(int ticket_price)
{
    this->ticket_price=ticket_price;
}



float boat:: total_weight()
    {


        return this->max_ppl * 200 + this->weight;
    }


//.........................................................................................................................
class Amphibious : public car, public boat
{
protected:

    float speed;
public :
    void set_speed(float s){ speed=s; }


};


int main()
{

Amphibious A;
int c;
string a,b;
do{
cout<<"enter vehicle brand and colour"<<endl;
cin>>a;
cin>>b;
A.set_carBrand_colour(a,b);
cout<<"enter year of production"<<endl;
cin>>c;
}while(!(isValid()));


A.set_yearOfProduction(c);
system("cls");

cout<<"Year production - " <<A.get_yearOfProduction()<<endl;
cout<<"Age of vehicle - "<<A.ageOfVehicle()<<endl;
cout<<"Brand - "<< A.getbrand()<<endl;
cout<<"Colour = "<<A.getcolour()<<endl;
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
