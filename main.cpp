/*
 Data Structure, Programming Assignment No-1
 Author: parag khodke
 Version: Created on Oct 3rd, 2019,
 All rights reserved.
 This is UNH car Rental System with two list(array For reservation Whose key is USER_NAME and Linked List for Car whose key is NUMBER_PLATE).
 User can add car to Inventory, user could Remove the Car From Inventory, user can reserve the availiable car and Delete the car.
 This program also checks if same Numberplate is entered or not while Removing the car from Inventory.
 This program also checks To cancle the Reservation if same Username is Entered or not , if same Name is Not Entered It will show Error Message.
 The Uer are only reserve the car from Inventory if the Car is availiable only.
 This program uses recursion to display the Menu after Each choice EXCEPT if the user Entered Exit(7).
*/

#include <iostream>
#include "Car.hpp"
#include "CarLinkedList.hpp"
#include "Reservation.hpp"
#include "ReservationArrayList.hpp"

void printMenu();
void PrintingAllCars();
void AddingCarToInventory();
void RemoveCarFromInventory();
void ListAllReservation();
void AddReservation();
void CancleReservation();

using namespace std;

LinkedList* carList = (LinkedList* ) new  LinkedList(); // created linked list for car
ArrayList* reservationList = (ArrayList*) new ArrayList() ;// created linked list for Reservation

void printMenu(){ // printing menu for User
    int userChoice;
    cout << "\n-------------------------------------------" << endl;
    cout << "\t\tWelcome to UNH Car Rental System" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\t\t1. List all cars" << endl;
    cout << "\t\t2. Add car to inventory" << endl;
    cout << "\t\t3. Remove car from inventory" << endl;
    cout << "\t\t4. List all reservations" << endl;
    cout << "\t\t5. Add a reservation" << endl;
    cout << "\t\t6. Cancel reservation" << endl;
    cout << "\t\t7. Exit" << endl;
    cout << "\nKindly Enter your choice from Above Menu:\n";
    cin >> userChoice;
 
    switch (userChoice) {
        case 1:
            PrintingAllCars();
            printMenu();
            break;
        case 2:
            AddingCarToInventory();
            printMenu();
            break;
        case 3:
            RemoveCarFromInventory();
            printMenu();
            break;
        case 4:
            ListAllReservation();
            printMenu();
            break;
        case 5:
            AddReservation();
            printMenu();
            break;
        case 6:
            CancleReservation();
            printMenu();
            break;
        case 7:
            cout << "\n\nThank you for visiting ' UNH Car Rental Application'  Visit Again Bye. !!!\n\n";
            exit(0);
            break;
        default: cout<<"\nInvalid integer chocie ! Please Try Again \n";
            printMenu();
            break;
    }
}

// printing cars from car list
void PrintingAllCars(){
    if(carList->getLength() > 0){
        cout<<"\n\nSr.No\t\tplate No\t\tMake\t\tModel\t\tType\t\tPrice\n";
       cout << *carList << endl;
    }else
    cout<<"\nSorry .. No car in Inventory now, You could add cars to Inventory by choosing option '2'.\n\n\n\n";
}

// adding car to Inventory
//same number plate added and not showing all the availiable cars
void AddingCarToInventory(){
    Car carObject;
    string plateNumber;
    string ModelName;
    string Make;
    vehicleType TypeOfvehicle;
    double pricePerDay;
    bool availability = true;
    
    cout << "\n\nAdding Cars To Inventory." << endl;
    cout << "\nPlease enter a Plate number: \n";
    cin >> plateNumber;
    carObject.getPlateNumber() = plateNumber; // get plate Number
    cout <<"\nWho Make this car?"<<endl;
    cin>> Make;
    carObject.getMake() = Make;//get make
    cout << "\nPlease Enter Car Model: ?\n";
    cin >> ModelName;
    carObject.getModel()=ModelName;// get Model Name
    cout << "\nwhat is the typr of this  ?\n   0 = Hondan\n   1 = Sedan\n   2 = Exotic,\n   3 = suv\n\n";
    cin >> TypeOfvehicle;// get Type of Vehicle
    cout << "\nWHat is the cost per day for this Car \n$";
    cin >> pricePerDay;
    
    carObject = Car(plateNumber,Make, ModelName, TypeOfvehicle, pricePerDay, availability);
    carList->putCar(carObject); // car Object is passed into putList of car to add the car
    cout<<"\nCar Successfully added to inventory now.\n\n\n\n";
}


// Remove car from inventory
void RemoveCarFromInventory(){
    if(carList->getLength() > 0){
        Car carObject;
        string plateNumber;
        cout << "\n\nTo Remove Your Reservation, First Please Enter Plate Number for car ? \n";
        cin >> plateNumber;
        carList->deleteCar(Car(plateNumber,"","",{},0,true), false);
        }
    else
        cout <<"\nNo cars right now in Inventory to Remove\n\n\n\n ";
 }

// print all reservation List
void ListAllReservation(){
    if (reservationList->reservationGetLength() >0)
        cout << *reservationList << endl;
    else
        cout<<"\nSorry, No reservations availiables till now.\n\n\n\n";
}

// adding Reservation
void AddReservation(){
    if(carList->getLength()>0){
        string UserName;
        int choice;// index
        int cancel;
        string plateNumber;
        Car carObject;
        cout << "\nAdding Reservation..\n\nKindly Enter Your Name ?\n";
        cin >> UserName;
        carList->printAvailCar(cout);
        cancel = carList->getLength() + 1; // get length of list and after that, add cancle option
        cout << cancel << ".  Cancel" << endl;
        cout << "\nWhich car do you want to book? \n";
        cin >> choice;
        if (choice == cancel){
            cout<<"\nYou Dont want to add Reservations, you can choose from the menu..\n\n\n\n";
            printMenu();
        }
        else{
            carObject = carList->getCarAtIndex(choice-1);
            carList->deleteCar(Car(carObject.getPlateNumber(), "","",{},0,true), true);// se
            carList->putCar( Car( carObject.getPlateNumber(),carObject.getMake(),carObject.getModel(),carObject.getType(),carObject.getPPD(), false ) );
            plateNumber = carObject.getPlateNumber();
            Reservation r(UserName, plateNumber); // reserve car using User name and Plate Number
            reservationList->reservationPutItem(r); // pass username and plate number as object into reservation List
            cout<<"\nCongratulation !! Your reservation is Confirmed now!!!\n\n";
        }
    }
    else
        cout<<"\noppps !! no cars in inventory, First Add car and the Reserve Your Seat\n\n\n\n";
}

// cancle reservation
void CancleReservation(){
    if (reservationList->reservationGetLength()>0) {
        string Username;
        Reservation ResObj;
        Car carObject;
        bool temp = false;
        cout << "\n\nTo Cancle Your Reservation, Please Enter Your Name ?\n";
        cin >> Username;
        ResObj= Reservation(Username,"");// Delete the reservation based on User Name
        reservationList -> reservationDeleteItem (reservationList->reservationGetItem (ResObj, temp) );
        carObject.setAvailable(true);// after remove Reservation, set that car to availiable
    }else
        cout<<"\nNo reservation added Yet, add first and then try to remove\n\n\n\n";
}


int main(int argc, const char * argv[]) {
    printMenu();
    return 0;
}
