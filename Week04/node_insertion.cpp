
#include <iostream>
#include <limits>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int node_data)
	{
		this->data = node_data;
		this->next = nullptr;
	}
};

class LinkList
{
public:
	Node *head;
	Node *tail;

	LinkList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data)
	{
		Node *node = new Node(node_data);

		if (!this->head)
		{
			this->head = node;
		}
		else
		{
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void free_singly_linked_list(Node *node)
{
	while (node)
	{
		Node *temp = node;
		node = node->next;

		free(temp);
	}
}

void printLinkedList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}

Node *insertSortedLinkedList(Node *head, int x)
{
	Node *newNode = new Node(x);

	if (head == nullptr || x <= head->data)
	{
		newNode->next = head;
		return newNode;
	}

	Node *current = head;

	while (current->next != nullptr && current->next->data < x)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;

	return head;
}

int main()
{
	LinkList *llist = new LinkList();
	int llist_count;
	int x;

	cin >> llist_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < llist_count; i++)
	{
		int llist_item;
		cin >> llist_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		llist->insert_node(llist_item);
	}
	cin >> x;
	llist->head = insertSortedLinkedList(llist->head, x);
	printLinkedList(llist->head);

	return 0;
}
