#include <bits/stdc++.h>
using namespace std;

#define TASK "tree"
const long long INF = 1e9 + 7;

int isVisted[1000005] = {0};

struct Node
{
	int x;
	Node *left, *right;
	Node(int x) : x(x), left(nullptr), right(nullptr) { isVisted[x] = 1; }
};

class Tree
{
private:
	Node *root;

	void printSubTree(Node *node, const string &prefix, bool isLeft) const
	{
		if (!node)
			return;

		if (node->right)
		{
			printSubTree(node->right, prefix + (isLeft ? "|   " : "    "), false);
		}

		cout << prefix;
		cout << "|---" << node->x << endl;

		if (node->left)
		{
			printSubTree(node->left, prefix + (isLeft ? "    " : "|   "), true);
		}
	}

public:
	Tree() : root(nullptr) {}
	~Tree()
	{
		stack<Node *> s;
		if (root)
			s.push(root);
		while (!s.empty())
		{
			Node *cur = s.top();
			s.pop();
			if (cur->left)
				s.push(cur->left);
			if (cur->right)
				s.push(cur->right);
			delete cur;
		}
	}

	void insert(int x)
	{
		if (!root)
		{
			root = new Node(x);
			return;
		}
		Node *cur = root;
		while (true)
		{
			if (x < cur->x)
			{
				if (!cur->left)
				{
					cur->left = new Node(x);
					break;
				}
				cur = cur->left;
			}
			else
			{
				if (!cur->right)
				{
					cur->right = new Node(x);
					break;
				}
				cur = cur->right;
			}
		}
	}

	void output() const
	{
		if (!root)
			return;

		if (root->right)
		{
			printSubTree(root->right, "", false);
		}

		cout << root->x << endl;

		if (root->left)
		{
			printSubTree(root->left, "", true);
		}
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x;
	Tree tree;

	while (cin >> x)
		if (x && !isVisted[x])
			tree.insert(x);

	tree.output();
	return 0;
}
