/**
 * This is to implement an SAS (State-Action-State) transitioning model
 * for reinformcement learning.
 */

#include <iostream>

using namespace std;

#define DEBUG

#define ROWS 10
#define COLS 10

enum MoveDirection { UP, DOWN, LEFT, RIGHT };
enum ActionType { EXPLORATION, EXPLOITATION };

struct State {
  int* data;
  State() {
    this->data = new int[ROWS * COLS];
#ifdef DEBUG
    cout << "Data created." << endl;
#endif
    memset(this->data, 0, sizeof(int) * ROWS * COLS);
  }

  ~State() {
    delete[] this->data;
#ifdef DEBUG
    cout << "Data cleaned up." << endl;
#endif
  }

  void print() {
    for (int i = 0; i < ROWS; ++i) {
      for (int j = 0; j < COLS; ++j) {
        cout << this->data[i * COLS + j];
      }
      cout << endl;
    }
  }

  void setToAt(int value, int row, int col) {
    this->data[row * COLS + col] = value;
  }

  void setByAt(int value, int row, int col) {
    this->data[row * COLS + col] += value;
  }

  int getAt(int row, int col) { return this->data[row * COLS + col]; }
};

struct Action {
  ActionType type;
  MoveDirection direction;
};

int main() {
  State state;
  state.setToAt(3, 3, 3);
  state.setByAt(5, 3, 3);
  state.print();
  cout << state.getAt(3, 3) << endl;
  return 0;
}
