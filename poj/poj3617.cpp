#include<iostream>
#include<cstring>

#define MAXN 2010

using namespace std;

char str1[MAXN];
char str2[MAXN];
char str3[MAXN];

int main(){
	int n;
	while(cin>>n){
		char *s1=str1,*s2=str2;
		for (int i = 0; i < n; ++i)
		{
			cin>>str1[i];
			str2[n-1-i]=str1[i];
		}
		int i=0;
		while(i<n){
			if (strcmp(s1,s2)<0)
			{
				str3[i++]=s1[0];
				s1++;
			}else{
				str3[i++]=s2[0];
				s2++;
			}
		}
		cout<<str3<<endl;
	}
}

