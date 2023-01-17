#include "MovieManager.h"
#include <iostream>
using namespace std;

void MovieManager::run() {
    try{
    this-> mmUI.printMenu();
    string command;
    command = this-> mmUI.getCommand();
    while (command != "Q") {
    if (command == "AM") {

        std::string moviename;
        moviename = this -> mmUI.getMovieName();
        std::string moviecode;
        moviecode = this -> mmUI.getMovieCode();
        std::string renterfn;
        Movie thismovie;
        thismovie.setMovieCode(moviecode);
        thismovie.setMovieName(moviename);
        addMovie(thismovie);
    }
    else if (command == "DM") {
        std::string mcode;
        mcode = this -> mmUI.getMovieCode();
        discontinueMovie(mcode);
    }
    else if (command == "RM") {
        std::string mcode;
        mcode = this -> mmUI.getMovieCode();
        std::string renterfn;
        renterfn = this -> mmUI.getRenterFirstName();
        std::string renterln;
        renterln = this -> mmUI.getRenterLastName();
        int rentid;
        rentid = this -> mmUI.getRenterID();
        Renter thisrenter;
        thisrenter.setRenterID(rentid);
        thisrenter.setRenterFirstName(renterfn);
        thisrenter.setRenterLastName(renterln);
        rentMovie(mcode, thisrenter);
    }
    else if (command == "RR") {
        int rentid;
        rentid = this -> mmUI.getRenterID();
        std::string mcode;
        mcode = this -> mmUI.getMovieCode();
        returnRental(rentid, mcode);
    }
    else if (command == "P") {
        printInventory();
    }
    this -> mmUI.enterToContinue();
    command = this-> mmUI.getCommand();
    }
    }
    catch(DuplicateMovieException& erx) {
        std::cout << erx.what();}
    catch(DuplicateRenterException& erx) {
        std::cout << erx.what();}
    catch(EmptyMovieInfoException& erx) {
        std::cout << erx.what();}
    catch(EmptyMovieListException& erx) {
        std::cout << erx.what();}
    catch(EmptyRenterListException& erx) {
        std::cout << erx.what();}
    catch(EmptyRenterNameException& erx) {
        std::cout << erx.what();}
    catch(InvalidRenterIDException& erx) {
        std::cout << erx.what();}
    catch(MovieLimitException& erx) {
        std::cout << erx.what();}
    catch(MovieNotFoundException& rx) {
        std::cout << rx.what();}
    catch(RentedMovieException& erx) {
        std::cout << erx.what();}
    catch(RenterLimitException& erx) {
        std::cout << erx.what();}
    catch(RenterNotFoundException& erx) {
        std::cout << erx.what();}




}
void MovieManager::addMovie(Movie newmovie){

        bool duplicate = false;
        for (int i = 0; i < movies.size(); i++){
            if (movies[i].getMovieCode() == newmovie.getMovieCode()){
                duplicate = true;
            }

        }
        if (movies.size() == 20){
            throw MovieLimitException();
        }
        else if (newmovie.getMovieCode() == "" || newmovie.getMovieName() == "") {
            throw EmptyMovieInfoException();
        }
        else if (duplicate == true) {
            throw DuplicateMovieException();


    }

    movies.insert(movies.end(), newmovie);
}
void MovieManager::discontinueMovie(std::string movieCode) {
    if (movies.size() == 0) {
            throw EmptyMovieListException();
        }
    bool exist = false;
    int wi = 0;
    for (int i = 0; i < movies.size(); i++){
            if (movies[i].getMovieCode() == movieCode){
                wi = i;
            }
        }
    for (int i = 0; i < movies.size(); i++){
            if (movies[i].getMovieCode() == movieCode) {
               exist = true;
            }}


        if (exist == false) {
            throw MovieNotFoundException();
        }
        else if (movies[wi].renters.size() > 0) {
            throw RentedMovieException();}

    movies.erase(movies.begin() + wi);

}

void MovieManager::rentMovie(std::string movieCode, Renter s) {
    bool exist = false;
    int wi = 0;
    for (int i = 0; i < movies.size(); i++){
            if (movies[i].getMovieCode() == movieCode) {
               exist = true;
            }
    }

        if (exist == false) {
            throw MovieNotFoundException();
        }
        else if (s.getRenterFirstName() == "" || s.getRenterLastName() == "") {
            throw EmptyRenterNameException();
        }
        else if (s.getRenterID() < 0) {
            throw InvalidRenterIDException();
        }

    for (int i = 0; i < movies.size(); i++){
            if (movies[i].getMovieCode() == movieCode){
                wi = i;
            }
        }
    Movie copymovie = movies[wi];
    copymovie.rentMovie(s);
    movies[wi] = copymovie;
}
void MovieManager::returnRental(int rentId, std::string movieCode){
    bool exist = false;
    int wi = 0;
    for (int i = 0; i < movies.size(); i++){
            if (movies[i].getMovieCode() == movieCode) {
               exist = true;
	       wi = i;
            }
    }

        if (exist == false) {
            throw MovieNotFoundException();
        }
        else if (rentId < 0) {
            throw InvalidRenterIDException();

    }
    Movie copymovie = movies[wi];
    copymovie.returnRental(rentId);
    movies[wi] = copymovie;
}
void MovieManager::printInventory() {
    for (int i = 0; i < movies.size(); i++) {
        movies[i].printMovieInfo();
    }
}
