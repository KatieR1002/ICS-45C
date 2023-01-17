#include "MovieManagerUI.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

std::string MovieManagerUI::toUpper(std::string str) {
    std::string r = "";
    for (int i = 0; i < str.length(); i++) {
        r += toupper(str[i]);
    }
    return r;
}
void MovieManagerUI::printMenu() {
    string menu = "am: Add Movie\ndm: Discontinue Movie\nrm: Rent Movie\nrr: Return Rental\np: Print Movie Inventory\nq: Quit Program\n-----\nEnter Command:";
    cout << menu << endl;
}
std::string MovieManagerUI::getCommand() {
    std::string command;
    cin >> command;
    std::string fc;
    fc = toUpper(command);
    std::vector<string> commands{"AM", "DM", "RM", "RR", "P", "Q"};
    bool valid = false;
    for (int i = 0; i < commands.size(); i++){
            if (fc == commands[i]) {
                valid = true;
            }
    }
    while (valid == false) {
        MovieManagerUI::invalidSelection();
        cin >> command;
        fc = toUpper(command);
        for (int i = 0; i < commands.size(); i++){
            if (fc == commands[i]) {
                valid = true;
            }
        }
    }
    return fc;
}
std::string MovieManagerUI::getMovieName() {
    std::string MovieName;
    std::cout << "Enter Movie Name: " << endl;
    cin >> MovieName;
    return MovieName;
}
std::string MovieManagerUI::getMovieCode() {
    std::string MovieCode;
    std::cout << "Enter Movie Code: " << endl;
    cin >> MovieCode;
    return MovieCode;
}
int MovieManagerUI::getRenterID() {
    int RenterID;
    std::cout << "Enter Renter ID: " << endl;
    cin >> RenterID;
    return RenterID;
}
std::string MovieManagerUI::getRenterFirstName() {
    std::string fn;
    std::cout << "Enter Renter First Name: " << endl;
    cin >> fn;
    return fn;
}
std::string MovieManagerUI::getRenterLastName() {
    std::string ln;
    std::cout << "Enter Renter Last Name: " << endl;
    cin >> ln;
    return ln;
}
void MovieManagerUI::invalidSelection() {
    std::cout << "Command is invalid!\n";
}
void MovieManagerUI::enterToContinue(){
    std::cout << "Enter to continue.\n";
}
void MovieManagerUI::print(std::string sth){
    std::cout << sth;
}
/*
	std::string getRenterFirstName();
	std::string getRenterLastName();
	void invalidSelection();
	void enterToContinue();
	void print(std::string);
};*/
