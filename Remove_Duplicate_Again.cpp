#include <bits/stdc++.h>
using namespace std;


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
    auto it = head.begin();
    while (it != head.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}