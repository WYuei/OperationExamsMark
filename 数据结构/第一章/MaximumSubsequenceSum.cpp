#include<iostream>
using namespace std;
/* �����ģ��ݹ�ֳ����ݣ��ֱ���ÿ���ָ��������кͣ�ʱ�临�Ӷ�Ϊ O(n*logn)*/
/* �������������ֵ*/
int Max3(int A,int B,int C){
	return (A>B)?((A>C)?A:C):((B>C)?B:C);
}
/* ����*/
int DivideAndConquer(a,0,n-1)
{
	
}



/*
int DivideAndConquer(int a[],int left,int right){
	
	cout<<left<<" "<<right<<endl;
	//�ݹ��������������ֻ��һ������
	// ������Ϊ����ʱ��������к�Ϊ�䱾��
	// ������Ϊ����ʱ��������к�Ϊ 0
	if(left == right){
		if(0 < a[left])  
			return a[left];
		return 0;
	}
	
	// �ֱ�ݹ��ҵ�����������к�
	int center = (left+right)/2; 
	int MaxLeftSum = DivideAndConquer(a,left,center);
	int MaxRightSum = DivideAndConquer(a,center+1,right);
	
	// �ٷֱ������ҿ��������к�
	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for(int i=center;i>=left;i--){  //Ӧ�ôӱ߽�����������
		LeftBorderSum += a[i];
		if(MaxLeftBorderSum < LeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;	
	}
	int MaXRightBorderSum = 0;
	int RightBorderSum = 0;
	for(int i=center+1;i<=right;i++){  // �ӱ߽�������ұ���
		RightBorderSum += a[i];
		if(MaXRightBorderSum < RightBorderSum)
			MaXRightBorderSum = RightBorderSum;
	}
	
	//��󷵻طֽ�����������кͣ��ұ�������кͣ��Ϳ��������к�������������
	return Max3(MaxLeftSum,MaxRightSum,MaXRightBorderSum+MaxLeftBorderSum);
}
*/
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
/*	int maximum=0,thisSum=0;
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
	 		tmpleft=i+1;//���thisSum��ǰ���ֱ������������п���Ҳ����һ�εĵ�һ���� 
			 }	
	 }
	cout<<left<<" "<<right<<endl;*/
	int maximum=DivideAndConquer(a,0,n-1);
	cout<<maximum;
	return 0;
}
