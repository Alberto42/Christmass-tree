#ifndef JNP1_CHRISTMASS_TREE_PERSON_CC_H
#define JNP1_CHRISTMASS_TREE_PERSON_CC_H

#include <string>
#include <memory>
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

    Adult(std::string name, Price savings = Price(0));

    Price getSavings();

    void buyDecoration(const Decoration &decoration);

};

class Child : public Person {
private:
    std::string name;

    std::string getName();

public:
    Child(std::string name);
};

#endif //JNP1_CHRISTMASS_TREE_PERSON_CC_H
