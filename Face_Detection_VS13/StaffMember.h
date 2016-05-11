#pragma once
#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <iostream>
#include <string>
#include <fstream>
//#include <vector>

//using namespace std;

class StaffMember {
private:
	std::string firstName;
	std::string lastName;
	std::string idNumber;
	std::string employeeLevel;
	std::string picturePath;
	static int totalStaff;
	//static std::vector<std::string> staffList;

public:
	std::string getName();
	std::string getIdNumber();
	std::string getPicturePath();
	static int getTotalStaff();

	void setIdNumber(std::string);
	void setPicturePath(std::string);
	void setEmployeeLevel(std::string);

	
	StaffMember(std::string, std::string, std::string, std::string);

	StaffMember();
	~StaffMember();
};
#endif // !STAFFMEMBER_H