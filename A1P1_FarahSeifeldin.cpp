//FARAH SEIF EL-DIN - 900160195
//ASSIGNMENT 1//Problem 1: Graph Traversal

#include <iostream>
#include <string>
#include <fstream>
#include "Stackt.h"
using namespace std;

//the city's order of visiting it
int order = 0;

// struct to create an array of type city that has the order of visiting the city 
//and if it was seen or not
struct city {
	int corder = -1;
	bool seen = false;
};

// creates a 2D dynamic array with rows and cols = number of cities in the file
void create2D(int ** &cities,int ncities) {
	cities = new int*[ncities];
	for (int i = 0; i < ncities; i++)
		cities[i] = new int[ncities];
}


// reads cities from the input file and stores them in a 2D array
//cities is a 2D array and ncities is the number of cities
// this function returns either true (if the file was opened successfully)
// or false if the file failed to open
bool readCities(string filename, int ** &cities, int &ncities) {

	//opening file
	ifstream myinput;
	myinput.open(filename);
	if (!myinput.fail()) {

		int distance;

		//reading the number of cities in the file e.g. ncities=15
		myinput >> ncities;

		//create 2D array filled with the distances between each city and the others
		create2D(cities, ncities);

		// fill the 2D array with the distances between cities
		for (int i = 0; i < ncities; i++)
			for (int j = 0; j < ncities; j++) {
				myinput >> distance;
				cities[i][j] = distance;	
			}
	}

	else {
		// if file fails to open, close it and return false
		myinput.close();
		return false;
	}

	// file opened successfully, close it, and return true
	myinput.close();
	return true;
}


// checks if there's a route from city1 to city2 and if city2 was visited before (seen or unseen)
// return true if there's a route and if city2 is unseen
// else returns false
bool canVisit(int **cities, city *visits, int city1, int city2, int ncities) {
	return (cities[city1][city2] != 0 && !visits[city2].seen);
}

//visits the city with index=index_city by pushing it onto the stack and marking it as seen
void visitCity(int index_city, Stackt <int> &visited, city *visits) {
	visited.push(index_city);
	visits[index_city].seen = true;
}

//starts the trip with index of 1st city to visit = starting_city
void startTrip(int starting_city, int ncities, int **cities, city *&visits) {

	//create stackt called trip 
	Stackt <int> trip;

	//visits the starting city
	visitCity(starting_city, trip, visits);

	//i stores the index of the city we pop from the stack
	int i;
	
	//algorithm in question 1
	/*while S is not empty
	{
		Pop stack(S) to get current source(i);
	Increment(order) and save it in V[i];
	for (j = N; j >= 1; j--) // Scan row (i) from right to left
		if (city(j) is connected to city(i)) if (V[j] == unseen)
		{
			Push(j) on(S); Set V[j] = hold;
		}
	}*/

	while (!trip.stackempty()) {

		trip.pop(i);
		order++;
		visits[i].corder = order;

		for (int j = ncities-1; j >= 0; j--) 
			if (canVisit(cities, visits, i, j, ncities)) {
				visitCity(j, trip, visits);
			}
	}
}

int main() {

	string filename;

	// pointer of pointers to create 2D dynamic array
	int **cities;

	//will contain number of cities in the file
	int ncities;

	//pointer to create 1D dynamic array that has the order of each city 
	//and if it is unseen or seen
	city *visits;

	//validation for filename
	do {
		cout << "Please enter a valid file name" << endl;
		cin >> filename;
	}
	while(!readCities(filename, cities, ncities));

	int starting_city;

	//validation for starting city index
	do {
		cout << "Please enter the index/number of the city you want to start with:" << endl;
		cin >> starting_city;

		//the indices of the cities are from 0 to (ncities-1) in the arrays, 
		//but for the user, they appear to be from 1 to ncities
		//if the user types 3, this 3 is actually 2 in the cities array
		starting_city--;

	} while (starting_city >= ncities || starting_city < 0);

	//initialize 1D dynamic array for the order of the visits
	visits = new city[ncities];

	//start the trip - implement DFS algorithm
	startTrip(starting_city, ncities, cities, visits);

	// print each city and its order in the trip

	cout << "        Order of Visit" << endl;
	for (int i = 0; i < ncities; i++) {
		cout << "City " << i + 1 << ": ";
		cout << visits[i].corder << endl;

	}

	system("pause");
	return 0;
}





