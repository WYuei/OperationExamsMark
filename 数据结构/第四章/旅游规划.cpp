#include<iostream>
using namespace std;

#define MAXVERTEX 505
int G[MAXVERTEX][MAXVERTEX];
int C[MAXVERTEX][MAXVERTEX];
bool checked[MAXVERTEX];
int dist[MAXVERTEX];
int cost[MAXVERTEX];
int Nv,Ne;

void dijkstra(int ori,int dest)
{
	for(int i=0;i<Nv;i++)
	{
		dist[i]=G[ori][i];
		cost[i]=C[ori][i];
	}
	checked[ori]=true;
	while(true)
	{
		int tmp=0,i;
		for(i=0;i<Nv;i++)
			if(checked[i]==false)
			{
				if(dist[tmp]>dist[i])
					tmp=i;
			}
		if(i==Nv) //代表没有找到false的选项 
			break;
		if(tmp==dest)
			break;
		checked[tmp]=true;
		for(int j=0;j<Nv;j++)
		{
			if(checked[j]==false)
			{
				if(dist[j]>dist[tmp]+G[tmp][j])
				{
					dist[j]=dist[tmp]+G[tmp][j];
					cost[j]=cost[tmp]+C[tmp][j];
				}
			}
		}
	}
}

int main()
{
	int ori,dest;
	cin>>Nv>>Ne>>ori>>dest;
	for(int i=0;i<Nv;i++)
	{
		checked[i]=false;
		for(int j=0;j<Nv;j++)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=999;
			C[i][j]=-1;
		}
	}
	for(int i=0;i<Ne;i++)
	{
		int a,b,len,c;
		cin>>a>>b>>len>>c;
		G[a][b]=len;
		G[b][a]=len;
		C[a][b]=c;
		C[b][a]=c;
	}
	dijkstra(ori,dest);
}
