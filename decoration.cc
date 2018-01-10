//
// Created by albert on 09.01.18.
//

#include <assert.h>
#include "decoration.h"
#include "person.h"

ChristmasTree::ChristmasTree(std::string name) : name(name) {

}

Price ChristmasTree::getPrice() {
    Price result(0);
    for (auto d : decorations) {
        result = result + d->getPrice();
    }
    return result;
}

void ChristmasTree::addDecoration(std::shared_ptr<Decoration> decoration) {
    decorations.push_back(decoration);
    notify(decoration);
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

void ChristmasTree::notify(std::shared_ptr<Decoration> decoration) {
    for(auto o = observators.begin();o != observators.end(); o++) {
        (*o)->notify(decoration);
    }
}

void ChristmasTree::attachObserver(std::shared_ptr<Person> observator) {
    observators.push_back(observator);
}

void ChristmasTree::detachObserver(ObservatorsList::iterator observator) {
    observators.erase(observator);
}

GlassBall::GlassBall(std::string name, Price price) : Decoration(name, price) {
    broken = false;
}

void GlassBall::doOperation(std::ostream &stream) {
    if (randomNumber() % 4 == 0) {
        broken = true;
    }

    stream << getName() << ": " << (broken ? "broken\n" : "OK\n");

}

Lights::Lights(std::string name, Price price) : Decoration(name, price) {
    state = 0;
}

Tree::Tree(std::string name, Price price, Date date) : Decoration(name, price),
                                                       date(date) {

}

void Tree::doOperation(std::ostream &stream) {
    assert(date < currentDate());
    int coverage = std::max((100 - (currentDate() - date)), 0);
    stream << getName() << ": ";
    stream << coverage << "% of tree covered with needles\n";

}

void Lights::doOperation(std::ostream &stream) {
    state = (state + 1) % 3;

    stream << getName() << ": "
           << (state == 0 ? "off\n" :
               state == 1 ? "constant\n" : "blinking"
                       "n");
}
