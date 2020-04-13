#include<iostream>
#include<queue>
using namespace std;

#define maxsize 100
int G[maxsize][maxsize];
int visit[maxsize];
int Ne,Nv;

void Build()
{
	cin>>Nv; //��ȡNv���� 
	for(int i=0;i<Nv;i++)
	{
		visit[i]=0; //ÿ�����㶼����Ϊδ���� 
		for(int j=0;j<Nv;j++) //ÿ���߶�����Ϊû�б� 
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
		if(G[V][i]==1) //�����ڽ�
		{
			if(visit[i]==0) //����ڽӵĻ�û�з��ʹ�
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
			if(G[v][i]==1 && visit[i]==0) //�ڽӵ㲢��û�з��ʹ�
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
		if(visit[i]==0) //����㻹û�з��ʹ�
		{	cout<<"{ " ;
			DFS(i); //�Ǿ����� ��ȡ��������ͨ�� 
			cout<<"}"<<endl;
		} 
	}
	
	for(int i=0;i<Nv;i++)
		visit[i]=0;
	for(int i=0;i<Nv;i++)
	{
		if(visit[i]==0) //����㻹û�з��ʹ�
		{	cout<<"{ " ;
			BFS(i); //�Ǿ����� ��ȡ��������ͨ�� 
			cout<<"}"<<endl;
		} 
	}
	
		
}
