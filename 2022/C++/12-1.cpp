#include "basehead.hpp"
#include <algorithm>

struct pix {
  char value;
  bool visited;
  bool enqueued;
  int distance;
};

struct pos {
  int x;
  int y;
};

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
        pix newPix = {iptLine[k], false, false, INT_MAX};
        if (iptLine[k] == 'E') {
          newPix.value = 'z' + 1;
        }
        if (iptLine[k] == 'S') {
          newPix.value = 'a' - 1;
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
  for (int i = 0; i < L->size(); i++) {
    for (int j = 0; j < (*L)[i].size(); j++) {
      if ((*L)[i][j].visited == true) {
        cout << (*L)[i][j].value;
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

int ans(vector<vector<pix>> *L, pos start) {
#define L(i, j) (*L)[i][j]
  int X = L->size();
  int Y = (*L)[0].size();
  queue<pos> q;
  q.push(start);
  L(start.x, start.y).enqueued = true;
  char max_c = 'a' - 1;
  while (q.size() != 0) {
    pos p = q.front();
    q.pop();
    L(p.x, p.y).visited = true;
    if (L(p.x, p.y).value > max_c) {
      max_c = L(p.x, p.y).value;
    }
    if (L(p.x, p.y).value == 'z' + 1) {
      return L(p.x, p.y).distance;
    }
    if (p.x != 0 && (L(p.x - 1, p.y).value <= L(p.x, p.y).value + 1)) {
      if (!L(p.x - 1, p.y).visited && !L(p.x - 1, p.y).enqueued) {
        q.push({p.x - 1, p.y});
        L(p.x - 1, p.y).enqueued = true;
      }
      L(p.x - 1, p.y).distance =
          std::min(L(p.x - 1, p.y).distance, L(p.x, p.y).distance + 1);
    }
    if (p.x != X - 1 && (L(p.x + 1, p.y).value <= L(p.x, p.y).value + 1)) {
      if (!L(p.x + 1, p.y).visited && !L(p.x + 1, p.y).enqueued) {
        q.push({p.x + 1, p.y});
        L(p.x + 1, p.y).enqueued = true;
      }
      L(p.x + 1, p.y).distance =
          std::min(L(p.x + 1, p.y).distance, L(p.x, p.y).distance + 1);
    }
    if (p.y != 0 && (L(p.x, p.y - 1).value <= L(p.x, p.y).value + 1)) {
      if (!L(p.x, p.y - 1).visited && !L(p.x, p.y - 1).enqueued) {
        q.push({p.x, p.y - 1});
        L(p.x, p.y - 1).enqueued = true;
      }
      L(p.x, p.y - 1).distance =
          std::min(L(p.x, p.y - 1).distance, L(p.x, p.y).distance + 1);
    }
    if (p.y != Y - 1 && (L(p.x, p.y + 1).value <= L(p.x, p.y).value + 1)) {
      if (!L(p.x, p.y + 1).visited && !L(p.x, p.y + 1).enqueued) {
        q.push({p.x, p.y + 1});
        L(p.x, p.y + 1).enqueued = true;
      }
      L(p.x, p.y + 1).distance =
          std::min(L(p.x, p.y + 1).distance, L(p.x, p.y).distance + 1);
    }
  }
  return INT_MAX;
}

int main(void) {
  vector<vector<pix>> L;
  cout << ans(&L, input(&L)) << endl;
  return 0;
}
