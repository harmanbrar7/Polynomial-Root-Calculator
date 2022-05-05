// Assignment 1 
// Harman Brar(301293707) CMPT 129
// Completed Feb/19/2021
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

//Defining a function to calculate f(x)
double F(double X, double coef4, double coef3, double coef2, double coef1, double coef0)
{
	return ((((coef4*X + coef3)*X + coef2)*X + coef1)*X + coef0);

}

int main()
{
	
	int counter = 0;
	int numRows = 0;
	int numIterations = 0;
	double coef4 = 0;
	double coef3 = 0;
	double coef2 = 0;
	double coef1 = 0;
	double coef0 = 0;
	double intervalEndMin = 0;
	double intervalEndMax = 0;
	double intervalMinAllocator = 0;
	double intervalMaxAllocator = 0;
	double intervalShift = 0;
	double intervalLength = 0;
	double midpoint = 0;
	const double EPS = 0.000001;
	const double COEFMAX = 50.0;
	const double COEFMIN = -50.0;
	const double RANGEMAX = 60.0;
	const double RANGEMIN = -60.0;
	const double ROWMAX = 25;
	const double ROWMIN = 1;
	const double SHIFTMAX = 20.0;
	const double SHIFTMIN = 0.0;
	const int MAXTRIES = 2;//this will give 3 tries + input try for a total of 4, counter starts from 0
	const int MAXITERATIONS = 51;//this runs as 50 because I start at 1(I could have easily put a literal constant of "+1" in my for-loop but decided to stick with named constant) 
	const int TXTWIDTH = 13;//textwidth for screen output
	const int TXTWIDTH2 = 5;//textwidth for screen output iterations
	const int TXTWIDTH3 = 16;//textwidth for file ouput
	const int TXTWIDTH4 = 10;//textwidth for file ouput iterations
	const int TXTPRECISION = 6;
    string fileOut;
	ofstream mystream;

	//Getting value for coef4
	cout << "Please enter the value of the coefficient for the order 4 term\n"
		<< "(-50.0 <= coefficient <= 50.0): ";
	cin >> coef4;

	do
	{

		if (coef4 < COEFMIN || coef4 > COEFMAX)
		{
			cerr << "ERROR: The value of the order 4 term is out of range\n"
				<< "Please re-enter the value of the coefficient for the order 4 term\n"
				<< "(-50.0 <= coefficient <= 50.0): ";
			cin >> coef4;

		}
		else
		{
			break;

		}
		counter++;


	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: The value of the order 4 term is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(1);
	}

	//reset counter and get value for coef3
	counter = 0;
	cout << "Please enter the value of the coefficient for the order 3 term\n"
		<< "(-50.0 <= coefficient <= 50.0): ";
	cin >> coef3;

	do
	{

		if (coef3 < COEFMIN || coef3 > COEFMAX)
		{
			cerr << "ERROR: The value of the order 3 term is out of range\n"
				<< "Please re-enter the value of the coefficient for the order 3 term\n"
				<< "(-50.0 <= coefficient <= 50.0): ";
			cin >> coef3;

		}
		else
		{
			break;

		}
		counter++;

	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: The value of the order 3 term is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(2);
	}

	//reset counter and get value for coef2
	counter = 0;
	cout << "Please enter the value of the coefficient for the order 2 term\n"
		<< "(-50.0 <= coefficient <= 50.0): ";
	cin >> coef2;

	do
	{

		if (coef2 < COEFMIN || coef2 > COEFMAX)
		{
			cerr << "ERROR: The value of the order 2 term is out of range\n"
				<< "Please re-enter the value of the coefficient for the order 2 term\n"
				<< "(-50.0 <= coefficient <= 50.0): ";
			cin >> coef2;

		}
		else
		{
			break;

		}
		counter++;

	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: The value of the order 2 term is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(3);
	}

	//reset counter and get value for coef1
	counter = 0;
	cout << "Please enter the value of the coefficient for the order 1 term\n"
		<< "(-50.0 <= coefficient <= 50.0): ";
	cin >> coef1;

	do
	{

		if (coef1 < COEFMIN || coef1 > COEFMAX)
		{
			cerr << "ERROR: The value of the order 1 term is out of range\n"
				<< "Please re-enter the value of the coefficient for the order 1 term\n"
				<< "(-50.0 <= coefficient <= 50.0): ";
			cin >> coef1;

		}
		else
		{
			break;

		}
		counter++;



	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: The value of the order 1 term is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(4);
	}


	//get value for coef0
	counter = 0;
	cout << "Please enter the value of the coefficient for the order 0 term\n"
		<< "(-50.0 <= coefficient <= 50.0): ";
	cin >> coef0;

	do
	{

		if (coef0 < COEFMIN || coef0 > COEFMAX)
		{
			cerr << "ERROR: The value of the order 0 term is out of range\n"
				<< "Please re-enter the value of the coefficient for the order 0 term\n"
				<< "(-50.0 <= coefficient <= 50.0): ";
			cin >> coef0;

		}
		else
		{
			break;

		}
		counter++;


	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: The value of the order 0 term is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(5);
	}



	//getting minimum x value
	counter = 0;
	cout << "Please enter the minimum X value in the initial range\n"
		<< "(-60.0 <= minimum X value in the initial range <= 60.0): ";
	cin >> intervalEndMin;

	do
	{

		if (intervalEndMin < RANGEMIN || intervalEndMin > RANGEMAX)
		{
			cerr << "ERROR: The minimum X value in the initial range is out of range\n"
				<< "Please re-enter the minimum X value in the initial range\n"
				<< "(-60.0 <= minimum X value in the initial range <= 60.0): ";
			cin >> intervalEndMin;

		}
		else
		{
			break;

		}
		counter++;

	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: minimum X value in the initial range is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(6);
	}

	//getting maximum x value
	counter = 0;
	cout << "Please enter the maximum X value in the initial range\n"
		<< "(-60.0 <= maximum X value in the initial range <= 60.0): ";
	cin >> intervalEndMax;

	do
	{

		if (intervalEndMax < RANGEMIN || intervalEndMax > RANGEMAX)
		{
			cerr << "ERROR: The maximum X value in the initial range is out of range\n"
				<< "Please re-enter the maximum X value in the initial range\n"
				<< "(-60.0 <= maximum X value in the initial range <= 60.0): ";
			cin >> intervalEndMax;

		}
		else
		{
			break;

		}
		counter++;

	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: maximum X value in the initial range is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(7);
	}

	//gettting the number of rows
	counter = 0;
	cout << "Please enter the number of rows in the table\n"
		<< "(1 <= number of rows in the table <= 25): ";
	cin >> numRows;

	do
	{

		if (numRows < ROWMIN || numRows > ROWMAX)
		{
			cerr << "ERROR: The number of rows in the table is out of range\n"
				<< "Please re-enter the number of rows in the table\n"
				<< "(1 <= number of rows in the table <= 25): ";
			cin >> numRows;

		}
		else
		{
			break;

		}
		counter++;


	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: the number of rows in the table is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(8);
	}

	//getting the shift
	counter = 0;
	cout << "Please enter the shift of the starting interval between rows\n"
		<< "(0.0 <= shift of starting interval between rows <= 20.0): ";
	cin >> intervalShift;

	do
	{

		if (intervalShift < SHIFTMIN || intervalShift > SHIFTMAX)
		{
			cerr << "ERROR: The shift in the starting interval between rows is out of range\n"
				<< "Please re-enter the shift in the starting interval between rows\n"
				<< "(0.0 <= shift of starting interval between rows <= 20.0): ";
			cin >> intervalShift;

		}
		else
		{
			break;

		}
		counter++;


	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: the shift in the starting interval between rows is out of range\n"
			<< "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(9);
	}

	//getting output file name and seeing if it opens correctly
	cout << "Enter the name of the output file ";
	cin >> fileOut;

	mystream.open(fileOut, ios::out);
	do
	{

		if (mystream.fail())
		{
			mystream.clear();
			cerr << "ERROR: the file did not open, please re-enter the name of the output file: ";
			cin >> fileOut;
			mystream.open(fileOut, ios::out);

		}
		else
		{
			break;

		}
		counter++;

	} while (counter <= MAXTRIES);
	if (counter > MAXTRIES)
	{
		cerr << "ERROR: the file did not open\n" << "Maximum number of tries entering data exceeded. Program terminating.\n";
		exit(10);
	}







	// variables store values of interval ends to use in for loop
	//because I want for-loop to start off with original values of intervals and then apply interval shift
	intervalMaxAllocator = intervalEndMax;
	intervalMinAllocator = intervalEndMin;



	cout << setw(TXTWIDTH) << "intEndMin" << setw(TXTWIDTH) << "intEndMax" << setw(TXTWIDTH) << "midpoint" << setw(TXTWIDTH) << "root" << setw(TXTWIDTH2) << "N" << endl;
	//two for loops implement the bisection method and the intervalshift, second for-loop includes all statements that produce the root
	for (counter = 1; counter < (numRows+1); counter++)
	{
		intervalEndMax = intervalMaxAllocator;
		intervalEndMin = intervalMinAllocator;


		intervalEndMin = intervalEndMin + (counter - 1)*intervalShift;
		intervalEndMax = intervalEndMax + (counter - 1)*intervalShift;
		intervalLength = intervalEndMax - intervalEndMin;
		midpoint = (intervalEndMin + intervalLength / 2.0);

		mystream << setw(TXTWIDTH3) << "Interval Start" << setw(TXTWIDTH3) << "P(x) Start" << setw(TXTWIDTH3) << "Interval End" << setw(TXTWIDTH3) << "P(x) End" << setw(TXTWIDTH3)
			<< "Midpoint" << setw(TXTWIDTH3) << "P(Midpoint)" << "Iteration#" << endl;

		cout << fixed << setprecision(TXTPRECISION) << setw(TXTWIDTH) << intervalEndMin << setw(TXTWIDTH) << intervalEndMax << setw(TXTWIDTH) << midpoint;
		for (numIterations = 1; numIterations < MAXITERATIONS; numIterations++)
		{
			intervalLength = intervalEndMax - intervalEndMin;
			midpoint = (intervalEndMin + intervalLength / 2.0);
			mystream << fixed << setprecision(TXTPRECISION) << setw(TXTWIDTH3) << intervalEndMin << setw(TXTWIDTH3) <<scientific << F(intervalEndMin, coef4, coef3, coef2, coef1, coef0) << setw(TXTWIDTH3)
				<<fixed << intervalEndMax << setw(TXTWIDTH3) << scientific << F(intervalEndMax, coef4, coef3, coef2, coef1, coef0) << setw(TXTWIDTH3) << fixed << midpoint << setw(TXTWIDTH3) << scientific
				<< F(midpoint, coef4, coef3, coef2, coef1, coef0) << setw(TXTWIDTH4) << fixed << numIterations << endl;

			if (abs(F(intervalEndMin, coef4, coef3, coef2, coef1, coef0)) < EPS)
			{
				cout << setw(TXTWIDTH) << intervalEndMin << setw(TXTWIDTH2) << numIterations;
				break;

			}
			else if (abs(F(intervalEndMax, coef4, coef3, coef2, coef1, coef0)) < EPS)
			{
				cout << setw(TXTWIDTH) << intervalEndMax << setw(TXTWIDTH2) << numIterations;
				break;
			}
			else if (abs(F(midpoint, coef4, coef3, coef2, coef1, coef0)) < EPS)
			{
				cout << setw(TXTWIDTH) << midpoint << setw(TXTWIDTH2) << numIterations;
				break;
			}
			else if ((intervalLength < EPS))
			{
				cout << setw(TXTWIDTH) << midpoint << setw(TXTWIDTH2) << numIterations;
				break;

			}
			else if (((F(intervalEndMin, coef4, coef3, coef2, coef1, coef0)) * (F(midpoint, coef4, coef3, coef2, coef1, coef0))) < 0.0)
			{

				intervalEndMax = midpoint;
			}
			else if (((F(intervalEndMax, coef4, coef3, coef2, coef1, coef0)) * (F(midpoint, coef4, coef3, coef2, coef1, coef0))) < 0.0)
			{
					intervalEndMin = midpoint;
			}
			else
			{
				cout << "-------------ERROR:  no roots in the interval";
				mystream << "ERROR: no roots in the interval";
				break;
			}

			



		}
		if (numIterations >= MAXITERATIONS)
		{
			cout << "-------------ERROR: did not converge";
			mystream << "ERROR: did not converge";
		}

		cout << endl;
		mystream << endl << endl << endl;

	}



    

	return 0;
}

	





	

	




	




	

