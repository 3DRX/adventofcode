#ifndef BASEHEAD_HPP
#define BASEHEAD_HPP

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include <vector>

#define TOSTR(os, x) friend std::ostream &operator<<(std::ostream &os, const x)

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

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
  i64 size = str.size();
  for (i64 i = 0; i < size; i++) {
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
