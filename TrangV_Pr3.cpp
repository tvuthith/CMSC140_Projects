/*
 * Class: CMSC140 
 * Instructor: Najmeh Abedzadeh
 * Project 3
 * Description: testing the ability of using loops by writing a program that 
 calculates the occupancy rate and the total hotel income for one night and displays this information 
 * Due Date: Nov 9 2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: TRANG VU THI THU

 * Pseudocode or Algorithm for the program:
   Get location from input
   Get number of floor from input
   while number of floor is not in [1,5]
      Display error message
	  Get the number of floors from input again
   End while
   Intitial floor count = 1
   For the floor count to be <= number of floor
      Get the input of number of room on that floor
	  While number of room is not in [1,30}
	      Display error message
		  Get the number of room from input again
	  End while
      Do
	      Get the number of occupied Rooms
	  While total occupied rooms do not exceed number of room on that floor
	  If Floor count = 1, 
	      let least room be number of room on 1st floor
	  else
	      if number of room is smaller than the least room from the last if
		  then least room be number of on that floor
   calculate all totals
   End for
   Display income and totals
   Display rate
      if rate < 60
	  print warning message
   End.
 
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	int Floor_Num, Floor_count, Room_Num, occupied_Single, occupied_Double, occupied_King,
		occupied_Suite, total_Occupied, income, min_Room_Num{}, min_Floor_count{};
	int sum_Single = 0, sum_Double = 0, sum_King = 0, sum_Suite = 0, sum_Room = 0, sum_Occupied = 0;
	double rate;
	const int project_num = 3;
	const string PRGMMNM = "Trang Vu Thi Thu", DueDate = "Nov 9 2019";
	string location;

	cout << "=========================================================================================================\n"
		<< setw(50) << "BlueMont Hotel\n"
		<< "=========================================================================================================\n";
	
	cout << "Enter the location of this hotel chain: ";
	getline(cin, location);
	cout << "\nEnter total number of floors of this hotel: ";
	cin >> Floor_Num;
	
	while (Floor_Num > 5 || Floor_Num < 1)  //loop to check the condition that # floor should be in the interval [1,5]
	{
	cout << "Number of floors should be between 1 and 5 !! Please try again.\n" //error message if condition is not met
		<< "\nEnter total number of floors of this hotel: ";
	cin >> Floor_Num;
	}
	
	for (Floor_count = 1; Floor_count <= Floor_Num; Floor_count++) //loop to calculate number of rooms on each floor
	{
		do //loop to calculate number of rooms of different kinds
		{
			cout << "\nEnter number of room in the " << Floor_count << "th floor: ";
			cin >> Room_Num;
			while (Room_Num > 30 || Room_Num < 1) //loop to check the condition that # floor should be in the interval [1,30]
			{
				cout << "Number of rooms should be between 1 and 30!! Please try again.\n"
					<< "\nEnter number of room in the " << Floor_count << "th floor: ";
				cin >> Room_Num;
			}
			cout << "How many SINGLE rooms are occupied in the " << Floor_count << "th floor: ";
			cin >> occupied_Single;
			cout << "How many DOUBLE rooms are occupied in the " << Floor_count << "th floor: ";
			cin >> occupied_Double;
			cout << "How many KING rooms are occupied in the " << Floor_count << "th floor: ";
			cin >> occupied_King;
			cout << "How many SUITE rooms are occupied in the " << Floor_count << "th floor: ";
			cin >> occupied_Suite;
			total_Occupied = occupied_Single + occupied_Double + occupied_King + occupied_Suite;
			if(total_Occupied > Room_Num) 
				cout << "The total number of occupied rooms exceeds the number of total rooms!! Please try again.\n";
		} while (total_Occupied > Room_Num); //loop to check if number of occupied rooms exceed number of total room
		
		if (Floor_count == 1) //used to compare which room has the smallest number of room
		{
			min_Room_Num = Room_Num;
			min_Floor_count = Floor_count;
		}
		
	    else if (Room_Num < min_Room_Num)
		{
			min_Room_Num = Room_Num;
			min_Floor_count = Floor_count;
		}
		
		sum_Single += occupied_Single; //calculate number of occupied Single room in the hotel
		sum_Double += occupied_Double; //calculate number of occupied Double room in the hotel
		sum_King += occupied_King; //calculate number of occupied King room in the hotel
		sum_Suite += occupied_Suite;//calculate number of occupied Suite room in the hotel
		sum_Room += Room_Num; //calculate total number of rooms in the hotel
		sum_Occupied += total_Occupied;////calculate number of occupied room in the hotel
		
	}

	cout << "==========================================================================\n"
		 << "\t\t\tBlueMont Hotel located in " << location << endl
		<< "\n\t\t\tTODAY'S ROOM RATE<US$/night>\n"
		<< "\tSingle Room" << "\tDouble Room" << "\t  King Room" << "\t Suite Room\n" 
		<< "\t\t 60" << "\t\t 75" << "\t\t100" << "\t\t150\n"
		<< "==========================================================================\n";
	income = sum_Single * 60 + sum_Double * 75 + sum_King * 100 + sum_Suite * 150;
	cout << "Hotel income: "<< income;
	cout << "\nTotal # of rooms: " << sum_Room;
	cout << "\nTotal # of occupied rooms: " << sum_Occupied;
	cout << "\nTotal # of unoccupied rooms: " <<  sum_Room - sum_Occupied;
	rate = (double)sum_Occupied / (double)sum_Room; //calculate the rate
	cout << "\nOccupancy rate: " << setprecision(2) << fixed << showpoint << rate*100 << "%\n"; //display rate

	cout << "\n" << min_Floor_count << "th floor with " << min_Room_Num << " rooms has the least # of room.\n";
	if (rate*100 < 60) 
		cout << "Need to improve Hotel occupancy rate!!\n";

	cout << "\nThank you for testing my program!!\n";
	cout << "PROGRAMMER: " << PRGMMNM << endl;
	cout << "CMSC140 Common Project " << project_num << endl;
	cout << "Due date: " << DueDate;
	return 0;
}