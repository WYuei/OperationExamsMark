#include<iostream>
using namespace std;

struct treeNode{
	char element;
	int left;
	int right;
}t1[10],t2[10]; //据说这个叫静态链表！ 

int readTree(treeNode t[])
{
	int n;
	cin>>n;
	int check[10]={0};
	for(int i=0;i<n;i++)
	{
		char ele,leftchar,rightchar;
		/*读入新节点,按顺序存入链表*/
		cin>>ele>>leftchar>>rightchar;
		t[i].element=ele;
		if(leftchar!='-')
		{	t[i].left=leftchar-'0';
			check[t[i].left]=1;
			}	
		else
			t[i].left=-1;
		if(rightchar!='-')
		{	t[i].right=rightchar-'0';
			check[t[i].right]=1;
			}	
		else
			t[i].right=-1;		
	}
	for(int i=0;i<n;i++)
		if(!check[i])
			return i;
}
bool judge(int r1,int r2)
{
	if(r1==-1 && r2==-1) //两个都是空节点 
		return true;
	if((r1==-1 && r2!=-1) || (r1!=-1 && r2==-1)) //一个是空节点 一个不是空节点
		return false;
	if(t1[r1].element != t2[r2].element) //节点内容不同 自然不同
		return false;
	if(t1[r1].left ==-1 && t2[r2].left==-1)//两个节点的左子树都是空的 此时代表，节点内容相同！ 
		return judge(t1[r1].right,t2[r2].right) ;
	if(t1[r1].left!=-1 && t2[r2].left !=-1 && t1[t1[r1].left].element == t2[t2[r2].left].element) //两个节点的左子树元素相同
		return judge(t1[r1].left,t2[r2].left) && judge(t1[r1].right,t2[r2].right);
	else
		return judge(t1[r1].left,t2[r2].right) && judge(t1[r1].right,t2[r2].left); 
		
}

int main()
{
	int root1=readTree(t1);
	int root2=readTree(t2);
	
	if(judge(root1,root2) == true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
		return 0;
}
