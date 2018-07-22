int m;
int p[MAXN];
int w[MAXN];
int dp[MAXN];

void dkap(){
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < m; ++i)
	{
		for (int j =g ; j >=	w[i]; --j)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
			vis[j][i]=1;
		}
	}
}

void print_ans(){
	int t=g;
	for (int i = m-1; i >=0; --i)//从后往前，与背包放置的阶段相反
	{
		if (vis[t][i]==1)
		{
			cout<<i<<" ";
			t-=p[i];
		}
	}
}