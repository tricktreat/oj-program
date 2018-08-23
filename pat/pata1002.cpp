#include<iostream>
#include<iomanip>
#include<stack>
#define MAXN 10005

float a[MAXN]={0};
float b[MAXN]={0};
float res[MAXN]={0};

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k1,k2,j,count,t;
	stack<int> s;
	bool first=true;

	cin>>k1;

	for (int i = 0; i < k1; ++i)
	{
		cin>>j;
		cin>>a[j];
	}

	cin>>k2;

	for (int i = 0; i < k2; ++i)
	{
		cin>>j;
		cin>>b[j];
	}

	for (int i = 0; i < MAXN; ++i)
	{
		res[i]=a[i]+b[i];
		if (res[i]!=0)
		{
			s.push(i);
		}
	}

	cout<<s.size();
	if (s.empty())
	{
		return 0;
	}
	cout<<" ";
	cout.setf(ios::fixed);
	while(!s.empty()){
		if (!first)
		{
			cout<<" ";
		}else{
			first=false;
		}
		t=s.top();

		cout<<t<<" "<<setprecision(1)<<res[t];
		s.pop();
	}


}