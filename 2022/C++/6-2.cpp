#include <cstdio>
#include <list>

using std::list;

bool noRepeat(list<char>* List);

int main(void)
{
    list<char>* List = new list<char>;
    for (int i = 0; i < 14; i++) {
        List->push_back(getchar());
    }
    int ans = 14;
    while (1) {
        char ipt = getchar();
        ans++;
        if (ipt == '\n') {
            break;
        }
        if (noRepeat(List)) {
            printf("ans=%d\n", ans - 1);
            break;
        }
        else {
            List->pop_front();
            List->push_back(ipt);
        }
    }
    return 0;
}

bool noRepeat(list<char>* List)
{
    for (int i = 0; i < 13; i++) {
        auto iter = List->begin();
        for (int j = 0; j < i; j++) {
            iter++;
        }
        char begin = *iter;
        while (iter != List->end()) {
            iter++;
            if (*iter == begin) {
                return false;
            }
        }
    }
    return true;
}
