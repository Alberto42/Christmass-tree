//
// Created by albert on 09.01.18.
//

#include "decoration.h"
#include "person.h"

ChristmasTree::ChristmasTree(std::string name):name(name){

}

Price ChristmasTree::getPrice() {
    Price result(0);
    for(auto d : decorations) {
        result = result + d->getPrice();
    }
    return result;
}

void ChristmasTree::addDecoration(std::shared_ptr<Decoration> decoration) {
    decorations.push_back(decoration);
    notify();
}

void ChristmasTree::removeDecoration(CompositeList::iterator decoration) {
    decorations.erase(decoration);
}

CompositeList::iterator ChristmasTree::begin() {
    return decorations.begin();
}

CompositeList::iterator ChristmasTree::end() {
    return decorations.end();
}

void ChristmasTree::notify() {
}

void ChristmasTree::attachObserver(std::shared_ptr<Person> observator) {
    observators.push_back(observator);
}

void ChristmasTree::detachObserver(ObservatorsList::iterator observator) {
    observators.erase(observator);
}

Price Decoration::getPrice() {
    return Price();
}
