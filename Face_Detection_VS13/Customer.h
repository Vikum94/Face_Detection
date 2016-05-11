#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <fstream>
//#include <vector>

//#include "FaceRec.h"

//using namespace std;

class Customer {
private:
	std::string firstName;
	std::string surname;
	std::string idNumber;
	std::string status;
	std::string picturePath;
	bool isPrivileged;
	bool isTroubleMaker;
	
	//static vector<std::string> customerList;
	static int totalCustomers;
	static int totalPrivileged;
	static int totalBadCustomers;

public:
	std::string getFisrstName();
	std::string getSurname();
	std::string getIdNumber();
	std::string getStatus();
	static int getTotalCustomers();

	void setFirstName(std::string);
	void setsurname(std::string);
	void setStatus(std::string, bool);
	void setPicturePath(std::string);
	void setId(std::string);

	bool registerCustomer();

	Customer(std::string, std::string, std::string);

	Customer();
	~Customer();
};
#endif // !CUSTOMER_H