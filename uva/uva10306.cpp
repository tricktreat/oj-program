#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 50
#define MAXS 310
using namespace std;

int v1[MAXN];
int v2[MAXN];
int n,s;
int dp[MAXS][MAXS];

void twodimknap(){
	for (int j = 0; j <= s; ++j)
	{
		for (int k = 0; k <= s; ++k)
		{
			dp[j][k]=1<<20;
		}
	}
	dp[0][0]=0;

	for (int j = 0; j < n; ++j)
	{
		for (int k = v1[j]; k <= s; ++k)
		{
			for (int m = v2[j]; m <= s; ++m)
			{
				dp[k][m]=min(dp[k][m],dp[k-v1[j]][m-v2[j]]+1);
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>n>>s;
		for (int j = 0; j < n; ++j)
		{
			cin>>v1[j]>>v2[j];
		}
		
		twodimknap();
		int ans=1<<20;
		for (int j = 0; j <= s; ++j)
		{
			for (int k = 0; k <= s; ++k)
			{
				if (j*j+k*k==s*s)
				{
					ans=min(ans,dp[j][k]);
				}
			}
		}
		if (ans==1<<20)
		{
			cout<<"not possible"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}