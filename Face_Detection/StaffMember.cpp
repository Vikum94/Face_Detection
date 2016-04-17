#include <iostream>
#include <string>

using namespace std;

class StaffMember {
private:
	string name;
	int idNumber;
	string picturePath;
	static int totalStaff;

public:
	string getName() { return name; }
	int getIdNumber() { return idNumber; }
	string getPicturePath() { return picturePath; }

	void setIdNumber(int idNumber) { this->idNumber = idNumber; }
	void setPicturePath(string picturePath) { this->picturePath = picturePath; }

	StaffMember(string, int, string);

	StaffMember();
	~StaffMember();
};

StaffMember::StaffMember(string name, int idNumber, string picturePath) {
	this->name = name;
	this->idNumber = idNumber;
	this->picturePath = picturePath;
	StaffMember::totalStaff += 1;
}

StaffMember::StaffMember() {
	StaffMember::totalStaff += 1;
}

StaffMember::~StaffMember() {
	StaffMember::totalStaff -= 1;
}

