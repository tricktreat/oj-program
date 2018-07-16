#include<iostream>
#include<cstring>
#define MAXN 20

using namespace std;

int n;
int ordered[MAXN];
int seq[MAXN];
int ans[MAXN][MAXN];
int path[MAXN][MAXN];

void printlcs(int i,int j){
	if (i==0||j==0)
	{
		return;
	}
	if (path[i][j]==0)
	{
		printlcs(i-1,j-1);
		cout<<" "<<ordered[i];
	}else{
		if (path[i][j]==1)
		{
			printlcs(i-1,j);
		}else{
			printlcs(i,j-1);
		}
	}
}

void lcs(){
	memset(ans,0,sizeof(ans));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (ordered[i]==seq[j])//ordered和seq从下标1开始存元素
			{
				ans[i][j]=ans[i-1][j-1]+1;
				path[i][j]=0;
			}else{
				if (ans[i-1][j]>ans[i][j-1])
				{
					ans[i][j]=ans[i-1][j];
					path[i][j]=1;
				}else{
					ans[i][j]=ans[i][j-1];
					path[i][j]=2;
				}
			}
		}
	}
}

int main(){
	int x;
	while(cin>>n){
		for (int i = 1; i <= n; ++i)
		{
			cin>>x;
			ordered[x]=i;//按时间顺序存储事件，x表示时间次序，i表示事件标号,则ordered里保存了事件的顺序
		}
		while(cin>>x){
			seq[x]=1;
			for (int i = 2; i <= n; ++i)
			{
				cin>>x;
				seq[x]=i;
			}
			lcs();
			//printlcs(n,n);
			cout<<ans[n][n]<<endl;
		}
	}
}