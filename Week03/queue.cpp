#include <iostream>

struct Node
{
	int num;
	Node *prev;
	Node *next;
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	Node **nodeArr = (Node **)malloc(n * sizeof(Node *));
	Node *head = NULL, *tail = NULL;
	for (int i = 0; i < n; i++)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));

		newNode->num = i + 1;
		newNode->prev = (i == 0) ? NULL : nodeArr[i - 1];
		newNode->next = NULL;

		if (i == 0)
		{
			head = newNode;
		}
		else
		{
			nodeArr[i - 1]->next = newNode;
		}
		nodeArr[i] = newNode;
		tail = newNode;
	}

	for (int i = 0; i < m; i++)
	{
		int query;
		scanf("%d", &query);
		Node *current = nodeArr[query - 1];

		if (current == head)
			continue;

		if (current->prev)
			current->prev->next = current->next;
		if (current->next)
		{
			current->next->prev = current->prev;
		}
		else
		{
			tail = current->prev;
		}

		current->next = head;
		head->prev = current;
		current->prev = NULL;
		head = current;
	}

	Node *temp = head;
	while (temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");

	temp = head;
	while (temp)
	{
		Node *next = temp->next;
		free(temp);
		temp = next;
	}
	free(nodeArr);

	return 0;
}
