#include "Customer.h"
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

int Customer::totalCustomers=0;
int Customer::totalBadCustomers = 0;
int Customer::totalPrivileged = 0;

void Customer::setFirstName(std::string firstName) { this->firstName = firstName; }
void Customer::setsurname(std::string surname) { this->surname = surname; }
void Customer::setPicturePath(std::string picturePath) { this->picturePath = picturePath; }
void Customer::setId(std::string id){ this->idNumber = id; }
void Customer::setTotalCustomers(int total_customers){ Customer::totalCustomers = total_customers; }
void Customer::setCustomerType(bool cType){ this->isPrivileged = cType; }

	
std::string Customer::getFisrstName() { return firstName; }
std::string Customer::getSurname() { return surname; }
std::string Customer::getIdNumber() { return idNumber; }
std::string Customer::getStatus() { return this->status; }
int Customer::getTotalCustomers(){ return Customer::totalCustomers; }
std::string Customer::getPicturePath(){ return picturePath; }
int Customer::getCustomerType(){ if (isPrivileged) return 1; else return 0; }

void Customer::setTotalCustomersByDataBase(){
	String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT MAX(entry) FROM face_detection.CustomerInfo", conDataBase);
	MySqlDataReader^ myReader;
	conDataBase->Open();
	String^ content;
	std::string inKey;
	try{
		myReader = cmdDataBase->ExecuteReader();
		
		while (myReader->Read())
		{
			content = myReader->GetString(0);
			inKey = msclr::interop::marshal_as<std::string>(content);

		}
	}
	catch (Exception^ ex){
		inKey = "0";
	}
	int id = std::stoi(inKey);
	cout << "setting total customers : " << id << endl;
	Customer::setTotalCustomers(id);
}

void Customer::setIdByDataBase(){
	String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT MAX(entry) FROM face_detection.CustomerInfo", conDataBase);
	MySqlDataReader^ myReader;
	conDataBase->Open();
	
	String^ content;
	std::string inKey;
	try{
		myReader = cmdDataBase->ExecuteReader();
		while (myReader->Read())
		{
			content = myReader->GetString(0);
			inKey = msclr::interop::marshal_as<std::string>(content);
		}
	}
	catch (Exception^ e){
		inKey = "0";
	}
	//inKey.erase(0, 1);
	int num = std::stoi(inKey);
	num += 1;
	Customer::setId("C"+ std::to_string(num));
}

void Customer::addToDatabase(){
	//add customer to the database
	String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("insert into face_detection.CustomerInfo(id,first_name,last_name,status,Picture_name,CustomerType) values('" + 
		gcnew String(Customer::getIdNumber().c_str()) + "','" +gcnew String(Customer::getFisrstName().c_str()) + "','" + 
		gcnew String(Customer::getSurname().c_str()) + "','" + gcnew String(Customer::getStatus().c_str()) + "','" + 
		gcnew String(Customer::getPicturePath().c_str()) + "','" + gcnew int(Customer::getCustomerType()) + "');", conDataBase);
	MySqlDataReader^ myReader;

	try{
		conDataBase->Open();
		myReader = cmdDataBase->ExecuteReader();

		while (myReader->Read()){

		}


	}
	catch (Exception^ ex){
		MessageBox::Show(ex->Message);
	}
}

void Customer::setStatus(std::string status, bool isPrivileged) {
	this->status = status;
	this->isPrivileged = isPrivileged;
	if (this->isPrivileged && !isPrivileged) {
		Customer::totalPrivileged -= 1;
	}
	else if (!this->isPrivileged && isPrivileged){
		Customer::totalPrivileged += 1;
	}
}
Customer::Customer(std::string firstName, std::string surname, std::string picturePath) {
	Customer::totalCustomers += 1;
	this->firstName = firstName;
	this->surname = surname;
	this->picturePath = picturePath;
	this->idNumber = "C" + std::to_string(Customer::totalCustomers);
	//Customer::customerList.push_back(idNumber);

	std::ofstream file;
	file.open("C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/at.txt", std::ios_base::app);
	file << "C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/" + picturePath + ";" + idNumber.substr(1) + "\n";
	file.close();
}
Customer::Customer() {
	//Constructor for latter use
}

Customer::~Customer() {
	std::cout << this->getFisrstName() + this->getSurname() << "destroyed" << std::endl;
}

