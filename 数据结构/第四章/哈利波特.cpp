#include<iostream>
using namespace std;
#define MAXVERTEX 105
int Nv,Ne;
int G[MAXVERTEX][MAXVERTEX];

bool Floyd(int N)
{
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
			}
		}
	}
	return true;
}

void printG()
{
		for(int i=1;i<=Nv;i++)
	{
			for(int j=1;j<=Nv;j++)
			{
					cout<<G[i][j]<<" ";
		}
			cout<<endl;
		}
}

void getMinInMax(int N)
{
	int minCost=999;
	int index=0;
	for(int i=1;i<=Nv;i++)
	{
		int maxCost=0;
		for(int j=1;j<=Nv;j++)
		{
			if(G[i][j]==999) //代表i不能到j，代表i不能用咒语变成j，所以只带一只动物不行 
			{
				cout<<0<<endl;
				return;
			}
			if(G[i][j]>maxCost)
				maxCost=G[i][j];
		}
		if(maxCost<minCost)
		{
			minCost=maxCost;
			index=i;
		}
	}
	cout<<index<<" "<<minCost<<endl;
}

int main()
{
	cin>>Nv>>Ne;
	for(int i=1;i<=Nv;i++)
		for(int j=1;j<=Nv;j++)
			{
				if(i==j)
					G[i][j]=0;
				else
					G[i][j]=999;
			}
	for(int i=0;i<Ne;i++)
	{
		int a,b,weight;
		cin>>a>>b>>weight;
		
		G[a][b]=weight;
		G[b][a]=weight;
	 } 
	Floyd(Nv);
	getMinInMax(Nv);
}
