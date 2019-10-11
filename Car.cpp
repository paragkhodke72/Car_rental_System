#include "Car.hpp"

// constructor
Car::Car(string pNum,string Make,string model, vehicleType vType, double ppd,
         bool isAvail): plateNumber(pNum), Make{Make},model{model}, TypeOfvehicle(vType), pricePerDay(ppd)
        {}


// Operator Overloading used here --> printing all cars : cout << *carList;
ostream& operator<<(ostream& out, Car carObject){
    vehicleType vt = carObject.getType();
    out <<" \t\t\t"<<carObject.getPlateNumber()<<"\t\t\t"<<carObject.getMake()<<"\t\t\t" << carObject.getModel() <<"\t\t\t"<< typeNames[vt] <<"\t\t\t"<<carObject.getPPD()<<endl;
    return out;
}


// add reservation -> print availiable car
ostream& Car::PrintAvailable( ostream& out ) {
    vehicleType vt = getType();
    out << "Car Number Plate is: " << getPlateNumber()<<"  , Car maker is: "<< getMake()<< " ,  Car Model is: "
    <<typeNames[vt]<< " , and price per day is: $ "<< getPPD() ;
    return out;
}

