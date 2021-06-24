#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main(void) {
  int test_cases;
  std::cin >> test_cases;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  for (int i = 0; i < test_cases; i++) {
    bool x_won = false;
    bool o_won = false;
    int x_num = 0;
    int o_num = 0;
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

    // Get input
    for (int j = 0; j < 3; j++) {
      std::cin >> board[j][0] >> board[j][1] >> board[j][2];

      for (char c : board[j]) {
        if (c == 'X') {
          x_num++;
        } else if (c == 'O') {
          o_num++;
        }
      }
    }

    for (int j = 0; j < 3; j++) {
      // Check rows
      if (board[j][0] == 'X' && board[j][1] == 'X' && board[j][2] == 'X') {
        x_won = true;
      } else if (board[j][0] == 'O' && board[j][1] == 'O' &&
                 board[j][2] == 'O') {
        o_won = true;
      }
      // Check columns
      if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
        x_won = true;
      } else if (board[0][j] == 'O' && board[1][j] == 'O' &&
                 board[2][j] == 'O') {
        o_won = true;
      }
    }

    // Up-left -> down-right
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
      x_won = true;
    } else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
      o_won = true;
    }

    // Up-right -> down-left
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
      x_won = true;
    } else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
      o_won = true;
    }

    bool is_valid = true;
    if (x_won && o_won) {
      is_valid = false;
    } else if (x_num < o_num) {
      is_valid = false;
    } else if ((o_won && x_num > o_num) || (x_won && x_num == o_num) ||
               (x_won && o_num > x_num)) {
      is_valid = false;
    } else if (std::abs(x_num - o_num) >= 2) {
      is_valid = false;
    }
    std::cout << (is_valid ? "yes" : "no") << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return 0;
}