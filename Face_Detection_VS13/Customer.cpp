#include "Customer.h"

int Customer::totalCustomers=0;
int Customer::totalBadCustomers = 0;
int Customer::totalPrivileged = 0;

void Customer::setFirstName(std::string firstName) { this->firstName = firstName; }
void Customer::setsurname(std::string surname) { this->surname = surname; }
void Customer::setPicturePath(std::string picturePath) { this->picturePath = picturePath; }
void Customer::setId(std::string id){ this->idNumber = id; }
void Customer::setTotalCustomers(int total_customers){ Customer::totalCustomers = total_customers; }
	
std::string Customer::getFisrstName() { return firstName; }
std::string Customer::getSurname() { return surname; }
std::string Customer::getIdNumber() { return idNumber; }
std::string Customer::getStatus() { return this->status; }
int Customer::getTotalCustomers(){ return Customer::totalCustomers; }

void Customer::setStatus(std::string status, bool isPrivileged) {
	this->status = status;
	if (this->isPrivileged && !isPrivileged) {
		Customer::totalPrivileged -= 1;
	}
	else if (!this->isPrivileged && isPrivileged){
		Customer::totalPrivileged += 1;
	}
}
Customer::Customer(std::string firstName, std::string surname, std::string picturePath) {
	Customer::totalCustomers += 1;
	this->firstName = firstName;
	this->surname = surname;
	this->picturePath = picturePath;
	this->idNumber = "C" + std::to_string(Customer::totalCustomers);
	//Customer::customerList.push_back(idNumber);

	std::ofstream file;
	file.open("at.txt", std::ios_base::app);
	file << "C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/" + picturePath + ";" + idNumber + "\n";
	file.close();
}
Customer::Customer() {
	//Constructor for latter use
}

Customer::~Customer() {
	std::cout << this->getFisrstName() + this->getSurname() << "destroyed" << std::endl;
}

