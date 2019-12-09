#include <boost/algorithm/string.hpp>
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
      int pos = fin.tellg();
      string lastLine;
      getline(fin, lastLine);
      boost::trim(lastLine);
      if (lastLine.length() > 0) {
        return lastLine;
      } else {
        fin.clear();
        fin.seekg(pos - 2, ios_base::beg);
      }
    } else {
      fin.seekg(-2, ios_base::cur);
    }
  }

  string lastLine;
  getline(fin, lastLine);
  boost::trim(lastLine);
  return lastLine;
}
