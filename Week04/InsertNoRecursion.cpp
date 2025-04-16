#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution
{
public:
	Node *insert(Node *root, int data)
	{
		Node *result = new Node(data);
		if (root == NULL)
			return result;
		Node *current = root;
		while (true)
		{
			if (data <= current->data)
			{
				if (current->left == NULL)
				{
					current->left = result;
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if (current->right == NULL)
				{
					current->right = result;
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}

		return root;
	}

	int height(Node *root)
	{
		return (root == nullptr ? -0 : 1 + max(height(root->left), height(root->right)));
	}
};

int main()
{

	Solution myTree;
	Node *root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0)
	{
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	int height = myTree.height(root);

	std::cout << height;

	return 0;
}
