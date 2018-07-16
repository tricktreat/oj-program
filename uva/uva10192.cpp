#include<iostream>
#include<algorithm>
#include<cstring>

#define MAXN 110

using namespace std;

char a[MAXN],b[MAXN];
int c[MAXN][MAXN];
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
	while(cin.getline(a,MAXN)){
		if (a[0]=='#')
		{
			break;
		}
		cin.getline(b,MAXN);
		m=strlen(a);
		n=strlen(b);
		lcs();
		cout<<"Case #"<<++t<<": you can visit at most "<<c[m][n]<<" cities."<<endl;
	}
}