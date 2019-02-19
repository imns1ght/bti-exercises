/* Problem II [INCOMPLETE]
 * 
 * Given an unordered list of flights taken by someone, each represented as `(origin,
 * destination)` pairs, and a starting airport, compute the person's itinerary. If 
 * no such itinerary exists, return `null`. If there are multiple possible itineraries,
 * return the lexicographically smallest one. All flights must be used in the itinerary.
 */

#include <iostream>
#include <string>

using namespace std;

int defineFlights(struct Flights flight[]);
int searchItinerary(int nFlights, struct Flights flight[], string start);

struct Flights {
	string origin;
	string destination;
};

int main()
{	
	int nFlights;
	string start;
	struct Flights flight[] {{"A", "B"}, {"D", "B"},{"C", "D"}, {"B", "C"}};

	nFlights = defineFlights(flight);
	int tmp = searchItinerary(nFlights, flight, start);

	return 0;
}

int searchItinerary(int nFlights, struct Flights flight[], string start) 
{
	string itinerary[nFlights];

	for (int i = 0; i < nFlights; i++) {
		if (flight[i].origin == start) {
			return NULL;
		}
	}

	for (int i = 0; i < nFlights; i++) {
		cout << itinerary[i];
	}
	cout << endl;

	return 0;
}
