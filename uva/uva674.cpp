#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 7500

using namespace std;

int c[5]={1,5,10,25,50};
int dp[MAXN];
int dp2[MAXN][5];
int m;

void changecoin(){
	dp[0]=1;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = c[i]; j <= m; ++j)//利用上一阶段（i-1）的值，c[i]-->m：f[i,v]=f[i-1,v]+f[i,v-c[i]],这个式子表明计算f[i,v]需要"上一阶段"的"同兑换钱币"的值，需要"本阶段的"少于兑换钱币"的值
		{
			dp[j]+=dp[j-c[i]];
		}
	}
}

long long solve(int s, int i) {
	if (dp2[s][i] != -1)
		return dp2[s][i];
	dp2[s][i] = 0;
	for (int j = i; j < 5 && s >= c[j]; j++)
		dp2[s][i] += solve( s - c[j],j);

	return dp2[s][i];
}


int main(){
	while(cin>>m){
		memset(dp2,-1,sizeof(dp2));
		memset(dp,0,sizeof(dp));

		for (int i = 0; i < 5; ++i)
		{
			dp2[0][i]=1;
		}
		changecoin();
		cout<<dp[m]<<endl;
		//cout<<solve(m,0)<<endl;
	}
}