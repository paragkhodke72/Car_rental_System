#ifndef Reservation_hpp
#define Reservation_hpp
#include <iostream>
#include <string>
#include "enums.hpp"
//#include "CarLinkedList.hpp"

using namespace std;

class Reservation{
private:
    string name;
    string Plate;

public:
    Reservation(): name{""}, Plate{""}{};
    Reservation(string name, string plate);
    string getName(){ return name;}
    string getPlate(){ return Plate;}

    Comparision CompareForGetname(Reservation other){
        if(name < other.getName())
            return Comparision::LessThan;
        else if (name == other.getName())
            return Comparision::EqualTo;
        return Comparision::GreaterThan;
    }
};

ostream& operator<<(ostream& out, Reservation reservation);

#endif

