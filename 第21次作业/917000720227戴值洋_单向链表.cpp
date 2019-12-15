#include <iostream>
using namespace std;

struct node{
	unsigned num;
	node *next;
}; 

node *create(int a[],int n)
{
	node *head=NULL,*rear=NULL;
	for(int i=0;i<n;i++)
	{
		node *p=new node{a[i],head};
		if(head==NULL)
		{
			head=p;
			rear=p;
		}
		else
		{
			rear->next=p;
			rear=p;
		}
	} 
	rear->next=NULL;
	return head;
}

void print(node *head)
{
	node *rear=head;
	while(rear!= NULL)
	{
		cout<<rear->num<<" ";
		rear=rear->next;
	}
	cout<<endl;
}

void del(node *head,int num)
{ 
	node *fore=head,*hind=head;
	int count=0;
	while(count!=num)
	{
		hind=fore;
		fore=fore->next;
		count++;
	}
	node *p=fore;
	hind->next=fore->next;
	fore = fore->next; 
	delete p;
	cout<<"序号为"<<count<<"的节点已被删除"<<endl;
	print(head);
	cout<<endl;
}

void destroy(node *head)
{
	node *fore = head, *hind = head;
	while(fore->next!=NULL)
	{
		hind = fore->next;
		delete(fore);
		fore = hind;
	}
	delete(fore);
	cout<<"链表空间已被释放"; 
}

int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	node *head=create(a,n);
	print(head);
	cout<<"请输入要删除的节点序号：";
	int num;
	cin>>num; 
	del(head,num);
	cout<<"是否删除链表？1：是 0：否";
	int choose;
	cin>>choose;
	if(choose==1)
	destroy(head);
	return 0;
}

