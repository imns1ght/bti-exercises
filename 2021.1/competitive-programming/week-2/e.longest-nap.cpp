#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Time {
 public:
  int hours, minutes;

  Time() {}

  Time(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
  }

  std::string print() {
    return std::to_string(hours) + ":" +
           (minutes >= 0 && minutes <= 9 ? "0" : "") + std::to_string(minutes);
  }

  bool operator!=(const Time& b) {
    return this->hours != b.hours || this->minutes != b.minutes;
  }
};

Time UPPER_TIME(10, 0);
Time LOWER_TIME(18, 0);

int durationInMinutes(Time end, Time start) {
  return (end.minutes + end.hours * 60) - (start.minutes + start.hours * 60);
}

bool is_time_valid(Time start, Time end) {
  return start.hours >= UPPER_TIME.hours &&
         start.minutes >= UPPER_TIME.minutes && end.hours <= LOWER_TIME.hours;
}

class TimeGap {
 public:
  Time start;
  Time end;

  TimeGap() {}

  TimeGap(int start, int end) {
    this->start.hours = start;
    this->start.minutes = 0;
    this->end.hours = end;
    this->end.minutes = 0;
  }

  TimeGap(std::string start, std::string end) {
    this->start = this->getFormatedTime(start);
    this->end = this->getFormatedTime(end);
  }

  Time getFormatedTime(std::string timeStr) {
    Time formatedTime;
    formatedTime.hours = std::stoi(timeStr.substr(0, 2));
    formatedTime.minutes = std::stoi(timeStr.substr(3, 2));

    return formatedTime;
  }

  std::string printDuration() {
    int hours = 0;
    int minutes = durationInMinutes(this->end, this->start);

    if (minutes >= 60) {
      hours = minutes / 60;
      minutes = minutes % 60;
      return std::to_string(hours) + " hours and " + std::to_string(minutes) +
             " minutes.";
    } else {
      return std::to_string(minutes) + " minutes.";
    }
  }

  bool operator!=(const TimeGap& b) {
    return this->start != b.start || this->end != b.end;
  }
};

int main(void) {
  int test_cases;

  for (int n_set = 1; std::cin >> test_cases; n_set++) {
    std::vector<TimeGap> times;
    TimeGap best_time(0, 10);
    for (int i = 1; i <= test_cases; i++) {
      std::string line;

      while (line == "") {
        std::getline(std::cin, line);
      }

      TimeGap currentTime(line.substr(0, 5), line.substr(6, 5));

      if (is_time_valid(currentTime.start, currentTime.end)) {
        TimeGap prev_element = i == 1 ? best_time : times.back();
        if (currentTime.start != prev_element.end) {
          best_time.start = prev_element.end;
          best_time.end = currentTime.start;
        }
      }
      times.push_back(currentTime);
    }

    if (durationInMinutes(LOWER_TIME, times.back().end) >
        durationInMinutes(best_time.end, best_time.start)) {
      best_time.start = times.back().end;
      best_time.end = LOWER_TIME;
    }

    std::cout << "Day #" << n_set << ": the longest nap starts at "
              << best_time.start.print() << " and will last for "
              << best_time.printDuration() << std::endl;
  }

  return 0;
}