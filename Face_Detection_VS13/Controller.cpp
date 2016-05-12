#include "Controller.h"

std::vector<int> Controller::id_list;

void Controller::add_customer(std::string first_name, std::string last_name, std::string pic_name, std::string status, bool is_privileged){
	Customer new_customer = Customer(first_name, last_name, pic_name);
	new_customer.setStatus(status, is_privileged);
	id_list.push_back(atoi(new_customer.getIdNumber().substr(1).c_str()));
	if (is_privileged)
		MobileDevice::sendMyRequest(gcnew System::String(("RC" + first_name + "*" + last_name).c_str()));
	else
		MobileDevice::sendMyRequest(gcnew System::String(("RT" + first_name + "*" + last_name).c_str()));
}

void Controller::add_staffMember(std::string first_name, std::string last_name, std::string employee_level, std::string pic_name){
	StaffMember new_staffMember = StaffMember(first_name, last_name, employee_level, pic_name);
	id_list.push_back(atoi(new_staffMember.getIdNumber().substr(2).c_str()));
	MobileDevice::sendMyRequest(gcnew System::String(("RS" + first_name + "*" + last_name).c_str()));
}

int Controller::get_total_customers(){
	return Customer::getTotalCustomers();
}

int Controller::get_total_staffMembers(){
	return StaffMember::getTotalStaff();
}

void Controller::clear_all(){
	MobileDevice::sendMyRequest("I");
}

void Controller::send_detected(){

}

Controller::Controller(){
}

Controller::~Controller(){
}