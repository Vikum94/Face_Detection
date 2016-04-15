#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Customer {
private:
	string firstName;
	string surname;
	int id;
	string status;
	string picturePath;

public:
	string getFisrstName() { return firstName; }
	string getSurname() { return surname; }
	int getId() { return id; }
	string getStatus() { return status; }
	
	void setFirstName(string firstName) { this->firstName = firstName; }
	void setsurname(string surname) { this->surname = surname; }
	void setId(int id) { this->id = id; }
	void setStatus(string status) { this->status = status; }
	void setPicturePath(string picturePath) { this->picturePath = picturePath; }

	bool train();

	Customer(string, string, int);

	Customer();
	~Customer();

};

bool Customer::train() {
	//training the customer picture to the system
	return true;
}

Customer::Customer(string firstName, string surname, int id) {
	this->firstName = firstName;
	this->surname = surname;
	this->id = id;
}

Customer::Customer() {
	//Constructor for latter use
}

Customer::~Customer() {
	cout << this->getFisrstName + getSurname << "destroyed" << endl;
}