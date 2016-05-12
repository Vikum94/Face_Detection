#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<string>
#include "Customer.h"
#include "StaffMember.h"
#include <vector>
#include "MobileDevice.h"

class Controller{
private:
	static std::vector<int> id_list;
public:
	static void add_customer(std::string, std::string, std::string, std::string, bool);
	static int get_total_customers();

	static void add_staffMember(std::string, std::string, std::string, std::string);
	static int get_total_staffMembers();

	static void register_privileged_customer();
	static void register_bad_customer();
	static void clear_all();
	static void Controller::send_detected();
	Controller();
	~Controller();
};

#endif