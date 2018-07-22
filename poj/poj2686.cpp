#include<cstdio>
#include<cstring>
#include<algorithm>

#define MAXT 8
#define MAXM 30
#define INF 1<<30

using namespace std;

int t[MAXT];
int dist[MAXM][MAXM];
double dp[1<<MAXT][MAXM];
int n,m,p,a,b;

int main(){
	while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b)==5&&(n!=0||m!=0||p!=0||a!=0||b!=0)){
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&t[i]);
		}
		for (int i = 0; i < (1<<MAXT); ++i)
		{
			fill(dist[i],dist[i]+m,INF);
		}
		for (int i = 0; i < p; ++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			dist[x-1][y-1]=dist[y-1][x-1]=z;
		}
		for (int i = 0; i < (1<<MAXT); ++i)
		{
			fill(dp[i],dp[i]+m,INF);
		}
		dp[(1<<n)-1][a-1]=0;
		for (int s = (1<<n)-2; s >= 0; --s)
		{
			for (int u = 0; u < m; ++u)
			{
				for (int v = 0; v < m; ++v)
				{
					if (dist[v][u]!=INF)
					{
						for (int i = 0; i < n; ++i)
						{
							if ((s&(1<<i))==0)
							{
							dp[s][u]=min(dp[s|1<<i][v]+(double)dist[v][u]/(double)t[i],dp[s][u]);
								dp[s][u]=min(dp[s|1<<i][v]+(double)dist[v][u]/t[i],dp[s][u]);
							}
						}	
					}
					
				}
			}
		}
		double mincost=INF;
		for (int s = (1<<n)-1; s >= 0; --s)
		{
			mincost=min(mincost,dp[s][b-1]);
		}
		if(mincost==INF){
			printf("Impossible\n");
		}else{
			printf("%.3f\n", mincost);
		}
	}
}