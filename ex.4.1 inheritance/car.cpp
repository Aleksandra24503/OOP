#include "car.h"
#include "vehice.h"

#include <iostream>


void car::set_mileage_per_year(float mileage_per_year)
{
    this->mileage_per_year=mileage_per_year;
}


float car:: costOfJourney(float km)
    {

        return (this->fuel_consumption) * km * pricePerl;
    }


float car::expected_mileage()

{
     return year_of_production*mileage_per_year;
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
