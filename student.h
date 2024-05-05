#pragma once
#include "degree.h"
#include <iostream>
#include <string>

class Student{
public:
	 //Array of days to complete 3 courses
	const static int numberOfCourses = 3;
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[numberOfCourses];
	DegreeProgram degreeProgram;

public:
	//Create full constructor
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, 
			int age, int daysInCourse[], DegreeProgram degreeProgram); 
	
	//Create getters
	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Create setters
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDays(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print headers for student data table
	static void printHeader();
	//Print specific student data
	void print();
};