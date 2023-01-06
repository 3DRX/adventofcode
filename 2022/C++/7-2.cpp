#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::getline;
using std::queue;
using std::string;
using std::vector;

typedef struct _node {
    vector<struct _node*> childrens;
    int                   size;
    struct _node*         parent;
} node;

void  generateTree(node* root);
int   getAns(node* root);
node* initNode(void);

int main(void)
{
    node* treeRoot = initNode();
    generateTree(treeRoot);
    cout << getAns(treeRoot) << std::endl;
    return 0;
}

node* initNode(void)
{
    node* res = (node*)malloc(sizeof(node));
    res->childrens.clear();
    res->size = 0;
    res->parent = nullptr;
    return res;
}

void generateTree(node* root)
{
    while (1) {
        string ipt;
        getline(cin, ipt);
        if (ipt == "") {
            return;
        }
        if (ipt[0] == '$') {
            if (ipt[2] == 'l') {
                continue;
            }
            else if (ipt == "$ cd ..") {
                continue;
            }
            else {
                break;
            }
        }
        ipt = ipt.substr(0, ipt.find(" "));
        if (ipt == "dir") {
            node* newNode = initNode();
            newNode->parent = root;
            root->childrens.push_back(newNode);
            // cout << "add new subdir" << std::endl;
        }
        else {
            root->size += std::stoi(ipt);
            // cout << "add new file of size: " << std::stoi(ipt) << std::endl;
        }
    }
    for (int i = 0; i < root->childrens.size(); i++) {
        generateTree(root->childrens[i]);
        root->size += root->childrens[i]->size;
    }
}

int maxSize(queue<node*>* Q)
{
    int ans = 0;
    for (int i = 0; i < Q->size(); i++) {
        node* temp = Q->front();
        Q->pop();
        Q->push(temp);
        if (temp->size > ans) {
            ans = temp->size;
        }
    }
    return ans;
}

int getAns(node* root)
{
    int ans = INT_MAX;
    int spaceNeed = 30000000 - (70000000 - (root->size));
    cout << "spaceNeed: " << spaceNeed << std::endl;
    queue<node*> Q;
    for (int i = 0; i < root->childrens.size(); i++) {
        Q.push(root->childrens.at(i));
    }
    while (maxSize(&Q) > spaceNeed) {
        node* Node = Q.front();
        cout << "visiting: " << Node->size << std::endl;
        if (Node->size < ans && Node->size >= spaceNeed) {
            ans = Node->size;
        }
        Q.pop();
        for (int i = 0; i < Node->childrens.size(); i++) {
            Q.push(Node->childrens.at(i));
        }
    }
    return ans;
}

