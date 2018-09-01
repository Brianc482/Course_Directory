#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Course_Directory.h"

using namespace std;

Course_Directory::Course_Directory(){
    courseName;
    courseNum;
    numStudents;
    IDs;
    numberOfDepts;
}

Course_Directory courses[1001];

void Course_Directory::run(string filename){
    ifstream file;
    file.open("input.txt");
    int numberOfDepts;
    file >> numberOfDepts;
	char *token;
	int i = 0, j;
	if (!file.fail()) {
		std::string line, temp;
		while (getline(file, line)) {
			j = 0;
			char *str = const_cast<char *>(line.c_str());
			token = strtok(str, " ");
			while (token != NULL)
			{
				if (j == 0)
					strcpy(courseName[i].Course_Directory(), token);
				else if (j == 1)
					courses[i].courseNum = atoi(token);
				else if (j == 2)
					courses[i].numStudents = atoi(token);
				else{
					courses[i].IDs[j - 3] = atoi(token);
				}
				j++;
				token = strtok(NULL, " ");
			}
			i++;
		}
		file.close();
	}
	else{
            cout << "File not found." << endl;
    }
	//menu
	Course_Directory next;
    next.displayMenu();
}
void Course_Directory::displayMenu(){
	cout << "1.Print all courses" << endl;
	cout << "2.Print all courses for a department" << endl;
	cout << "3.Print roster for a course" << endl;
	cout << "4.Print the largest class" << endl;
	cout << "5.Swap two classes" << endl;
	cout << "6.Print schedule for a student" << endl;
	cout << "7.Exit" << endl;

	char dept[50], dept2[50];
	int courseNo, courseNo2, i, choice;

	while (choice != 7) {
		cout << "\nEnter your choice: ";
		cin >> choice;
		if (choice == 1)
            printAllCourses(*numberOfDepts);
		else if (choice == 2) {
			cout << "\nEnter department name:";
			cin >> dept;
		for(int j = 0; j < sizeof(dept); j++)
        {
            dept[j] = (toupper(dept[j]));
        }
			coursesInDept(dept, *numberOfDepts);
		}
		else if (choice == 3) {
			cout << "\nEnter course number:";
			cin >> courseNo;
			studentsInCourse(courseNo, i);
		}
		else if (choice == 4) {
			largestClass(*numberOfDepts);
		}
		else if (choice == 5) {
			cout << "\nEnter first department name :";
			cin >> dept;
			for(int j = 0; j < sizeof(dept); j++)
            {
                dept[j] = (toupper(dept[j]));
            }
			cout << "\nEnter first course number: ";
			cin >> courseNo;
			cout << "\nEnter second department name :";
			cin >> dept2;
            for(int k = 0; k < sizeof(dept2); k++)
            {
                dept2[k] = (toupper(dept2[k]));
            }
			cout << "\nEnter second course number: ";
            cin >> courseNo2;
			swap2(dept, courseNo, dept2, courseNo2, i);
		}
		else if (choice == 6) {
			int id;
			cout << "\nEnter a student Id:";
			cin >> id;
			schedule(id, i);
		}
	}
    cout << "Goodbye!\n";
}
void Course_Directory::printAllCourses(int len){
	for (int i = 0; i < len; i++)
		cout << "Course name: " << courses[i].courseName << ", Course number: " << courses[i].courseNum << endl;
		cout << len;
}
void Course_Directory::coursesInDept(char *dept, int len) {
	for (int i = 0; i < len; i++)
		if (strcmp(dept, courses[i].courseName) == 0)
			cout << "Course Name: " << courses[i].courseName << ", Course number: " << courses[i].courseNum << endl;
}

void Course_Directory::studentsInCourse(int courseNo, int len) {
	for (int i = 0; i < len; i++)
		if (courseNo == courses[i].courseNum) {
			for (int m = 0; m < courses[i].numStudents - 1; m++)
				cout << courses[i].IDs[m] << ",";
				cout << courses[i].IDs[courses[i].numStudents - 1] << endl;
		}
}

void Course_Directory::largestClass(int len) {
	int max = -999;
	for (int i = 0; i < len; i++) {
		if (courses[i].numStudents > max)
			max = courses[i].numStudents;
	}
	for (int i = 0; i < len; i++) {
		if (courses[i].numStudents == max){
			cout << "\nThe largest class is in department: " << courses[i].courseName
			<< ", and the course number is: " << courses[i].courseNum << "\n";
			cout << "The class currently has " << max << " students enrolled.\n";
		}
	}
}

void Course_Directory::swap2(char *firstDep, int firstNo, char *secondDep, int secondNo, int len) {
	Course_Directory temp;
	int firstIndex, secondIndex;
	for (int i = 0; i < len; i++) {
		if (strcmp(firstDep, courses[i].courseName) == 0 && courses[i].courseNum == firstNo)
			firstIndex = i;
		if (strcmp(secondDep, courses[i].courseName) == 0 && courses[i].courseNum == secondNo)
			secondIndex = i;
	}
	temp = courses[firstIndex];
	courses[firstIndex] = courses[secondIndex];
	courses[secondIndex] = temp;
}

void Course_Directory::schedule(int id, int len) {
	cout << "Courses student " << id << " is enrolled in: " << endl;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < courses[i].numStudents; j++)
			if (courses[i].IDs[j] == id)
				cout << courses[i].courseNum << " \n";
	}
}
Course_Directory::~Course_Directory(){
    delete [] courses;
}

