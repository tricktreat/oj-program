#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 15

using namespace std;

int h[MAXN];
int w[MAXN];
int dp[MAXN][MAXN];
int rec[MAXN][MAXN];
int n;

void matrixchain(){
	memset(dp,0,sizeof(dp));
	for (int i = 2; i <= n; ++i)
	{
		for (int s = 0; s <= n-i; ++s)
		{
			int e=s+i-1;
			dp[s][e]=dp[s+1][e]+h[s]*w[s]*w[e];//长度为2时此处更新完毕
			rec[s][e]=s;
			for (int k = s+1; k < e; ++k)//长度为2时不进入
			{
				if (dp[s][e]>dp[s][k]+dp[k+1][e]+h[s]*w[k]*w[e])
				{
					dp[s][e]=dp[s][k]+dp[k+1][e]+h[s]*w[k]*w[e];
					rec[s][e]=k;
				}
			}
		}
	}
}

void printtmatrixchain(int i,int j){

	if (i==j)
	{
		cout<<"A"<<i+1;
		return;
	}
	int k=rec[i][j];
	if (k!=i)
	{
		cout<<"(";
	}
	printtmatrixchain(i,rec[i][j]);
	if (k!=i)
	{
		cout<<")";
	}
	cout<<" x ";
	if ((k+1)!=j)
	{
		cout<<"(";
	}
	printtmatrixchain(rec[i][j]+1,j);
	
	if ((k+1)!=j)
	{
		cout<<")";
	}
}

int main(){
	int t=0;
	while(cin>>n&&n){
		for (int i = 0; i < n; ++i)
		{
			cin>>h[i]>>w[i];
		}
		matrixchain();
		cout<<"Case "<<++t<<": ";

		cout<<"(";
		printtmatrixchain(0,n-1);
		cout<<")"<<endl;
	}
}