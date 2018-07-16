#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 20
#define MAXM 1<<10

using namespace std;

int tracks[MAXN];
int m,n;
int dp[MAXM];
int vis[MAXM][MAXM];

void dkap(){
	memset(dp,0,sizeof(dp));
	memset( ,0,sizeof(vis));
	for (int i = 0; i < n; ++i)
	{
		for (int j = m; j >= tracks[i]; --j)
		{
			if (dp[j]<=dp[j-tracks[i]]+tracks[i])
			{
				dp[j]=dp[j-tracks[i]]+tracks[i];
				vis[j][i]=1;
			}
		}
	}
}

int main(){
	while(cin>>m>>n){
		for (int i = 0; i < n; ++i)
		{
			cin>>tracks[i];
		}
		dkap();
		int t=m;
		// while(pre[t]!=-1){//这种方法没有正确的回溯，因为dp丢失了阶段信息
		// 	cout<<tracks[pre[t]]<<" ";
		// 	t=t-tracks[pre[t]];
		// }
		for (int i = n-1; i >=0; --i)//从后往前，与背包放置的阶段相反
		{
			if (vis[t][i]==1)
			{
				cout<<tracks[i]<<" ";
				t-=tracks[i];
			}
		}
		cout<<"sum:"<<dp[m]<<endl;
	}
}