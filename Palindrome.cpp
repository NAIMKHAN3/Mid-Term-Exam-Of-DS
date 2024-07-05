#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int v)
    {
        val = v;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int v)
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

bool isPalindrome(Node *head, Node *tail)
{
    Node *left = head;
    Node *right = tail;
    while (left != right && left->prev != right)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        int v;
        cin >> v;
        if (v == -1)
            break;

        insertAtTail(head, tail, v);
    }

    if (isPalindrome(head, tail))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}