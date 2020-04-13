#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* create(int x)
{
	Node * tmp = new Node;
	tmp->data = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void order(Node* node)
{
	if (node != NULL)
	{
		order(node->left);
		order(node->right);
		cout << node->data << " ";
	}
}

int main()
{
	int N;
	cin >> N;
	stack<Node*> s;
	string inputStr;
	cin >> inputStr;
	int x;
	cin >> x;
	Node * node = create(x);
	Node * head = node;
	s.push(node);
	for (int i = 1; i < 2 * N; i++)
	{
		cin >> inputStr;
		if (strcmp(inputStr.c_str(), "Push") == 0) //如果是PUSH
		{
			cin >> x;
			Node* tmp = create(x);
			if (node->left == NULL)
			{
				node->left = tmp;
				
			}
			else
				if (node->right == NULL)
				{
					node->right = tmp;
				}
			node = tmp;
			s.push(tmp);
		}
		else //如果是pop
		{
			node = s.top();
			s.pop();
		}

	}
	order(head);
	system("pause");
	return 0;
}