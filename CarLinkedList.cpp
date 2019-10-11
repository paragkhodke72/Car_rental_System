#include "CarLinkedList.hpp"

// display list
ostream& operator<<(ostream& out, LinkedList& l){
    l.resetList();
    out << "-----------------------------------------------------------------------";
    for(int i = 0; i < l.getLength(); ++i){
        int index = i;
        out <<"\n"<< index + 1 << "." << l.getNextCar();
    }
    out << endl;
    return out;
}

// get all the length of list
int LinkedList::getLength(){
    return length;
}

// de-constructor
LinkedList::~LinkedList(){
    makeEmpty();
}

// reset the list
void LinkedList::resetList(){
    currentPos = NULL;
}


Car LinkedList::getNextCar(){
    if(currentPos == NULL)
        currentPos = head;
    else
        currentPos = currentPos->next;
    return currentPos->data;
}


// empty  car linked List
void LinkedList::makeEmpty(){
    Node* temp;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

// add car to linked list
void LinkedList::putCar(Car car){
    Node* temp = new Node;
    temp->data = car;
    temp->next = head;
    head = temp;
    length++;
}

// get the car/ search the car and get the car from linked list
Car& LinkedList::getCar(Car car, bool &found){
    found = false;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data.CompararePlateNumber(car) == Comparision::EqualTo){// compare for same Number Plate Entered
            found = true;
            car = temp->data;
            break;
        }
        temp = temp->next;
    }
    throw "Number Plate is not  found";
//    return car;
}


// delete the car from the linked list
void LinkedList::deleteCar(Car car, bool isFromReservation){
    
    // if user already Rented the car and if we try to delete that NumberPlate
    if( car.getAvailable() == false ){
        cout << "\noopss, other user has rented this car From Inventory now\n" << endl;
        return;
    }
    
    if(head == nullptr){ // if
        cout << "\nopps sorry, Another user has rented ... " << endl;
        return;
    }
    
    //  if NumberPlate is found in head, delete numberplate from Head Itself,
    Node* temp;
    if(head->data.CompararePlateNumber(car) == Comparision::EqualTo){// compare for same Number Plate Entered
        temp = head->next;
        delete head;
        head = temp;
        length--;
        if(!isFromReservation)
            cout<<"Your Entered Number Plate Found, you Have successfully Removed the Car\n\n\n\n";
        return;
    }else{
        // if Numberplate is not in Head,Search All node and Delete That Node
        temp = head;
        while(temp->next != nullptr){
            if(temp->next->data.CompararePlateNumber(car) == Comparision::EqualTo){ // checking if entered numberplate is same or not
                Node* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                length--;
                if(!isFromReservation)
                    cout<<"You Have successfully Removed the Car\n\n\n\n";
                return;
            }
            temp = temp->next;
        }
    }
    cerr<<"opps Sorry, Your Entered Number Plate Is Not Found\n\n\n\n";
}



// printin only availiable cars and after that add cancle option
void LinkedList::printAvailCar( ostream& out ){
    resetList();
    out << "\nAvailable Cars is as Following: \n\n";
    for(int i =0 ;i<getLength() ; ++i){
        int index = i;
        out <<index + 1 << ".  ";// to show cancle item after printing all the availiable list
        Car temp = getCarAtIndex(index); // printing all availiables cars
        
        if(temp.getAvailable() == true){
            temp.PrintAvailable(out);//
            cout<<"\n";
        }
        else
            cout<<"This Car is Not availiable\n";
    }
}

Car& LinkedList::getCarAtIndex(int index){
    currentPos = head;
      for(int i = 0; i < index; i++){
            currentPos = currentPos->next;
       }
     return currentPos->data;
}
 

