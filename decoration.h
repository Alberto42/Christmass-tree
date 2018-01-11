#ifndef JNP1_CHRISTMASS_TREE_DECORATION_H
#define JNP1_CHRISTMASS_TREE_DECORATION_H

#include <memory>
#include <list>
#include "helper.h"
#include "person.h"

/*
 * Typ listy dekoracji swiatecznych
 */
using CompositeList = std::list<std::shared_ptr<Decoration> >;
/*
 * Typ listy obserwatorow choinki, dzieci lub doroslych
 */
using ObserversList = std::list<std::shared_ptr<Observer>>;

class ObservableTree {
    ObserversList observators;

protected:
    /*
     * Funkcja powiadamia wszystkich obserwatorow o dodanej dekoracji
     */
    void notify(std::shared_ptr<Decoration> decoration);

    ObservableTree() = default;

public:
    /*
     * Dodaje obserwatora choinki
     */
    void attachObserver(std::shared_ptr<Observer> observer);

    /*
     * Usuwa obserwatora choinki
     */
    void detachObserver(ObserversList::iterator observer);
};

/*
 * Klasa reprezentuje drzewo ktore jest kompozytem
 */
class CompositeTree : public ObservableTree {
protected:
    CompositeTree() = default;

    CompositeList decorations;
public:
    void addDecoration(std::shared_ptr<Decoration> decoration);

    void removeDecoration(CompositeList::iterator decoration);
};

/*
 *           *
            /.\
           /..'\
           /'.'\
          /.''.'\
          /.'.'.\
   "'""""/'.''.'.\""'"'"
         ^^^[_]^^^

 */
class ChristmasTree : public CompositeTree {
private:
    std::string name;

public:

    ChristmasTree(std::string name);

    Price getPrice();

    /*
     * Iterator poczatku listy dekoracji
     */
    CompositeList::iterator begin();

    /*
     * Iterator za koncem listy dekoracji
     */
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
