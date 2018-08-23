#include<iostream>
#include<iomanip>
#define MAXN 1005
#define MAXC 2005
using namespace std;

float k,a[MAXN]={0},b[MAXN]={0},c[MAXC]={0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m,maxm=-1,maxc=-1;

	cin>>n;
	while(n--){
		cin>>m>>k;
		a[m]=k;
		if(m>maxm){
			maxm=m;
		}
	}

	cin>>n;
	while(n--){
		cin>>m>>k;
		b[m]=k;
		if(m>maxm){
			maxm=m;
		}
	}

	int count=0;
	for (int i = 0; i <= maxm; ++i)
	{
		for (int j = 0; j <= maxm; ++j)
		{
			c[i+j]=a[i]*b[j]+c[i+j];
			if(c[i+j]!=0&&(i+j)>maxc){
				maxc=i+j;
			}
		}
	}
	for (int i = 0; i <= maxc; ++i)
	{
		if (c[i]!=0)
		{
			count++;
		}
	}
	cout<<count;
	for (int i = maxc; i >=0; --i)
	{
		if (c[i]!=0)
		{
			cout<<" "<<i<<" "<<fixed<<setprecision(1)<<c[i];
		}
	}


}