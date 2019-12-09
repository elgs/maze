#include <fstream>
#include <iostream>

using namespace std;

string getLastLine(ifstream& fin) {
  fin.seekg(-1, ios_base::end);

  bool keepLooping = true;
  while (keepLooping) {
    char ch;
    fin.get(ch);

    if ((int)fin.tellg() <= 1) {
      fin.seekg(0);
      keepLooping = false;
    } else if (ch == '\n') {
      keepLooping = false;
    } else {
      fin.seekg(-2, ios_base::cur);
    }
  }

  string lastLine;
  getline(fin, lastLine); // Read the current line
  return lastLine;
}