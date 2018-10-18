#include<iostream>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int grid[5][5];
int visited[5][5];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

struct node
{
	int x,y,pre;
};

node nodes[25];

void printres(int front){
	if (front==-1)
	{
		return;
	}
	printres(nodes[front].pre);
	cout<<"("<<nodes[front].x<<", "<<nodes[front].y<<")"<<endl;
}

int main(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin>>grid[i][j];
		}
	}
	nodes[0].x=0;
	nodes[0].y=0;
	nodes[0].pre=-1;
	visited[0][0]=1;
	int front=0;
	int cnt=1;
	while(front<cnt){
		node q=nodes[front];

		if (q.x==4&&q.y==4)
		{	
			printres(front);
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int x=q.x+step[i][0];
			int y=q.y+step[i][1];
			if (x<0||y<0||x>4||y>4||grid[x][y]==1||visited[x][y]==1)
			{
				continue;
			}
			visited[x][y]=1;

			nodes[cnt].x=x;
			nodes[cnt].y=y;
			nodes[cnt].pre=front;
			cnt++;
		}

		front++;
	}
}