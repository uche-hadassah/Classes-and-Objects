/* a) Construct a class named Employee that can be used to represent an employee of a 
company. Each employee is defined by an integer ID number, a pay rate, and the 
maximum number of hours the employee should work each week. The services 
(functions) provided by the class should be: the ability to enter data for a new 
employee, the ability to display data for an employee. (Your class should include two 
constructors: one with parameters and one without parameters).
b) Include the class definition above in a program that declares two objects of type 
Employee: emp1 and emp2 (using a different constructor for each one), and asks the 
user to enter the required data for each of the two employees and then diplays the data 
of each one.*/#include<iostream>using namespace std;class Employee{public:	Employee();//Constructor without parameters	Employee(int employeeID, double employeePayRate, int maxHoursPerWeek);//Constructor with parameters	void enterData();//function to enter data for new employee	void displayData();//function to display data of an employeeprivate:	int ID;	double payRate;	int hours;};Employee::Employee():ID(0),payRate(0.0),hours(0){}Employee::Employee(int employeeID, double employeePayRate, int maxHoursPerWeek)	:ID(employeeID), payRate(employeePayRate), hours(maxHoursPerWeek){}void Employee::enterData(){}