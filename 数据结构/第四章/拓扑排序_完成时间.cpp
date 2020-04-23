#include<iostream>
#include<queue>
#include<vector>
#define maxsize 1005
using namespace std;
int N,M;
int S[maxsize],E[maxsize],L[maxsize];
struct Node
{
	int vertex;
	int endTime;
	int degree;	
};
queue<Node> q;
vector<Node> array;

void topsort()
{
	for(int i=0;i<array.size();i++)
		if(array[i].degree==0)
			q.push(array[i]);
	int cnt=0,Index=-1;
	while(!q.empty())
	{
		Node tmp=q.front();
		cnt++;
		Index=tmp.vertex;
		q.pop();
		for(int j=0;j<M;j++)
		{
			if(tmp.vertex==S[j])
			{
				int eTime=tmp.endTime+L[j];
				if(eTime>array[E[j]].endTime)
					array[E[j]].endTime=eTime;
				array[E[j]].degree--;
				if(array[E[j]].degree==0)
					q.push(array[E[j]]);
			}
		}
	}
	if(cnt<N)
		cout<<"Impossible"<<endl;
	else
	{
		if(Index!=-1)
			cout<<array[Index].endTime<<endl;
	}
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
		cin>>S[i]>>E[i]>>L[i];
	for(int i=0;i<N;i++)
	{
		Node tmp;
		tmp.vertex=i;
		tmp.endTime=0;
		tmp.degree=0;
		for(int j=0;j<M;j++)
			if(E[j]==i)
				tmp.degree++;
		array.push_back(tmp);
	}
	topsort();
}
