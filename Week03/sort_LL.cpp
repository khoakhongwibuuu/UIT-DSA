

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *split(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        if (fast != nullptr)
        {
            slow = slow->next;
        }
    }

    Node *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Node *merge(Node *first, Node *second)
{

    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    if (first->data < second->data)
    {

        first->next = merge(first->next, second);
        return first;
    }
    else
    {

        second->next = merge(first, second->next);
        return second;
    }
}

Node *MergeSort(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *second = split(head);

    head = MergeSort(head);
    second = MergeSort(second);

    return merge(head, second);
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    head = MergeSort(head);
    printList(head);

    return 0;
}
