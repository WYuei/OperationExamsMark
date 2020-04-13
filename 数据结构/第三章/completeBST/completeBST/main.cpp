#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int A[10],B[10];
int getLeftTreeNum(int n)
{
	int H = log(n + 1) / log(2);//完整的三角的个数
	int X = n + 1 - pow(2, H);
	X = X < pow(2, H - 1) ? X : pow(2, H - 1);

	return pow(2,H-1)-1+X;
}

void solve(int Aleft, int Aright, int Troot)
{
	cout << "Aleft：" << Aleft << ",Aright: " << Aright << endl << "Troot:";
	cout << Troot << endl;

	if (Aleft == Aright)
	{
		B[Troot] = A[Aleft];
		return;
	}
	else
		if (Aleft > Aright)
			return;
	int N = Aright - Aleft + 1;//当前这棵树的节点个数
	int NumL = getLeftTreeNum(N);//当前这棵树的左子树节点个数
	B[Troot] = A[Aleft + NumL];
	int leftChild = Troot * 2 + 1;
	int rightChild = leftChild+1;
	solve(Aleft, Aleft + NumL - 1, leftChild);
	solve(Aleft + NumL + 1, Aright, rightChild);
}

int main()
{
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	sort(A, A + 10);
	solve(0, 9, 0);
	for (int i = 0; i < 10; i++)
		cout << B[i] << " ";
	system("pause");
}