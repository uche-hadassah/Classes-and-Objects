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
//Function to get student ID
void Student::enterID()
{
	cout << "Enter student ID:";
	cin >> studentID;
}

//Function to enter a single test grade and update the total number of grades entered
void Student::enterTestGrade()
{
	if (total < 5)
	{
		cout << "Enter Test Grade " << total + 1 << ": ";
		cin >> grades[total];
		total++;
	}
	else
	{
		cout << "Cannot enter more than 5 grades." << endl;
	}
}

//Function to display all the data of the student
void Student::displayStudentData()
{
	cout << "Student ID: " << studentID << endl;
	cout << "Test Grades: ";
	for (int i = 0; i < total; ++i) 
	{
		cout << grades[i] << " ";
	}
	cout << endl;
}

//Function to compute and display the average grade along with the student ID
void Student::averageGrade()
{
	if (total > 0)
	{
		double sum = 0;
		for (int i = 0; i < total; ++i) {
			sum += grades[i];
		}
		double average = sum / total;
		cout << "Average Grade: " << average << endl;
	}
	else
	{
		cout << "No grades entered yet." << endl;
	}
}