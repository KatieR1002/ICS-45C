#include "Movie.h"
#include <iostream>
Movie::Movie() {
    this -> movieCode = "";
    this -> movieName = "";

}
Movie::Movie(std::string mcode, std::string mName) {
    this -> movieCode = mcode;
    this -> movieName = mName;
}
void Movie::setMovieCode(std::string Mcode) {
    this -> movieCode = Mcode;
}
std::string Movie::getMovieCode() {
    return this -> movieCode;
}
void Movie::setMovieName(std::string Mname) {
    this -> movieName = Mname;
}
std::string Movie::getMovieName() {
    return this -> movieName;
}
void Movie::rentMovie(Renter newrenter) {
        if (renters.size() == 10){
            throw RenterLimitException();
        }
        for (int i = 0; i < renters.size(); i++){
            if (renters[i].getRenterID() == newrenter.getRenterID()){
               throw DuplicateRenterException();
            }

        }

    renters.insert(renters.end(), newrenter);
}

void Movie::returnRental(int rentId) {
    if (renters.size() == 0) {
            throw EmptyRenterListException();
        }
    bool exist = false;
    int wi = 0;
    for (int i = 0; i < renters.size(); i++){
            if (renters[i].getRenterID() == rentId) {
               exist = true;
               wi = i;
            }
    }


    if (exist == false) {
        throw RenterNotFoundException();
    }
    renters.erase(renters.begin() + wi);
    }

bool Movie::isBeingRented(){
    if(renters.size() > 0) {
        return true;
    }
    return false;
}
void Movie::printMovieInfo() {
    std::cout << "#" << movieCode << " " << movieName << std::endl;
    std::cout << "Renter List\n";
    for (int i = 0; i < renters.size(); i++){
        std::cout << renters[i].getRenterID() << ": " << renters[i].getRenterFirstName() << " " <<renters[i].getRenterLastName()<< std::endl;
    }

}

