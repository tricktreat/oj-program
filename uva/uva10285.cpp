#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

#define MAXN 100

using namespace std;

int c,r;
int grid[MAXN][MAXN];
int d[MAXN][MAXN];

int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int dp(int i,int j){
	if (d[i][j]>0)
	{
		return d[i][j];
	}
	d[i][j]=1;

	int a,b;
	for (int k = 0; k < 4; ++k)
	{
		a=step[k][0]+i;
		b=step[k][1]+j;
		if (a<0||a>=c||b<0||b>=r)
		{
			continue;
		}
		if (grid[i][j]<grid[a][b])
		{
			d[i][j]=max(d[i][j],dp(a,b)+1);
		}
	}
	return d[i][j];
}

int main(){
	int n;
	cin>>n;
	string name;
	for (int i = 0; i < n; ++i)
	{
		memset(d,0,sizeof(d));
		cin>>name;
		cin>>c>>r;

		for (int j = 0; j < c; ++j)
		{
			for (int k = 0; k < r; ++k)
			{
				cin>>grid[j][k];
			}
		}
		int maxv=0;
		for (int j = 0; j < c; ++j)
		{
			for (int k = 0; k < r; ++k)
			{
				maxv=max(maxv,dp(j,k));
			}
		}
		cout<<name<<": "<<maxv<<endl;
	}
}