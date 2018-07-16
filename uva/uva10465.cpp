#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 10005

using namespace std;

int m,n,t;
int dp[MAXN];

void knap(){
	for (int i = 1; i <=t; ++i) {
		dp[i]=-(1<<30);
	}
	dp[0]=0;
	for (int j = m; j <= t; ++j)
	{
		dp[j]=max(dp[j],dp[j-m]+1);
	}
	for (int j = n; j <= t; ++j)
	{
		dp[j]=max(dp[j],dp[j-n]+1);
	}
}

int main(){
	while(cin>>m>>n>>t){
		knap();
		int i;
		for (i = t; i >0; --i) {
			if(dp[i]>0){
				
				break;
			}
		}
		cout<<dp[i];
		if (t-i>0) cout<<" "<<t-i;
		cout<<endl;
	}
}