#include<iostream>
using namespace std;

typedef long long ll;

//O(logn)计算x^n，循环形式
ll fast_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1){
			res=res*x;
		}
		x=x*x;
		n>>=1;
	}
	return res;
}

//O(logn)计算x^n，递归形式
ll fast_pow(ll x,ll n){
	if (n==0)
	{
		return 1;
	}
	ll res=1;
	if (n&1)
	{
		res=res*x;
	}
	res=res*fast_pow(x*x,n/2);
	return res;
}

int main(){
	cout<<fast_pow(2,14);
}