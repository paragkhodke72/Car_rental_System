#ifndef enums_hpp
#define enums_hpp

#include <iostream>
#include <string>
using namespace std;

enum class Comparision{
    LessThan,
    EqualTo,
    GreaterThan,
};

enum vehicleType{
    Honda,
    sedan,
    exotic,
    suv
};


inline istream& operator>> ( istream& in, vehicleType& TypeOfvehicle )
{
    int val;
    if ( in >> val ) {
        TypeOfvehicle = static_cast<vehicleType>(val); // it returns a value of Vehicle Type
    }
    return in;
}

#endif
