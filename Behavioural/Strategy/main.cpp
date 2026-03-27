/* 
Write Difference between new with () and without ()
Why two times delete is required
Understand drawbacks in the original code
Change image
*/
#include<iostream>
using namespace std;
class PaymentInterface{ //Strategy interface
    public:
    virtual void pay()=0;
    virtual ~PaymentInterface(){}
};
class CreditCard: public PaymentInterface{ //Concrete Strategy
    public:
    void pay() override{
        cout<<"Credit card"<<endl;
    }
};
class UPI: public PaymentInterface{ //Concrete Strategy
    public:
    void pay() override{
        cout<<"UPI"<<endl;
    }
};
class PayPal: public PaymentInterface{ //Concrete Strategy
    public:
    void pay() override{
        cout<<"PayPal"<<endl;
    }
};
class PaymentContext{ //Context
    private:
    PaymentInterface* strategy;
    public:
    PaymentContext(){
        strategy=nullptr;
    }
    void setPayment(PaymentInterface* obj){
        //delete old strategy
        delete strategy;
        strategy=obj;
    }
    void executePayment(){
        if (strategy) {
            cout << "Payment done through ";
            strategy->pay();
        } else {
            cout << "No payment method set!" << endl;
        }
    }
    ~PaymentContext(){
        delete strategy;
    }
};

//Client
int main(){
    PaymentContext* c1= new PaymentContext();
    c1->setPayment(new CreditCard);
    c1->executePayment();

    c1->setPayment(new UPI);
    c1->executePayment();

    c1->setPayment(new PayPal);
    c1->executePayment();

    delete c1;
}