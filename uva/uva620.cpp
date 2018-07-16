#include<iostream>

using namespace std;

int flag;
int first;

int judge(const char *str,int l){
	if (l==1&&str[0]=='A')
	{
		if (first)
		{
			flag=1;
			first=0;
		}
		return 1;
	}
	if (str[l-2]=='A'&&str[l-1]=='B')
	{	
		if (first)
		{
			flag=2;
			first=0;
		}
		return judge(str,l-2);
	}
	if (str[0]=='B'&&str[l-1]=='A')
	{
		if (first)
		{
			flag=3;
			first=0;
		}
		return judge(str+1,l-2);
	}
	return 0;
}

int main(){
	int n;
	string s;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		flag=0;
		first=1;
		cin>>s;
		int l=s.length();
		if (judge(s.c_str(),l))
		{
			if (flag==1)
			{
				cout<<"SIMPLE"<<endl;
			}else if(flag==2){
				cout<<"FULLY-GROWN"<<endl;
			}else if(flag==3){
				cout<<"MUTAGENIC"<<endl;
			}
		}else{
			cout<<"MUTANT"<<endl;
		}
	}
}