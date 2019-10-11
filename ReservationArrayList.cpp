#include "ReservationArrayList.hpp"

void ArrayList::reservationMakeEmpty(){
    length = 0;
}
//Put item in Reservation List
void ArrayList::reservationPutItem(Reservation reserve){
    data[length++] = reserve;
    cout<<"\n\nConfirmed";
}

void ArrayList::reservationResetList(){
    currentPosition = 0;
}

Reservation ArrayList::reservationGetNextItem(){
    if(currentPosition < length)
        return data[currentPosition++];

    throw "Out of Range";
}
// length of reservation List
int ArrayList::reservationGetLength(){
    return length;
}
// printing Reservation List
ostream& operator<<(ostream& out, ArrayList& arrayList){
    arrayList.reservationResetList();
    out << "\nReservation List: \n";
    for(int i = 0; i < arrayList.reservationGetLength(); ++i){
        int index = i;
        out << index + 1 << ". " << arrayList.reservationGetNextItem();
    }
    out << endl;
    return out;
}

// car Rented Comparasion
Reservation ArrayList::reservationGetItem(Reservation reserve, bool& Reservationfound){
    Reservationfound = false;
    for(int i = 0; i < length; ++i){
        if (data[i].CompareForGetname(reserve) == Comparision::EqualTo ) { // compare for same user name enterd or Not
            reserve = data[i];
            Reservationfound = true;
            cout<<"\nYour reservation is Now cancelled, Visit Again !!! \n\n\n\n";
            break;
        }else{
            Reservationfound = false;
            cerr <<"\nSorry Your Entered Name Is Not Found In Reservation List, Kindly Enter Correct Name to Cancle your Reservation\n\n\n\n";
        }
    }
    return reserve;
}

void ArrayList::reservationDeleteItem(Reservation reserve){
    for(int i = 0; i < length; ++i){
        if (data[i].CompareForGetname(reserve) == Comparision::EqualTo ) // compare for same user name enterd or Not
            data[i] = data[--length];
       // cout<<"You'r In";
    }
    //cerr <<"Sorry Your Name Is Not Found";
}


