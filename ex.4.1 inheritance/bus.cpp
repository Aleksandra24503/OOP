#include "bus.h"
#include "vehice.h"

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


        return this->max_ppl * 200 + v.weight;
    }
