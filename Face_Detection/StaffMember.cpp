#include "stdafx.h"
#include "StaffMember.h"

int StaffMember::totalStaff = 0;

string StaffMember::getName() { return name; }
int StaffMember::getIdNumber() { return idNumber; }
string StaffMember::getPicturePath() { return picturePath; }
void StaffMember::setIdNumber(int idNumber) { this->idNumber = idNumber; }
void StaffMember::setPicturePath(string picturePath) { this->picturePath = picturePath; }

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