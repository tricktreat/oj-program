#include<cstdio>
#include<cmath>
#define MAXD 1<<10

using namespace std;

int n,sum;
int res[MAXD];
int nodes[MAXD];
int cursum;

void solve(int t,int d){
	if (nodes[d]==-1)
	{
		return;
	}
	cursum+=nodes[t];
	res[d]=nodes[t];
	if (sum==cursum&&d==n-1)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	if(d<n-1){
		solve(2*t,d+1);
		solve(2*t+1,d+1);
	}
	cursum-=nodes[t];
}

int main(){
	while(scanf("%d%d",&n,&sum)==2){
		for (int i = 1; i < pow(2,n); ++i)
		{
			scanf("%d",&nodes[i]);
		}
		solve(1,0);
	}
}
