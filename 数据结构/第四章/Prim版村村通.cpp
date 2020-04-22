#include<iostream>
using namespace std;
#define maxsize 1005
int G[maxsize][maxsize];
int dist[maxsize];

int N,M;

int FindMin()
{
	int minIndex=-1,minNum=999;
	for(int i=1;i<=N;i++)
	{
		if(dist[i]!=0 && dist[i]<minNum)
		{
			minNum=dist[i];
			minIndex=i;
		}
	}
	return minIndex;
}

int Prim(int s)
{
	for(int j=1;j<=N;j++)
		dist[j]=G[s][j];
	int count=0;
	int Vcount=1;
	while(1)
	{
		int V=FindMin();
		if(V==-1)
			break;
		count+=dist[V];
		dist[V]=0;
		Vcount++;
		for(int j=1;j<=N;j++)
		{
			if(dist[j]!=0)
			{
				if(dist[j]>G[V][j])
					dist[j]=G[V][j];
			}
		}
	}
	if(Vcount!=N)
		return -1;
	else
		return count;
}
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=999;
	}
	for(int i=1;i<=M;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		G[a][b]=w;
		G[b][a]=w;
	}
	cout<<Prim(1)<<endl;
}
