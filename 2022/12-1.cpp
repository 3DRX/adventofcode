
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#define VAL(a) (a == 'S' ? 0 : a == 'E' ? 25 \
                                        : a - 'a')

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

struct pix {
    char value;
    bool visited;
    int  distence;
    int  i;
    int  k;
    pix(int i, int k, char value, bool visited, int distence = INT_MAX)
    {
        this->value = value;
        this->visited = visited;
        this->distence = distence;
        this->i = i;
        this->k = k;
    }
    pix(const pix& a)
    {
        this->value = a.value;
        this->visited = a.visited;
        this->distence = a.distence;
        this->i = a.i;
        this->k = a.k;
    }
};

pix input(vector<vector<pix>>* L);
int ans(vector<vector<pix>>* L, pix P);

int main(void)
{
    vector<vector<pix>> L;
    cout << ans(&L, input(&L)) << endl;
    return 0;
}

pix input(vector<vector<pix>>* L)
{
    pix*   res;
    string iptLine;
    int    i = 0;
    while (1) {
        getline(cin, iptLine);
        if (iptLine == "") {
            break;
        }
        else {
            vector<pix> newLine;
            for (int k = 0; k < iptLine.size(); k++) {
                pix newPix = pix(i, k, iptLine[k], false, INT_MAX);
                newLine.push_back(newPix);
                if (newPix.value == 'S') {
                    res = new pix(newPix);
                }
            }
            L->push_back(newLine);
        }
        i++;
    }
    return *res;
}

void printGrid(vector<vector<pix>>* L)
{
    for (auto line : *L) {
        for (auto a : line) {
            if (a.visited) {
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

bool isValid(vector<vector<pix>>* L, int i, int k, char direction)
{
    pix  self = L->at(i).at(k);
    pix* dest;
    if (direction == 'w') {
        if (i == 0) {
            return false;
        }
        dest = &L->at(i - 1).at(k);
    }
    else if (direction == 'a') {
        if (k == 0) {
            return false;
        }
        dest = &L->at(i).at(k - 1);
    }
    else if (direction == 's') {
        if (i == L->size() - 1) {
            return false;
        }
        dest = &L->at(i + 1).at(k);
    }
    else {
        if (k == L->at(0).size() - 1) {
            return false;
        }
        dest = &L->at(i).at(k + 1);
    }
    if (VAL(dest->value) - VAL(self.value) > 1 || dest->visited) {
        return false;
    }
    else {
        return true;
    }
}

int updateList(vector<vector<pix>>* L, vector<pix>* dijkstraList)
{
    while (1) {
        for (auto iter = dijkstraList->begin(); iter != dijkstraList->end(); iter++) {
            if (iter->value == 'E') {
                return iter->distence;
            }
            if (isValid(L, iter->i, iter->k, 'w')) {
                if (iter->distence + 1 < L->at(iter->i - 1).at(iter->k).distence) {
                    L->at(iter->i - 1).at(iter->k).distence++;
                }
                dijkstraList->push_back(L->at(iter->i - 1).at(iter->k));
            }
            if (isValid(L, iter->i, iter->k, 'a')) {
                if (iter->distence + 1 < L->at(iter->i).at(iter->k - 1).distence) {
                    L->at(iter->i - 1).at(iter->k).distence++;
                }
                dijkstraList->push_back(L->at(iter->i - 1).at(iter->k));
            }
            if (isValid(L, iter->i, iter->k, 's')) {
                if (iter->distence + 1 < L->at(iter->i + 1).at(iter->k).distence) {
                    L->at(iter->i - 1).at(iter->k).distence++;
                }
                dijkstraList->push_back(L->at(iter->i - 1).at(iter->k));
            }
            if (isValid(L, iter->i, iter->k, 'd')) {
                if (iter->distence + 1 < L->at(iter->i).at(iter->k + 1).distence) {
                    L->at(iter->i - 1).at(iter->k).distence++;
                }
                dijkstraList->push_back(L->at(iter->i - 1).at(iter->k));
            }
            dijkstraList->erase(iter);
        }
    }
}

int ans(vector<vector<pix>>* L, pix P)
{
    vector<pix> dijkstraList;
    dijkstraList.push_back(P);
    return updateList(L, &dijkstraList);
}
