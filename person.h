#ifndef JNP1_CHRISTMASS_TREE_PERSON_CC_H
#define JNP1_CHRISTMASS_TREE_PERSON_CC_H

#include <string>
#include <memory>
#include <iostream>
#include "helper.h"

class Observer {
protected:
    Observer() = default;
public:
    virtual void notify(std::shared_ptr<Decoration> decoration,
                        std::ostream& stream = std::cout) = 0;
};

class Adult : public Observer {
private:
    std::string name;
    Price savings;
    Price totalCost;
public:
    std::string getName();

    Adult(std::string name, Price savings = Price(0));

    Price getSavings();

    void notify(std::shared_ptr<Decoration> decoration,
                        std::ostream& ostream = std::cout) override;

    void buyDecoration(const Decoration &decoration);

};

class Child : public Observer {
private:
    std::string name;

    std::string getName();

public:

    Child(std::string name);
    void notify(std::shared_ptr<Decoration> decoration,
                        std::ostream& stream = std::cout) override;
};

#endif //JNP1_CHRISTMASS_TREE_PERSON_CC_H
