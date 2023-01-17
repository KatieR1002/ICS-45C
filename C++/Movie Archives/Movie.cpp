#include "Movie.h"

using namespace std;

Movie::Movie() {
    this->movieTime = 0;
    this->movieYearOut = 0;
    this->numberOfActors = 1;
    this->actorArrayIndex = 0;
    this->moviePrice = 0.0;
    this->movieTitle = "";
    this -> actors = new Actor[this -> numberOfActors];
}
Movie::Movie(int time, int year, int nactors, double price, std::string title) {
    this->movieTime = time;
    this->movieYearOut = year;
    this->numberOfActors = nactors;
    this->moviePrice = price;
    this->movieTitle = title;
    this->actorArrayIndex = 0;
    this -> actors = new Actor[this->numberOfActors];
}

Movie::Movie(const Movie &m) {
    this->movieTime = m.movieTime;
    this->movieYearOut = m.movieYearOut;
    this->numberOfActors = m.numberOfActors;
    this->actorArrayIndex = m.actorArrayIndex;
    this->moviePrice = m.moviePrice;
    this->movieTitle = m.movieTitle;
    this->actors = new Actor[this->numberOfActors];
    for (int i = 0; i < actorArrayIndex; ++i) {this->actors[i] = m.actors[i];}
}
Movie::~Movie(){
    delete[] actors;
}
void Movie::setMovieTime(int Time) {
    this->movieTime = Time;
}
int Movie::getMovieTime() {
    return this->movieTime;
}
void Movie::setMovieYearOut(int year) {
     this->movieYearOut = year;
}
int Movie::getMovieYearOut(){
    return this->movieYearOut;
}
void Movie::setNumberOfActors(int nactors){
    this->numberOfActors = nactors;
}
int Movie::getNumberOfActors(){
    return this->numberOfActors;
}
void Movie::addActor(std::string f, std::string l, int byear){
    Actor nactor = Actor(f,l,byear);
    actors[this->actorArrayIndex] = nactor;
    this->actorArrayIndex++;
}
void Movie::setMoviePrice(double price){
    this->moviePrice = price;
}
double Movie::getMoviePrice(){
    return this->moviePrice;
}
void Movie::setMovieTitle(std::string title){
    this->movieTitle = title;
}
std::string Movie::getMovieTitle(){
    return this->movieTitle;
}
void Movie::printMovieInfo(){
    cout << "Title: " << this->movieTitle << ", Published in: " << this->movieYearOut << endl;
    cout << "Duration of Movie: " << this->movieTime << " minutes" << endl;
    cout << "Price: $" << this->moviePrice << endl;
    cout << "Actors:" << endl;
    for (int i = 0; i <= sizeof(this->actors); i++){
        cout << this->actors[i].getFirstName() << " " << this->actors[i].getLastName() << ", " << this->actors[i].getBirthYear() << endl;
    }
}
