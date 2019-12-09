/**
 * This is to implement an SAS (State-Action-State) transitioning model
 * for reinformcement learning.
 */

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>

#include "utils.hpp"

using namespace std;

#define ROWS 8
#define COLS 8

enum MoveDirection { UP, DOWN, LEFT, RIGHT };
enum ActionType { EXPLORATION, EXPLOITATION };

struct State {
  int* data;
  State() {
    this->data = new int[ROWS * COLS];
    memset(this->data, 0, sizeof(this->data[0]) * ROWS * COLS);
  }

  State(State& state) {
    this->data = new int[ROWS * COLS];
    memcpy(this->data, state.data, sizeof(this->data[0]) * ROWS * COLS);
  }

  ~State() { delete[] this->data; }

  void print(ostream& out, bool readable = false) {
    for (int i = 0; i < ROWS; ++i) {
      for (int j = 0; j < COLS; ++j) {
        (out ? out : cout) << this->data[i * COLS + j];
      }
      if (readable) {
        (out ? out : cout) << endl;
      }
    }
    (out ? out : cout) << endl;
  }

  // void load(istream& in) { in.re }

  void setToAt(int value, int row, int col) {
    this->data[row * COLS + col] = value;
  }

  void setByAt(int value, int row, int col) {
    this->data[row * COLS + col] += value;
  }

  int getAt(int row, int col) { return this->data[row * COLS + col]; }
};

struct Agent {
  State move(MoveDirection moveDirection, ActionType actionType);
};

struct Action {
  ActionType type;
  MoveDirection direction;
};

void test() {
  State state;
  state.setToAt(3, 3, 3);
  state.setByAt(5, 3, 3);

  cout << state.getAt(3, 3) << endl;

  State newState(state);
  newState.setByAt(7, 1, 1);

  state.print(cout, true);
  newState.print(cout, true);

  ofstream mazeFile;
  mazeFile.open("maze.txt");
  state.print(mazeFile);
  newState.print(mazeFile);
  mazeFile.close();
}

int main() {
  test();
  // ifstream mazeFile;
  // mazeFile.open("maze.txt");
  // string s = getLastLine(mazeFile);
  // cout << s << endl;
  return 0;
}
