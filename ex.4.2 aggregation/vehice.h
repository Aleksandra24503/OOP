#ifndef VEHICE_H_INCLUDED
#define VEHICE_H_INCLUDED

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
    float get_price(){return pricePerl;}

    friend class car;
    friend class bus;

};

#endif // VEHICE_H_INCLUDED
