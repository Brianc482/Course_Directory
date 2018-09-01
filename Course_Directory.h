#ifndef COURSE_DIRECTORY_H
#define COURSE_DIRECTORY_H

#include <iostream>
using namespace std;

class Course_Directory{
	private:
        int* numberOfDepts;
        string filename;

	public:
        char courseName;
        int courseNum;
        int numStudents;
        int IDs;
        int* choice;
        void displayMenu();
        Course_Directory();
        //Course_Directory(const Course_Directory& original);
        ~Course_Directory();
        void run(string);
        void coursesInDept(char*, int);
        void studentsInCourse(int, int);
        void largestClass(int);
        void swap2(char*, int, char*, int, int);
        void schedule(int, int);
        void printAllCourses(int);
};
#endif //COURSE_DIRECTORY_H
