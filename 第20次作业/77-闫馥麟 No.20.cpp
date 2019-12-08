//P144（6）
#include <iostream>
#include <string.h>
using namespace std;

int getRev (char *pa)
{
	if (pa==NULL)
	return 0;
	else
	{
		int rev=0;
		for (int i=0;*(pa+i);i++)
		{
			for (int j=i+1;*(pa+j);j++)
			{
				if (*(pa+i)>*(pa+j))
				rev++;
			}
		}
		return rev;
	}
}

struct Row
{
	int len,rev;
	char *prow;
};

void setorder(Row *tb,int row)
{
	int temp1;
	char *temp2;
	
	for (int x=0;x<row;x++)
	{
		for (int y=x+1;y<row;y++)
		{
			if (tb[x].rev>tb[y].rev)
			{
				temp1=tb[x].rev;
				tb[x].rev=tb[y].rev;
				tb[y].rev=temp1;
				
				temp2=tb[x].prow;
				tb[x].prow=tb[y].prow;
				tb[y].prow=temp2;
			}
		}
	}
}

void print(Row *tb,int row)
{
	for (int m=0;m<row;m++)
	{
		cout<<"字符串："<<tb[m].prow<<"   "<<"逆序："<<tb[m].rev<<endl;
	}
}

void del(Row *tb,int row)
{
	for (int n=0;n<row;n++)
	{
		delete []tb[n].prow;
	}
	delete []tb;
}

int main()
{
	int row=0,i,j;
	cout<<"请输入打算输入的字符串的个数"<<endl;
	cin>>row;
	Row *table=new Row[row];
	
	char s[21];
	cout<<"开始输入字符串吧"<<endl;
	cin.getline(s,20);
	for (i=0;i<row;i++)
	{
		cin.getline(s,20);
		int len=strlen(s);
		table[i].rev=getRev(s);
		table[i].prow=new char[len];
		table[i].len=len;
		for (j=0;j<len;j++)
		{
			table[i].prow[j]=s[j];
		}
	}
	
	setorder(table,row);
	cout<<"排序后输出如下："<<endl;
	print(table,row);
	del(table,row);
	return 0;
} 


//P237（4）
#include <iostream>
#include <string.h>
#define ERASE 0
using namespace std;

struct Row
{
	int n,count,len;
	char *prow;
};

void getcount(Row *tb,int n)
{
	int c=1;
	for (int x=0;x<n;x++)
	{
		c=1;
		for (int y=x+1;y<n;y++)
		{
			if (strcmp(tb[x].prow,tb[y].prow)==0)
			{
				c++;
				tb[y].count=ERASE;
			}
		}
		if (tb[x].count!=0)
			tb[x].count=c;
	}
}

void setorder1(Row *tb,int n)
{
	char *temp;
	for (int k=0;k<n;k++)
	{
		for (int p=k+1;p<n;p++)
		{
			if (strcmp(tb[k].prow,tb[p].prow)==1)
			{
				temp=tb[k].prow;
				tb[k].prow=tb[p].prow;
				tb[p].prow=temp;
			}
		}
	}
}

void setorder2(Row *tb,int n)
{
	int temp1;
	char *temp2;
	for (int r=0;r<n;r++)
	{
		for (int t=r+1;t<n;t++)
		{
			if (tb[r].count>tb[t].count)
			{
				temp1=tb[r].count;
				tb[r].count=tb[t].count;
				tb[t].count=temp1;
				
				temp2=tb[r].prow;
				tb[r].prow=tb[t].prow;
				tb[t].prow=temp2;
			}
		}
	}
}

void print1(Row *tb,int n)
{
	cout<<"第一次排序后输出如下："<<endl;
	for (int m1=0;m1<n;m1++)	
		cout<<tb[m1].prow<<endl;
}

void print2(Row *tb,int n)
{
	cout<<"第二次排序后输出如下："<<endl;
	for (int m2=0;m2<n;m2++)
	{
		if (tb[m2].count==0)
			continue;
		cout<<"字符串:"<<tb[m2].prow<<"   "<<"重复出现的次数:"<<tb[m2].count<<endl;
	}
		
}

void del(Row *tb,int n)
{
	for (int e=0;e<n;e++)
		delete []tb[e].prow;
	delete []tb;
}

int main()
{
	int n,i,j,n_;
	cin>>n;
	if (n>2)
	{
		Row *table=new Row[n];
		
		char s[100];
		cin.getline(s,100);
		for (i=0;i<n;i++)
		{
			cin.getline(s,100);
			int len=strlen(s);
			table[i].prow=new char [len];
			table[i].len=len;
			for (j=0;j<len;j++)
				table[i].prow[j]=s[j];
			table[i].count=1;
		}
		
		setorder1(table,n);
		print1(table,n);
		
		getcount(table,n);
		setorder2(table,n);
		print2(table,n);
		
		del(table,n);
	}
	return 0;
} 
