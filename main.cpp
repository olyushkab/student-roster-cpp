#include "roster.h"

int main()
{
	std::cout << "Add header data" << std::endl;
	std::cout << "Language used: C++" << std::endl;
	std::cout << "Add header data" << std::endl;
	std::cout << "Name: Olga Odarenko" << std::endl << std::endl;

	const std::string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Olga,Odarenko,oodaren@wgu.edu,29,15,20,30,SOFTWARE" 
		};

	const int numberOfStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numberOfStudents; i++) classRoster.parse(studentData[i]);
	std::cout << "Class Roster: " << std::endl;
	classRoster.printAll();
	std::cout << std::endl;
	
	std::cout << "Displaying invalid Emails:" << std::endl << std::endl;
	classRoster.printInvalidEmails();
	std::cout << std::endl;

	std::cout << "Average days in course for each student: " << std::endl << std::endl;
	for (int i = 0; i < numberOfStudents; i++){
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	std::cout << std::endl;
	
	std::cout << "Displaying by degree program: " << degreeProgramArray[2] << std::endl << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << std::endl;
	
	std::cout << "Removing Student A3" << std::endl;
	classRoster.remove("A3");
	std::cout << std::endl;

	for (int i = 0; i < numberOfStudents; i++) classRoster.parse(studentData[i]);
	std::cout << "Class Roster: " << std::endl;
	classRoster.printAll();
	std::cout << std::endl;

	std::cout << "Removing Student A3 again" << std::endl;
	classRoster.remove("A3");
	std::cout << std::endl;

	system("pause");
	return 0;
}
