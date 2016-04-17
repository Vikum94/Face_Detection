#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "stdafx.h"

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
	string& getFisrstName();
	string getSurname();
	int getIdNumber();
	string getStatus();

	void setFirstName(string);
	void setsurname(string);
	void setIdNumber(int);
	void setStatus(string, bool);
	void setPicturePath(string);

	bool train();

	Customer(string, string, int);

	Customer();
	~Customer();
};
#endif // !CUSTOMER_H