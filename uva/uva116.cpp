#include<iostream>
#include<algorithm>
#define INF 1<<30
#define MAXC 100
#define MAXR 10

using namespace std;

int grid[MAXR][MAXC];
int r,c,ans,last;
int cost[MAXR][MAXC];
int pre[MAXR][MAXC];

void dp(){
	for (int i = 0; i < r; ++i)
	{
		cost[i][0]=grid[i][0];
	}

	for (int i = 1; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			cost[j][i]=INF;
			int rows[3]={(j-1)==-1?r-1:j-1,j,(j+1)==r?0:j+1};
			sort(rows,rows+3);
			for (int k = 0; k < 3; ++k)
			{
				if (cost[rows[k]][i-1]+grid[j][i]<cost[j][i])
				{
					cost[j][i]=cost[rows[k]][i-1]+grid[j][i];
					pre[j][i]=rows[k];
				}
			}
			if (i==(c-1)&&cost[j][i]<ans)
			{
				ans=cost[j][i];
				last=j;
			}
		}

	}
}

void print_ans(int i,int j){
	if (j==0)
	{
		cout<<i+1;
		return;
	}
	print_ans(pre[i][j],j-1);
	cout<<" "<<i+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin>>r>>c){

		ans=INF;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>grid[i][j];
			}

		}
		if (c==1)
		{
			for (int i = 0; i < r; ++i)
			{
				if (grid[i][0]<ans)
				{
					ans=grid[i][0];
					last=i;
				};
			}
			cout<<last+1<<endl<<ans<<endl;
		}else{
			dp();
			print_ans(last,c-1);
			cout<<endl<<ans<<endl;
		}
	}
}