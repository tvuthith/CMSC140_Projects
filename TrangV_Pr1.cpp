/* 
 * TRANG VU THI THU
 * Class: CMSC140 
 * Instructor: Najmeh Abedzadeh
 * Project 1
 * Description: protype robot scripting
 * Due Date: Oct 5, 2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Trang Vu Thi Thu


 * Pseudocode or Algorithm for the program:
  1. Ask for user's name
  2. Get user's name as input
  3. Ask for age number of pet or someone
  4. Get age as input
  5. Months=Age*12
  6. Days=Months*30
  7. Hours=Days*24
  8. Minutes=Hours*60
  9. Seconds=Minutes*60
  10. Print Months, Days, Hours, Minutes, Seconds
  11. Dog year=Age*7
  12. Print Dog year
  13. Gold fish year=Age*5
  14. Print Gold fish year
  15. Print user name
  16. Ask for first number
  17. Get first number as input
  18. ASk for second number
  19. Get second number as input
  20. sum= first number + second number
  21. print sum
  22. quotient= first number/second number
  23. print quotient.
 
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string RobotName = "Bot", UserName;
	unsigned long long int age, months, days, hours, minutes, seconds;
    int num1, num2;
	const string ProName = "Trang Vu", DueDate = "5/10/19";
	const int AssignNum = 1, One_Dog_Year = 7, Days_In_Month = 30, Gold_fish_Age = 5;
	
	cout << "**************** Robot Prototype Scripting ********************\n";
	cout << "\nHello, welcome to Montgomery College! My name is " << RobotName 
		<< ". May I have your name?\n" ;                                          //get user's name
	getline(cin, UserName);
	
	cout << "Nice to have you with us today, " << UserName << "!\n"
		<< "Let me impress you with a small game.\n" << "Give me the age of an important person or a pet to you.\n"
		<< "Please give me only number: \n";
	cin >> age;                                                                   //get a person or a pet's age
	
	months = age * 12;                                                            //calculate months
	days = months * 30;                                                           //calculate days
	hours = days * 24;                                                            //calculate hours
	minutes = hours * 60;                                                         //calculate minutes
	seconds = minutes * 60;                                                       //calculate seconds

	cout << "\nYou have entered  " << age << ".\n" << "If this is for a person, the age can be expressed as: \n" 
		<< age << " years\n"
		<< "or " << months << " months\n" << "or about " << days << " days\n" << "or about " << hours 
		<< " hours\n" << "or about " << minutes << " minutes\n" << "or about "
		<< seconds << " seconds.\n";                                               //print months,days,hours,minutes,seconds
	cout << "If this is for a dog, it is " << age * One_Dog_Year << " years old in human age.\n";       //calculate dog's age to human's age
	cout << "If this is for a goldfish, it is " << age * Gold_fish_Age << " years old in human age.\n"; //calculate fish's age to human's age

	cout << "\nLet's play another game, " << UserName << ". Give me a whole number.\n";
	cin >> num1;                                                                  //get first number
	cout << "Very well. Give me another whole number.\n";
	cin >> num2;                                                                  //get second number
	//calculate sum
	cout << "Using the operator '+' in C++, the result of " << num1 <<"+" << num2 << " is " << num1 + num2 << ".\n";
	//calculate quotient
	cout << "Using the operator '/' in C++, the result of " << num1 << "/" << num2 << " is " << num1 / num2 << endl;
	cout << setprecision(1) << fixed << showpoint;                                //set only 1 number appears after decimal point
	cout << "however, the result of " << static_cast<double>(num1) << "/" << static_cast<double>(num2) << " is about " 
		<< static_cast<double>(num1)/(num2) << ".\n";
	cout << "\nThank you for testing my program!!" << "\nPROGRAMMER: " << ProName << "\nCMSC140 Common Project " 
		<< AssignNum << "\nDue date: " << DueDate;
	
	return 0;

}