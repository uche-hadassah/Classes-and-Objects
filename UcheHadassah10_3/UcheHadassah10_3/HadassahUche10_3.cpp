/*a) Construct a class named Student consisting of a student id (string), an array of 5 
floating-point grades, and an integer representing the total number of grades entered. 
The constructor should initialize the numerical data members to zero. Included in the 
class should be member functions to: (i) enter the student ID number, (ii) enter a 
single test grade and update the total number of grades entered, (iii) display all the 
data of the student, and (iv) compute and display the average grade along with the
student ID.
b) Include the class constructed above within the context of a complete program. 
Your program should declare one object of type Student and accept and display 
data for this object in order to test all the member functions.*/
#include<iostream>
using namespace std;
class Student
{
public:
	Student(string ID, double Grades[], int totalNumber);//Constructor
	void enterID();
	void enterTestGrade();
	void displayStudentData();
	void averageGrade();
private:
	string studentID;
	double grades[5];
	int total;
};
//Constructor definition
Student::Student(string ID, double Grades[], int totalNumber)
	:studentID(ID),total(totalNumber) 
{
	for (int i = 0; i < 5; i++)
	{
		grades[i] = Grades[i];
	}
}
