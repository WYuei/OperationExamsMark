#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	int height;
};


int getHeight(Node* BST)
{
	return BST == NULL ? -1 : BST->height;
}
int MAX(int a, int b)
{
	return a > b ? a : b;
}
Node* LLrotation(Node* A)
{
	Node* B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = MAX(getHeight(A->left), getHeight(A->right)) + 1;
	B->height = MAX(getHeight(B->left), getHeight(B->right)) + 1;
	return B;
}
Node* RRrotation(Node* A)
{
	Node* B = A->right;
	A->right = B->left;
	B->left = A;

	A->height = MAX(getHeight(A->left), getHeight(A->right)) + 1;
	B->height = MAX(getHeight(B->left), getHeight(B->right)) + 1;
	return B;
}
Node* LRrotation(Node* A)
{
	A->left = RRrotation(A->left);
	return LLrotation(A);
}
Node* RLrotation(Node* A)
{
	A->right = LLrotation(A->right);
	return RRrotation(A);
}

Node* insert(int x, Node* BST)
{
	if (!BST)
	{
		Node* tmp = new Node;
		BST = tmp;
		BST->data = x;
		BST->left = BST->right = NULL;
		BST->height = 0;
	}
	else
		if (x < BST->data)
		{
			BST->left = insert(x, BST->left);
			if (getHeight(BST->left) - getHeight(BST->right) == 2)
			{
				if (x < BST->left->data)
					BST = LLrotation(BST);
				else
					BST = LRrotation(BST);
			}
		}
		else
			if (x > BST->data)
			{
				BST->right = insert(x, BST->right);
				if (getHeight(BST->right) - getHeight(BST->left) == 2)
				{
					if (x < BST->right->data)
						BST = RLrotation(BST);
					else
						BST = RRrotation(BST);
				}
			}
	BST->height = MAX(getHeight(BST->left), getHeight(BST->right)) + 1;
	return BST;
}

int main()
{
	int N;
	cin >> N;
	int x;
	Node* head = NULL;
	while (N--)
	{
		cin >> x;
		head = insert(x, head);
	}
	cout << head->data;
	system("pause");
	return 0;
}