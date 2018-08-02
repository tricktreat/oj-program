#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;


struct node
{
	int v;
	int cost;
};
int a,b;
int visited[10000];
queue<node> q;
bool isprime[10000];

int bfs(){
	while(!q.empty()){
		q.pop();
	}
	node n;
	n.v=a;
	n.cost=0;
	q.push(n);
	visited[n.v]=1;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		cout<<u.v<<endl;
		if (u.v==b)
		{
			return u.cost;
		}
		u.cost++;
		int dig[4];
		dig[3]=u.v%10;
		dig[2]=u.v/10%10;
		dig[1]=u.v/100%10;
		dig[0]=u.v/1000;
		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i <= 9; ++i)
			{
				if (j==0&&i==0)
				{
					continue;
				}

				u.v+=(i-dig[j])*pow(10,3-j);
				if (visited[u.v]==1||!isprime[u.v])
				{
					continue;
				}
				q.push(u);
				visited[u.v]=1;
			}
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < 10000; ++i)
	{
		isprime[i]=true;
	}
	isprime[0]=isprime[1]=false;
	for (int i = 2; i < 10000; ++i)
	{
		if (isprime[i])
		{
			for (int j = i*2; j < 10000; j+=i)
			{
				isprime[j]=false;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		memset(visited,0,sizeof(visited));
		cin>>a>>b;
		int res=bfs();
		if (res==-1)
		{
			cout<<"Impossible"<<endl;
		}else{
			cout<<res<<endl;
		}
	}
}