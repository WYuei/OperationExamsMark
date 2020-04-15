#include<iostream>
using namespace std;

#define MAXVERTEX 505
int G[MAXVERTEX][MAXVERTEX];
int C[MAXVERTEX][MAXVERTEX];
bool checked[MAXVERTEX];
int dist[MAXVERTEX];
int path[MAXVERTEX];
int Nv,Ne;

int getCost(int x)
{
	int Sum=0;
	while(path[x]!=-1)
	{
		Sum+=C[path[x]][x];
		x=path[x];
	}
	return Sum;
}

void dijkstra(int ori,int dest)
{
	for(int i=0;i<Nv;i++)
	{
		dist[i]=G[ori][i];
		path[i]=ori;
	}
	path[ori]=-1;
	checked[ori]=true;
	while(true)
	{
		int tmpmin=999,minIndex,i;
		/*找false里最小的dist*/ 
		for(i=0;i<Nv;i++)
			if(checked[i]==false)
			{
				if(tmpmin>dist[i])
				{
					tmpmin=dist[i];
					minIndex=i;
				}
			}
		if(tmpmin==999) //代表没有找到false的选项 ,说明全都true了 
			break;
		if(minIndex==dest) //找到终点了 
			break;
		checked[minIndex]=true;
		for(int j=0;j<Nv;j++)
		{
			if(checked[j]==false)
			{
				if(dist[j]>dist[minIndex]+G[minIndex][j])
				{
					dist[j]=dist[minIndex]+G[minIndex][j];
					path[j]=minIndex; 
				}
				else
					if(dist[j]==dist[minIndex]+G[minIndex][j])
					{
						int tmpPathIndex=path[j];
						int costLast=getCost(j);
						path[j]=minIndex;
						int costNow=getCost(j);
						if(costNow>costLast)
							path[j]=tmpPathIndex;
					}
			}
		}
	}
}

void printGC()
{
	cout<<"Graph:"<<endl;
	for(int i=0;i<Nv;i++)
		{
		for(int j=0;j<Nv;j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
		}
	cout<<"Cost:"<<endl;
	for(int i=0;i<Nv;i++)
		{
		for(int j=0;j<Nv;j++)
			cout<<C[i][j]<<" ";
		cout<<endl;
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
			C[i][j]=0;
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
	cout<<dis[dest]<<" "<<getCost(dest)<<endl;
}
