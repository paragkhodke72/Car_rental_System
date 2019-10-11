
#ifndef ReservationArrayList_hpp
#define ReservationArrayList_hpp
#define MAX 1

#include "Reservation.hpp"
#include "Car.hpp"

class ArrayList{

private:
    int currentPosition;
    int length;
    Reservation data[MAX];

public:
    ArrayList(): currentPosition{0}, length{0}{}
    void reservationMakeEmpty();
    void reservationPutItem(Reservation reserve);
    Reservation reservationGetItem(Reservation reserve, bool& Reservationfound);
    void reservationDeleteItem(Reservation reserve);
    void reservationResetList();
    Reservation reservationGetNextItem();
    int reservationGetLength();

};

ostream& operator<<(ostream& out, ArrayList& arrayList);

#endif
