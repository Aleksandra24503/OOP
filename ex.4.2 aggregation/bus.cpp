#include "bus.h"
#include "vehice.h"

int bus::count_income(int nrOfpassengers)
    {
        return ticket_price * nrOfpassengers;
    }



void  bus::set_nrOfPassengers(int nrOfPassengers)
{
    this->nrOfPassengers=nrOfPassengers;
}


void bus::set_max_ppl(int max_ppl)
{
    this->max_ppl=max_ppl;
}



void bus::set_ticket_price(int ticket_price)
{
    this->ticket_price=ticket_price;
}



float bus:: total_weight()
    {


        return this->max_ppl * 200 + v.weight;


    }



