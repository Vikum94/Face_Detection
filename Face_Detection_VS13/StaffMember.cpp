#include "StaffMember.h"
#include <string>

#include <msclr\marshal_cppstd.h>

//using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

using namespace std;
int StaffMember::totalStaff = 0;

std::string StaffMember::getName() { return firstName+lastName; }
std::string StaffMember::getIdNumber() { return idNumber; }
std::string StaffMember::getPicturePath() { return picturePath; }
void StaffMember::setPicturePath(string picturePath) { this->picturePath = picturePath; }
void StaffMember::setEmployeeLevel(string employeeLevel){ this->employeeLevel = employeeLevel; }
int StaffMember::getTotalStaff(){ return totalStaff; }
void StaffMember::setTotalStaffMembers(int total_staff){ StaffMember::totalStaff = total_staff; }
std::string StaffMember::getStaffType(){ return staffType; }
std::string StaffMember::getFirstName(){ return firstName; }
std::string StaffMember::getSurname(){ return lastName; }
std::string StaffMember::getEmployeelevel(){ return employeeLevel; }
void StaffMember::setId(std::string id){ this->idNumber = id; }

void StaffMember::setIdByDatabase(){
	String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT MAX(entry) FROM face_detection.StaffInfo", conDataBase);
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
	StaffMember::setId("SM" + std::to_string(num));
}

void StaffMember::setTotalStaffByDataBase(){
	String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT MAX(entry) FROM face_detection.StaffInfo", conDataBase);
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
	//inKey.erase(0, 1);
	//cout << "cuhcufh " << inKey << endl;
	int id = std::stoi(inKey);
	cout << "setting total staff : " << id << endl;
	StaffMember::setTotalStaffMembers(id);
}

void StaffMember::addToDatabase(){
	//add staff member to the database
	String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("insert into face_detection.StaffInfo(id,first_name,last_name,EmployeeLevel,Picture_name) values('" + 
		gcnew String(StaffMember::getIdNumber().c_str()) + "','" + 
		gcnew String(StaffMember::getFirstName().c_str()) + "','" + 
		gcnew String(StaffMember::getSurname().c_str()) + "','" + 
		gcnew String(StaffMember::getEmployeelevel().c_str()) + "','" + 
		gcnew String(StaffMember::getPicturePath().c_str()) + "');", conDataBase);
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

StaffMember::StaffMember(string firstName, string lastName, string employeeLevel, string picturePath) {
	StaffMember::totalStaff += 1;
	this->firstName = firstName;
	this->lastName = lastName;
	this->employeeLevel = employeeLevel;
	this->idNumber = "SM" + to_string(StaffMember::totalStaff+100);
	this->picturePath = picturePath;
	//StaffMember::staffList.push_back(idNumber);

	ofstream file;
	file.open("C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/at.txt",std::ios_base::app);
	file << "C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/" + picturePath + ";" + idNumber.substr(2) + "\n";
	file.close();
}

StaffMember::StaffMember() {
	StaffMember::totalStaff += 1;
}

StaffMember::~StaffMember() {
	//StaffMember::totalStaff -= 1;
}