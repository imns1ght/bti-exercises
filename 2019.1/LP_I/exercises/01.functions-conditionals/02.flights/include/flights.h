#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <iostream>
#include <string>

using namespace std;

string itinerary(int nFlights, struct Flights flight[], string query);
string searchFlight(int *nFlights, struct Flights flight[], string *query);
void swap(int *nFlights, struct Flights flight[], int i);

struct Flights {
	string origin;
	string destination;
};

#endif
