#include<iostream>
#include<string>
#include<stack>

using namespace std;

string words[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	cin>>line;
	int sum=0;
	stack<int> digits;
	for (int i = 0; i < line.length(); ++i)
	{
		sum+=line[i]-'0';
	}

	if (sum==0)//特殊情况
	{
		digits.push(0);
	}
	while(sum!=0){
		digits.push(sum%10);
		sum=sum/10;
	}
	while(!digits.empty()){
		cout<<words[digits.top()];
		digits.pop();
		if (!digits.empty())
		{
			cout<<" ";
		}
	}
}