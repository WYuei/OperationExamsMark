#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	int flag;
};
Node* insert(int x, Node* BST)
{
	if (!BST)
	{
		Node* tmp = new Node;
		BST = tmp;
		BST->data = x;
		BST->left = BST->right = NULL;
		BST->flag = 0;
	}
	if (x < BST->data)
	{
		BST->left = insert(x, BST->left);
	}
	else
		if (x > BST->data)
		{
			BST->right = insert(x, BST->right);
		}

	return BST;
}
void resetBST(Node* BST)
{
	if (BST!=NULL)
	{

		resetBST(BST->left);
		BST->flag=0;
		resetBST(BST->right);
	}
}

int judge(int x, Node* BST)
{
	if (BST->flag == 0)//还没访问的
	{
		if (x == BST->data)
		{
			BST->flag = 1;
			return 1;
		}
		else
			return 0;
	}
	else//已经访问过的
	{
		if (x < BST->data)
			return judge(x, BST->left);
		else
			if (x > BST->data)
				return judge(x, BST->right);
			else//待检测队列里面有两个x！所以肯定这个队列本身是一个错误的队列
				return 0;
	}
}
int main()
{
	int N, L;
	cin >> N;
	while (N)
	{
		cin >> L;
		int x;
		cin >> x;
		Node* head = insert(x, NULL);
		for (int i = 1; i < N; i++)
		{
			cin >> x;
			head = insert(x, head);
		}
		for (int i = 0; i < L; i++)
		{
			int flag = 1;
			int y;
			for (int j = 0; j < N; j++)
			{
				cin >> y;
				if (flag == 1)
					flag = judge(y, head);
			}
			if (flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			resetBST(head);
		}
		//这里可以有一个删除树
		cin >> N;
	}
	system("pause");
	return 0;
}