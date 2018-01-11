#include <cassert>
#include "decoration.h"

ChristmasTree::ChristmasTree(std::string name) : name(name) {

}

Price ChristmasTree::getPrice() {
    Price result(0);
    for (auto d : decorations) {
        result = result + d->getPrice();
    }
    return result;
}

CompositeList::iterator ChristmasTree::begin() {
    return decorations.begin();
}

CompositeList::iterator ChristmasTree::end() {
    return decorations.end();
}

GlassBall::GlassBall(std::string name, Price price) : Decoration(name, price) {
    broken = false;
}

void GlassBall::doOperation(std::ostream &stream) {
    if (!broken) {
        if (randomNumber() % 4 == 0) {
            broken = true;
        }
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
    //Drzewko traci igły liniowo względem czasu,
    // przy czym straci wszystki po ok. 5 tyg
    int coverage = std::max((100 - (currentDate() - date) / 500), 0);
    stream << getName() << ": ";
    stream << coverage << "% of tree covered with needles\n";

}

void Lights::doOperation(std::ostream &stream) {
    state = (state + 1) % 3;

    stream << getName() << ": "
           << (state == 0 ? "off\n" :
               state == 1 ? "constant\n" : "blinking\n");
}

void ObservableTree::notify(std::shared_ptr<Decoration> decoration) {
    for (auto o = observators.begin(); o != observators.end(); o++) {
        (*o)->notify(decoration);
    }
}

void ObservableTree::attachObserver(std::shared_ptr<Observer> observer) {
    observators.push_back(observer);
}

void ObservableTree::detachObserver(ObserversList::iterator observer) {
    observators.erase(observer);
}

void CompositeTree::addDecoration(std::shared_ptr<Decoration> decoration) {
    decorations.push_back(decoration);
    ObservableTree::notify(decoration);
}

void CompositeTree::removeDecoration(CompositeList::iterator decoration) {
    decorations.erase(decoration);
}