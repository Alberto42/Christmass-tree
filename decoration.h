//

#ifndef JNP1_CHRISTMASS_TREE_DECORATION_H
#define JNP1_CHRISTMASS_TREE_DECORATION_H

#include <memory>
#include <list>
#include "helper.h"
#include "person.h"

//
// Created by albert on 09.01.18.
//class Component {
//
//    virtual void addDecoration(std::shared_ptr<Composite>);
//    virtual void removeDecoration(CompositeList::iterator);
//
//};
//class Composite {
//private:
//
//public:
//    virtual void doOperation(std::ostream &stream);
//
//};
//class Leaf {
//
class Decoration{
public:
    Price getPrice();
};

using CompositeList = std::list<std::shared_ptr<Decoration> >;
using ObservatorsList = std::list<std::shared_ptr<Person>>;
//class Observer {
//    virtual void update();
//};
//class Observable {
//private:
//    virtual void detach(Observer observer);
//
//protected:
//    virtual void notify();
//
//public:
//    virtual void attachObserver(std::shared_ptr<Observer> observer);
//    virtual void detachObserver(ObservatorsList::iterator);
//};

//};

class ChristmasTree {
private:
    std::string name;
    CompositeList decorations;
    ObservatorsList observators;

public:
    ChristmasTree(std::string name);
    Price getPrice();
    void addDecoration(std::shared_ptr<Decoration> decoration);
    void removeDecoration(CompositeList::iterator decoration);
    CompositeList::iterator begin();
    CompositeList::iterator end();
    void notify();
    void attachObserver(std::shared_ptr<Person> observator);
    void detachObserver(ObservatorsList::iterator observator);

};
#endif //JNP1_CHRISTMASS_TREE_DECORATION_H
