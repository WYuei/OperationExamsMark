#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	int flag;
};
Node* insert(int x,Node* BST)
{
	if(!BST)
	{
		Node* tmp=new Node;
		BST=tmp;
		BST->data=x;
		BST->left=BST->right=NULL;
		BST->flag=0;
	}
	if(x<BST->data)
		BST->left=insert(x,BST->left);
	else
		if(x>BST->data)
			BST->right=insert(x,BST->right);
	
	return BST;
}
void printBST(Node* BST)
{
	if(!BST)
	{
		printBST(BST->left);
		cout<<BST->data<<" ";
		printBST(BST->right);
	}
}
int main()
{
	int N,L;
	cin>>N;
	while(N)
	{
		cin>>L;
		int x;
		cin>>x;
		Node* head=insert(x,NULL);
		for(int i=1;i<N;i++)
		{
			cin>>x;
			head=insert(x,head);
			}	
		printBST(head);
		cout<<endl;
		cin>>N; 
	}
	return 0;
}
