#include "basehead.hpp"

struct Item {
  int i;
  vector<Item> v;
  const bool isInt;

  Item(int i) : isInt(true), i(i){};
  Item() : isInt(false), v(vector<Item>()){};
  void print_item(Item item, bool end) const {
    if (item.isInt) {
      cout << item.i;
    } else {
      cout << "[";
      for (size_t i = 0; i < item.v.size(); i++) {
        if (i == item.v.size() - 1) {
          print_item(item.v[i], true);
        } else {
          print_item(item.v[i], false);
        }
      }
      cout << "]";
    }
    if (!end) {
      cout << ", ";
    }
  }

  Item &operator=(const Item &other) {
    if (this != &other) {
      if (other.isInt) {
        this->i = other.i;
      } else {
        this->v = other.v;
      }
    }
    return *this;
  }

  bool operator<(const Item &other) const {
    // cout << "comparing: ";
    // print_item(*this, true);
    // cout << " and ";
    // print_item(other, true);
    // cout << endl;
    if (this->isInt && other.isInt) {
      return this->i < other.i;
    } else if (!this->isInt && !other.isInt) {
      for (size_t i = 0; i < std::min(this->v.size(), other.v.size()); i++) {
        if (this->v[i] < other.v[i]) {
          return true;
        } else if (this->v[i] == other.v[i]) {
          continue;
        } else {
          return false;
        }
      }
      return this->v.size() < other.v.size();
    } else {
      if (this->isInt) {
        if (other.v.size() == 0) {
          return false;
        } else if (other.v.size() == 1) {
          return Item(this->i) < other.v[0];
        } else {
          return !(other.v[0] < Item(this->i));
        }
      } else {
        if (this->v.size() == 0) {
          return true;
        } else {
          return this->v[0] < Item(other.i);
        }
      }
    }
  }

  bool operator==(const Item &other) const {
    if (this->isInt && other.isInt) {
      return this->i == other.i;
    } else if (!this->isInt && !other.isInt) {
      if (this->v.size() != other.v.size()) {
        return false;
      } else {
        for (size_t i = 0; i < this->v.size(); i++) {
          if (this->v[i] == other.v[i]) {
            continue;
          } else {
            return false;
          }
        }
        return true;
      }
    } else {
      if (this->isInt) {
        if (other.v.size() == 1 && other.v[0] == this->i) {
          return true;
        } else {
          return false;
        }
      } else {
        if (this->v.size() == 1 && this->v[0] == other.i) {
          return true;
        } else {
          return false;
        }
      }
    }
  }
};

vector<string> split_elements(string str) {
  // str is like "[1,2,3]", split it into ["1", "2", "3"]
  vector<string> res;
  if (str == "[]") {
    return res;
  }
  int layer = 0;
  string tmp = "";
  string subs = str.substr(1, str.size() - 2);
  for (auto &i : subs) {
    if (i == ',' && layer == 0) {
      res.push_back(tmp);
      tmp = "";
    } else if (i == '[') {
      layer++;
      tmp += i;
    } else if (i == ']') {
      layer--;
      tmp += i;
    } else {
      tmp += i;
    }
  }
  res.push_back(tmp);
  return res;
}

struct Pair {
  Item first = Item(0);
  Item second = Item(0);

  Pair(string first, string second)
      : first(parse(first)), second(parse(second)){};

private:
  Item parse(string s) {
    if (s[0] == '[' && s[s.size() - 1] == ']') {
      Item res = Item();
      for (auto &i : split_elements(s)) {
        res.v.push_back(parse(i));
      }
      return res;
    } else {
      return Item(stoi(s));
    }
  }
};

void input(vector<Pair> *L) {
  string line;
  string first = "", second = "";
  std::ifstream infile("in.txt");
  while (getline(infile, line)) {
    if (line == "") {
      L->push_back(Pair(first, second));
      first = "";
      second = "";
    } else {
      if (first == "") {
        first = line;
      } else {
        second = line;
      }
    }
  }
}

void print_item(Item item, bool end) {
  if (item.isInt) {
    cout << item.i;
  } else {
    cout << "[";
    for (size_t i = 0; i < item.v.size(); i++) {
      if (i == item.v.size() - 1) {
        print_item(item.v[i], true);
      } else {
        print_item(item.v[i], false);
      }
    }
    cout << "]";
  }
  if (!end) {
    cout << ", ";
  }
}

int main(int argc, char *argv[]) {
  vector<Pair> L;
  input(&L);
  int count = 0;
  for (size_t i = 0; i < L.size(); i++) {
    auto pair = L[i];
    if (pair.first < pair.second) {
      count += i + 1;
      // cout << i + 1 << endl;
    }
  }
  cout << "count: " << count << endl;
  return 0;
}
