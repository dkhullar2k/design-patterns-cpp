/*
Thread safe (Double check locking)- Lazy Initialization
*/
#include<mutex>
class Singleton{
    private:
    //Use inline because otherwise static members need to be explicitely defined outside the class 
    inline static Singleton* obj=nullptr;
    inline static std::mutex mtx;
    Singleton(){}

    public:
    //Delete copy constructor and copy assignment
    Singleton(const Singleton&)=delete; 
    Singleton& operator=(const Singleton&)=delete;


    static Singleton* getInstance(){
        if(obj==nullptr){ //Ensure that lock only happens when obj is not already present
            std::lock_guard<std::mutex> lock(mtx);
            if(obj==nullptr){//Ensure that even if two threads enter the prev if condition only one actually creates the obj
                obj=new Singleton();
            }
        }
        return obj;
    }
};

int main(){
    Singleton* instance=Singleton::getInstance();
}