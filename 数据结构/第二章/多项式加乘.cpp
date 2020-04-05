#include <iostream>
using namespace std; 
struct Node{
	int num;
	int e;
	Node * next;
};
Node* read()
{
	int n;
	cin>>n;//读入有几个节点
	int num,e;
	
	Node* head=new Node;
	Node* p=head;
	while(n--)
	{	
		Node* tmp=new Node;
		cin>>num>>e;
		tmp->num=num;
		tmp->e=e;
		p->next=tmp;
		p=p->next;
	}
	p->next=NULL;
	
	return head->next;
	
}
void print(Node * head)
{
	Node* p=head;
	int flag=0;
	while(p!=NULL)
	{
		if(!flag)
		{
			flag=1;
		}
		else
			cout<<" ";
		cout<<p->num<<" "<<p->e;
		p=p->next;
	}
}
Node* addFunction(Node* head1,Node* head2)
{
	Node* resultHead=new Node;
	Node* p0=resultHead;
	
	Node* p1=head1;
	Node* p2=head2;
	
	while(p1!=NULL && p2!=NULL)
	{
		Node * tmp=new Node;
		tmp->next=NULL; //新节点 
		if(p1->e==p2->e)//阶数相等的情况 
		{
			tmp->num=p1->num+p2->num;
			tmp->e=p1->e;
			p1=p1->next;
			p2=p2->next;
		}
		else
			if(p1->e>p2->e)
		{
			tmp->num=p1->num;
			tmp->e=p1->e;
			p1=p1->next;
		 } 
		 	else{
				tmp->num=p2->num;
				tmp->e=p2->e;
				p2=p2->next;
		 }
		p0->next=tmp;
		p0=p0->next;
	}
	if(p1!=NULL)
		p0->next=p1;
	if(p2!=NULL)
		p0->next=p2;
	
	return resultHead->next;
}

Node * multiple(Node* head1,Node* head2)
{
	Node* mul=NULL,*head=NULL;
	Node* p1=head1;
	Node* p2=head2;
	
	for(;p1!=NULL;p1=p1->next)
	{
		for(p2=head2;p2!=NULL;p2=p2->next)
		{
			Node *tmp=new Node;
			tmp->num=(p1->num)*(p2->num);
			tmp->e=p1->e+p2->e;
			tmp->next=NULL;
			
			mul=addFunction(tmp,head);
			head=mul;
		}
	}
	return head;
}
int main()
{
	Node * head1=read();
	Node * head2=read();
	print(head1);
	cout<<endl;
	print(head2);
	cout<<endl;
	Node * result=multiple(head1,head2);
	print(result);
	return 0;
}
