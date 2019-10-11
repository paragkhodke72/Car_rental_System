#ifndef CarLinkedList_hpp
#define CarLinkedList_hpp

#include <iostream>
#include <string>
#include "Car.hpp"
using namespace std;

// node created
struct Node{
    Car data;
    Node* next;
};


class LinkedList{
private:
    int length;
    Node* currentPos;
    Node* head;

public:
    LinkedList():  currentPos{nullptr}, head{nullptr}, length{0}{}
    void makeEmpty();
    void putCar(Car car);
    Car& getCar(Car car, bool& found);
    void deleteCar(Car car, bool isFromReservation);
    void resetList();
    Car getNextCar();
    Car& getCarAtIndex(int index); // car reference
    int getLength();
    void printAvailCar( ostream& out );
    ~LinkedList();
    
};

ostream& operator<<(ostream& out, LinkedList& l);

#endif
