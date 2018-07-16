#include<iostream>
#include<cstring>
#include<algorithm>

#define MAXN 30

using namespace std;

struct Box
{
	int x,y,z;
	bool operator <(const Box &b){
		return (x<b.x&&y<b.y)||(x<b.y&&y<b.x);
	}
};

Box boxes[MAXN*3];
int d[MAXN*3];
int n;

int dp(int t){
	if (d[t]>0)
	{
		return d[t];
	}
	d[t]=boxes[t].z;
	for (int i = 0; i < n*3; ++i)
	{
		if (boxes[t]<boxes[i])
		{
			d[t]=max(d[t],dp(i)+boxes[t].z);
		}
	}
	return d[t];
}

int main(){
	int a,b,c,t=0;
	while(cin>>n&&n){
		memset(d,0,sizeof(d));
		for (int i = 0; i < n; ++i)
		{
			cin>>a>>b>>c;
			int j=0;
			boxes[i*3+j].x=a;
			boxes[i*3+j].y=b;
			boxes[i*3+j].z=c;
			j++;
			boxes[i*3+j].x=a;
			boxes[i*3+j].y=c;
			boxes[i*3+j].z=b;
			j++;
			boxes[i*3+j].x=b;
			boxes[i*3+j].y=c;
			boxes[i*3+j].z=a;
		}
		int maxv=0;
		for (int i = 0; i < 3*n; ++i)
		{
			maxv=max(maxv,dp(i));
		}
		cout<<"Case "<<++t<<": maximum height = "<<maxv<<endl;
	}
}