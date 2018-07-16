#include<iostream>
#define MAXN 1000
using namespace std;

int k,m;
int p[MAXN];
int v[MAXN];
int dp[MAXN];

void knap(){
	for (int i = 0; i <= m; ++i)
	{
		dp[i]=0;
	}
	for (int i = 0; i < k; ++i)
	{
		for (int j = m; j>=v[i]; --j)
		{
			if (dp[j-v[i]]+p[i]>dp[j])
			{
				dp[j]=dp[j-v[i]]+p[i];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	while(n--){
		cin>>k>>m;
		for (int i = 0; i < k; ++i)
		{
			cin>>p[i];
		}
		for (int i = 0; i < k; ++i)
		{
			cin>>v[i];
		}
		knap();
		cout<<dp[m]<<endl;
	}
}