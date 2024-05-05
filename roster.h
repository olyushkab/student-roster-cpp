#pragma once
#include "student.h"
#include "degree.h"

class Roster{
public:
	const static int numberOfStudents = 5;
	//Create an array of pointers to hold data in student table
	Student* classRosterArray[numberOfStudents]; 
	int lastIndex = -1;
public:
	//constructor
	Roster(); 
	//destructor
	~Roster(); 
	void parse(std::string row);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, 
		int days1, int days2, int days3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};