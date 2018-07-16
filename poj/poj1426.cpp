#include<iostream>
#include<queue>

using namespace std;

typedef long long ll;

int n;
queue<ll> q;


ll bfs(){
	q.push(1);
	while(!q.empty()){
		ll a=q.front();
		q.pop();

		if (a%n==0)
		{
			return a;
		}

		q.push(a*10);
		q.push(a*10+1);
	}
}

int main(){
	while(cin>>n&&n){
		while(!q.empty()){
			q.pop();
		}
		cout<<bfs()<<endl;
	}
}