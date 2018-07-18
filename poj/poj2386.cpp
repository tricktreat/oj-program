#include<iostream>
#include<cstring>
#include<algorithm>

#define MAXN 110

using namespace std;

char grid[MAXN][MAXN];
int n,m;
int step[8][2]={{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1},{0,1},{0,-1}};

void dfs(int q,int p){
	grid[q][p]='.';
	for (int i = 0; i < 8; ++i)
	{
		int y=p+step[i][1];
		int x=q+step[i][0];
		if (x>-1&&y>-1&&x<n&&y<m&&grid[x][y]=='W')
		{
			dfs(q+step[i][0],p+step[i][1]);
		}
	}
}

int main(){
	while(cin>>n>>m){
		int count=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>grid[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j]=='W')
				{
					dfs(i,j);
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
}