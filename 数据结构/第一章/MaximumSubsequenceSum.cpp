#include<iostream>
using namespace std;
int main()
{
	const int n=8;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		/*��ͨ����ʱ�临�Ӷ�O��N^2��*/ 
/*	int maximum=0;
	for(int i=0;i<n;i++)
	{
		int thisSum=0;
		for(int j=i;j<n;j++)
		{
			thisSum+=a[j];
			if(thisSum>maximum)
				maximum=thisSum;
		}
	}*/
	
	/*̰�ķ� ֻ���Ǿֲ����Ž�*/
	int maximum=0,thisSum=0;
	int left=0,tmpleft=0,right=n-1; 
	for(int i=0;i<n;i++) 
	 {
	 	thisSum+=a[i];
	 	if(thisSum>maximum)
	 	{	maximum=thisSum;
	 		left=tmpleft;//ÿ�θ��µ�ʱ��ȷ��right 
	 		right=i;
		 }
	 	if(thisSum<0) //ֻҪ�ǷǸ������Ͳ����Ϻ�����ӵ����ĺ��� 
	 	{	thisSum=0;
	 		tmpleft=i+1;//���thisSum��ǰ�������������п���Ҳ����һ�εĵ�һ���� 
			 }	
	 }
	cout<<left<<" "<<right<<endl;
	cout<<maximum;
	return 0;
}
