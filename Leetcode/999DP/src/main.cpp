#include <iostream>
using namespace std;

//有钞票1，5，11，求凑出15，需要最小的钞票数是多少
void function1(){
	int f[100],n,cost;
	cout<<"请输入要凑的总钱数（整数）："<<endl;
	scanf("%d",&n);
	f[0] = 0;
	cout<<"代价函数f(n)=需要的最少钞票张数的关系 依次如下："<<endl;
	for(int i=1;i<=n;i++){
		cost=INT_FAST32_MAX;
		if(i-1>=0)
			cost=min(cost,f[i-1]+1);
		if(i-5>=0)
			cost=min(cost,f[i-5]+1);
		if(i-11>=0)
			cost=min(cost,f[i-11]+1);
		f[i] = cost;
		printf("f[%d]=%d\n",i,f[i]);

	}
}

/*
 * 求最长上升子序列LIS问题
 * 1,5,3,4,6,9,7,8
 * */
void function2(){
	int f[100]={0},a[100]={0},n=0,cost=0;
	cout<<"请输入原始的数据序列长度："<<endl;
	scanf("%d",&n);
	cout<<"请输入长度是："<<n<<"的数据序列："<<endl;
	for(int i =1;i<=n;i++){
		scanf("%d",&a[i]);//原始的序列
		f[i] = 1;		//最长上升子序列的长度
	}

	cout<<"你输入的数据序列是："<<endl;
	for(int i =1;i<=n;i++){
		cout<<a[i]<<" ";
	}

	cout<<"代价函数f(n)=最长上升子序列LIS的长度之间的关系 依次如下："<<endl;
	int max_incre_len = 0;
	for(int x=1;x<=n;x++){
		for(int p=1;p<x;p++){
			if(a[p]<a[x])
				f[x]=max(f[x],f[p]+1);
		}
		if(f[x]>max_incre_len){
			max_incre_len = f[x];
		}
		printf("f[%d]=%d\n",x,f[x]);


	}
	cout<<"res:len(LIS)="<<max_incre_len<<endl;
}

int main(int argc,char * argv[]){
	function2();
    return 0;
}