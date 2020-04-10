#include<iostream>
using namespace std;
int S[10];

int Find(int x)
{
	if (S[x] < 0)
		return x;
	else
		return S[x] = Find(S[x]);
}

void Union(int root1, int root2)
{
	if (S[root1] < S[root2])//1的规模大一点
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
	else
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
}
void checkNetwork()
{
	int com1, com2;
	cin >> com1 >> com2;
	int root1 = Find(com1), root2 = Find(com2);
	if (root1 == root2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
void insertNetwork()
{
	int com1, com2;
	cin >> com1 >> com2;
	int root1 = Find(com1), root2 = Find(com2);
	if (root1 != root2)
		Union(root1, root2);
}
int main()
{
	
	char sign;
	int N;
	cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i++)
		S[i] = -1;
	do {
		cin >> sign;
		switch (sign)
		{
		case 'I':
			insertNetwork();
			break;
		case 'C':
			checkNetwork();
			break;
		case 'S':
			for (int i = 1; i <= N; i++)
			{
				cout << S[i] << " ";
				if (S[i] <0)
					count++;
			}
			if (count > 1)
				cout << "There are " << count << " components." << endl;
			else
				cout << "The network is connected." << endl;
			break;
		default:
			break;
		}
	} while (sign != 'S');
	system("pause");
}