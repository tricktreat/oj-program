//一维最长递减序列
void lis(){
	inc[0]=1;
	for (int i = 1; i < n; ++i)
	{
		inc[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if (seq[i]>seq[j])
			{
				inc[i]=max(inc[i],inc[j]+1);
			}
		}
	}
}

//二维矩阵的最长递减路径
int d[MAXR][MAXNC];
int r,c;
int grid[MAXR][MAXC];

int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int dp(int i,int j){
	if (d[i][j]>0)
	{
		return d[i][j];
	}
	d[i][j]=1;

	int a,b;
	for (int k = 0; k < 4; ++k)
	{
		a=step[k][0]+i;
		b=step[k][1]+j;
		if (a<0||a>=c||b<0||b>=r)//判断是否越界
		{
			continue;
		}
		if (grid[i][j]<grid[a][b])
		{
			d[i][j]=max(d[i][j],dp(a,b)+1);
		}
	}
	return d[i][j];
}