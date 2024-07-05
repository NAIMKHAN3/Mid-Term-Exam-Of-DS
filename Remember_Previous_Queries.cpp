#include <bits/stdc++.h>
using namespace std;

void print(list<int> &head)
{
    cout << "L -> ";
    auto it = head.begin();
    while (it != head.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void printReverse(list<int> &head)
{
    cout << "R -> ";
    auto it = head.end();
    it--;
    while (true)
    {
        if (!head.size())
        {
            break;
        }
        cout << *it << " ";
        if (it == head.begin())
        {
            break;
        }
        it--;
    }
    cout << endl;
}
int main()
{
    int q;
    cin >> q;
    list<int> head;
    while (q--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            head.push_front(v);
        }
        else if (x == 1)
        {
            head.push_back(v);
        }
        else if (x == 2)
        {
            if (v < head.size())
            {
                auto it = next(head.begin(), v);
                head.erase(it);
            }
        }
        print(head);
        printReverse(head);
    }
    return 0;
}