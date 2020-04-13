#include<iostream>
#include<cmath>
#include<stdlib.h>
#define MaxVertex 105
#define diameter 15
using namespace std;
struct Node {
	int x;
	int y;
	bool isSafe;
	bool isJump;//��һ�� �ܴӵ��Ͽ���ȥ
	bool visit;
};
int N, D;
bool flag = false;

Node vertex[MaxVertex];
double getLen(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
bool ashore(int x, int y) {
	// �ֱ���㵱ǰ����밶�ߵľ���
	// ���� (x,50),(x,-50),(50,y),(-50,y) �ľ���  
	if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y + 50) <= D || abs(y - 50) <= D)
		return true;
	return false;
}
void DFS(int n)
{
	vertex[n].visit = true;
	if (vertex[n].isSafe == true)
	{
		flag = true;
		return;
	}
	for (int i = 0; i < N; i++)
		if (vertex[i].visit == false && getLen(vertex[n].x, vertex[n].y, vertex[i].x, vertex[i].y) <= D)
			DFS(i);
}
int main()
{
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		int xx, yy;
		cin >> xx >> yy;

		vertex[i].x = xx;
		vertex[i].y = yy;
		vertex[i].visit = false;
		vertex[i].isSafe = ashore(xx, yy);//�����������������
		double len = getLen(xx, yy, 0, 0);
		if (len <= diameter / 2 + D)
			vertex[i].isJump = true;
		else
			vertex[i].isJump = false;
	}

	for (int i = 0; i < N; i++)
	{
		if (flag == false && vertex[i].isJump == true)
		{
			DFS(i);
		}
	}
	if (flag == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	//for (int i = 0; i < N; i++)
	//{
	//	cout << vertex[i].x << "," << vertex[i].y << ":" << vertex[i].isJump << endl;

	//}
	system("pause");
}
