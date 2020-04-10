#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
#include "vehice.h"

#include <iostream>



class boat


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
    float setweight2(float weight2)
    {
        v.weight=weight2;
    }


};




#endif // BUS_H_INCLUDED
