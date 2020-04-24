#include<iostream>
using namespace std; 
#define maxsize 100000

int num[maxsize];
int N;
void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void BubbleSort()
{
	for(int P=N-1;P>0;P--)
	{
		int flag=0;
		for(int i=0;i<P;i++)
			if(num[i]>num[i+1])
			{
				swap(num[i],num[i+1]);
				
				flag=1;
			}
		if(flag==0)
			break;
	}
}
void InsertionSort()
{
	for(int P=1;P<N;P++)
	{
		int tmp=num[P];
		int i;
		for(i=P;i>0 && num[i-1]>tmp;i--)
			num[i]=num[i-1];
		num[i]=tmp;
	}
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>num[i];
	//BubbleSort();
	InsertionSort();
	int flag=1;
	for(int i=0;i<N;i++)
		if(flag==1)
		{	cout<<num[i];
			flag=0;
			}
		else
			cout<<" "<<num[i];
}
