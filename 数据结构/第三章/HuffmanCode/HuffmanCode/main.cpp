#include<iostream>
#include<string>
using namespace std;
struct Node {
	char data;
	int weight;
	Node* left;
	Node* right;
};
Node* heap[20];
Node weightData[20];
int mysize;

Node* insertNode(char x,int w)
{
	Node* tmp = new Node;
	tmp->weight = w;
	tmp->data = x;
	tmp->left = tmp->right = NULL;

	heap[mysize] = tmp;
	int i = mysize;

	for (; heap[(i - 1) / 2]->weight > tmp->weight && i >= 1; i = (i - 1) / 2)
		heap[i] = heap[(i - 1) / 2];
	heap[i] = tmp;

	mysize++;
	return tmp;
}

Node* deleteNode()
{
	if (mysize <= 0)
		return NULL;
	Node* tmp = heap[0];
	mysize--;
	Node* curHead = heap[mysize];
	heap[0] = heap[mysize];

	int parent = 0;
	int child = parent * 2 + 1;
	for (; child < mysize; parent = child, child = 2 * parent + 1)
	{
		
		if (child + 1 < mysize && heap[child]->weight > heap[child + 1]->weight)
			child++;
		if (heap[child]->weight < curHead->weight)
		{
			heap[parent] = heap[child];/*
			cout << "parent:" << parent << ",child:" << child << endl;*/
		}
		else
			break;
	}
	heap[parent] = curHead;

	
	return tmp;
}

void Build(int root)
{
	Node* tmp = heap[root];
	int parent = root;
	int child = parent * 2 + 1;
	for (; child < mysize; parent = child, child = 2 * parent + 1)
	{
		if (child + 1 < mysize && heap[child]->weight < heap[child + 1]->weight)
			child++;
		if (heap[child]->weight < heap[parent]->weight)
			heap[parent] = heap[child];
		else
			break;
	}
	heap[parent] = tmp;
}
void proBuild()
{
	for (int i = (mysize / 2) - 1; i >= 0; i--)
		Build(i);
}

void order(Node* node)
{
	if (node!=NULL)
	{
		order(node->left);
		cout << node->data << " : " << node->weight << endl;
		order(node->right);
	}
}
int WPL(Node *node, int Depth)
{
	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
		{
			return node->weight*Depth;
		}
		else
			return (WPL(node->left, Depth + 1) + WPL(node->right, Depth + 1));
	}
}
void submit(int N,int wplLen)
{
	Node * head = new Node;
	head->data = '-';
	head->weight = 0;
	head->left = head->right = NULL;
	int flag = 1;
	int counter = 1;
	for (int i = 0; i < N; i++)
	{
		Node * node = head;

		string strInput;
		char code;
		cin >> code >> strInput;
		if (strInput.size() > N - 1)//如果编码长度过长 就不做判断了
			flag = 0;
		else
		{
			for (int j = 0; j < strInput.size(); j++)
			{
				if (node->weight != 0) //遇到叶子节点
					flag = 0;
				if (strInput[j] == '0')
				{
					if (node->left == NULL)
					{
						
						Node * tmp = new Node;
						tmp->data = '-';
						tmp->weight = 0;
						tmp->left = tmp->right = NULL;
						node->left = tmp;
						counter++;
					}
					node = node->left;
				}
				else
				{
					if (node->right == NULL)
					{
						Node * tmp = new Node;
						tmp->data = '-';
						tmp->weight = 0;
						tmp->left = tmp->right = NULL;
						node->right = tmp;
						counter++;
					}
					node = node->right;
				}
			}
			if (node->weight != 0)
				flag = 0;
			else
			{
				node->data = code;
				int k = 0;
				for (; k < N; k++)
					if (code == weightData[k].data)
						break;
				node->weight = weightData[k].weight;
				cout << "新建了一个叶子节点" << node->data << ":" << node->weight << endl;
			}
		}
	}
	int wpl = WPL(head, 0);
	cout << "WPL:" << wpl << endl;
	if (wpl == wplLen && flag!=0 && counter == 2 * N - 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
int main()
{
	int N,w;
	cin >> N;
	char x;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> w;
		Node* tmp = new Node;
		tmp->data = x;
		tmp->weight = w;
		tmp->left = tmp->right = NULL;
		heap[mysize] = tmp;
		weightData[mysize].data = x;
		weightData[mysize].weight = w;
		mysize++;
	}
	proBuild();
	
	for (int i = 1; i < N; i++)
	{
		Node* min1 = deleteNode();
		Node* min2 = deleteNode();
		Node* tmp =insertNode('-', min1->weight + min2->weight);
		tmp->left = min1;
		tmp->right = min2;
	}

	Node* head = deleteNode();
	int wpl= WPL(head,0);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		submit(N, wpl);
	
	system("pause");
}