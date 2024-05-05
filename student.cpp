#include "student.h"

//Create full constructor
Student::Student(std::string studentId, std::string firstName, std::string lastName, 
				std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram){
	this->studentID = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) 
		this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

//Create getters
std::string Student::getStudentID() {return this->studentID;}
std::string Student::getFirstName() {return this->firstName;}
std::string Student::getLastName() {return this->lastName;}
std::string Student::getEmailAddress() {return this->emailAddress;}
int Student::getAge() {return this->age;};
int* Student::getDaysInCourse() {return this->daysInCourse;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

//Create setters
void Student::setStudentID(std::string studentID) {this->studentID = studentID;}
void Student::setFirstName(std::string firstName) {this->firstName = firstName;}
void Student::setLastName(std::string lastName) {this->lastName = lastName;}
void Student::setEmailAddress(std::string emailAddress) {this->emailAddress = emailAddress;}
void Student::setAge(int age) {this->age = age;}
void Student::setDays(int daysInCourse[]){
	for (int i = 0; i < 3; i++) 
		this->daysInCourse[i] = daysInCourse[i];
	}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

//Print headers for student data table
void Student::printHeader(){
	std::cout << "StudentID | FirstName | LastName | Email | Age | DaysInCourse | DegreeProgram" << std::endl;
}
//Print specific student data
void Student::print(){
	std::cout << this->getStudentID() << '\t' << this->getFirstName() << '\t' << this->getLastName() << '\t' 
			<< this->getEmailAddress() << '\t' << this->getAge() << '\t' << this->getDaysInCourse()[0] << ", " 
			<< this->getDaysInCourse()[1] << ", " << this->getDaysInCourse()[2] << '\t'
			<< degreeProgramArray[this->getDegreeProgram()] << std::endl;
}

