#include <iostream>
#include <memory>
#include "person.h"
#include "decoration.h"

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
    ObservableTree();
}