#include <iostream>
#include <vector>

int ROWS, COLUMNS;

class Square {
 public:
  int minesAround = 0;
  bool isMine = false;

  Square();
  Square(bool isMine) { isMine = isMine; }

  void setIsMine(bool isMine) { this->isMine = isMine; }
  void increaseMinesAround() { ++(this->minesAround); }
};

struct Coords {
  int x, y;
};

bool isValid(int x, int y) {
  return (x >= 0) && (x < ROWS) && (y >= 0) && (y < COLUMNS);
}

void calcMinesAround(std::vector<std::vector<Square>>* board,
                     std::vector<Coords>* mines) {
  for (Coords mine : *mines) {
    // North
    if (isValid(mine.x - 1, mine.y))
      (*board)[mine.x - 1][mine.y].increaseMinesAround();
    // North-East
    if (isValid(mine.x - 1, mine.y + 1))
      (*board)[mine.x - 1][mine.y + 1].increaseMinesAround();
    // East
    if (isValid(mine.x, mine.y + 1))
      (*board)[mine.x][mine.y + 1].increaseMinesAround();
    // South-East
    if (isValid(mine.x + 1, mine.y + 1))
      (*board)[mine.x + 1][mine.y + 1].increaseMinesAround();
    // South
    if (isValid(mine.x + 1, mine.y))
      (*board)[mine.x + 1][mine.y].increaseMinesAround();
    // South-West
    if (isValid(mine.x + 1, mine.y - 1))
      (*board)[mine.x + 1][mine.y - 1].increaseMinesAround();
    // West
    if (isValid(mine.x, mine.y - 1))
      (*board)[mine.x][mine.y - 1].increaseMinesAround();
    // North-West
    if (isValid(mine.x - 1, mine.y - 1))
      (*board)[mine.x - 1][mine.y - 1].increaseMinesAround();
  }
}

int main(void) {
  int tCases = 1;

  while (std::cin >> ROWS >> COLUMNS) {
    if (ROWS == 0 && COLUMNS == 0) return 0;
    std::vector<std::vector<Square>> board(
        ROWS, std::vector<Square>(COLUMNS, new Square(false)));
    std::vector<Coords> mines;

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        char element;
        std::cin >> element;
        if (element == '*') {
          mines.push_back({i, j});
          board[i][j].setIsMine(true);
        }
        board[i][j].setIsMine(element == '*' ? true : false);
      }
    }

    calcMinesAround(&board, &mines);

    std::cout << (tCases == 1 ? "Field #" : "\nField #") << tCases << ':'
              << std::endl;
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        if (board[i][j].isMine) {
          std::cout << '*';
        } else {
          std::cout << board[i][j].minesAround;
        }
      }
      std::cout << "" << std::endl;
    }
    tCases++;
  }

  return 0;
}