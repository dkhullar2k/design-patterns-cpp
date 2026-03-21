/*Approach: Pointer + Constructor Initialization*/
#include<iostream>
using namespace std;
class Inventory{
    public:
    bool checkAvailability(){
        cout<<"Checking Availablility..."<<endl;
        return true;
    }
};
class Payment{
    public:
    void processPayment(){
        cout<<"Processing Payment..."<<endl;
    }
};
class Notification{
    public:
    void notify(){
        cout<<"Sending notification..."<<endl;
    }
};
class Facade{
    Inventory* i;
    Payment* p;
    Notification* n;
    public:

    Facade(){
        i=new Inventory();
        p=new Payment();
        n=new Notification();
    }

    ~Facade(){
        delete i;
        delete p;
        delete n;
    }

    void bookTicket(){
        if(i->checkAvailability()){
            p->processPayment();
            n->notify();
            cout<<"Booking successful"<<endl;
        }
        else cout<<"Seats not available"<<endl;
    }
};

//Client
int main(){
    Facade* booking=new Facade;
    booking->bookTicket();
    delete booking;
}