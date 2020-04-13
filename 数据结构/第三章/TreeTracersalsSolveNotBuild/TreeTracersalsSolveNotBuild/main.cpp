#include<iostream>
#include<string>
#include<stack>
using namespace std;
int pre[10];//先序 中左右
int in[10];//中序 左中右
int post[10];//后序 左右中

void solve(int preL, int inL, int postL, int n)
{
	if (n == 0) return;
	if (n == 1)
	{
		post[postL] = in[inL];
		return;
	}
	int root = pre[preL];//先序里面最左边的就是根节点
	post[postL + n - 1] = root;//所以放在后序里面的最后一个
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