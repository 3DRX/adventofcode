
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

struct pix {
    char value;
    bool visited;
    pix(char value, bool visited)
    {
        this->value = value;
        this->visited = visited;
    }
};

void input(vector<vector<pix>>* L);
void testipt(vector<vector<pix>>* L);
int  ans(vector<vector<pix>>* L);

int main(void)
{
    vector<vector<pix>> L;
    input(&L);
    // testipt(&L);
    cout << ans(&L) << endl;
    return 0;
}

void input(vector<vector<pix>>* L)
{
    string iptLine;
    while (1) {
        getline(cin, iptLine);
        if (iptLine == "") {
            break;
        }
        else {
            vector<pix> newLine;
            for (char c : iptLine) {
                newLine.push_back(pix(c, false));
            }
            L->push_back(newLine);
        }
    }
}

void testipt(vector<vector<char>>* L)
{
    for (auto A : *L) {
        for (auto B : A) {
            cout << B;
        }
        cout << endl;
    }
}

vector<char> possibleDirections(int i, int k, vector<vector<pix>>* L, vector<vector<bool>>* visited)
{
    vector<char> ans;
    char         self = L->at(i).at(k).value;
    if (self == 'S') {
        if (i != L->size() - 1) {
            ans.push_back('s');
        }
        if (k != L->at(0).size() - 1) {
            ans.push_back('d');
        }
        if (i != 0) {
            ans.push_back('w');
        }
        if (k != 0) {
            ans.push_back('a');
        }
    }
    else {
        // first, lets see if i is under 20(E is at 20,145) or not.
        // if so, go down first
        if (i < 20) {
            if (i != L->size() - 1 && L->at(i + 1).at(k).value - self <= 1 && visited->at(i + 1).at(k) == false) {
                if (L->at(i + 1).at(k).value == 'E' && (self != 'z' && self != 'y')) {
                }
                else {
                    ans.push_back('s');
                }
            }
            if (i != 0 && L->at(i - 1).at(k).value - self <= 1 && visited->at(i - 1).at(k) == false) {
                if (L->at(i - 1).at(k).value == 'E' && (self != 'z' && self != 'y')) {
                }
                else {
                    ans.push_back('w');
                }
            }
        }
        // else, go up first
        else {
            if (i != 0 && L->at(i - 1).at(k).value - self <= 1 && visited->at(i - 1).at(k) == false) {
                if (L->at(i - 1).at(k).value == 'E' && (self != 'z' && self != 'y')) {
                }
                else {
                    ans.push_back('w');
                }
            }
            if (L->at(i + 1).at(k).value == 'E' && (self != 'z' && self != 'y')) {
            }
            else {
                ans.push_back('s');
            }
        }
        if (k != L->at(0).size() - 1 && L->at(i).at(k + 1).value - self <= 1 && visited->at(i).at(k + 1) == false) {
            if (L->at(i).at(k + 1).value == 'E' && (self != 'z' && self != 'y')) {
            }
            else {
                ans.push_back('d');
            }
        }
        if (k != 0 && L->at(i).at(k - 1).value - self <= 1 && visited->at(i).at(k - 1) == false) {
            if (L->at(i).at(k - 1).value == 'E' && (self != 'z' && self != 'y')) {
            }
            else {
                ans.push_back('a');
            }
        }
    }
    return ans;
}

void printGrid(vector<vector<bool>>* visited)
{
    for (auto line : *visited) {
        for (auto a : line) {
            if (a) {
                cout << "#";
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int& ans, vector<vector<pix>>* L, int i, int k, int stepCount, vector<vector<bool>> visited)
{
    L->at(i).at(k).visited = true;
    visited.at(i).at(k) = true;
    printGrid(&visited);
    if (L->at(i).at(k).value == 'E') {
        cout << "find a solution with step: " << stepCount << endl;
        if (stepCount < ans) {
            ans = stepCount;
        }
        if (ans == 29) {
            exit(EXIT_SUCCESS);
        }
        return;
    }
    else {
        for (char direction : possibleDirections(i, k, L, &visited)) {
            if (direction == 'w') {
                dfs(ans, L, i - 1, k, stepCount + 1, visited);
            }
            else if (direction == 'a') {
                dfs(ans, L, i, k - 1, stepCount + 1, visited);
            }
            else if (direction == 's') {
                dfs(ans, L, i + 1, k, stepCount + 1, visited);
            }
            else if (direction == 'd') {
                dfs(ans, L, i, k + 1, stepCount + 1, visited);
            }
            else {
                exit(EXIT_FAILURE);
            }
        }
    }
}

int ans(vector<vector<pix>>* L)
{
    int                  ans = L->size() * L->at(0).size();
    vector<vector<bool>> visited;
    for (int i = 0; i < L->size(); i++) {
        vector<bool> a;
        for (int k = 0; k < L->at(0).size(); k++) {
            a.push_back(false);
        }
        visited.push_back(a);
    }
    dfs(ans, L, 0, 0, 0, visited);
    return ans;
}
