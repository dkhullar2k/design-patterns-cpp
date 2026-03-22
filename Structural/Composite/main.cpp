/*Problem solved by composite design pattern:
if (type == "file") ...
else if (type == "folder") ...

Problems:
-> Type checking everywhere
-> Tight coupling
-> Not scalable

💡Composite design pattern helps you treat individual objects
and group of objects in the same way
*/
#include<iostream>
#include<vector>
using namespace std;

class FileSystemComponent{ // Component
    public:
    virtual void display()=0;
    virtual ~FileSystemComponent()=default;
};
class File: public FileSystemComponent{ //Leaf
    string name;
    int size;
    public:
    File(string name, int size){
        this->name=name;
        this->size=size;
    }
    void display()override{
        cout<<"File: "<<name<<" has size: "<<size<<endl;
    }
    ~File(){
    }
};
class Directory: public FileSystemComponent{ //Composite
    string name;
    vector<FileSystemComponent*> components;
    public:
    Directory(string name){
        this->name=name;
    }
    void display()override{
        cout<<"Directory name: "<<name<<endl;
        for(const auto& component:components){
            component->display();
        }
    }
    void addComponent(FileSystemComponent* component){
        components.push_back(component);
    }
    ~Directory(){
        for(auto const& component:components){
            delete component;
        }
    }
};

//Client code
int main(){
    FileSystemComponent* f1=new File("file1.xml", 32);
    FileSystemComponent* f2=new File("file2.jpg", 12);
    Directory* d1=new Directory("Folder1");
    d1->addComponent(f1);
    d1->addComponent(f2);
    d1->display();

    delete d1;
}