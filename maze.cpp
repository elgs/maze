/**
 * This is to implement an SAS (State-Action-State) transitioning model
 * for reinformcement learning.
 */

#include <iostream>

using namespace std;

const int ROWS = 10;
const int COLS = 10;

enum MoveDirection { UP, DOWN, LEFT, RIGHT };
enum ActionType { EXPLORATION, EXPLOITATION };

struct State {
  int* data;
  State() {
    this->data = new int[ROWS * COLS];
    cout << sizeof this->data[0] << endl;
    memset(this->data, 0xFF, sizeof(int) * ROWS * COLS);
  }

  ~State() { delete[] this->data; }
};

struct Action {
  ActionType type;
  MoveDirection direction;
};

int main() {
  State state;
  return 0;
}
