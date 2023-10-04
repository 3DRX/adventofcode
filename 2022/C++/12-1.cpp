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

#define L(i, j) (*L)[i][j]

int ans(vector<vector<pix>> *L, pos start) {
  int X = L->size();
  int Y = (*L)[0].size();
  int step = 0;
  queue<pos> *current_layer = new queue<pos>;
  queue<pos> *next_layer = new queue<pos>;
  current_layer->push(start);
  L(start.x, start.y).enqueued = true;
  char max_c = 'a' - 1;
  while (true) {
    cout << "\riteration: " << step << " ";
    cout << "max_c: " << max_c << " ";
    cout << "current_layer: " << current_layer->size() << std::flush;
    if (max_c >= 'y') {
      cout << endl;
      display(L);
    }
    while (current_layer->size() != 0) {
      pos p = current_layer->front();
      current_layer->pop();
      L(p.x, p.y).visited = true;
      if (L(p.x, p.y).value > max_c) {
        max_c = L(p.x, p.y).value;
      }
      if (L(p.x, p.y).value == 'z' + 1) {
        delete current_layer;
        delete next_layer;
        return L(p.x, p.y).distance;
      }
      // get adjacent position of p
      if (p.x != 0 && !L(p.x - 1, p.y).visited && !L(p.x - 1, p.y).enqueued &&
          (L(p.x - 1, p.y).value <= L(p.x, p.y).value + 1)) {
        next_layer->push({p.x - 1, p.y});
        L(p.x - 1, p.y).enqueued = true;
        L(p.x - 1, p.y).distance =
            std::min(L(p.x - 1, p.y).distance, L(p.x, p.y).distance + 1);
        // cout << "push: " << p.x - 1 << " " << p.y << endl;
      }
      if (p.x != X - 1 && !L(p.x + 1, p.y).visited &&
          !L(p.x + 1, p.y).enqueued &&
          (L(p.x + 1, p.y).value <= L(p.x, p.y).value + 1)) {
        next_layer->push({p.x + 1, p.y});
        L(p.x + 1, p.y).enqueued = true;
        L(p.x + 1, p.y).distance =
            std::min(L(p.x + 1, p.y).distance, L(p.x, p.y).distance + 1);
        // cout << "push: " << p.x + 1 << " " << p.y << endl;
      }
      if (p.y != 0 && !L(p.x, p.y - 1).visited && !L(p.x, p.y - 1).enqueued &&
          (L(p.x, p.y - 1).value <= L(p.x, p.y).value + 1)) {
        next_layer->push({p.x, p.y - 1});
        L(p.x, p.y - 1).enqueued = true;
        L(p.x, p.y - 1).distance =
            std::min(L(p.x, p.y - 1).distance, L(p.x, p.y).distance + 1);
        // cout << "push: " << p.x << " " << p.y - 1 << endl;
      }
      if (p.y != Y - 1 && !L(p.x, p.y + 1).visited &&
          !L(p.x, p.y + 1).enqueued &&
          (L(p.x, p.y + 1).value <= L(p.x, p.y).value + 1)) {
        next_layer->push({p.x, p.y + 1});
        L(p.x, p.y + 1).enqueued = true;
        L(p.x, p.y + 1).distance =
            std::min(L(p.x, p.y + 1).distance, L(p.x, p.y).distance + 1);
        // cout << "push: " << p.x << " " << p.y + 1 << endl;
      }
    }
    // swap
    auto t = current_layer;
    current_layer = next_layer;
    next_layer = t;
    step++;
  }
}

int main(void) {
  vector<vector<pix>> L;
  cout << ans(&L, input(&L)) << endl;
  return 0;
}
