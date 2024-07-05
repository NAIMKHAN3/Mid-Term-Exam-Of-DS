#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prev;
    Node(string v)
    {
        val = v;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, string v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        string v;
        cin >> v;
        if (v == "end")
            break;

        insertAtTail(head, tail, v);
    }
    int q;
    cin >> q;
    Node *trackNode = head;

    while (q--)
    {
    Node *temp = head;
        // cout << q << endl;
        string n;
        cin >> n;
        if (n == "visit")
        {
            cin >> n;
            bool fount = false;
            while (temp != NULL)
            {
                if (temp->val == n)
                {
                    cout << temp->val << endl;
                    fount = true;
                    trackNode = temp;
                    break;
                }
                temp = temp->next;
            }
            if (!fount)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (n == "next")
        {
            if (trackNode && trackNode->next != NULL)
            {
                cout << trackNode->next->val << endl;
                trackNode = trackNode->next;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (n == "prev")
        {
            if (trackNode && trackNode->prev != NULL)
            {
                cout << trackNode->prev->val << endl;
                trackNode = trackNode->prev;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}