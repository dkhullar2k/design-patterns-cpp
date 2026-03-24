/*
Separate abstraction from implementation so both can evolve independently

You can have:
Basic Remote / Advanced Remote
Sony TV / Samsung TV

👉 Any remote should work with any TV
👉 WITHOUT creating combinations like:

SonyBasicRemote
SonyAdvancedRemote
SamsungBasicRemote
SamsungAdvancedRemote

🚨 That’s the problem Bridge solves
*/
#include <iostream>
using namespace std;

class Workshop{ //Implementer
    public:
    virtual void work()=0;
    virtual ~Workshop(){}
};
class Produce: public Workshop{ //Concrete Implementer
    public:
    void work() override{
        cout<<"Produced"<<endl;
    }
};
class Assemble: public Workshop{ //Concrete Implementer
    public:
    void work() override{
        cout<<"Assembled"<<endl;
    }
};

class Vehicle{ //Abstraction
    protected:
    Workshop* w1;
    Workshop* w2;
    public:
    Vehicle(Workshop* w1, Workshop* w2){
        this->w1=w1;
        this->w2=w2;
    }
    virtual void manufacture()=0;

    virtual ~Vehicle() {
        delete w1;
        delete w2;
    }
};

class Car: public Vehicle{ //Refined Abstraction
    public:
    Car(Workshop* w1, Workshop* w2):Vehicle(w1,w2){}
    void manufacture() override{
        cout<<"Car ";
        w1->work();
        cout<<"Car ";
        w2->work();
        cout<<"Car Manufactured"<<endl;
    }
}; 

class Bike: public Vehicle{ //Refined Abstraction
    public:
    Bike(Workshop* w1, Workshop* w2):Vehicle(w1,w2){}
    void manufacture() override{
        cout<<"Bike ";
        w1->work();
        cout<<"Bike ";
        w2->work();
        cout<<"Bike Manufactured"<<endl;
    }
}; 

int main(){
    Vehicle* v1=new Car(new Produce, new Assemble);
    Vehicle* v2=new Bike(new Assemble, new Produce);
    v1->manufacture();
    v2->manufacture();

    delete v1;
    delete v2;
}