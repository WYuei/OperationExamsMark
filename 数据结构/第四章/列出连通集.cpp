#include<iostream>
#include<queue>
using namespace std;

#define maxsize 100
int G[maxsize][maxsize];
int visit[maxsize];
int Ne,Nv;

void Build()
{
	cin>>Nv; //读取Nv个点 
	for(int i=0;i<Nv;i++)
	{
		visit[i]=0; //每个顶点都设置为未访问 
		for(int j=0;j<Nv;j++) //每条边都设置为没有边 
			G[i][j]=0;
	}
	
	cin>>Ne;
	for(int i=0;i<Ne;i++) 
	{
		int point1,point2;
		cin>>point1>>point2;
		G[point1][point2]=1;
		G[point2][point1]=1;
	}
}
void DFS(int V)
{
	visit[V]=1;
	cout<<V<<" ";
	for(int i=0;i<Nv;i++)
	{
		if(G[V][i]==1) //代表邻接
		{
			if(visit[i]==0) //这个邻接的还没有访问过
				DFS(i); 
		 } 
	}
}
void BFS(int V)
{
	visit[V]=1;
	queue<int> q;
	q.push(V);
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		cout<<v<<" ";
		for(int i=0;i<Nv;i++)
			if(G[v][i]==1 && visit[i]==0) //邻接点并且没有访问过
				{
					q.push(i); 
					visit[i]=1;
				}
	}
}
int main()
{
	Build();
	for(int i=0;i<Nv;i++)
	{
		if(visit[i]==0) //这个点还没有访问过
		{	cout<<"{ " ;
			DFS(i); //那就深搜 获取这个点的连通集 
			cout<<"}"<<endl;
		} 
	}
	
	for(int i=0;i<Nv;i++)
		visit[i]=0;
	for(int i=0;i<Nv;i++)
	{
		if(visit[i]==0) //这个点还没有访问过
		{	cout<<"{ " ;
			BFS(i); //那就深搜 获取这个点的连通集 
			cout<<"}"<<endl;
		} 
	}
	
		
}
