/*
 * Class: CMSC140 
 * Instructor:  Najmeh Abedzadeh Kouhanestani
 * Project 5
 * Description: Write a program that simulates a magic square using 3 one dimensional parallel arrays of integer type. 
 * Due Date: Dec 14, 2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: TRANG VU THI THU
 * Pseudocode  for the program:
 start
 void fillArray 
      for each index as long as index < size 
	  get values of array 1
	  for each index as long as index < size
	  get values of array 2
	  for each index as long as index < size
	  get values of array 3
 void showArray
	  for each index as long as index < size 
	  display values of array 1
	  for each index as long as index < size
	  display values of array 2
	  for each index as long as index < size
	  display values of array 3
 bool checkRange
      checkRange returns true if and only if
	  for each index < size, value of array 1 >= 1 and <= 9
	  for each index < size, value of array 2 >= 1 and <= 9
	  for each index < size, value of array 3 >= 1 and <= 9
 bool checkUnique
      checkUnique returns true if and only if 
	  for each index < size, no value of array 1 duplicates
	  for each index < size, no value of array 2 duplicates
	  for each index < size, no value of array 3 duplicates
 bool checkRowSum
      checkRowSum returns true if and only if
	  for each index < size, sum of values of array 1 = sum of values of array 2 = sum of values of array 3 = 15
 bool checkColSum
      checkColSum returns true if and only if
	  sum of values at index 0 of array 1, array 2, array 3 
	  = sum of values at index 1 of array 1, array 2, array 3 
	  = sum of values at index 2 of array 1, array 2, array 3
	  = 15
 bool checkDiagSum
      check DiagSum returns true if and only if
	  sum of value at index 0 of array 1 + value at index 1 of array 2 + of value at index 2 of array 3
	  = sum of value at index 2 of array 1 + value at index 1 of array 2 + of value at index 1 of array 3
	  =15
 bool isMagicSquare
      isMagicSquare returns true if and only if
	  checkRange true && checkUnique true && checkRowSum true && checkColSum true && checkDiagSum true
 int main
     1. call fillArray
	 2. call showArray
	 3. if isMagicSquare is true
	       print "This is Lo Shu magic square"
	    else print "This is not Lo Shu magic square"
	 4. prompt to ask user if they want to try again
	 5. get answer from user
	 6. while answer is 'y' or 'Y'
	    repeat 1-5
 end
 */


#include<iostream>
using namespace std;

// Global constants 
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
	char tryagain;
	int magicArray1[COLS], magicArray2[COLS], magicArray3[COLS];

	fillArray(magicArray1, magicArray2, magicArray3, COLS);
	showArray(magicArray1, magicArray2, magicArray3, COLS);
	if (isMagicSquare(magicArray1, magicArray2, magicArray3, COLS))
		cout << "\nThis is a Lo Shu magic square";
	else cout << "\nThis is not a Lo Shu magic Square";

	cout << "\n\nDo you want to try again? (y or n) ";
	cin >> tryagain;

	while (tryagain == 'y' || tryagain == 'Y')
	{
		fillArray(magicArray1, magicArray2, magicArray3, COLS);
		showArray(magicArray1, magicArray2, magicArray3, COLS);
		if (isMagicSquare(magicArray1, magicArray2, magicArray3, COLS))
			cout << "\nThis is a Lo Shu magic square";
		else cout << "\nThis is not a Lo Shu magic Square";
		
		cout << "\n\nDo you want to try again? (y or n)";
		cin >> tryagain;
	}

	cout << "\n\nPROGRAMMER'S NAME: TRANG VU THI THU\n";
	cout << "PROJECT 5 - FINAL\n";
	cout << "DUE DATE: DEC 14, 2019";

	return 0;
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)  //Accepts 3 int arrays and a size as arguments, and fills the arrays out 
{                                                                            //with values entered by the user. First argument corresponds to the first row 
	for (int i = 0; i < size; i++)                                           //of the magic square, second argument to the second row and the third 
	{                                                                        //argument to the third row of the magic square 
		cout << "Enter the number for row 1 and column " << i + 1 << ": ";
		cin >> arrayRow1[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the number for row 2 and column " << i + 1 << ": ";
		cin >> arrayRow2[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the number for row 3 and column " << i + 1 << ": ";
		cin >> arrayRow3[i];
	}
}

void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)  //accepts 3 int arrays and a size as arguments and displays their content
{
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow1[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arrayrow2[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arrayrow3[i] << " ";
	}
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) //Accepts 3 int arrays and a size as arguments 
{                                                                                              //and returns true if all the requirements of
	bool checkrow1 = false, checkrow2 = false, checkrow3 = false;                              //a magic square are met. Otherwise, it returns 
	int i = 0;                                                                                 //false
	while (i < size && !checkrow1)  //First row of magic square
	{
		if (arrayRow1[i] >= min && arrayRow1[i] <= max)
			checkrow1 = true;
		i++;
	}

	while (i < size && !checkrow2) //Second row of magic square
	{
		if (arrayRow2[i] >= min && arrayRow2[i] <= max)
			checkrow2 = true;
		i++;
	}

	while (i < size && !checkrow3) //Third row of magic square
	{
		if (arrayRow3[i] >= min && arrayRow3[i] <= max)
			checkrow3 = true;
		i++;
	}

	if (checkrow1 && checkrow2 && checkrow3)
		return true;
	else return false;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)  //Accepts 3 int arrays and a size as arguments, and returns true if 
{                                                                              //the values are unique. Otherwise, returns false
	bool checkunique1 = true, checkunique2 = true, checkunique3 = true;
	int a = 0, b = 0, c = 0;
	while (a < (size - 1) && checkunique1) //First row of magic square
	{
		for (int k = a + 1; k < size && checkunique1; k++)
		{
			if (arrayRow1[a] != arrayRow1[k])
				checkunique1 = true;
			else checkunique1 = false;
		}
		a++;
	}

	while (b < (size - 1) && checkunique2) //Second row of magic square
	{
		for (int k = b + 1; k < size && checkunique2; k++)
		{
			if (arrayRow2[b] != arrayRow2[k])
				checkunique2 = true;
			else checkunique2 = false;
		}
		b++;
	}

	while (c < (size - 1) && checkunique3) //Third row of magic square
	{
		for (int k = c + 1; k < size && checkunique3; k++)
		{
			if (arrayRow3[c] != arrayRow3[k])
				checkunique3 = true;
			else checkunique3 = false;
		}
		c++;
	}

	if (checkunique1 && checkunique2 && checkunique3)
		return true;
	else return false;
}

bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) //Accepts 3 int arrays and a size as arguments, and returns true if the sum of the
{                                                                             //values in each row are equal. Otherwise, returns false
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += arrayrow1[i]; //First row of magic square
	}

	for (int i = 0; i < size; i++)
	{
		sum2 += arrayrow2[i]; //Second row of magic square
	}

	for (int i = 0; i < size; i++)
	{
		sum3 += arrayrow3[i]; //Third row of magic square
	}

	if (sum1 == 15 && sum2 == 15 && sum3 == 15)
	{
		return true;
	}
	else return false;
}

bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) //Accepts 3 int arrays and a size as arguments, and returns true if the sum of the
{                                                                             //values in each column are equal. Otherwise, returns false
	int sum1 = arrayrow1[0] + arrayrow2[0] + arrayrow3[0]; //First column of magic square
	int sum2 = arrayrow1[1] + arrayrow2[1] + arrayrow3[1]; //Second column of magic square
	int sum3 = arrayrow1[2] + arrayrow2[2] + arrayrow3[2]; //Third column of magic square
	if (sum1 == 15 && sum2 == 15 && sum3 == 15)
		return true;
	else return false;
}

bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) //Accepts 3 int arrays and a size as arguments, and returns true if the sum of the
{                                                                              //values in each diagonal are equal. Otherwise, returns false   
	int sum1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2]; //First diagonals of magic square
	int sum2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0]; //Second diagonals
	if (sum1 == 15 && sum2 == 15)
		return true;
	else return false;
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) //Accepts 3 int arrays, a size and a min and max value as arguments and returns 
{                                                                               //true if the values in the arrays are within the specified range min and max.   
	if (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX)             //Otherwise, it returns false
		&& checkUnique(arrayRow1, arrayRow2, arrayRow3, size)
		&& checkRowSum(arrayRow1, arrayRow2, arrayRow3, size)
		&& checkColSum(arrayRow1, arrayRow2, arrayRow3, size)
		&& checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size))
		return true;
	else return false;
}


