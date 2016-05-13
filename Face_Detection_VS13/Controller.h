#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<string>
#include "Customer.h"
#include "StaffMember.h"
//#include "FaceRec.h"

class Controller{
private:
	//std::string first_name;
	//std::string last_name;
	//std::string pic_name;
	
	//std::string status;
	//bool is_privileged;
	
	//std::string employee_level;

public:
	static void add_customer(std::string, std::string, std::string, std::string, bool);
	//void add_customer();
	static int get_total_customers();
	static void set_total_customers(int);

	static void add_staffMember(std::string, std::string, std::string, std::string);
	//void add_staffMember();
	static int get_total_staffMembers();


	//Controller(std::string, std::string, std::string, std::string, bool);
	//Controller(std::string, std::string, std::string, std::string);
	Controller();
	~Controller();
};

#endif