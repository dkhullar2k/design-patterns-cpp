/*
Lazy Initialization - Basic approach
*/
class Singleton{
    private:
    static Singleton* obj; //Static ensures that memory is allocated only once
    Singleton(){}
    
    public:
    //Delete copy constructor and copy assignment
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

    static Singleton* getInstance(){ //Static enables the function to be not tied to an object
        if(obj==nullptr){
            obj=new Singleton();
        }
        return obj;
    }
};
Singleton* Singleton::obj=nullptr; //Initialize the static member

int main(){
    Singleton* instance=Singleton::getInstance();
}

