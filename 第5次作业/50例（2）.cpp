using namespace std;
#include <iostream>
int main(void){
	int I,bouns;
	cout<<"请输入当月利润I：";
	cin>>I;
	if(I<=100000)
	   bouns=I*0.1;
	else if(I<=200000)
	   bouns=100000*0.1+(I-100000)*0.075;
	else if(I<=400000)
	   bouns=100000*0.1+100000*0.075+(I-200000)*0.05;
	else if(I<=600000)
	   bouns=100000*0.1+100000*0.075+200000*0.05+(I-400000)*0.03;
	else if(I<=1000000)
	   bouns=100000*0.1+100000*0.075+200000*0.05+200000*0.03+(I-600000)*0.015;
	else
	   bouns=100000*0.1+100000*0.075+200000*0.05+200000*0.03+400000*0.015+(I-1000000)*0.1;
	cout<<"奖金总数为："<<bouns<<endl;
	return 0;
}
