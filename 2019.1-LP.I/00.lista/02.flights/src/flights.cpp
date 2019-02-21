/* Problem II
 * 
 * Given an unordered list of flights taken by someone, each represented as `(origin,
 * destination)` pairs, and a starting airport, compute the person's itinerary. If 
 * no such itinerary exists, return `null`. If there are multiple possible itineraries,
 * return the lexicographically smallest one. All flights must be used in the itinerary.
 */

#include "../include/flights.h"

int main()
{	
	/*
	 * struct Flights flight[] {{"", ""}, {"", ""}};
	 * struct Flights flight[] {{"SFO", "COM"}, {"COM", "YYZ"}};
	 * struct Flights flight[] {{"SFO", "HKO"}, {"YYZ", "SFO"}, {"YUL", "YYZ"}, {"HKO", "ORD"}};
	 */ 
	string start = "A"; /* Starting airport */ 
	struct Flights flight[] {{"A", "C"}, {"A", "B"}, {"B", "C"}, {"C", "A"}}; /* List of flights */
	size_t nFlights = (sizeof(flight) / sizeof(Flights)); /* Number of flights */

	cout << itinerary(nFlights, flight, start) << endl; /* Print the itinerary */

	return 0;
}

/* Creates the itinerary */
string itinerary(int nFlights, struct Flights flight[], string query) 
{	
	string itinerary = query + " ";	/* Start the itinerary with the first airport */

	while (nFlights > 0) {
		/* Search the flight in the list */
		query = searchFlight(&nFlights, flight, &query);

		/* If valid, add to itinerary. Otherwise, returns null */
		if (query == "null") {
			return "null";
		} else {
			itinerary += query + " ";
		}	
	}

	return itinerary;
}

string searchFlight(int *nFlights, struct Flights flight[], string *query) 
{
	// {{"A", "C"}, {"A", "B"}, {"B", "C"}, {"C", "A"}}

	for (int i = 0; i < *nFlights; i++) {
		if (flight[i].origin == *query) {
			*query = flight[i].destination;
			swap(nFlights, flight, i); 		
			*nFlights -= 1;
			return *query;
		}
	}

	return "null";
}


void swap(int *nFlights, struct Flights flight[], int i) 
{
	string tmp_origin = flight[i].origin;
	string tmp_destination = flight[i].destination;
	flight[i] = flight[*nFlights-1];
	flight[*nFlights-1].origin = tmp_origin;
	flight[*nFlights-1].destination = tmp_destination;
}