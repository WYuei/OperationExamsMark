#include<iostream>
using namespace std;
/* 方法四：递归分成两份，分别求每个分割后最大子列和，时间复杂度为 O(n*logn)*/
/* 返回三者中最大值*/
int Max3(int A,int B,int C){
	return (A>B)?((A>C)?A:C):((B>C)?B:C);
}
/* 分治*/
int DivideAndConquer(a,0,n-1)
{
	
}



/*
int DivideAndConquer(int a[],int left,int right){
	
	cout<<left<<" "<<right<<endl;
	//递归结束条件：子列只有一个数字
	// 当该数为正数时，最大子列和为其本身
	// 当该数为负数时，最大子列和为 0
	if(left == right){
		if(0 < a[left])  
			return a[left];
		return 0;
	}
	
	// 分别递归找到左右最大子列和
	int center = (left+right)/2; 
	int MaxLeftSum = DivideAndConquer(a,left,center);
	int MaxRightSum = DivideAndConquer(a,center+1,right);
	
	// 再分别找左右跨界最大子列和
	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for(int i=center;i>=left;i--){  //应该从边界出发向左边找
		LeftBorderSum += a[i];
		if(MaxLeftBorderSum < LeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;	
	}
	int MaXRightBorderSum = 0;
	int RightBorderSum = 0;
	for(int i=center+1;i<=right;i++){  // 从边界出发向右边找
		RightBorderSum += a[i];
		if(MaXRightBorderSum < RightBorderSum)
			MaXRightBorderSum = RightBorderSum;
	}
	
	//最后返回分解的左边最大子列和，右边最大子列和，和跨界最大子列和三者中最大的数
	return Max3(MaxLeftSum,MaxRightSum,MaXRightBorderSum+MaxLeftBorderSum);
}
*/
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
/*	int maximum=0,thisSum=0;
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
	 		tmpleft=i+1;//这段thisSum往前部分被抛弃，所以有可能也是下一段的第一个了 
			 }	
	 }
	cout<<left<<" "<<right<<endl;*/
	int maximum=DivideAndConquer(a,0,n-1);
	cout<<maximum;
	return 0;
}
