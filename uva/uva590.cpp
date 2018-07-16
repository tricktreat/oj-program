#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 10
#define MAXK 1000

using namespace std;

int a[MAXN][MAXN];
int b[30][MAXN][MAXN];
int dp[MAXK][MAXN];
int n,k;

void solve(){
	dp[0][0]=0;//第0天在出发地，cost为0
	for (int i = 1; i < n; ++i)
	{
		dp[0][i]=1<<30;//把不合理的状态初始化为无穷大，使得不影响后面状态的更新
	}
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j]=1<<30;//初始状态为无穷大
			for (int m = 0; m < n; ++m)
			{
				if (m!=j&&b[(i-1)%a[m][j]][m][j]!=0)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][m]+b[(i-1)%a[m][j]][m][j]);
				}
			}
			
		}
	}
}

int main(){
	int t=0;
	while(cin>>n>>k&&n&&k){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i!=j)
				{
					cin>>a[i][j];
				}
				for (int k = 0; k < a[i][j]; ++k)
				{
					cin>>b[k][i][j];//输入航班时刻表，i表示出发地，j表示目的地，k表示时间
				}
			}
		}

		solve();

		cout<<"Scenario #"<<++t<<endl;
		if (dp[k][n-1]!=1<<30)//这里的值为k时，才将第k-1天（即题目中的第k天）的飞行任务完成
		{
			cout<<"The best flight costs "<<dp[k][n-1]<<"."<<endl<<endl;;
		}else{
			cout<<"No flight possible."<<endl<<endl;;
		}
	}
}    