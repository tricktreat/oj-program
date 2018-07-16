#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 200

using namespace std;

int d[MAXN][MAXN];
int step[2][2]={{-1,0},{0,-1}};
int r,c;

int dp(int i,int j){
	if (d[i][j]>-1)
	{
		return d[i][j];
	}
	d[i][j]=0;
	for (int k = 0; k <2; ++k)
	{
		int a=i+step[k][0];
		int b=j+step[k][1];
		if(a>-1&&a<r&&b>-1&&b<c){
			d[i][j]+=dp(a,b);
		}
	}
	return d[i][j];
}

int main(){
	int n,cv;
	char a[MAXN];
	cin>>n;
	while (n--)
	{
		memset(d,-1,sizeof(d));
		cin>>r>>c;
        cin.get();
		for (int j = 0; j < r; ++j)
		{

			cin.getline(a,MAXN);

			int i=1;
			while(a[i]){
				if(isdigit(a[i]))
				{
					sscanf(a+i,"%d",&cv);
					d[j][cv-1]=0;
				}
                i++;
			}
			// cin>>rv;    //这种输入没有考虑列号超过1位数字的情况
			// while(cin.get(a)&&a!='\n'){
			// 	if (a==' ')
			// 	{
			// 		cv=cin.get()-'0';
			// 		d[rv-1][cv-1]=0;
			// 	}
			// }
		}
		d[0][0]=1;
		
		cout<<dp(r-1,c-1)<<endl;
		if(n){
			cout<<endl;
		}
	}
}