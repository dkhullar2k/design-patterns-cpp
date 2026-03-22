/*
Proxy avoids repeated expensive operations by controlling object 
creation and reusing the instance once initialized.
*/
#include<iostream>
using namespace std;

class Video{
    public:
    virtual void play()=0;
    virtual ~Video(){};
};
class RealVideo: public Video{
    string name;
    void loadFromServer(){
        cout<<"Content loading from server"<<endl;
    }
    public:
    RealVideo(string t){
        name=t;
        loadFromServer();
    }

    void play() override{
        cout<<"Video is playing: "<<name<<endl;
    }
};
class ProxyVideo: public Video{
    string title;
    RealVideo* vid=nullptr;
    public:
    ProxyVideo(string str){
        title=str;
    }
    void play() override{
        if(vid==nullptr){
            vid=new RealVideo(title);
        }
        cout<<"User is watching "<<title<<endl;
        vid->play();
    }
    ~ProxyVideo(){
        delete vid;
    }
};
int main(){
    Video* v1=new ProxyVideo("Movie1");
    v1->play();

    Video* v2=new ProxyVideo("Movie2");
    v2->play();
    v2->play();

    delete v1;
    delete v2;
}