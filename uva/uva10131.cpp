#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 1000

using namespace std;

struct Elephant
{
	int id,w,q;	
};

//lcs
Elephant eles[MAXN];
int a[MAXN];
int b[MAXN];
int c[MAXN][MAXN];
int n;

//lis
int dp[MAXN];
int maxv;
int last;
int fa[MAXN];

bool wcompare(Elephant a,Elephant b){
	return a.w<b.w;
}

bool qcompare(Elephant a,Elephant b){
	return a.q>b.q;
}

void printlcs(int i,int j){
	if (i==0||j==0)	
	{
		return;
	}
	if (c[i][j]==c[i-1][j])
	{
		printlcs(i-1,j);
	}else if (c[i][j]==c[i][j-1])
	{
		printlcs(i,j-1);
	}else{
		printlcs(i-1,j-1);
		cout<<a[i-1]<<endl;
	}
}

void lcs(){
	memset(c,0,sizeof(c));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i-1]==b[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
			}else if (c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
			}else{
				c[i][j]=c[i][j-1];
			}
		}
	}
}

void printlis(int t){
	if (dp[t]==1)
	{
		cout<<eles[t].id<<endl;
		return;
	}
	for (int i = 0; i < t; ++i)
	{
		if (dp[i]+1==dp[t]&&eles[i].q>eles[t].q)
		{
			printlis(i);
			break;
		}
	}
	cout<<eles[t].id<<endl;
}

void printlis2(int t){
	if (fa[t]==0)
	{
		cout<<eles[t].id<<endl;
		return;
	}
	printlis2(fa[t]);
	cout<<eles[t].id<<endl;
}

void lis(){
	for (int i = 0; i < n; ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if (eles[i].q<eles[j].q&&eles[i].w>eles[j].w)//重量严格递增才更新
			{
				if (dp[i]<dp[j]+1)
				{
					fa[i]=j;
					dp[i]=dp[j]+1;
				}
				if (dp[i]>maxv)
				{
					maxv=dp[i];
					last=i;
				}
			}
		}
	}
}

int main(){
	int w,q;
	n=0;
	while(cin>>w>>q){
		eles[n].id=n+1;
		eles[n].w=w;
		eles[n++].q=q;
	}

	sort(eles,eles+n,wcompare);

	// for (int i = 0; i < n; ++i)
	// {
	// 	a[i]=eles[i].id;
	// 	cout<<a[i];
	// }
	// cout<<endl;
	// sort(eles,eles+n,qcompare);
	// for (int i = 0; i < n; ++i)
	// {
	// 	b[i]=eles[i].id;
	// 	cout<<b[i];
	// }
	// cout<<endl;

	//lcs();
	//cout<<c[n][n]<<endl;
	//printlcs(n,n);

	lis();
	cout<<dp[last]<<endl;
	printlis2(last);
	//printlis(last);
}