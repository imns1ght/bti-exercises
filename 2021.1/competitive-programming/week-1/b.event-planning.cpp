#include <ios>  // <streamsize>
#include <iostream>
#include <limits>  // numeric_limits

int main(void) {
  int budge;
  int num_participants;
  int num_hotels;
  int num_weeks;

  while (std::cin >> num_participants >> budge >> num_hotels >> num_weeks) {
    int total_cost = 0;

    for (int hotel = 0; hotel < num_hotels; hotel++) {
      int individual_cost_per_week;
      std::cin >> individual_cost_per_week;
      int participants_cost = individual_cost_per_week * num_participants;

      bool have_beds = false;
      for (int week = 0; week < num_weeks; week++) {
        int num_beds;
        std::cin >> num_beds;

        if (num_beds >= num_participants) {
          have_beds = true;
          // discards the input buffer
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          break;
        }
      }

      if (have_beds && (total_cost == 0 || participants_cost < total_cost)) {
        total_cost = participants_cost;
      }
    }

    if (total_cost <= budge && total_cost != 0) {
      std::cout << total_cost << std::endl;
    } else {
      std::cout << "stay home" << std::endl;
    }
  }

  return 0;
}