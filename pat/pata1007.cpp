#include<iostream>
#define MAXN 10004
using namespace std;

int seq[MAXN]={0};
int s[MAXN]={0};
int dp[MAXN]={0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	bool neg=true;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>seq[i];
		if (seq[i]>=0)
		{
			neg=false;
		}
	}

	if (neg)
	{
		cout<<0<<" "<<seq[0]<<" "<<seq[n-1]<<endl;
		return 0;
	}

	dp[0]=seq[0];
	for (int i = 1; i < n; ++i)
	{
		if (dp[i-1]+seq[i]<=seq[i])
		{
			dp[i]=seq[i];
			s[i]=i;
		}else{
			dp[i]=dp[i-1]+seq[i];
			s[i]=s[i-1];
		}
	}

	int maxv=dp[0];
	int index=0;
	for (int i = 1; i < n; ++i)
	{
		if (dp[i]>maxv)
		{
			maxv=dp[i];
			index=i;
		}
	}
	cout<<maxv<<" "<<seq[s[index]]<<" "<<seq[index]<<endl;
	return 0;
}