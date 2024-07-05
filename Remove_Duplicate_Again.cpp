#include <bits/stdc++.h>
using namespace std;

void print(list<int> &head)
{
    auto it = head.begin();
    while (it != head.end())
    {
        cout << *it << " ";
        it++;
    }
}

void printReverse(list<int> &head) {
    auto it = head.end();
    it--;
    while (true) {
        cout << *it << " ";
        if (it == head.begin()) {
            break;
        }
        it--;
    }
    cout << endl;
}
int main()
{
    list<int> head;
    while (true)
    {
        int v;
        cin >> v;
        if (v == -1)
            break;
        head.push_back(v);
    }
    head.sort();
    head.unique();
    print(head);
    return 0;
}