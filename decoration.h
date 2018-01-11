#ifndef JNP1_CHRISTMASS_TREE_DECORATION_H
#define JNP1_CHRISTMASS_TREE_DECORATION_H

#include <memory>
#include <list>
#include "helper.h"
#include "person.h"

using CompositeList = std::list<std::shared_ptr<Decoration> >;
using ObserversList = std::list<std::shared_ptr<Person>>;

class ObservableTree {
    ObserversList observators;

protected:
    void notify(std::shared_ptr<Decoration> decoration);

public:
    void attachObserver(std::shared_ptr<Person> observer);

    void detachObserver(ObserversList::iterator observer);
};

class ChristmasTree : public ObservableTree {
private:
    std::string name;
    CompositeList decorations;

public:

    ChristmasTree(std::string name);

    Price getPrice();

    void addDecoration(std::shared_ptr<Decoration> decoration);

    void removeDecoration(CompositeList::iterator decoration);

    CompositeList::iterator begin();

    CompositeList::iterator end();

};

class GlassBall : public Decoration {
    bool broken;

public:
    GlassBall(std::string name, Price price);

    void doOperation(std::ostream &stream) override;
};

class Lights : public Decoration {
    int state;

public:
    Lights(std::string name, Price price);

    void doOperation(std::ostream &stream) override;
};


class Tree : public Decoration {
    Date date;

public:
    Tree(std::string name, Price price, Date date);

    void doOperation(std::ostream &stream) override;
};

#endif //JNP1_CHRISTMASS_TREE_DECORATION_H
