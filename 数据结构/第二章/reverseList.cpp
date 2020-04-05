#include<iostream>
using namespace std;
int main()
{
	const int MAXSIZE=100005;
	int Data[MAXSIZE];
	int Next[MAXSIZE];
	int List[MAXSIZE];
	int firstAddr,N,K;
	cin>>firstAddr>>N>>K;
	
	for(int i=0;i<N;i++)
	{
		int addr,data,next;
		cin>>addr>>data>>next;
		Data[addr]=data;
		Next[addr]=next;
	}
	int index=firstAddr;
	int sum=0;
	while(index!=-1)
	{
		List[sum]=index;
		sum++;
		index=Next[index];
	}
	for(int i=0;i+K<N;i+=K)
	{
		//初始版倒转链表，真的很丑，就是新建了个数组塞进去，再把新数组的拷贝回原来的数组 
		/*int tmp[10];
		int j;
		for(j=0;j<K;j++)
			tmp[j]=List[i+K-j-1];
		for(int z=i,j=0;z<i+K;z++,j++)
			List[z]=tmp[j];*/
			
		for(int z=0;z<K/2;z++)
		{
			int tmp=List[i+z];
			List[i+z]=List[i+K-z-1];
			List[i+K-z-1]=tmp;
		 } 
	}
	int i;
	for(i=0;i<N-1;i++)
		cout<<List[i]<<" "<<Data[List[i]]<<" "<<List[i+1]<<endl;
	cout<<List[i]<<" "<<Data[List[i]]<<" "<<-1<<endl;
	return 0;
}
