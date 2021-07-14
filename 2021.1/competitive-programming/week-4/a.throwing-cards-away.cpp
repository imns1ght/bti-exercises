#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

void clear(std::queue<int> &queue) {
  std::queue<int> empty;
  std::swap(queue, empty);
}

int main() {
  std::queue<int> queue;
  std::vector<int> discarded;
  int n;

  while (std::cin >> n && n != 0) {
    clear(queue);
    discarded.clear();
    for (int i = 1; i <= n; i++) {
      queue.push(i);
    }

    while (queue.size() >= 1) {
      if (queue.size() == 1) break;
      discarded.push_back(queue.front());
      queue.pop();
      queue.push(queue.front());
      queue.pop();
    }

    std::stringstream ss;
    std::cout << "Discarded cards:";
    for (int i : discarded) {
      ss << " " << i << ",";
    }
    std::string discarded = ss.str();
    std::cout << discarded.substr(0, discarded.size() - 1) << std::endl;
    std::cout << "Remaining card: " << queue.front() << std::endl;
  }

  return 0;
}