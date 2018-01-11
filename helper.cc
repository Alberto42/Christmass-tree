#include "helper.h"
#include <iostream>
#include <random>

int randomNumber() {
    static std::mt19937 gen(0);
    static std::uniform_int_distribution<>
            dis(0, std::numeric_limits<int>::max());
    return dis(gen);
}

Price Price::operator+(const Price &p) const {
    return Price(amount + p.amount);
}

Price &Price::operator-=(const Price &p) {
    amount -= p.amount;;
    return *this;
}

bool Price::operator<(const Price &p) const {
    return amount < p.amount;
}

std::ostream &operator<<(std::ostream &stream, const Price &p) {
    return stream << p.amount << " PLN";
}


Date &Date::operator++() {
    if (minute < 59) minute++;
    else {
        minute = 0;
        if (hour < 23) hour++;
        else {
            hour = 0;
            day++;
        }
    }
    return *this;
}

int operator-(const Date &d1, const Date &d2) {
    return d1.minute - d2.minute + (d1.hour - d2.hour) * 60 +
           (d1.day - d2.day) * 60 * 24;
}

bool Date::operator<(const Date &d) const {
    if (day != d.day) return day < d.day;
    else if (hour != d.hour) return hour < d.hour;
    else return minute < d.minute;
}

std::ostream &operator<<(std::ostream &stream, const Date &d) {
    stream << "December, " << d.day << ", " << d.hour << ":";
    if (d.minute < 10) stream << "0";
    stream << d.minute;
    return stream;
}

Date &currentDate() {
    static Date current(18, 16, 0);
    return current;
}

Price Decoration::getPrice() const {
    return price;
}

Decoration::Decoration(std::string name, Price price) : name(name),
                                                        price(price) {

}

std::string Decoration::getName() {
    return name;
}