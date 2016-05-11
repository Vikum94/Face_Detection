#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<string>
#include "Customer.h"
#include "StaffMember.h"
#include <vector>

class Controller{
private:
	static std::vector<std::string> id_list;
public:
	static void add_customer(std::string, std::string, std::string, std::string, bool);
	
	static int get_total_customers();

	static void add_staffMember(std::string, std::string, std::string, std::string);
	
	static int get_total_staffMembers();

	
	Controller();
	~Controller();
};

#endif