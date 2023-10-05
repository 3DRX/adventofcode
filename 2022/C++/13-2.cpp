#include "basehead.hpp"

struct Item {
  int i;
  vector<Item> v;
  bool isInt;

  Item(int i) : isInt(true), i(i){};
  Item() : isInt(false), v(vector<Item>()), i(0){};
  Item(string line)
      : isInt(parse(line).isInt), i(parse(line).i), v(parse(line).v){};
  Item(const Item &other) : isInt(other.isInt), i(other.i), v(other.v){};
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
      this->isInt = other.isInt;
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

private:
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

void input(vector<Item> *L) {
  string line;
  std::ifstream infile("in.txt");
  while (getline(infile, line)) {
    if (line == "") {
      continue;
    } else {
      L->push_back(Item(line));
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
  vector<Item> L;
  input(&L);
  // for (auto &l : L) {
  //   print_item(l, true);
  //   cout << endl;
  // }
  // cout << "============================" << endl;
  auto a = Item("[[2]]");
  auto b = Item("[[6]]");
  size_t index_a = 0;
  size_t index_b = 0;
  L.push_back(a);
  L.push_back(b);
  std::sort(L.begin(), L.end());
  for (auto &l : L) {
    // print_item(l, true);
    // cout << endl;
    if (l == a) {
      index_a = (&l - &L[0]) + 1;
      // cout << "index_a: " << index_a << endl;
    }
    if (l == b) {
      index_b = (&l - &L[0]) + 1;
      // cout << "index_b: " << index_b << endl;
    }
  }
  cout << index_a * index_b << endl;
  return 0;
}
