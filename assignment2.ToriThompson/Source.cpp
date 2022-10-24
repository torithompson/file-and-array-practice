#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>

//Tori Thompson
//Program to load homes and prices from a file and then add and remove specific address to the arrays beginning, middle or end

using namespace std;

const int SIZE = 20;

int loadArrays(string[], double[]);
int findHighest(const double[], int);
void printHomes(const string[], const double[], int);
double validatePrice(double);
int addHome(string[], double[], int);
int removeHome(string[], double[], int);

int main()
{
	string address[SIZE];
	double price[SIZE];
	int noRecords = 0;
	cout << "\nDelete an empty list:\n\n" << endl;
	printHomes(address, price, noRecords);
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nInitial array load:\n\n" << endl;
	noRecords = loadArrays(address, price);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a new home:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd the same home:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to the beginning of the array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to the end of the array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to middle of array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from start of array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete the same home\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from middle of array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from the end of the array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nProgram ended successfully" << endl;
	system("type homes.txt");
	system("pause");
}


/// <summary>
/// Function to load arrays with info from file
/// </summary>
/// <param name="address"></param>
/// <param name="price"></param>
/// <returns></returns>
int loadArrays(string address[], double price[])
{
	int length = 0;
	ifstream fin("homes.txt");
	cout << fixed << setprecision(2);

	if (!fin.is_open())
	{
		cout << "Unable to open file homes.txt";
		exit(-1);
	}

	for (length = 0; length < SIZE; length++)
	{
		getline(fin, address[length]);
		if (fin.eof())
			break;
		fin >> price[length];
		fin.ignore(80, '\n');
	}
	return length;
}
/// <summary>
///find the index value of employee with highest pay
/// </summary>
/// <param name="price"></param>
/// <param name="noRecords"></param>
/// <returns></returns>
int findHighest(const double price[], int noRecords)
{
	int highest = 0;
	for (int index = 1; index < noRecords; index++)
		if (price[index] > price[highest])
			highest = index;
	return highest;
}
/// <summary>
/// Print out all the homes and prices to the console in columns
/// </summary>
/// <param name="address"></param>
/// <param name="price"></param>
/// <param name="noRecords"></param>
void printHomes(const string address[], const double price[], int noRecords)
{
	int highest = findHighest(price, noRecords);
	cout << left << setw(40) << "Address"
		<< setw(20) << "Price" << endl << endl;

	for (int index = 0; index < noRecords; index++)
	{
		cout << left << setw(40) << address[index]
			<< setw(20) << price[index];
		if (price[index] == price[highest])
			cout << "***Highest Price***";
		cout << endl;
	}
	cout << endl;
}
/// <summary>
/// Validate price to ensure it is between 1 - 1 million and no input failure
/// </summary>
/// <param name="price"></param>
/// <returns></returns>
double validatePrice(double price)
{
	while (price < 1 || price > 1000000 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "You must enter a price between 1-1,000,000, enter again: " << endl;
		cin >> price;
	}
	return price;
}
/// <summary>
/// Adding a new home and price to the array from user input
/// </summary>
/// <param name="homes"></param>
/// <param name="price"></param>
/// <param name="noRecords"></param>
/// <returns></returns>
int addHome(string homes[], double price[], int noRecords)
{
	string newHouse;
	double newPrice;

	if (noRecords < SIZE)
	{
		int pos = 0;
		cout << "Enter the address you would like to add: " << endl;
		getline(cin, newHouse);
		while (newHouse == "")
		{
			cout << "You must enter a valid address, enter again:" << endl;
			getline(cin, newHouse);
		}
		for (; pos < noRecords; pos++)
		{
			if (newHouse <= homes[pos])
				break;
		}
		if (newHouse == homes[pos] && pos < noRecords)
		{
			cout << "Can't add already exists." << endl;
		}
		else
		{
			cout << "Enter the price for " << newHouse << endl;
			cin >> newPrice;
			newPrice = validatePrice(newPrice);
			cin.ignore(80, '\n');
			for (int index = noRecords; index > pos; index--)
			{
				homes[index] = homes[index - 1];
				price[index] = price[index - 1];
			}
			homes[pos] = newHouse;
			price[pos] = newPrice;
			noRecords++;
		}
	}
	else
		cout << "Sorry the array is full, cannot add another address." << endl;
	return noRecords;
}
/// <summary>
/// Removing a home and price from array using user input
/// </summary>
/// <param name="homes"></param>
/// <param name="price"></param>
/// <param name="noRecords"></param>
/// <returns></returns>
int removeHome(string homes[], double price[], int noRecords)
{
	if (noRecords > 0)
	{
		string name;
		int pos = 0;
		cout << "Enter the address you would like to remove: " << endl;
		getline(cin, name);

		for (; pos < noRecords; pos++)
		{
			if (homes[pos] == name)
				break;
		}
		if (pos == noRecords)
			cout << "Home not found" << endl;
		else
		{
			noRecords--;
			for (; pos < noRecords; pos++)
			{
				homes[pos] = homes[pos + 1];
				price[pos] = price[pos + 1];
			}
		}
	}
	else
		cout << "The array is already empty, nothing removed." << endl;
	return noRecords;
}
/*
Delete an empty list:


Address                                 Price


The array is already empty, nothing removed.
Address                                 Price


# homes = 0

Initial array load:


Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50           ***Highest Price***
2 Pine Street                           89888.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05

# homes = 8

Add a new home:


Enter the address you would like to add:
220 Added Road
Enter the price for 220 Added Road
220000
Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50           ***Highest Price***
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05

# homes = 9

Add the same home:


Enter the address you would like to add:
220 Added Road
Can't add already exists.
Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50           ***Highest Price***
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05

# homes = 9

Add a home to the beginning of the array:


Enter the address you would like to add:
0 Princess Street
Enter the price for 0 Princess Street
905000
Address                                 Price

0 Princess Street                       905000.00           ***Highest Price***
1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05

# homes = 10

Add a home to the end of the array:


Enter the address you would like to add:
750 End Lane
Enter the price for 750 End Lane
1000000
Address                                 Price

0 Princess Street                       905000.00
1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05
750 End Lane                            1000000.00          ***Highest Price***

# homes = 11

Add a home to middle of array:


Enter the address you would like to add:
350 Middle Lane
Enter the price for 350 Middle Lane
1020404
You must enter a price between 1-1,000,000, enter again:
102040
Address                                 Price

0 Princess Street                       905000.00
1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
350 Middle Lane                         102040.00
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05
750 End Lane                            1000000.00          ***Highest Price***

# homes = 12

Delete a home from start of array:


Enter the address you would like to remove:
0 Princess Street
Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
350 Middle Lane                         102040.00
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05
750 End Lane                            1000000.00          ***Highest Price***

# homes = 11

Delete the same home


Enter the address you would like to remove:
0 Princess Street
Home not found
Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
350 Middle Lane                         102040.00
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05
750 End Lane                            1000000.00          ***Highest Price***

# homes = 11

Delete a home from middle of array:


Enter the address you would like to remove:
350 Middle Lane
Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05
750 End Lane                            1000000.00          ***Highest Price***

# homes = 10

Delete a home from the end of the array:


Enter the address you would like to remove:
750 End Lane
Address                                 Price

1 Princess Street                       95000.00
100 Main Street                         100000.00
123 Test Road                           509000.50           ***Highest Price***
2 Pine Street                           89888.00
220 Added Road                          220000.00
300 Error avenue                        20000.25
45 St. Lawrence Street                  405000.00
500 Mcdonald avenue                     405604.54
635 Princess Street                     504969.05

# homes = 9

Program ended successfully
1 Princess Street
95000.00
100 Main Street
100000.00
123 Test Road
509000.50
2 Pine Street
89888.00
300 Error avenue
20000.25
45 St. Lawrence Street
405000.00
500 Mcdonald avenue
405604.54
635 Princess Street
504969.05
Press any key to continue . . .
*/