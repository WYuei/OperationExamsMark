#include<iostream>
using namespace std;
int main()
{
	const int n=8;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		/*普通法，时间复杂度O（N^2）*/ 
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
	
	/*贪心法 只考虑局部最优解*/
	int maximum=0,thisSum=0;
	int left=0,tmpleft=0,right=n-1; 
	for(int i=0;i<n;i++) 
	 {
	 	thisSum+=a[i];
	 	if(thisSum>maximum)
	 	{	maximum=thisSum;
	 		left=tmpleft;//每次更新的时候确定right 
	 		right=i;
		 }
	 	if(thisSum<0) //只要是非负数，就不会拖后面待加的数的后腿 
	 	{	thisSum=0;
	 		tmpleft=i+1;//这段thisSum往前被抛弃，所以有可能也是下一段的第一个了 
			 }	
	 }
	cout<<left<<" "<<right<<endl;
	cout<<maximum;
	return 0;
}
