#include<iostream>
#include<queue>
#include<vector> 
using namespace std;
#define maxsize 1005
int N,M;
class Node
{
public:
	int va;
	int vb;
	int w;
	Node()
	{
	}
	Node(int a,int b,int wei):va(a),vb(b),w(wei){}
	bool operator < (const Node &a) const
	{
		return w>a.w;
	}
};


priority_queue<Node> q;
Node mynode[maxsize];
int parent[maxsize];


void Union(int root1,int root2)
{
	if(parent[root1]<parent[root2])
	{
		parent[root1]+=parent[root2];
		parent[root2]=root1;
	}
	else
	{
		parent[root2]+=parent[root1];
		parent[root1]=root2;
	}
}

int Find(int x)
{
	if(parent[x]<0)
		return x;
	else
		return parent[x]=Find(parent[x]);
}


int Krusal()
{
	int count=0;
	int Ecount=0;
	while(Ecount<N-1 && q.size()>0)
	{
		Node minE=q.top();
		q.pop();
		
		cout<<Ecount<<" "<<q.size()<<endl;
		if(Find(minE.va) != Find(minE.vb))
		{
			Union(minE.va,minE.vb);
//			for(int i=1;i<=N;i++)
//				cout<<i<<":"<<parent[i]<<";";
			Ecount++;
			cout<<"add "<<minE.va<<" "<<minE.vb<<":"<<minE.w<<endl; 
			count+=minE.w;
		}
		cout<<Ecount<<" "<<q.size()<<endl<<endl;
	 } 
	if(Ecount<N-1)
		return -1;
	else
		return count;
}

int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		parent[i]=-1;
	for(int i=0;i<M;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		Node tmp(a,b,w);
		q.push(tmp);		
	}
	cout<<Krusal()<<endl;
//	for(int i=0;i<M;i++)
//	{
//		cout<<q.top().va<<" "<<q.top().vb<<":"<<q.top().w<<endl;	
//		q.pop();
//	}
	
}
