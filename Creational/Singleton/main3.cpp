/*
Thread safe & Use of smart pointers
*/
#include<memory>
#include<mutex>
using namespace std;

class Singleton{
    private:
    inline static unique_ptr<Singleton> obj=nullptr;
    inline static mutex mtx;
    Singleton(){}

    public:
    //Delete copy constructor and copy assignment
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

    static Singleton* getInstance(){
        if(obj==nullptr){
            lock_guard<mutex> lock(mtx);
            if(obj==nullptr){
                obj=make_unique<Singleton>();
            }  
        }
        return obj.get();
    }
};

int main(){
    Singleton* instance=Singleton::getInstance();
}
