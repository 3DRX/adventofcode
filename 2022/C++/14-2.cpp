#include "basehead.hpp"

#define WALL '+'
#define SAND '.'
#define AIR ' '

vector<string> split(string str, string pattern) {
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

struct Point {
  int x;
  int y;
};

struct Rock {
  vector<Point> points;

  Rock(string line) {
    for (auto &point_str : split(line, " -> ")) {
      auto point = split(point_str, ",");
      this->points.push_back({stoi(point[0]), stoi(point[1])});
    }
  }
};

void input(vector<Rock> &rocks) {
  string line;
  std::ifstream infile("in.txt");
  while (getline(infile, line)) {
    if (line == "") {
      continue;
    } else {
      rocks.push_back(Rock(line));
    }
  }
}

void display(vector<vector<char>> &screen) {
  cout << "\033[0;0H" << endl;
  for (int i = 0; i < screen.size(); i++) {
    for (int j = 0; j < screen[0].size(); j++) {
      if (screen[i][j] == WALL) {
        cout << "\033[0m";
      } else if (screen[i][j] == SAND) {
        cout << "\033[2m";
      } else {
      }
      cout << screen[i][j];
    }
    cout << endl;
  }
}

int iteration(vector<vector<char>> &screen, Point start) {
  static int sand_count = 0;
  Point current = start;
  screen[current.y][current.x] = SAND;
  while (true) {
    // display(screen);
    if (current.y == screen.size() - 1) {
      break;
    } else if (screen[current.y + 1][current.x] == AIR) {
      screen[current.y][current.x] = AIR;
      screen[current.y + 1][current.x] = SAND;
      current.y += 1;
    } else if (current.x == 0) {
      break;
    } else if (screen[current.y + 1][current.x - 1] == AIR) {
      screen[current.y][current.x] = AIR;
      screen[current.y + 1][current.x - 1] = SAND;
      current.y += 1;
      current.x -= 1;
    } else if (current.x == screen[0].size() - 1) {
      break;
    } else if (screen[current.y + 1][current.x + 1] == AIR) {
      screen[current.y][current.x] = AIR;
      screen[current.y + 1][current.x + 1] = SAND;
      current.y += 1;
      current.x += 1;
    } else if (screen[start.y][start.x] == SAND) {
      break;
    } else {
      sand_count++;
      break;
    }
  }
  return sand_count;
}

int main(int argc, char *argv[]) {
  cout << "\033[?25l" << endl;
  vector<Rock> rocks;
  input(rocks);
  // get the size of the screen
  int max_y = 0;
  for (auto &rock : rocks) {
    for (auto &point : rock.points) {
      max_y = std::max(max_y, point.y);
    }
  }
  int height = max_y + 3;
  int width = height * 2 - 1;
  vector<vector<char>> screen =
      vector<vector<char>>(height, vector<char>(width, AIR));
  int min_x = 500 - (height - 1);
  int max_x = 500 + (height - 1);
  Point start = {500 - min_x, 0};
  rocks.push_back(Rock(std::to_string(min_x) + "," + std::to_string(max_y + 2) +
                       " -> " + std::to_string(max_x) + "," +
                       std::to_string(max_y + 2)));
  // draw the rocks
  for (auto &rock : rocks) {
    for (size_t i = 0; i < rock.points.size() - 1; i++) {
      auto a = rock.points[i];
      auto b = rock.points[i + 1];
      if (a.y == b.y) {
        auto min = std::min(a.x, b.x);
        auto max = std::max(a.x, b.x);
        for (int j = min; j <= max; j++) {
          screen[a.y][j - min_x] = WALL;
        }
      } else if (a.x == b.x) {
        auto min = std::min(a.y, b.y);
        auto max = std::max(a.y, b.y);
        for (int j = min; j <= max; j++) {
          screen[j][a.x - min_x] = WALL;
        }
      } else {
        cout << "error" << endl;
        exit(1);
      }
    }
  }
  // display(screen);
  int last_count = 0;
  int this_count = 0;
  while (true) {
    this_count = iteration(screen, start);
    if (this_count == last_count) {
      cout << "max sand: " << this_count + 1;
      break;
    } else {
      last_count = this_count;
    }
  }
  cout << "\33[?25h";
  return 0;
}
