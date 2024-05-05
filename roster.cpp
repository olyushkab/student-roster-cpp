#include "roster.h"

Roster::Roster(){}

void Roster::parse(std::string studentData){
	//Parse all student data one by one
	int right = studentData.find(",");
	std::string studentID = studentData.substr(0, right);

	int left = right + 1;
	right = studentData.find(",", left);
	std::string firstName = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	std::string lastName = studentData.substr(left, right - left);

    left = right + 1;
	right = studentData.find(",", left);
	std::string emailAddress = studentData.substr(left, right - left);

    left = right + 1;
	right = studentData.find(",", left);
	int age = std::stoi(studentData.substr(left, right - left));

    left = right + 1;
	right = studentData.find(",", left);
	int days1 = std::stoi(studentData.substr(left, right - left));

    left = right + 1;
	right = studentData.find(",", left);
	int days2 = std::stoi(studentData.substr(left, right - left));

    left = right + 1;
	right = studentData.find(",", left);
	int days3 = std::stoi(studentData.substr(left, right - left));

	//Set default value for degree program type
	DegreeProgram degreeProgram = SECURITY;
	//Check the last character of degree program type to identify which program particular student is in
	if (studentData.back() == 'K') degreeProgram = NETWORK; 
	else if (studentData.back() == 'E') degreeProgram = SOFTWARE;

	//Add student object
	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, 
	int age, int days1, int days2, int days3, DegreeProgram degreeProgram){
	int days[3] = {days1, days2, days3};
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, days, degreeProgram);
}

void Roster::printAll(){
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++){
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	std::cout << std::endl;
}

void Roster::printInvalidEmails(){	
	bool invalid = false;
	for (int i = 0; i <= Roster::lastIndex; i++){
		std::string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find("@") == std::string::npos || (emailAddress.find('.') == std::string::npos) || (emailAddress.find(' ') != std::string::npos)){
			invalid = true;
			std::cout << emailAddress << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
		}
	}
	if (!invalid) std::cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID){
	for (int i = 0; i <= Roster::lastIndex; i++){
		if (classRosterArray[i]->getStudentID()==studentID){
			std::cout << " Student ID: " << studentID << "," << " averages " 
					<< (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] 
					+ classRosterArray[i]->getDaysInCourse()[2])/3 << " days in a course" << std::endl;
			}
	}
	std::cout << std::endl;
}

void Roster::remove(std::string studentID){
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++){
		if (classRosterArray[i]->getStudentID() == studentID){
			success = true;
			if (i < numberOfStudents - 1){
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numberOfStudents - 1];
				classRosterArray[numberOfStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success){
		std::cout << studentID << " has been removed from the roster" << std::endl;
		this->printAll();
	} else {
		std::cout << studentID << " studentID was not found" << std::endl;
	}
}

//Call destructor to remove objects that were created dynamically
Roster::~Roster(){
	std::cout << "Calling destructor" << std::endl;
	for (int i = 0; i < numberOfStudents; i++){
		std::cout << "Removing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
		}
}













