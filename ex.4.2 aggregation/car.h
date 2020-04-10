#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<iostream>
#include "vehice.h"



class car
{
private:

   vehicle v;
   vehicle s;
    float fuel_consumption;
    float mileage_per_year;
    std::string carBrand;
    std::string colour;

public:

    void set_mileage_per_year(float);
    void set_fuel_consumption(float);
    void set_carBrand_colour(std::string,std::string);
    float expected_mileage();
    float costOfJourney(float);
    std::    string getbrand(){return carBrand;}
     std::  string getcolour(){return colour;}
void set_price2v(vehicle & v, float l)
{
    v.pricePerl=l;
}


     void set_weight2(float value)
{
    v.weight=value;
}

float maxload2(float producermax)
{

    return producermax-(v.weight);

}

float get_weight2() {return v.get_weight();}
float get_p2() {return v.get_price();}

};



#endif // CAR_H_INCLUDED
