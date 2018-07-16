#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
#define MAXN 35

using namespace std;

struct Point
{
	int x,y,z,time;
};

char grid[MAXN][MAXN][MAXN];
int visited[MAXN][MAXN][MAXN];
Point s;
int l,r,c,e_x,e_y,e_z;
int step[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int bfs(){
	queue<Point> q;
	q.push(s);

	while(!q.empty()){
		Point p=q.front();
		q.pop();
		if (p.x==e_x&&p.y==e_y&&p.z==e_z)
		{
			return p.time;
		}

		int x=p.x;
		int y=p.y;
		int z=p.z;
		p.time++;
		for (int i = 0; i < 6; ++i)
		{
			p.x=x+step[i][0];
			p.y=y+step[i][1];
			p.z=z+step[i][2];

			if (!visited[p.x][p.y][p.z]&&p.x>=0&&p.x<l&&p.y>=0&&p.y<r&&p.z>=0&&p.z<c)
			{
				q.push(p);
				visited[p.x][p.y][p.z]=1;
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin>>l>>r>>c){
		if(l==0&&r==0&&c==0)
			break;
		for (int i = 0; i <l; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				for (int k = 0; k < c; ++k)
				{
					cin>>grid[i][j][k];
					if (grid[i][j][k]=='S')
					{
						visited[i][j][k]=1;
						s.x=i;
						s.y=j;
						s.z=k;
						s.time=0;
					}
					if (grid[i][j][k]=='E')
					{
						e_x=i;
						e_y=j;
						e_z=k;
						visited[i][j][k]=0;
					}
					if (grid[i][j][k]=='.')
					{
						visited[i][j][k]=0;
					}
					if (grid[i][j][k]=='#')
					{
						visited[i][j][k]=1;
					}
				}
			}
		}
		
		int flag=bfs();
		if (!flag)
		{
			cout<<"Trapped!"<<endl;
		}else{
			cout<<"Escaped in "<<flag<<" minute(s)."<<endl;
		}
	}
}