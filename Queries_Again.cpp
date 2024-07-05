#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
int size(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

bool insert_at_position(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);
    if (pos == 0)
    {
        insert_at_head(head, tail, val);
        return true;
    }
    int element = size(head);
    if (pos > element)
    {
        return false;
    }
    if (pos == element)
    {
        insert_at_tail(head, tail, val);
        return true;
    }
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return true;
}

void print(Node *head)
{
    if(head == NULL) return;
    Node *temp = head;
    cout << "L -> ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    if (tail == NULL)
    {
        return;
    }
    cout << "R -> ";
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin >> q;
    while (q--)
    {
        int pos, v;
        cin >> pos >> v;
        if (insert_at_position(head, tail, pos, v))
        {
            print(head);
            print_reverse(tail);
        }
        else
        {
            cout << "Invalid" << endl;
        }
       
    }
    return 0;
}