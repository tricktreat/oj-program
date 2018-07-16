#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 500*6
using namespace std;

struct cube
{
	int top,bottom,pos,weight;

};

char top[6][10]={"front","back","left","right","top","bottom"};
int m;
int dp[MAXN];
cube cubes[MAXN];
int temp[6];
int rec[MAXN];

void lis(){
	memset(rec,-1,sizeof(rec));
	dp[0]=1;
	for (int i = 1; i < m; ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if (cubes[i].weight>cubes[j].weight&&cubes[j].bottom==cubes[i].top)
			{
				if (dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					rec[i]=j;
				}
				
			}
			
		}
	}
}

void printtower(int i){
	if (i==-1)
	{
		return;
	}
	printtower(rec[i]);
	cout<<i/6+1<<" "<<top[i%6]<<endl;
}

int main(){
	int n;
	int t=0;
	while(cin>>n&&n){
		m=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				cin>>temp[j];
			}
			for (int j = 0; j < 6; ++j)
			{
				cubes[m].top=temp[j];
				cubes[m].bottom=temp[j+(j%2==0?1:-1)];
				cubes[m].weight=i;
				cubes[m++].pos=i;
			}
		}
		lis();
		int maxh=1;
		int maxi=0;
		for (int i = 0; i < m; ++i)
		{
			if (maxh<dp[i])
			{
				maxh=dp[i];
				maxi=i;
			}
		}
		if (t)
		{
			cout<<endl;
		}
		cout<<"Case #"<<++t<<endl<<maxh<<endl;
		printtower(maxi);
	}
}