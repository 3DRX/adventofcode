#include "basehead.hpp"

struct Valve {
  string name;
  u64 flow_rate;
  vector<string> adj;

  Valve() {}

  Valve(string str) {
    auto s = split(str);
    this->name = s[1];
    this->flow_rate = stoul(split(s[4].substr(0, s[4].size() - 1), "=")[1]);
    for (u64 i = 9; i < s.size(); i++) {
      if (i == s.size() - 1) {
        this->adj.push_back(s[i]);
      } else {
        this->adj.push_back(s[i].substr(0, s[i].size() - 1));
      }
    }
  }

  TOSTR(os, Valve &v) {
    os << v.name << " ";
    os << "(" << v.flow_rate << "):";
    for (auto &i : v.adj) {
      os << " " << i;
    }
    return os;
  }
};

string input(unordered_map<string, Valve> &v) {
  string line;
  std::ifstream infile("in.txt");
  string start = "";
  while (getline(infile, line)) {
    if (line == "") {
      continue;
    } else {
      auto new_valve = Valve(line);
      if (start == "") {
        start = new_valve.name;
      }
      v[new_valve.name] = new_valve;
    }
  }
  return start;
}

u32 max_pressure(unordered_map<string, Valve> &v, string start) {
  cout << start << endl;
  return 0;
}

int main(int argc, char *argv[]) {
  unordered_map<string, Valve> valves;
  string start = input(valves);
  print(max_pressure(valves, start));
  return 0;
}
