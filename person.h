#ifndef JNP1_CHRISTMASS_TREE_PERSON_CC_H
#define JNP1_CHRISTMASS_TREE_PERSON_CC_H

#include <string>
#include "helper.h"

class Person {
public:
    void notify();
};
class Adult : public Person {
private:
    std::string name;
    Price savings;
public:
    std::string getName();
    Adult(std::string name,Price savings = Price(0) );
//    void buyDecoration(Decoration& decoration);
    Price getSavings();

};

class Child : public Person{
private:
    std::string name;
    std::string getName();
public:
    Child(std::string name);
};

#endif //JNP1_CHRISTMASS_TREE_PERSON_CC_H
