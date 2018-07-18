#include<iostream>
#include<algorithm>
#include<queue>

#define MAXN 20010
using namespace std;

typedef long long ll;

priority_queue<int,vector<int> ,greater<int> > pq;
int n;


int main(){
	while(cin>>n){
		int t;
		for (int i = 0; i < n; ++i)
		{
			cin>>t;
			pq.push(t);
		}
		ll ans=0;
		if (n==1)
		{
			ans=pq.top();
		}
		while(pq.size()!=1){
			int a=pq.top();
			pq.pop();
			int b=pq.top();
			pq.pop();
			pq.push(a+b);
			ans=ans+a+b;
		}

		cout<<ans<<endl;
		pq.pop();
	}
}