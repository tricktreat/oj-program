#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXNUM 30
#define MAXDIM 10

using namespace std;

int d[MAXNUM];
int adj[MAXNUM][MAXNUM];
int boxes[MAXNUM][MAXDIM];
int m,n;

void printdag(int i){
	for (int j = 0; j < m; ++j)
	{
		if (adj[i][j]==1&&d[i]==d[j]+1)
		{
			printdag(j);
			break;
		}
	}
	if (d[i]!=1)
	{
		cout<<" ";
	}
	cout<<i+1;

}

int dp(int i){
	if(d[i]>0){
		return d[i];
	}
	d[i]=1;//终结点，出度为零直接返回1
	for (int j = 0; j < m; ++j)
	{
		if (adj[i][j])
		{
			d[i]=max(d[i],dp(j)+1);
		}
	}
	return d[i];
}

int main(){
	int count;
	while(cin>>m>>n){
		memset(d,0,sizeof(d));
		memset(adj,0,sizeof(adj));

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>boxes[i][j];
			}
			sort(boxes[i],boxes[i]+n);
			for (int k = 0; k < i; ++k)
			{
				count=0;
				for (int j = 0; j < n; ++j)
				{
					if(boxes[i][j]<boxes[k][j]){
						count++;
					}
					if(boxes[i][j]>boxes[k][j]){
						count--;
					}
				}
				if (count==n)
				{
					adj[k][i]=1;
				}
				if (count==-n)
				{
					adj[i][k]=1;
				}
			}
		}

		int maxv=dp(0);
		int first;
		int a;
		for (int i = 1; i < m; ++i)
		{
			a=dp(i);
			if (maxv<a)
			{
				maxv=a;
				first=i;
			}
			
		}
		cout<<maxv<<endl;
		printdag(first);
		cout<<endl;
	}
}