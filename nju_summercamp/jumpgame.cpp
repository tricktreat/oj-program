#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1<<20

using namespace std;
int seq[MAXN];
// int d[MAXN];

// int dp(int t){
// 	if(d[t]!=-1){
// 		return d[t];
// 	}
// 	d[t]=0;
// 	for (int i = 0; i < t; ++i)
// 	{
// 		if (dp(i)&&i+seq[i]>=t)
// 		{
// 			d[t]=1;
// 			break;
// 		}
// 	}
// 	return d[t];
// }

// int main(){
// 	int n;
// 	scanf("%d",&n);
// 	for (int i = 0; i < n; ++i)
// 	{
// 		int t;
// 		scanf("%d",&t);
// 		for (int i = 0; i < t; ++i)
// 		{
// 			scanf("%d",&seq[i]);
// 		}
// 		memset(d,-1,sizeof(d));
// 		d[0]=1;
// 		int flag=dp(t-1);
// 		if (flag)
// 		{
// 			printf("True\n");
// 		}else{
// 			printf("False\n");
// 		}
// 	}
// }

//best
int canjump(int t){
	int rightmost=0;
	for (int i = 0; i < t; ++i)
	{
		if (i>rightmost)
		{
			return 0;
		}
		rightmost=max(rightmost,i+seq[i]);
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d",&t);
		for (int i = 0; i < t; ++i)
		{
			scanf("%d",&seq[i]);
		}
		
		int flag=canjump(t);
		if (flag)
		{
			printf("True\n");
		}else{
			printf("False\n");
		}
	}
}

