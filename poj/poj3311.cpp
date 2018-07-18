#include<cstdio>
#include<algorithm>
#include<cstring>

#define INF 1<<30
#define MAXN 11

using namespace std;

int n;
int dist[MAXN][MAXN];
int d[1<<MAXN][MAXN];

void floyd(){
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

int dp(int s,int t){
	if (d[s][t]>=0)
	{
		return d[s][t];
	}
	if (s==(1<<n)-1&&t==0)
	{
		return d[s][0]=0;
	}
	d[s][t]=INF;
	for (int i = 0; i < n; ++i)
	{
		if (!(s&(1<<i)))
		{
			d[s][t]=min(d[s][t],dp(s|(1<<i),i)+dist[t][i]);
		}
	}
	return d[s][t];
}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		n++;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&dist[i][j]);
			}
		}

		floyd();
		memset(d,-1,sizeof(d));
		printf("%d\n",dp(0,0));
	}
}