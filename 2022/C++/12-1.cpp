#include "basehead.hpp"

struct pix {
  char value;
  bool visited;
  int distance;
};

struct pos {
  int x;
  int y;
};

// elevation
char E(char c) {
  if (c == 'E') {
    return 'z';
  } else if (c == 'S') {
    return 'a';
  } else {
    return c;
  }
}

pos input(vector<vector<pix>> *L) {
  string iptLine;
  pos start;
  int i = 0;
  while (1) {
    getline(cin, iptLine);
    if (iptLine == "") {
      break;
    } else {
      vector<pix> newLine;
      for (int k = 0; k < iptLine.size(); k++) {
        pix newPix = {iptLine[k], false, INT_MAX};
        if (iptLine[k] == 'S') {
          newPix.distance = 0;
          start.x = i;
          start.y = k;
        }
        newLine.push_back(newPix);
      }
      L->push_back(newLine);
    }
    i++;
  }
  return start;
}

void display(vector<vector<pix>> *L) {
  cout << "\033[0;0H" << endl;
  for (int i = 0; i < L->size(); i++) {
    for (int j = 0; j < (*L)[i].size(); j++) {
      if ((*L)[i][j].visited == true) {
        cout << "\033[0m";
      } else {
        cout << "\033[2m";
      }
      cout << (*L)[i][j].value << std::flush;
    }
    cout << endl;
  }
}

int ans(vector<vector<pix>> *L, pos start) {
#define L(i, j) (*L)[i][j]
  cout << "\033[?25l" << endl;
  int X = L->size();
  int Y = (*L)[0].size();
  queue<pos> q;
  q.push(start);
  L(start.x, start.y).visited = true;
  while (q.size() != 0) {
    display(L);
    pos p = q.front();
    q.pop();
    if (L(p.x, p.y).value == 'E') {
      return L(p.x, p.y).distance;
    }
    if (p.x != 0 && (E(L(p.x - 1, p.y).value) <= E(L(p.x, p.y).value) + 1) &&
        !L(p.x - 1, p.y).visited) {
      q.push({p.x - 1, p.y});
      L(p.x - 1, p.y).visited = true;
      L(p.x - 1, p.y).distance =
          std::min(L(p.x - 1, p.y).distance, L(p.x, p.y).distance + 1);
    }
    if (p.x != X - 1 &&
        (E(L(p.x + 1, p.y).value) <= E(L(p.x, p.y).value) + 1) &&
        !L(p.x + 1, p.y).visited) {
      q.push({p.x + 1, p.y});
      L(p.x + 1, p.y).visited = true;
      L(p.x + 1, p.y).distance =
          std::min(L(p.x + 1, p.y).distance, L(p.x, p.y).distance + 1);
    }
    if (p.y != 0 && (E(L(p.x, p.y - 1).value) <= E(L(p.x, p.y).value) + 1) &&
        !L(p.x, p.y - 1).visited) {
      q.push({p.x, p.y - 1});
      L(p.x, p.y - 1).visited = true;
      L(p.x, p.y - 1).distance =
          std::min(L(p.x, p.y - 1).distance, L(p.x, p.y).distance + 1);
    }
    if (p.y != Y - 1 &&
        (E(L(p.x, p.y + 1).value) <= E(L(p.x, p.y).value) + 1) &&
        !L(p.x, p.y + 1).visited) {
      q.push({p.x, p.y + 1});
      L(p.x, p.y + 1).visited = true;
      L(p.x, p.y + 1).distance =
          std::min(L(p.x, p.y + 1).distance, L(p.x, p.y).distance + 1);
    }
  }
  cout << "\33[?25h" << endl;
  return INT_MAX;
}

int main(void) {
  vector<vector<pix>> L;
  cout << ans(&L, input(&L)) << endl;
  return 0;
}
