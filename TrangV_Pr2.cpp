/*
 * Class: CMSC140 CRN
 * Instructor: Najmeh Abedzadeh
 * Project 2
 * Description: Convert from Metric system to Imperial System
 * Due Date: Oct 19, 2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Trang Vu Thi Thu


 * Pseudocode or Algorithm for the program:
	
 1. Ask user for country name
 2. Get country name as input
 3. Ask user for choice
 4. Get choice as input
 5. If choice = 1
 6. 	ask user for temperature in Celcius
 7. 	get temperature in Celcius as input
 8. 	Farenheiet = Celcius*9/5+32
 9. 	print Celcius
 10.	break, go to 33
 11. Else If choice = 2
 12.	ask user for distance kim Kilometers
 13. 	get distance in kilometers as input
 14. 	If distance < 0
 15.		print Error
 16.	Else 
 17.		Miles = Kilometers*0.6
 18.		print Miles
 19.		break, go to 33
 20. Else If choice = 3
 21.	ask user for weight in Kilograms
 22. 	get weight as input
 23.	If weight < 0 
 24.		print Error
 25. 	Else 
 26.		Pounds = Kilogram*2.2
 27.		print Pounds
 28.		break, go to 33
 29. Else If choice = 4
 30. 	break, go to 33
 31. Else
 32.	print "Only choose 1-4"
 33. Print Country name
 34. End

*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	int choice;
	string countryName;
	double temperature, distance, weight;

	// Ask for country name
	cout << "Enter a country name: ";
	getline(cin, countryName);

	cout << "\nConverter Toolkit\n" << "-------------------\n" << "1. Temperature Converter\n"
		<< "2. Distance Converter\n" << "3. Weight Converter\n" << "4. Quit\n"; //output menu
	// Ask for user's choice
	cout << "\nEnter your choice (1-4): "; // Get user's choice
	cin >> choice;
	switch (choice)
	{
	case 1: cout << "\nEnter your temperature in Celcius (such as 24): ";
		cin >> temperature;                     // Get temperature from user
		temperature = temperature * 9 / 5 + 32; // Calculate temperature in Farenheit
		cout << setprecision(0) << fixed;      
		cout << "\nIt is " << temperature << " in Fahrenheit\n"; // Display Farenheit temperature
		break;

	case 2: cout << "Enter yout distance in Kilometers (such as 18.5): ";
		cin >> distance;                       // Get distance from user
		if (distance < 0) cout << "Error, distance must be greater than 0\n"; // Error message when distance < 0
		else
			cout << "\nIt is " << setprecision(2) << fixed << showpoint <<
			distance * 0.6 << " in miles\n";  // Calculate and display distance in miles
		break;

	case 3: cout << "Enter your weight in Kilograms (such as 45): ";
		cin >> weight;                        // Get weight from user
		if (weight < 0) cout << "Error, weight must be greater than 0\n"; // Error message when weight < 0
		else
			cout << "\nIt is " << setprecision(1) << fixed << showpoint <<
			weight * 2.2 << " in pounds\n";  // Calculate and display weight in pounds
		break;
		
	case 4:                                 // Case 4: quit
		break;

	default: cout << "Please only enter from 1 to 4\n"; // Error message when user enter something different than 4

	}
	cout << "\n" << countryName << " sounds fun!\n"; // Output country name
	
	cout << "\nThank you for testing my program!!\n" << "PROGRAMMER: Trang Vu Thi Thu\n"
		<< "CMSC140 Common Project 2\n" << "Due date: 9/24/2019\n";

	return 0;
}
