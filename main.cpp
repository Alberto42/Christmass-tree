#include <iostream>
#include <memory>
#include "person.h"

using namespace std;

class base
{
public:
    virtual void myFunc() {
        cout << "My base function" << std::endl;
    }
};

class derived : public base
{
public:
    derived() {}
    void myFunc() override { cout << "My derived function" << std::endl; }

};
class MyClass {

};

int main() {
//    shared_ptr<derived> dupa(make_shared<derived>() );
//    shared_ptr<base> pbase =  make_shared<derived>();
//    pbase->myFunc();
    std::shared_ptr<Person> pointer;
}