/* Name:Uche Hadassah
* This project reads in the data for 2 employees and displays it
*/
#include<iostream>
using namespace std;
class Employee
{
public:
	Employee();//Constructor without parameters
	Employee(int employeeID, double employeePayRate, int maxHoursPerWeek);//Constructor with parameters

	void enterData();//function to enter data for new employee
	void displayData();//function to display data of an employee
private:
	int ID;
	double payRate;
	int hours;
};

//implementation of the Employee class
Employee::Employee():ID(0),payRate(0.0),hours(0){}

Employee::Employee(int employeeID, double employeePayRate, int maxHoursPerWeek)
	:ID(employeeID), payRate(employeePayRate), hours(maxHoursPerWeek){}

//Function to get employee data
void Employee::enterData()
{
	cout << "Enter Employee ID: ";
	cin >> ID;

	cout << "Enter Pay Rate: ";
	cin >> payRate;

	cout << "Enter Maximum Hours per Week: ";
	cin >> hours;
}

//Function to show employee data
void Employee::displayData()
{
	cout << "Employee ID: " << ID << endl;
	cout << "Pay Rate: $" << payRate << " per hour" << endl;
	cout << "Maximum Hours per Week: " << hours << " hours" << endl;
}
int main()
{
	// Declare two objects of type Employee
	Employee emp1;//The constructor without parameters will be called
	Employee emp2(2,35.0,20);//The constructor with parameters will be called
	
	cout << "Enter the data for employee 1" << endl;
	emp1.enterData();
	cout << "Enter the data for employee 2" << endl;
	emp2.enterData();
	cout << "The data for the two employees are as follows:" << endl;
	emp1.displayData();
	cout << "--------------------" << endl;
	emp2.displayData();
	cout << "--------------------" << endl;
	return 0;
}