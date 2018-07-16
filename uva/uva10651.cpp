#include<iostream>
#include<cstring>

#define MAXN (1<<12)

using namespace std;

int d[MAXN];

int dp(int i){
	if (d[i]>=0)
	{
		return d[i];
	}
	int count=0;
	for (int j = 0; j < 12; ++j)
	{
		if (i&(1<<j))
		{
			count++;
		}
	}
	d[i]=count;

	for (int j = 10; j > 0; --j)
	{
		if ((i&(1<<(j+1)))==0&&(i&(1<<j))&&(i&(1<<(j-1))))
		{
			d[i]=min(d[i],dp(i+(1<<(j-1))));
			break;
		}
	}

	for (int j = 11; j >1; --j)
	{
		if ((i&(1<<j))&&(i&(1<<(j-1)))&&(i&(1<<(j-2)))==0)
		{
			d[i]=min(d[i],dp(i-(1<<(j-2))-(1<<(j))));
			break;
		}
	}
	return d[i];
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		memset(d,-1,sizeof(d));
		int j=12;
		int sum=0;
		cin.get();
		while(j--){
			if (cin.get()=='o')
			{
				sum+=(1<<j);
			}
		}
		cout<<dp(sum)<<endl;
	}
}