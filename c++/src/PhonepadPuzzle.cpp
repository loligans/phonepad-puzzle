#include <vector>
#include <list>
#include <iostream>
using namespace std;

// Function declarations
bool solvePuzzle(int chosenNumber, list<int>& digits, bool canCross);
bool digitsCross(list<int>& digits);
bool nextDigit(int num, list<int>& digits, bool canCross);
bool isSolution(list<int>& digits);
int concatInt(int a, int b, int c = -1);

// The Phonepad containing adjacent digits
const vector<vector<int>> phonepad = { 
	/*0*/ { 7, 8, 9 },
	/*1*/ { 2, 4, 5 },
	/*2*/ { 1, 3, 4, 5, 6 },
	/*3*/ { 2, 5, 6 },
	/*4*/ { 1, 2, 5, 7, 8 },
	/*5*/ { 1, 2, 3, 4, 6, 7, 8, 9 },
	/*6*/ { 2, 3, 5, 8, 9 },
	/*7*/ { 4, 5, 8, 0 },
	/*8*/ { 4, 5, 6, 7, 9, 0 },
	/*9*/ { 5, 6, 8, 0 }
};

//----------------------------------------------------------------------------
// Function: solvePuzzle()
// Title: Solve Puzzle
// Description:
//   Recursively adds 9 adjacent digits to a collection and then 
//   tests for a solution.
//
// Programmer: Ethan Lindemann-Michael
// Date: 9/Feb/2018
// Version: 0.1
//
// Called By: main()
//
// Parameters: 
// int chosenNumber - The next digit to include in the solution.
// list<int>& digits - The collection of digits that will contain the solution.
// bool canCross - Whether digits can cross each other.
// 
// Returns:	bool
//----------------------------------------------------------------------------
bool solvePuzzle(int chosenNumber, list<int>& digits, bool canCross)
{
	digits.push_back(chosenNumber);

	// Prevent digits crossing
	if (!canCross && digitsCross(digits))
		return false;

	// Base case
	if (digits.size() == 9)
	{
		return isSolution(digits);
	}
	// continue until we have 9-digits
	else
	{
		for (const int& num : phonepad[chosenNumber])
		{
			bool solution = nextDigit(num, digits, canCross);
			// cease recursion if we found our solution
			if (solution)
				return solution;
		}
	}
	return false;
}

//----------------------------------------------------------------------------
// Function: digitsCross()
// Title: Digits Cross
// Description:
//   Checks if the last 4 digits in a collection cross.
//
// Programmer: Ethan Lindemann-Michael
// Date: 9/Feb/2018
// Version: 0.1
//
// Calls:
// isSolution()
// nextDigit()
//
// Called By: solvePuzzle()
//
// Parameters: 
// list<int>& digits - The collection of digits to check.
// 
// Returns:	bool
//----------------------------------------------------------------------------
bool digitsCross(list<int>& digits)
{
	// Testing requires 4 ints on the list
	if (digits.size() < 4)
		return false;

	// Get the last 4 elements in the list
	list<int>::reverse_iterator it = digits.rbegin();
	const int firstInt = *it;
	const int secondInt = *(++it);
	const int thirdInt = *(++it);
	const int fourthInt = *(++it);

	// Test if the path crosses
	const bool cross = firstInt + secondInt == thirdInt + fourthInt;

	return cross;
}

//----------------------------------------------------------------------------
// Function: nextDigit()
// Title: Next Digit
// Description:
//   Adds another digit to the collection then tries to solve the puzzle.
//
// Programmer: Ethan Lindemann-Michael
// Date: 9/Feb/2018
// Version: 0.1
//
// Calls:
// solvePuzzle()
//
// Called By: solvePuzzle()
//
// Parameters: 
// int num - The next digit to add into the collection.
// list<int>& digits - The collection of digits to check.
// bool canCross - Whether digits can cross each other.
//
// Returns:	bool
//----------------------------------------------------------------------------
bool nextDigit(int num, list<int>& digits, bool canCross)
{
	// makes sure the list doesn't contain duplicate digits
	bool containsNum = find(digits.begin(), digits.end(), num) != digits.end();
	if (!containsNum)
	{
		bool solution = solvePuzzle(num, digits, canCross);
		if (solution)
			return solution;
		else
		{
			digits.pop_back();
			return false;
		}
	}
	return false;
}

//----------------------------------------------------------------------------
// Function: isSolution()
// Title: Check Solution
// Description:
//   Verifies the combined first 3-digits plus the combined second 3-digits 
//   equals the combined last 3-digits.
//
// Programmer: Ethan Lindemann-Michael
// Date: 9/Feb/2018
// Version: 0.1
//
// Calls:
// concatInt()
//
// Called By: solvePuzzle()
//
// Parameters: 
// list<int>& digits - The collection of digits to check.
//
// Returns:	bool
//----------------------------------------------------------------------------
bool isSolution(list<int>& digits)
{
	// Grabs each digit from the list
	list<int>::iterator it = digits.begin();
	int f1 = *it    , f2 = *(++it), f3 = *(++it);
	int s1 = *(++it), s2 = *(++it), s3 = *(++it);
	int t1 = *(++it), t2 = *(++it), t3 = *(++it);

	// concat 3-digits into a single int. ie. 1, 2, 3 -> 123
	int first = concatInt(f1, f2, f3);
	int secon = concatInt(s1, s2, s3);
	int third = concatInt(t1, t2, t3);
	
	bool isSolution = first + secon == third;
	if (isSolution)
	{
		cout << first << " + " << secon << " == " << third << " | " << "True" << endl;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
// Function: concatInt()
// Title: Combine Integer
// Description:
//   Combines an integer into another integer. ie: 1 and 2 would become 12. 
//
// Programmer: Ethan Lindemann-Michael
// Date: 9/Feb/2018
// Version: 0.1
//
// Calls:
// concatInt()
//
// Called By: isSolution()
//
// Parameters: 
// int a - The leading integer
// int b - The secondary integer
// int c - An optional tritary integer
//
// Returns:	bool
//----------------------------------------------------------------------------
int concatInt(int a, int b, int c)
{
	// assuming base 10
	int pow = 10;
	while (b >= pow)
		pow *= 10;
	int result = (a * pow) + b;

	if (c == -1)
		return result;
	else
		return concatInt(result, c);
}

int main()
{
	// Run solution with crossing disabled
	cout << "Solutions with crossing disabled" << endl;
	for (int num = 0; num < phonepad.size(); num++)
	{
		auto digitsNoCrossing = list<int>();
		solvePuzzle(num, digitsNoCrossing, false);
	}

	// Run solution with crossing enabled
	cout << endl << "Solutions with crossing enabled" << endl;
	for (int num = 0; num < phonepad.size(); num++)
	{
		auto digitsCrossing = list<int>();
		solvePuzzle(num, digitsCrossing, true);
	}

	// Pause application
	cout << endl << "Press <enter> to continue.";
	cin.ignore(INT_MAX, '\n');
	return EXIT_SUCCESS;
}

