#include "vehice.h"
#include <ctime>
#include<iostream>
using namespace std;
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
