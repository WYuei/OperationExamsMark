#include<iostream>
using namespace std;
int heap[20];
int mysize = 0;
int insert(int x)
{
	if (mysize == 20)
	{
		return -1;
	}
	int tmp = x;
	int i = mysize;
	for (; heap[(i - 1) / 2] < tmp && i >= 1; i = (i - 1) / 2)
		heap[i] = heap[(i - 1) / 2];
	heap[i] = tmp;
	mysize++;
	return 0;
}

void deleteMax()
{
	
	heap[0] = heap[mysize - 1];
	mysize--;
	int parent = 0;
	int tmp = heap[0];
	int child = parent * 2 + 1;
	for (; child < mysize; parent = child,child=parent*2+1)
	{
		if (child + 1 < mysize && heap[child] < heap[child + 1])
			child = child + 1;//找更大的子结点
		if (heap[child] > tmp)
			heap[parent] = heap[child];
		else
			break;
	}
	heap[parent] = tmp;
}

void subBuild(int root) //root是这个子树的根节点
{
	int tmp = heap[root];
	int parent = root;
	int child = parent * 2 + 1;
	for (; child < mysize; parent = child, child = parent * 2 + 1)
	{
		if (child + 1 < mysize && heap[child] < heap[child + 1])
			child = child + 1;//找更大的子结点
		if (heap[child] > tmp)
			heap[parent] = heap[child];
		else
			break;
	}
	heap[parent] = tmp;
}

void buildTree()
{
	for (int i = mysize / 2 - 1; i >= 0; i--)
		subBuild(i);
}

int main()
{
	int N;
	cin >> N;
	mysize = N;
	for (int i = 0; i < N; i++)
		cin >> heap[i];
	int x;
	buildTree();
	for (int i = 0; i < mysize; i++)
		cout << heap[i] << " ";
	system("pause");
	return 0;
}