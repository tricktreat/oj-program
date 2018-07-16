#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXL 1000
#define MAXN 50

using namespace std;

int heaps[MAXN];
int d[MAXN][MAXN];
int n,l;

int dp(int s,int e){
	if (d[s][e]>=0)
	{
		return d[s][e];
	}
	d[s][e]=dp(s,s+1)+dp(s+1,e)+heaps[e]-heaps[s];
	for (int i = s+2; i < e; ++i)
	{
		d[s][e]=min(d[s][e],dp(s,i)+dp(i,e)+heaps[e]-heaps[s]);
	}
	return d[s][e];
}

int main(){
	while(cin>>l&&l){
		cin>>n;
		memset(d,-1,sizeof(d));
		for (int i = 0; i <= n; ++i)
		{
			d[i][i+1]=0;
		}
		heaps[0]=0;
		for (int i = 1; i <= n; ++i)
		{
			cin>>heaps[i];
		}
		heaps[n+1]=l;

		cout<<"The minimum cutting is "<<dp(0,n+1)<<"."<<endl;
	}
}