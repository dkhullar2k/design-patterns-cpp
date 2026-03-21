/*Approach: Direct Object Initialisation */
#include<iostream>
using namespace std;

class Engine{
    public:
    void start(){
        cout<<"Engine started"<<endl;
    }
    void stop(){
        cout<<"Engine stopped"<<endl;
    }
};
class Lights{
    public:
    void turnOn(){
        cout<<"Headlights turned on"<<endl;
    }
    void turnOff(){
        cout<<"Headlights turned off"<<endl;
    }
};
class CarFacade{
    Engine e;
    Lights l;
    public:
    void startCar(){
        e.start();
        l.turnOn();
        cout<<"Car is ready to drive"<<endl;
    }
    void stopCar(){
        e.stop();
        l.turnOff();
        cout<<"Car has stopped"<<endl;
    }
};

//Client Code
int main(){
    CarFacade car;
    car.startCar();
    car.stopCar();
}