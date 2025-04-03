
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode
{
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data)
	{
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList
{
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void insert_node(SinglyLinkedList *node, int lli)
{
	SinglyLinkedListNode *nodes = new SinglyLinkedListNode(lli);

	if (!node->head)
	{
		node->head = nodes;
	}
	else
	{
		node->tail->next = nodes;
	}

	node->tail = nodes;
}

void printLinkedList(SinglyLinkedList *ll)
{
	SinglyLinkedListNode *head = ll->head;
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}

void reverseLinkedList(SinglyLinkedList *ll)
{
	SinglyLinkedListNode *prev = nullptr;
	SinglyLinkedListNode *current = ll->head;
	SinglyLinkedListNode *next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	ll->tail = ll->head;
	ll->head = prev;
}

int main()
{
	SinglyLinkedList *llist = new SinglyLinkedList();
	int llist_count;

	cin >> llist_count;

	for (int i = 0; i < llist_count; i++)
	{
		int llist_item;
		cin >> llist_item;

		insert_node(llist, llist_item);
	}

	reverseLinkedList(llist);
	printLinkedList(llist);

	return 0;
}
