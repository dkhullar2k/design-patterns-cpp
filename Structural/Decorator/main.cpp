/*
What not to do:
class Coffee{
    public:
    virtual int cost()=0;
};
class MilkCoffee : public Coffee{
    public:
    int cost()override{
        return 120;
    }
};
class SugarMilkCoffee : public Coffee{
    public:
    int cost()override{
        return 130;
    }
};
*/

#include<iostream>
using namespace std;
class Coffee{ //Abstract class
    public:
    virtual int getCost()=0;
    virtual string getDescription()=0;
};
class PlainCoffee: public Coffee{ //Concrete class
    public:
    int getCost() override{
        return 100;
    }
    string getDescription() override{
        return "Plain Coffee";
    }
};
class CoffeeDecorator: public Coffee{ //Abstract class
    protected:
    Coffee* coffeeDecorator;
    public:
    CoffeeDecorator(Coffee* c){
        coffeeDecorator=c;
    };
};
class MilkDecorator: public CoffeeDecorator{ //Concrete class
    public:
    MilkDecorator(Coffee* decoratedCoffee): CoffeeDecorator(decoratedCoffee){}
    int getCost() override{
        return coffeeDecorator->getCost()+ 20;
    }
    string getDescription() override{
        return coffeeDecorator->getDescription() + " With Milk";
    }
};
class SugarDecorator: public CoffeeDecorator{
    public:
    SugarDecorator(Coffee* decoratedCoffee):CoffeeDecorator(decoratedCoffee){}
    int getCost() override{
        return coffeeDecorator->getCost()+ 30;
    }
    string getDescription() override{
        return coffeeDecorator->getDescription() +" With Sugar";
    }
};

//Client Code
int main(){
    Coffee* coffee= new PlainCoffee();
    cout<<coffee->getDescription()<<" "<<coffee->getCost()<<endl;
    
    Coffee* milkCoffee=new MilkDecorator(new PlainCoffee());
    cout<<milkCoffee->getDescription()<<" "<<milkCoffee->getCost()<<endl;

    Coffee* sugarCoffee=new SugarDecorator(new PlainCoffee());
    cout<<sugarCoffee->getDescription()<<" "<<sugarCoffee->getCost()<<endl;

    Coffee* sugarMilkCoffee=new SugarDecorator(new MilkDecorator(new PlainCoffee()));
    cout<<sugarMilkCoffee->getDescription()<<" "<<sugarMilkCoffee->getCost()<<endl;

    delete coffee;
    delete milkCoffee;
    delete sugarCoffee;
    delete sugarMilkCoffee;
}

