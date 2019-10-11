#include "Reservation.hpp"

Reservation:: Reservation(string name, string Plate): name{name}, Plate{Plate}{}

// printing reservation List using operator overloading
ostream& operator<<(ostream& out, Reservation reservation){
    out << reservation.getName() << " Has Rented the Car Whose Plate Number is  " << reservation.getPlate() << endl;
    return out;
}



