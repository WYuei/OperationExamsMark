#include<iostream>
#include<queue>
#include<iomanip>
#define MaxVertex 10005
using namespace std;
struct Node {
	int vertex;
	Node* next;
};
Node* G[MaxVertex];
bool visit[MaxVertex];
int Nv, Ne;

int BFS(int vertex)
{
	visit[vertex] = true;
	int count = 1;
	int last = vertex, tail = vertex,level=0;
	queue<Node*> q;
	q.push(G[vertex]);
	while (!q.empty())
	{
		
		Node* tmp = q.front();
		q.pop();
		cout << "ɨ��" << tmp->vertex << "�����ڽӽڵ���" << endl;
		
		Node* firstEdge = G[tmp->vertex]->next;
		while (firstEdge != NULL) //�Ե�ǰ�ڵ���������ڽڵ����ɨ��
		{
			cout << "�������ж�" << firstEdge->vertex << "���ʹ���" << endl;
			if (visit[firstEdge->vertex] == false) //û���ʹ����Ҿͼ�!
			{
				cout << "����" << tmp->vertex << "�ڵ���ڽӽڵ�" << firstEdge->vertex << endl;
				visit[firstEdge->vertex] = true;
				q.push(firstEdge);
				count++;
				tail = firstEdge->vertex;
			}
			firstEdge = firstEdge->next;
		}
		if (last == tmp->vertex)
		{
			level++;
			last = tail;
		}
		if (level == 6)
			break;
	}
	return count;
}

int main()
{
	cin >> Nv >> Ne;//��ȡ��ͱ�
	for (int i = 1; i <= Nv; i++)
	{
		Node * tmp = new Node;
		tmp->vertex = i;
		tmp->next = NULL;
		G[i] = tmp;  
	}

	for (int i = 1; i <= Ne; i++)
	{
		int ori, dest;
		cin >> ori >> dest;

		Node* tmp = new Node;
		tmp->vertex = dest;
		tmp->next = G[ori]->next;
		G[ori]->next = tmp;

		Node* tmp2 = new Node;
		tmp2->vertex = ori;
		tmp2->next = G[dest]->next;
		G[dest]->next = tmp2;
	}


	/*for (int i = 1; i <= Nv; i++)
	{
		cout << G[i]->vertex << " : ";
		Node* tmp = G[i]->next;
		while (tmp != NULL)
		{
			cout << tmp->vertex << ",";
			tmp = tmp->next;
		}
		cout << endl;
	}
*/
	for (int i = 1; i <= Nv; i++)
	{
		int count = BFS(i);
		cout << i  << ": " << setiosflags(ios::fixed)<< setprecision(2) <<(100.0*count) / Nv << "%" << endl;
		for (int j = 1; j <= Nv; j++)
			visit[j] = false;
	}
	
	system("pause");
}