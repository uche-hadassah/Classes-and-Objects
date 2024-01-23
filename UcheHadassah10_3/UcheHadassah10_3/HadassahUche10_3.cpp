/*Name:Uche hadassah
This orogram receives a student's info and grades and prints them out*/
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

//Main function
int main()
{
	double initialGrades[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	//Declare an object of type student
	Student student("DefaultID", initialGrades, 0);
	// Test member functions
	student.enterID();
	for(int i = 0;i<5;i++)
	{
		student.enterTestGrade();
	}
	student.displayStudentData();
	student.averageGrade();
	return 0;
}