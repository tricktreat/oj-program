#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

#define MAXN 100010

int dis[MAXN];

int main(){
	int n,d,p,q,m,sum=0;
	scanf("%d",&n);
	dis[0]=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&d);
		sum+=d;
		dis[i+1]=sum;
	}
	scanf("%d",&m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&p,&q);
		if (p>q)
		{
			printf("%d\n", min(dis[p-1]-dis[q-1],sum-dis[p-1]+dis[q-1]));
		}else{
			printf("%d\n", min(dis[q-1]-dis[p-1],sum-dis[q-1]+dis[p-1]));
		}
	}
	return 0;
}