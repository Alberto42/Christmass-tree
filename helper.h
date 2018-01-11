#ifndef HELPER
#define HELPER

#include <iostream>

int randomNumber();

class Price {
    int amount;
public:
    Price(int a = 0) : amount(a) {}

    Price operator+(const Price &p) const;

    Price &operator-=(const Price &p);

    bool operator<(const Price &p) const;

    friend std::ostream &operator<<(std::ostream &stream, const Price &p);
};

/*
 * Data swiateczna, obejmuje tylko dni swiateczne
 */
class Date {
    int day;
    int hour;
    int minute;
public:
    Date(int d, int h, int m) : day(d), hour(h), minute(m) {}

    Date &operator++();

    friend int operator-(const Date &d1, const Date &d2);

    bool operator<(const Date &d) const;

    friend std::ostream &operator<<(std::ostream &stream, const Date &d);
};

/*
 * Biezaca data, ktora mozna inkrementowac
 */
Date &currentDate();

/*
 * Dekoracja choinki
 */
class Decoration {
private:
    Price price;
    std::string name;
protected:
    Decoration(std::string name, Price price);

    Decoration() = default;

public:
    std::string getName();

    Price getPrice() const;

    /*
     * Operacja zabawy dekoracja swiateczna
     */
    virtual void doOperation(std::ostream &stream) = 0;

};


#endif //HELPER