#include <algorithm>
#include <iostream>

int main(void) {
    int test_cases;
    int salaries[3];

    std::cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        std::cin >> salaries[0] >> salaries[1] >> salaries[2];
        std::sort(&salaries[0], &salaries[3]);
        std::cout << "Case " << i + 1 << ": " << salaries[1] << std::endl;
    }

    return 0;
}