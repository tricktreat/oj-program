#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 1000005
#define MAXM 10005

using namespace std;

int ne[MAXM];
int pattern[MAXN];
int des[MAXN];
int m;
int n;

void getne(){
	ne[0]=-1;
	int k=-1;
	int j=0;
	while(j<m)
	{
		if (k==-1||pattern[j]==pattern[k])
		{
			ne[++j]=++k;
		}else{
			k=ne[k];
		}
	}
}

int kmpindex(){
	int i=0,j=0;
	while(i<n&&j<m){
		if (j==-1||des[i]==pattern[j])
		{
			i++;
			j++;
		}else{
			j=ne[j];
		}
	}

	if (j==m)
	{
		return i-m+1;
	}
	if (i==n)
	{
		return -1;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;

	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>n>>m;
		for (int j = 0; j < n; ++j)
		{
			cin>>des[j];
		}
		for (int j = 0; j < m; ++j)
		{
			cin>>pattern[j];
		}
		getne();
		cout<<kmpindex()<<endl; 
	}
}