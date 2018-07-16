#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 100
#define MAXL 35

using namespace std;

char awords[MAXN][MAXL];
char bwords[MAXN][MAXL];
int dp[MAXN+1][MAXN+1];
int m,n;
int flag;

void lcs(){
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (!strcmp(awords[i-1],bwords[j-1]))
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}

void printlcs(int i,int j){
	if (i==0||j==0)
	{
		return;
	}
	if (dp[i][j]==dp[i-1][j])
	{
		printlcs(i-1,j);
	}else if (dp[i][j]==dp[i][j-1]){
		printlcs(i,j-1);
	} else{
		printlcs(i-1,j-1);
		if (flag)
		{
			cout<<" ";
		}
		flag=1;
		cout<<awords[i-1];
	}
}

int main(){
	char temp[MAXL];
	while(cin>>temp){
		flag=0;
		m=0;
		n=0;
		while(temp[0]!='#'){
			strcpy(awords[m++],temp);
			cin>>temp;
		}

		cin>>temp;
		while(temp[0]!='#'){
			strcpy(bwords[n++],temp);
			cin>>temp;
		}
		lcs();
		printlcs(m,n);
		cout<<endl;
	}
}