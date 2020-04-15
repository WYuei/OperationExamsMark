#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<queue>

#define MaxVertex 105
#define diameter 15
using namespace std;

struct Node {
	int n;
	int x;
	int y;
	bool isSafe;//安全了吗 
	bool isJump;//第一步 能从岛上跨上去
	bool visit;
};
int N, D;
bool flag = false;
int path[MaxVertex];
int dist[MaxVertex]; 
queue<Node> q;
Node vertex[MaxVertex];

double getLen(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
bool ashore(int x, int y) {
	// 分别计算当前结点与岸边的距离
	// 即与 (x,50),(x,-50),(50,y),(-50,y) 的距离  
	if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y + 50) <= D || abs(y - 50) <= D)
		return true;
	return false;
}
void BFS()
{
	bool first=true;
	for(int i=0;i<N;i++)
	{
		dist[i]=-1;
		path[i]=-2;
	}
	for(int i=0;i<N;i++)
		if(vertex[i].isJump==true)
		{
			q.push(vertex[i]);  //先把第一圈 都能jump的都加进队列 
			dist[i]=1;
			path[i]=-1;
		}
	while(!q.empty())
	{
		Node tmp=q.front();
		q.pop();
		if(tmp.isSafe==true)
		{
			flag=true;
			dist[tmp.n]=dist[tmp.n]+1;
			continue;
		 } 
		for(int i=0;i<N;i++)
		{
			if(dist[i]==-1 && getLen(tmp.x,tmp.y,vertex[i].x,vertex[i].y)<=D)
			{
				dist[i]=dist[tmp.n]+1;
				path[i]=tmp.n;
				q.push(vertex[i]);
			}
		}
	}
}
void getPath(int v)
{
	if(path[v]!=-2)
	{
		getPath(path[v]);
	}
	cout<<vertex[v].x<<" "<<vertex[v].y<<endl;
}
int main()
{
	
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		int xx, yy;
		cin >> xx >> yy;

		vertex[i].n=i;
		vertex[i].x = xx;
		vertex[i].y = yy;
		vertex[i].visit = false;
		vertex[i].isSafe = ashore(xx, yy);//这个鳄鱼能碰到岸吗
		double len = getLen(xx, yy, 0, 0);
		if (len <= diameter / 2 + D)
			vertex[i].isJump = true;
		else
			vertex[i].isJump = false;
	}

	BFS();
	if(flag==false)
		cout<<0<<endl;
	else
	{
		int tmp=99,tmpIndex=-1;
		for(int i=0;i<N;i++)
		{
			if(vertex[i].isSafe==true && dist[i]<tmp)
			{
				tmp=dist[i];
				tmpIndex=i;
			}
		}
		cout<<endl;
		cout<<tmp<<endl;
		getPath(tmpIndex);
	}
}
