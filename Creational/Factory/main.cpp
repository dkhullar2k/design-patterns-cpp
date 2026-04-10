/*
Define an interface for creating objects
-> Delegates object creation to a method
*/
#include <iostream>
using namespace std;

class Vehicle{ //Abstract Product
    public:
    virtual void printVehicle()=0;
    virtual ~Vehicle(){}
};
class TwoWheeler: public Vehicle{ //Concrete Product
    public:
    void printVehicle()override{
        cout<<"I am a two wheeler vehicle"<<endl;
    }
};
class FourWheeler: public Vehicle{ //Concrete Product
    public:
    void printVehicle() override{
        cout<<"I am a four wheeler vehicle"<<endl;
    }
};

class FactoryVehicle{ //Abstract Factory
    public:
    virtual Vehicle* createVehicle()=0;
    virtual ~FactoryVehicle(){}
};
class FactoryTwoWheeler: public FactoryVehicle{ //Concrete Factory
    public:
    Vehicle* createVehicle() override{
        return new TwoWheeler();
    }
};
class FactoryFourWheeler: public FactoryVehicle{ //Concrete Factory
    public:
    Vehicle* createVehicle() override{
        return new FourWheeler();
    }
};

int main(){
    FactoryVehicle* f1=new FactoryTwoWheeler();
    Vehicle* twoWheel=f1->createVehicle();
    twoWheel->printVehicle();

    FactoryVehicle* f2=new FactoryFourWheeler();
    Vehicle* fourWheel=f2->createVehicle();
    fourWheel->printVehicle();

    delete(twoWheel); //Prefer destroying objects before their creators
    delete(f1);
    
    delete(fourWheel);
    delete(f2);
}
