//
// Created by albert on 09.01.18.
//

#include "person.h"

std::string Adult::getName() {
    return name;
}

Adult::Adult(std::string name, Price savings) : name(name), savings(savings) {

}

Price Adult::getSavings() {
    return savings;
}

void Adult::buyDecoration(const Decoration &decoration) {
    savings -= decoration.getPrice();
}

std::string Child::getName() {
    return name;
}

Child::Child(std::string name) : name(name) {

}
