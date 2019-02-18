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
	struct Flights flight[10];

	cout << ">>> Starting airport: ";
	cin >> start;
	start.resize(3);
	cout << endl; 

	nFlights = defineFlights(flight);
	int tmp = searchItinerary(nFlights, flight, start);

	return 0;
}

int defineFlights(struct Flights flight[])
{
	int i;
	
	cout << ">>> Warning:\n[1] limited to 10 flights\n" << "[2] when ready, type 'done'" << "\n\n";
	
	for (i = 0; i < 10; i++) {
		cout << ">>> Flight [" << i+1 << "] <<<\n";
		cout << ">>> Origin: ";
		cin >> flight[i].origin;
		
		if (flight[i].origin == "done") {
			cout << endl;
			return i;
		}

		flight[i].origin.resize(3);
		cout << ">>> Destination: ";
		cin >> flight[i].destination;
		flight[i].destination.resize(3); 
		cout << endl;
	}
	cout << endl;

	return i;
}

/* Incomplete :( */
int searchItinerary(int nFlights, struct Flights flight[], string start) 
{
	int i, cont;
	string itinerary[nFlights];

	for (i = 0, cont = 0; cont < nFlights; i++) {

	}

	for (int i = 0; i < nFlights; i++) {
		cout << itinerary[i];
	}
	cout << endl;

	return 0;
}
