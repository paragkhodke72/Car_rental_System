#ifndef Car_hpp
#define Car_hpp
#include <iostream>
#include <string>
#include "enums.hpp"

using namespace std;
extern const char* typeNames[35];

class Car{
protected:
    string plateNumber;
    string model;
    string Make;
    vehicleType TypeOfvehicle;
    double pricePerDay;
    bool isAvailable = true;// by default its availiable

public:
    Car(): plateNumber{""},Make {""},model{""}, TypeOfvehicle(), pricePerDay{0},isAvailable{true}{}
    Car(string pNum,string Make, string model, vehicleType TypeOfvehicle, double ppd,bool isAvail);
    
    ostream& print( ostream& out );// operator overloading as out
    
    string getPlateNumber(){ return plateNumber; }
    string getMake(){return Make; }
    string getModel(){ return model; }
    vehicleType getType(){ return TypeOfvehicle; }
    double getPPD(){ return pricePerDay; }
    
    void setAvailable( bool available ){ isAvailable = available; }
    bool getAvailable(){ return isAvailable; }
    ostream& PrintAvailable( ostream& out );

    // this compar Finction is check if entered Numberplate is same from the List of not
    Comparision CompararePlateNumber(Car other){
        if(plateNumber < other.getPlateNumber())
            return Comparision::LessThan;
        else if (plateNumber == other.getPlateNumber())
            return Comparision::EqualTo;
        return Comparision::GreaterThan;
      
    }
};

ostream& operator<<(ostream& out, Car carObject);
#endif
