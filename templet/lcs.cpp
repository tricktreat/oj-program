int c[MAXN+1][MAXN+1];
char a[MAXN];
char b[MAXN];
int n;

void printlcs(int i,int j){
	if (i==0||j==0)	
	{
		return;
	}
	if (c[i][j]==c[i-1][j])
	{
		printlcs(i-1,j);
	}else if (c[i][j]==c[i][j-1])
	{
		printlcs(i,j-1);
	}else{
		printlcs(i-1,j-1);
		cout<<a[i-1]<<endl;
	}
}

void lcs(){
	memset(c,0,sizeof(c));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i-1]==b[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
			}else if (c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
			}else{
				c[i][j]=c[i][j-1];
			}
		}
	}
}