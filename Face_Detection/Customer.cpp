#include "stdafx.h"
#include "Customer.h"

int Customer::totalBadCustomers = 0;
int Customer::totalPrivileged = 0;

void Customer::setFirstName(string firstName) { this->firstName = firstName; }
void Customer::setsurname(string surname) { this->surname = surname; }
void Customer::setIdNumber(int idNumber) { this->idNumber = idNumber; }
void Customer::setPicturePath(string picturePath) { this->picturePath = picturePath; }
	
string& Customer::getFisrstName() {
	return firstName;
}
string Customer::getSurname() {
	return surname;
}
int Customer::getIdNumber() {
	return idNumber;
}
string Customer::getStatus() {
	return this->status;
}
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
	cout << this->getFisrstName() + this->getSurname() << "destroyed" << endl;
}

bool Customer::train() {
	//training the customer picture to the system
	return true;
}
