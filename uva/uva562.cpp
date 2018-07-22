#include<iostream>
#include<cstring>
#include<algorithm>

#define MAXN 100005
#define MAXSUM 100005
using namespace std;

int m;
int sum;
int coins[MAXN];
int dp[MAXSUM];

//分成俩份，总价值的差值尽可能小
void dkap(){
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < m; ++i)
	{
		for (int j = sum/2; j >= coins[i]; j--)
		{
			dp[j]=max(dp[j],dp[j-coins[i]]+coins[i]);//尽可能总价值接近sum/2，这里的价值和体积都是硬币价值
		}
	}
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>m;
		sum=0;
		for (int j = 0; j < m; ++j)
		{
			cin>>coins[j];
			sum+=coins[j];
		}

		dkap();
		cout<<sum-2*dp[sum/2]<<endl;
	}
}