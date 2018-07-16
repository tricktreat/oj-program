#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 100

using namespace std;

int a[MAXN],b[MAXN],c[MAXN][MAXN];
int m,n;

void lcs(){
	memset(c,0,sizeof(c));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i-1]==b[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
			}else{
				c[i][j]=max(c[i-1][j],c[i][j-1]);
			}
		}
	}
}

int main(){
	int t=0;
	while(cin>>m>>n&&(m!=0||n!=0)){
		for (int i = 0; i < m; ++i)
		{
			cin>>a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>b[i];
		}

		lcs();

		cout<<"Twin Towers #"<<++t<<endl;
        cout<<"Number of Tiles : "<<c[m][n]<<endl;
        cout<<endl;

	}
}