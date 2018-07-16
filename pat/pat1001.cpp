#include<iostream>
#include<cmath>
#include<stack>
#include<iomanip>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b,c,d;
	stack<int> s;
	bool first=true;

	cin>>a>>b;

	c=a+b;

	if (abs(c)<1000)
	{
		cout<<c<<endl;
		return 0;
	}

	if(c<0){
		cout<<"-";
	}

	c=abs(c);

	while(c!=0){
		s.push(c%1000);
		c=c/1000;
	}
	while(!s.empty()){

		d=s.top();
		if (first)
		{
			cout<<d;
		}else{
			cout<<","<<setw(3)<<setfill('0')<<d;
		}
		s.pop();
		first=false;
	}
	cout<<endl;
	return 0;
}