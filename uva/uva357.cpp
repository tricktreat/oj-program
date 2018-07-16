#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 300005

using namespace std;

int c[5]={1,5,10,25,50};
long long dp[MAXN];

void changecoin(){
	dp[0]=1;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = c[i]; j < MAXN; ++j)
		{
			dp[j]+=dp[j-c[i]];
		}
	}
}

int main(){
	int m;
	changecoin();
	while(cin>>m){
		if (dp[m]==1)
		{
			cout<<"There is only "<<dp[m]<<" way to produce "<<m<<" cents change."<<endl;
		}else{
			cout<<"There are "<<dp[m]<<" ways to produce "<<m<<" cents change."<<endl;
		}
	}
}