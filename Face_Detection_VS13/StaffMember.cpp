#include "StaffMember.h"
#include <string>

using namespace std;
int StaffMember::totalStaff = 0;

string StaffMember::getName() { return firstName+lastName; }
string StaffMember::getIdNumber() { return idNumber; }
string StaffMember::getPicturePath() { return picturePath; }
void StaffMember::setPicturePath(string picturePath) { this->picturePath = picturePath; }
void StaffMember::setEmployeeLevel(string employeeLevel){ this->employeeLevel = employeeLevel; }
int StaffMember::getTotalStaff(){ return totalStaff; }

StaffMember::StaffMember(string firstName, string lastName, string employeeLevel, string picturePath) {
	StaffMember::totalStaff += 1;
	this->firstName = firstName;
	this->lastName = lastName;
	this->employeeLevel = employeeLevel;
	this->idNumber = "SM" + to_string(StaffMember::totalStaff);
	this->picturePath = picturePath;
	//StaffMember::staffList.push_back(idNumber);

	ofstream file;
	file.open("at.txt",std::ios_base::app);
	file << "C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/"+picturePath + ";" + idNumber+"\n";
	file.close();
}

StaffMember::StaffMember() {
	StaffMember::totalStaff += 1;
}

StaffMember::~StaffMember() {
	//StaffMember::totalStaff -= 1;
}