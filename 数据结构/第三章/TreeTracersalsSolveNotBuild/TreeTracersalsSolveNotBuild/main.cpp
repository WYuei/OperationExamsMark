#include<iostream>
#include<string>
#include<stack>
using namespace std;
int pre[10];//���� ������
int in[10];//���� ������
int post[10];//���� ������

void solve(int preL, int inL, int postL, int n)
{
	if (n == 0) return;
	if (n == 1)
	{
		post[postL] = in[inL];
		return;
	}
	int root = pre[preL];//������������ߵľ��Ǹ��ڵ�
	post[postL + n - 1] = root;//���Է��ں�����������һ��
	int i;
	for (i = inL; i < inL + n; i++)
		if (in[i] == root)
			break;
	int Llen = i - inL;
	int Rlen = n - Llen - 1;
	solve(preL + 1, inL, postL, Llen);
	solve(preL + Llen + 1, i + 1, postL + Llen, Rlen);

}
int main()
{
	int N, x;
	stack<int> s;
	string inputStr;
	cin >> N;
	int preI = 0, inI = 0, postI = 0;
	for (int i = 0; i < N * 2; i++)
	{
		cin >> inputStr;
		if (strcmp(inputStr.c_str(), "Push") == 0)
		{
			cin >> x;
			pre[preI] = x;
			preI++;
			s.push(x);
		}
		else
		{
			in[inI] = s.top();
			inI++;
			s.pop();
		}
	}
	solve(0, 0, 0, N);
	for (int i = 0; i < N; i++)
		cout << post[i] << " ";
	system("pause");
}