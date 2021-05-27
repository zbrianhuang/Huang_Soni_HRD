
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>
#include <sstream>
#include "Functions.h"

using namespace std;

//Empty Student Class Constructor
Student::Student() {

}
//Student Class Constructor with Name and # of Courses
Student::Student(string studentName, int numCourses) {
	this->studentName = studentName;
	this->numCourses = numCourses;
}

//Function to ask for the name of the student
void Student::setName() {
	while (true) {
		std::cout << "Enter student's full name: ";
		getline(cin, this->studentName);
		if (studentName.empty()) {
			std::cout << "Invalid Input\n";
		}
		else {
			break;
		}
	}
}

//Function to get the name of the student
string Student::getName() {
	return studentName;
}

//Function to ask the user for the number of courses
void Student::setCourses() {
	string sCourse = "";
	int result = 0;
	bool done = false;
	while (!done) {
		std::cout << "How many courses are you taking (Min = 1 and Max = 8): ";
		getline(cin, sCourse);
		std::istringstream is(sCourse);
		int len = sCourse.length();
		int decimal = 0;

		for (int j = 0; j < len; j++) {
			if (sCourse[j] == '.') {
				decimal = 1;
				break;
			}
		}
		if (!(is >> result) || decimal == 1) {
			std::cout << "Invalid input\n";
		}
		else {
			done = true;
		}
	}
	int course = stoi(sCourse);
	std::cin.clear();
	numCourses = course;
}

//Function to get the # of courses
int Student::getCourses() {
	return numCourses;
}

//Function to create a list of Course Objects
void Student::getCourseList() {
	//Creating a Course object with Name and Grade
	Course course;
	for (int i = 0; i < numCourses; i++) {
		course.setCourseName();
		course.setCourseGrade();
		//Adding to the Object List
		courses.push_front(course);
	}
}

//Function to Generate a 5% chance of a Discipline Issue
bool Student::getDisciplineIssue() {
	srand(time(NULL));
	double randGen = ((rand() % 100) + 1);
	if (randGen > 95) {
		disciplineIssue = true;
	}
	else {
		disciplineIssue = false;
	}
	return disciplineIssue;
}

//Function to the Average of the Grades
int Student::getAverage() {
	int sum = 0;
	for (int i = 0; i < courses.size(); i++) {
		//Obtaining the object in the list
		list<Course>::iterator it = courses.begin();
		advance(it, i);
		Course course = *it;
		//Getting the Grade and Adding to the sum
		int grade = course.getCourseGrade();
		sum += grade;
	}
	//Calculating, Rounding, and Returning the Average
	double avg = sum / (courses.size());
	this->average = round(avg);
	return this->average;
}

//Function  to Check Elligibility for Honor Roll
bool Student::getHonorRoll() {
	if ((this->average >= 90) & (this->numCourses >= 5) & (this->disciplineIssue == 0)) {
		this->honorRoll = true;
		return 1;
	}
	else {
		this->honorRoll = false;
		return 0;
	}
}

//Function to Print the Information of the Student
void Student::printInfo() {
	std::cout << "\n";
	std::cout << "Name: " << studentName << "\n";
	std::cout << "\n";
	std::cout << "Class                   Grade\n";
	//Printing out the Table with Corresponding Courses and Grades
	for (int i = courses.size() - 1; i >= 0; i--) {
		list<Course>::iterator it = courses.begin();
		advance(it, i);
		Course course = *it;
		string name = course.getCourseName();
		std::cout << name;
		for (int j = 0; j < 25- name.length(); j++) {
			std::cout << " ";
		}
		std::cout << course.getCourseGrade() << "\n";
	}
	//Printing out the Average, Disciplinary Infraction, and Honor Roll Elligibility
	std::cout << "\n";
	std::cout << "Average is: " << this->average << "\n";
	std::cout << "\n";
	if (this->disciplineIssue == 1) {
		std::cout << "Disciplinary Infraction: YES\n";
	}
	else {
		std::cout << "Disciplinary Infraction: NO\n";
	}
	std::cout << "\n";
	if (this->honorRoll == 1) {
		std::cout << "Congratulations " << this->studentName << "! You have made the honor roll.\n";
	}
	else {
		std::cout << "I'm sorry " << this->studentName << " but you didn't qualify for the honor roll.\n";
	}
}

//Course Contructor
Course::Course() {

}

//Course Contructor with Course Name and Grade
Course::Course(string courseName, int courseGrade) {
	this->courseName = courseName;
	this->courseGrade = courseGrade;
}

//Function to as the User for the Course Name
string Course::setCourseName() {
	string courseName = "abcdefghijklmnopqrstuvwxyz";
	//Running a While Loop until Valid Input is Given
	while (courseName.length() > 20 || courseName.empty()) {
		std::cout << "Course Name (20 characters): ";
		getline(cin,courseName);
		if (courseName.length() > 20) {
			std::cout << "Invalid input\n";
		}
		else if (courseName.empty()) {
			std::cout << "\n";
		}
		else {
			this->courseName = courseName;
			return courseName;
		}
		cin.clear();
	}
}

//Function to get the Course Name
string Course::getCourseName() {
	return courseName;
}

//Function to as the User for the Course Grade
int Course::setCourseGrade() {
	int grade = 121;
	int c = 0;
	int charordec = 0;
	//While Loop runs until valid input is given
	while (grade < 0 || grade > 120 || charordec == 1) {
		std::cout << "Course Grade (0-120): ";
		string cGrade;
		std::cin >> cGrade;
		charordec = 0;
		//Error Trapping for Non-Numeric Input
		for (int i = 0; cGrade[i] != '\0'; i++) {
			if (!isdigit(cGrade[i]))
				charordec = 1;
		}
		if (charordec == 0) {
			grade = stoi(cGrade);
			if ((grade > 0) & (grade < 120)) {
				this->courseGrade = grade;
				return grade;
			}
		}
	}
}

//Function to Return the Course Grade
int Course::getCourseGrade() {
	return courseGrade;
}
