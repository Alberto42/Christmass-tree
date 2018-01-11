#ifndef JNP1_CHRISTMASS_TREE_DECORATION_H
#define JNP1_CHRISTMASS_TREE_DECORATION_H

#include <memory>
#include <list>
#include "helper.h"
#include "person.h"

using CompositeList = std::list<std::shared_ptr<Decoration> >;
using ObserversList = std::list<std::shared_ptr<Observer>>;

class ObservableTree {
    ObserversList observators;

protected:
    void notify(std::shared_ptr<Decoration> decoration);
    ObservableTree() = default;

public:
    void attachObserver(std::shared_ptr<Observer> observer);

    void detachObserver(ObserversList::iterator observer);
};

class CompositeTree : public ObservableTree {
protected:
    CompositeTree() = default;
    CompositeList decorations;
public:
    void addDecoration(std::shared_ptr<Decoration> decoration);

    void removeDecoration(CompositeList::iterator decoration);
};

class ChristmasTree : public CompositeTree {
private:
    std::string name;

public:

    ChristmasTree(std::string name);

    Price getPrice();

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
