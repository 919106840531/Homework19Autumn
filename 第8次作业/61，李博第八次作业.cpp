	21.（6）
#include<iostream>
using namespace std;
int ComFac(int a,int b){
	int m,n;
	m=a;
	n=b;
	if(n==0)
	return a;
	ComFac(n,m%n);
	
}
int ComMul(int c,int b){
	if(ComFac(c,b)==1)
	return c*b;
	else
	return c*b/ComFac(c,b);
	
}
int main(){
	int k,l;
	cout<<"请输入两个正整数：";
	cin>>k>>l;
	cout<<"最大公因数是："<<ComFac(k,l)<<'\n';
	cout<<"最小公倍数是："<<ComMul(k,l)<<endl; 
	return 0;
	
	
}
21.（7）
#include<iostream>
using namespace std;
int S(int n){
	int a,s=0;
	while(n>0){
		a=n%10;
		s=s+a;
		s=s*10;
		n=n/10;
	}
	return s/10;
}
int main(){
	int a;
	cin>>a;
	cout<<S(a);
                return 0;
}
(7)
#include<iostream>
using namespace std;
void S(int n){
	if(n==0)
	return;
	cout<<n%10;
	n=n/10;
	S(n);
	
}
int main(){
	int a;
	cin>>a;
	S(a);
}