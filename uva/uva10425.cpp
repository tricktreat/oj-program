#include<iostream>
#include<cstring>
#define MAXN 1005

using namespace std;

char a[MAXN],b[MAXN];
int c[MAXN][MAXN];
int m,n;



void lcs(){
	for (int i = 0; i <= m; ++i)
	{
		c[i][0]=0;
	}
	for (int j = 0; j <= n; ++j)
	{
		c[0][j]=0;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i-1]==b[j-1])//更新c[i][j]时，判断序列的第i和第j个是否相等，这里序列从下标0开始存，但是c记录俩序列长度是从1开始的
			{
				c[i][j]=c[i-1][j-1]+1;
			}else if (c[i][j-1]>c[i-1][j])
			{
				c[i][j]=c[i][j-1];
			}else{
				c[i][j]=c[i-1][j];
			}
		}
	}
}

int main(){
	while(cin.getline(a,MAXN)){
		cin.getline(b,MAXN);
		memset(c,0,sizeof(c));
		m=strlen(a);
		n=strlen(b);
		lcs();
		cout<<c[m][n]<<endl;
	}
}