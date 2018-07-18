//记忆搜索
int n;
int dist[MAXN][MAXN];
int d[1<<MAXN][MAXN];

int dp(int s,int t){
	if (d[s][t]>=0)
	{
		return d[s][t];
	}
	if (s==(1<<n)-1&&t==0)
	{
		return d[s][t]=0;//表示的意思为已经访问了所有城市，从城市0出发去访问未访问所有城市所需代价
	}
	d[s][t]=INF;
	for (int i = 0; i < n; ++i)
	{
		if (!s&(1<<i))
		{
			d[s][t]=min(dp(s|(1<<i,i)+dist[t][i]),d[s][t])
		}
	}
	return d[s][t];
}

void solve(){
	memset(d,-1,sizeof(d));
	cout<<dp(0,0)<<endl;//表示所有城市都未访问的状态下，从0出发访问未访问的所有城市需要的代价
}


//循环求解
int dp[1<<MAXN][MAXN];

void solve(){
	for (int s = 0; s < 1<<n; ++s)
	{
		fill(dp[s],dp[s]+n,INF);
	}

	dp[0][0]=0;//最小规模问题解，dp由这里开始更新

	//更新的顺序为：已访问的城市由多到少，目前所在城市首先为0，其他顺序可随意
	for (int s = (1<<n)-1; s>=0 ; s--)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int v = 0; v < n; ++v)
			{
				dp[s][i]=min(dp[s|1<<v][v]+dist[i][v],dp[s][i]);
			}
			
		}
	}

	cout<<dp(0,0)<<endl;
}