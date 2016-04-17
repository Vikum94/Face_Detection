#pragma once
#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <iostream>
#include <string>
#include "stdafx.h"

using namespace std;

class StaffMember {
private:
	string name;
	int idNumber;
	string picturePath;
	static int totalStaff;

public:
	string getName();
	int getIdNumber();
	string getPicturePath();

	void setIdNumber(int);
	void setPicturePath(string);

	StaffMember(string, int, string);

	StaffMember();
	~StaffMember();
};
#endif // !STAFFMEMBER_H