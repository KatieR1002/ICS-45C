#include "Renter.h"
Renter::Renter() {
    this -> renterID = 0;
    this -> renterFirstName = "";
    this -> renterLastName = "";
}
Renter::Renter(int ID, std::string fName, std::string lName) {
    this -> renterID = ID;
    this -> renterFirstName = fName;
    this -> renterLastName = lName;
}
void Renter::setRenterID(int ID) {
    this -> renterID = ID;
}
int Renter::getRenterID() {
    return this -> renterID;}
void Renter::setRenterFirstName(std::string Fname) {
    this -> renterFirstName = Fname;
}
std::string Renter::getRenterFirstName() {
    return this -> renterFirstName;
}
void Renter::setRenterLastName(std::string Lname) {
    this -> renterLastName = Lname;
}
std::string Renter::getRenterLastName() {
    return this -> renterLastName;
}
/*class Renter{
private:
	int renterID;
	std::string renterFirstName;
	std::string renterLastName;
public:
	Renter();
	Renter(int, std::string, std::string);
	void setRenterID(int);
	int getRenterID();
	void setRenterFirstName(std::string);
	std::string getRenterFirstName();
	void setRenterLastName(std::string);
	std::string getRenterLastName();
};*/
