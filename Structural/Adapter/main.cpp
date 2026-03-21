
/*
The Client expects to use a new payment interface,
but the actual processing is implemented in an old payment class.
The Adapter bridges the gap by translating the new interface calls
into the old class's implementation.
*/
#include<iostream>
using namespace std;

class NewPaymentInterface{
    public:
    virtual void pay(int amount)=0;
};
class OldPayment{
    public:
    void rupay(double amount){
        cout<<"Payment done: "<<amount<<endl;
    }
};
class Adapter: public NewPaymentInterface{
    OldPayment* obj;
    public:
    Adapter(){
        obj=new OldPayment();
    }
    void pay(int amount) override{
        obj->rupay(static_cast<double>(amount));
    }
};

//Client class
int main(){
    NewPaymentInterface* o1=new Adapter();
    o1->pay(200);
    delete o1;
}

