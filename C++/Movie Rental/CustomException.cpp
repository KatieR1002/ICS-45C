#include "CustomException.h"
const char* DuplicateMovieException::what() const throw() {
    return "Movie exists";
}

const char* DuplicateRenterException::what() const throw(){
    return "Renter exists";
}

const char* EmptyMovieInfoException::what() const throw(){
    return "Movie code and/or movie name is empty";
}

const char* EmptyMovieListException::what() const throw(){
    return "Movie iventory list is empty";
}

const char* EmptyRenterListException::what() const throw(){
    return "Movie does not have any renters";
}

const char* EmptyRenterNameException::what() const throw(){
    return "Empty firstname and/or last name for the renter";
}

const char* InvalidRenterIDException:: what() const throw(){
    return "Invalid renter ID";
}

const char* MovieLimitException::what() const throw(){
    return "Exceed the maximum movie number";
}

const char* MovieNotFoundException::what() const throw(){
    return "Movie does not exsits";
}

const char* RentedMovieException::what() const throw(){
    return "User attempts to discontinue a movie that has copies currently rented out";
}

const char* RenterLimitException::what() const throw(){
    return "There are no available copies";
}

const char* RenterNotFoundException::what() const throw(){
    return "Renter does not exsit";
}
