#include<queue>
#include<map> 
#include<iostream>
#include<algorithm>
#define MaxSize 64
using namespace std;
priority_queue<int, vector<int>, greater<int> >q; // �������ȶ��У���ǰ���ֵ��С
map<char, int> mapp;
struct character {
	char ch;   // �ַ� 
	int fre;  // Ƶ�� 
};
struct huffmanTree {
	char ch;  // �ַ� 
	string str;  // ���� 
};


// ����
int bulidTree(int n, character c[]) {
	int weight = 0;
	// ��� 
	for (int i = 0; i < n; i++)
		q.push((c[i].fre));
	while (q.size() > 1) {
		// ȡ���Ѷ�Ԫ�� 
		int x = q.top();
		// �����Ѷ�Ԫ�� 
		q.pop();
		int y = q.top();
		q.pop();
		// ��� 
		q.push(x + y);
		weight += x + y;  // �õ����볤�� 
		// СȨֵ�᲻�ϱ��� 
	}
	q.pop();
	return weight;
}
bool cmp(huffmanTree a, huffmanTree b) {
	return a.str.size() < b.str.size();
}

// �ж��Ƿ�Ϊǰ׺
bool isPrefix(huffmanTree code[], int n) {
	// ���ַ������ȴ�С�������� 
	sort(code, code + n, cmp);
	for (int i = 0; i < n; i++) {
		string str = code[i].str;
		for (int j = i + 1; j < n; j++) { // ����֮��ȫ���ַ�
			// ������ַ����볤�ַ�����ȡ��ͬ������ȣ���Ϊǰ׺ 
			if (code[j].str.substr(0, str.size()) == str)
				return true;
		}
	}
	return false;
}

void judge(int n, character c[], int weight) {
	// ���� WPL 
	huffmanTree code[MaxSize];
	int codelen = 0;
	for (int i = 0; i < n; i++) {
		cin >> code[i].ch >> code[i].str;
		// ���볤�ȵ��ڱ��볤��*Ƶ���ܺ� 
		codelen += mapp[code[i].ch] * code[i].str.size();
	}
	if (codelen != weight || isPrefix(code, n))
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main() {
	int n;
	int m;
	cin >> n;
	character c[MaxSize];
	for (int i = 0; i < n; i++) {
		cin >> c[i].ch >> c[i].fre;
		mapp[c[i].ch] = c[i].fre;
	}
	int weight = bulidTree(n, c);
	cout << weight << endl;
	cin >> m;
	for (int i = 0; i < m; i++)
		judge(n, c, weight);
	return 0;
}
