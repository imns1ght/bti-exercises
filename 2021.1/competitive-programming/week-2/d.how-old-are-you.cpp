#include <cmath>
#include <iostream>
#include <string>

struct Date {
  int day, month, year;
};

class Dates {
 public:
  struct Date current;
  struct Date birth;

  Dates(std::string currentDate, std::string birthDate) {
    current.day = std::stoi(currentDate.substr(0, 2));
    current.month = std::stoi(currentDate.substr(3, 2));
    current.year = std::stoi(currentDate.substr(6, 4));
    birth.day = std::stoi(birthDate.substr(0, 2));
    birth.month = std::stoi(birthDate.substr(3, 2));
    birth.year = std::stoi(birthDate.substr(6, 4));
  }

  std::string get_age() {
    int years = 0;
    int months = 0;
    int days = 0;

    years += std::abs(current.year - birth.year);
    months += std::abs(current.month - birth.month);
    days += std::abs(current.day - birth.day);

    if (current.month < birth.month ||
        (current.day < birth.day && current.month == birth.month)) {
      years--;
    }

    if ((current.year < birth.year) ||
        (current.year == birth.year && current.month < birth.month) ||
        (current.year == birth.year && current.month == birth.month &&
         current.day < birth.day)) {
      return "Invalid birth date";
    } else if (years > 130) {
      return "Check birth date";
    } else {
      return std::to_string(years);
    }
  }
};

int main(void) {
  int test_cases;

  std::cin >> test_cases;

  for (int i = 1; i <= test_cases; i++) {
    std::string currentDate, birthDate;
    while (std::getline(std::cin, currentDate) && currentDate == "")
      ;
    std::getline(std::cin, birthDate);
    Dates date(currentDate, birthDate);
    std::cout << "Case #" << i << ": " << date.get_age() << std::endl;
  }
}