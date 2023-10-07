#ifndef BASEHEAD_HPP
#define BASEHEAD_HPP

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::queue;
using std::string;
using std::unordered_map;
using std::vector;

inline vector<string> split(string str, string pattern = " ") {
  string::size_type pos;
  vector<string> result;
  str += pattern;
  int size = str.size();
  for (int i = 0; i < size; i++) {
    pos = str.find(pattern, i);
    if (pos < size) {
      string s = str.substr(i, pos - i);
      result.push_back(s);
      i = pos + pattern.size() - 1;
    }
  }
  return result;
}

template <typename T> inline void print(T v, string end = "\n") {
  cout << v;
  if (end != "\n") {
    cout << end;
  } else {
    cout << endl;
  }
}

#endif
