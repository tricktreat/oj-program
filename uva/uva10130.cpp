#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 1000
#define MAXG 100

using namespace std;

int m;
int p[MAXN];
int w[MAXN];
int dp[MAXN];

void dkap(){
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < m; ++i)
	{
		for (int j =MAXG ; j >=	w[i]; --j)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		}
	}
}

int main(){
	int k;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>m;

		for (int j = 0; j < m; ++j)
		{
			cin>>p[j]>>w[j];
		}
		dkap();
		cin>>k;
		int sum=0;
		for (int t = 0; t < k; ++t)
		{
			int g;
			cin>>g;
			sum+=dp[g];
		}
		cout<<sum<<endl;
	}
}