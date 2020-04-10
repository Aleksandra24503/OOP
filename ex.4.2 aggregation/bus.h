#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
#include "vehice.h"

#include <iostream>



class bus


{
private:
    vehicle v;
    int nrOfPassengers;
    int max_ppl;
    int ticket_price;

public:

    int count_income(int );
    void set_ticket_price(int);
    void set_max_ppl(int);
    void set_nrOfPassengers(int);
    float total_weight();
    int ageOfVehicle2(){return v.ageOfVehicle();}    //function from vehicle

    void set_yearOfProduction2(int year_of_production)
{
    v.year_of_production=year_of_production;
};





};




#endif // BUS_H_INCLUDED
