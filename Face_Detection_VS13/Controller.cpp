#include "Controller.h"

std::vector<std::string> Controller::id_list;

void Controller::add_customer(std::string first_name, std::string last_name, std::string pic_name, std::string status, bool is_privileged){
	Customer new_customer = Customer(first_name, last_name, pic_name);
	new_customer.setStatus(status, is_privileged);
	id_list.push_back(new_customer.getIdNumber());

}

void Controller::add_staffMember(std::string first_name, std::string last_name, std::string employee_level, std::string pic_name){
	StaffMember new_staffMember = StaffMember(first_name, last_name, employee_level, pic_name);
	id_list.push_back(new_staffMember.getIdNumber());
}

int Controller::get_total_customers(){
	return Customer::getTotalCustomers();
}

int Controller::get_total_staffMembers(){
	return StaffMember::getTotalStaff();
}



/*Controller::Controller(std::string first_name, std::string last_name, std::string status, std::string pic_name, bool is_privileged){
	this->first_name = first_name;
	this->last_name = last_name;
	this->status = status;
	this->pic_name = pic_name;
	this->is_privileged = is_privileged;
}

Controller::Controller(std::string first_name, std::string last_name, std::string employee_level, std::string pic_name){
	this->first_name = first_name;
	this->last_name = last_name;
	this->employee_level = employee_level;
	this->pic_name = pic_name;
}*/

Controller::Controller(){
}

Controller::~Controller(){
}