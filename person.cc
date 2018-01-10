//
// Created by albert on 09.01.18.
//

#include "person.h"

std::string Adult::getName() {
    return name;
}

Adult::Adult(std::string name, Price savings) :
        name(name), savings(savings), totalCost(0) {
}

Price Adult::getSavings() {
    return savings;
}

void Adult::buyDecoration(const Decoration &decoration) {
    savings -= decoration.getPrice();
}

void
Adult::notify(std::shared_ptr<Decoration> decoration, std::ostream &ostream) {
    totalCost = totalCost + decoration->getPrice();
    ostream << "We have new decoration!" << std::endl
           << "Total cost is " << totalCost << "." << std::endl;
}

std::string Child::getName() {
    return name;
}

Child::Child(std::string name) : name(name) {

}

void
Child::notify(std::shared_ptr<Decoration> decoration, std::ostream &stream) {
    stream << "Wow!" << std::endl;
    decoration->doOperation(std::cout);

}
