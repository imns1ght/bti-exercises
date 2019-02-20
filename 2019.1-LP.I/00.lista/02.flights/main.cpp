/* Problem II
 * 
 * Given an unordered list of flights taken by someone, each represented as `(origin,
 * destination)` pairs, and a starting airport, compute the person's itinerary. If 
 * no such itinerary exists, return `null`. If there are multiple possible itineraries,
 * return the lexicographically smallest one. All flights must be used in the itinerary.
 */

#include <iostream>
#include <string>

using namespace std;

void searchItinerary(int nFlights, struct Flights flight[], string start);
int searchFirst(int nFlights, struct Flights flight[], string start);
void traceItinerary(int nFlights, struct Flights flight[], string start);

struct Flights {
	string origin;
	string destination;
};

int main()
{	
	string start = "A"; /* Starting airport */
	// struct Flights flight[] {{"SFO", "HKO"}, {"YYZ", "SFO"}, {"YUL", "YYZ"}, {"HKO", "ORD"}};
	struct Flights flight[] {{"A", "B"}, {"A", "C"}, {"B", "C"}, {"C", "A"}}; /* List of flights */
	size_t nFlights = (sizeof(flight) / sizeof(flight[0])) + 1; /* Calculates the number of flights */
	searchItinerary(nFlights, flight, start);

	return 0;
}

/* Search the itinerary */
void searchItinerary(int nFlights, struct Flights flight[], string start) 
{	
	int first = searchFirst(nFlights, flight, start);

	if (first == -1) {
		cout << "null";
	} else {
		traceItinerary(nFlights, flight, start);
	}
	cout << endl;
}

/* Search if the first flight exists */
int searchFirst(int nFlights, struct Flights flight[], string start)
{
	for (int i = 0; i < nFlights; i++) {
		if (flight[i].origin == start) {
			return i;
		}
	}

	return -1;
}

/* Trace the itinerary made by user */
void traceItinerary(int nFlights, struct Flights flight[], string start) 
{
	string itinerary[nFlights];
	itinerary[0] = start;

	for (int i = 0; i < nFlights; i++) {
		for (int j = 0; j < nFlights; j++) {
			if (itinerary[i] == flight[j].origin) {
				if (itinerary[i+1] > flight[j].destination) {
					itinerary[i+1] = flight[j].destination;
					flight[j] = {"", ""};
				} else if (itinerary[i+1] == ""){
					itinerary[i+1] = flight[j].destination;
					flight[j] = {"", ""};
				}	 
			} 
		}
	}

	cout << ">>> Itinerary <<<\n\n";
	for (int i = 0; i < nFlights; i++) {
		cout << ">>> " << itinerary[i] << endl;
	}
}