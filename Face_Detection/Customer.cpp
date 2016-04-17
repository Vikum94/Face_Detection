#include <string>
#include <iostream>

using namespace std;

class Customer {

private:
	string firstName;
	string surname;
	int idNumber;
	string status;
	string picturePath;

	static int totalPrivileged;
	static int totalBadCustomers;

public:
	string getFisrstName() { return firstName; }
	string getSurname() { return surname; }
	int getIdNumber() { return idNumber; }
	string getStatus() { return status; }
	
	void setFirstName(string firstName) { this->firstName = firstName; }
	void setsurname(string surname) { this->surname = surname; }
	void setIdNumber(int idNumber) { this->idNumber = idNumber; }
	void setStatus(string, bool);
	void setPicturePath(string picturePath) { this->picturePath = picturePath; }

	bool train();

	Customer(string, string, int);

	Customer();
	~Customer();

};

void Customer::setStatus(string status, bool isPrivileged) {
	this->status = status; 
	if (isPrivileged) {
		Customer::totalPrivileged += 1;
	}
	else
		Customer::totalBadCustomers += 1;
}

Customer::Customer(string firstName, string surname, int idNumber) {
	this->firstName = firstName;
	this->surname = surname;
	this->idNumber = idNumber;
}

Customer::Customer() {
	//Constructor for latter use
}

Customer::~Customer() {
	cout << this->getFisrstName + getSurname << "destroyed" << endl;
}

bool Customer::train() {
	//training the customer picture to the system
	return true;
}