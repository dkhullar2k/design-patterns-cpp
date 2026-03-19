//Decorator functionality without abstract decorator class
#include<iostream>
using namespace std;

class Coffee{ //Abstract class
    public:
    virtual int getCost()=0;
    virtual string getDescription()=0;
};

class PlainCoffee: public Coffee{ //Concrete class
    public:
    int getCost(){
        return 100;
    }
    string getDescription(){
        return "Plain Coffee";
    }
};
class MilkCoffee: public Coffee{ //Concrete class
    Coffee * c;
    public:
    MilkCoffee(Coffee* coffee){
        c=coffee;
    }
    int getCost(){
        return c->getCost()+ 20;
    }
    string getDescription(){
        return c->getDescription() + " With Milk";
    }
};
class SugarCoffee: public Coffee{ //Concrete class
    Coffee* c;
    public:
    SugarCoffee(Coffee* coffee){
        c=coffee;
    }
    int getCost(){
        return c->getCost()+ 30;
    }
    string getDescription(){
        return c->getDescription() +" With Sugar";
    }
};

//Client Code
int main(){
    Coffee* coffee= new PlainCoffee();
    cout<<coffee->getDescription()<<" "<<coffee->getCost()<<endl;
    
    Coffee* milkCoffee=new MilkCoffee(new PlainCoffee());
    cout<<milkCoffee->getDescription()<<" "<<milkCoffee->getCost()<<endl;

    Coffee* sugarCoffee=new SugarCoffee(new PlainCoffee());
    cout<<sugarCoffee->getDescription()<<" "<<sugarCoffee->getCost()<<endl;

    Coffee* sugarMilkCoffee=new SugarCoffee(new MilkCoffee(new PlainCoffee()));
    cout<<sugarMilkCoffee->getDescription()<<" "<<sugarMilkCoffee->getCost()<<endl;

    delete coffee;
    delete milkCoffee;
    delete sugarCoffee;
    delete sugarMilkCoffee;
}