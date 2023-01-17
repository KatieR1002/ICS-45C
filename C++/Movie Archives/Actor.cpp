#include "Actor.h"

using namespace std;
Actor::Actor() {
    this-> firstName = "";
    this-> lastName = "";
    this-> birthYear = 0;
    }
Actor::Actor(std::string f, std::string l, int by) {
    this-> firstName = f;
    this-> lastName = l;
    this-> birthYear = by;
}
std::string Actor::getFirstName() {
    return this->firstName;
}
std::string Actor::getLastName() {
    return this->lastName;
}
int Actor::getBirthYear() {
    return this->birthYear;
}
void Actor::setFirstName(string fn) {
    this->firstName = fn;
}
void Actor::setLastName(string ln) {
    this->lastName = ln;
}
void Actor::setBirthYear(int by) {
    this->birthYear = by;
}
