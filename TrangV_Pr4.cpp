/*
 * Class: CMSC140 CRN
 * Instructor: Najmeh Abedzadeh
 * Project 4
 * Description: Write a program that calculates
 the average number of days a company's employees are absent during the year and outputs a report on a file named "employeeAbsences.txt".
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: TRANG VU THI THU


 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)

 Funtion NumOfEmployees
    Prompt user
	Get number of employees from user
	While number of employee < 0
	   Display error message
	   Prompt user
	   Get number of employees from user
	Return number of employees
 Function TotDaysAbsent
    Open output file
	For i=0, i<number of employee, i++
	   Prompt user
	   Get employee's ID
	   Prompt user
	   Get employee absent days
	   While absent days<0
	       Display error message
		   Prompt user
	       Get number of absent days from user
	   Calculate sum of absent days
       Display data into output file
     Return sum
 Function AverageAbsent
     Return absent days/employees
 Call NumOfEmployees
 Call TotDaysAbsent
 Call AverageAbsent
 Write total absent days and average absent days to output file
 Close output file
 End program
 
*/

#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;

ofstream outputFile;                                  //Global variables													
int employee_Num, ID, AbsentDays, sum = 0;                    
         

int NumOfEmployees()
{
	cout << "Please enter the number of employees in the company: ";
	cin >> employee_Num;

	while (employee_Num < 1)                         //Validating number of employees
	{
		cout << "Error! Please enter again. The number of employee should be at least 1.\n";
		cout << "Please enter the number of employees in the company: ";
		cin >> employee_Num;
	}
	return employee_Num;
}


int TotDaysAbsent()
{
	outputFile.open("employeeAbsences.txt");       //Open output file
	outputFile << "EMPLOYEE ABSENT REPORT\n" << "Employee ID   Absent days\n";
	for (int i = 0; i < employee_Num; i++)         //Get employee IDs, number of days absent, write to output file and calculate total number of absent days
	{
		cout << "Please enter the an employee ID: ";
		cin >> ID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> AbsentDays;
		while (AbsentDays < 0)                     //Validating number of absent days
		{
			cout << "Error! Please enter again. The number of absent days should be at least 0.\n";
			cout << "Please enter the number of days this employee was absent: ";
			cin >> AbsentDays;
		}
		sum += AbsentDays;

		outputFile << "  " << ID << "		" << AbsentDays << endl;
	}
	return sum;
}

double AverageAbsent()
{
	return (double)sum / (double)employee_Num;
}


int main()
{
	double averageAbsent;

	NumOfEmployees();                          //Calling the functions
	TotDaysAbsent();
	averageAbsent = AverageAbsent();
	
	outputFile << "\nThe " << employee_Num << " employees were absent a total of "
		<< sum << " days.\n";
	outputFile << "The average number of days absent is " << setprecision(1) << fixed << showpoint << averageAbsent << " days.\n";
	outputFile << "Programmer's name: TRANG VU THI THU\n" << "Due date: Nov 23 2019";
	outputFile.close();

	cout << "Programmer's name: TRANG VU THI THU\n" << "Due date: Nov 23 2019";
	return 0;
}
