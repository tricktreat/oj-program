#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

ll cacvalue(char *num,ll radix){//num为一位时，无论基数合不合法，输出的都是正确的
	ll sum=0;
	int n=strlen(num);
	for (int i = 0; i < n; ++i)
	{
		sum=sum*radix+((num[i]-'a')<0?num[i]-'0':num[i]-'a'+10);
	}
	return sum;
}

int main(){
	char num1[11],num2[11],num[11];
	int flag;
	ll a,b,radix;

	cin>>num1>>num2>>flag>>radix;

	if (flag==1)
	{
		a=cacvalue(num1,radix);
		strcpy(num,num2);
	}else{
		a=cacvalue(num2,radix);
		strcpy(num,num1);
	}

	if (strlen(num)==1)//特殊的，一位数字串
	{
		if (((num[0]-'a')<0?num[0]-'0':num[0]-'a'+10)==a)
		{
			cout<<((num[0]-'a')<0?num[0]-'0':num[0]-'a'+10)+1;
			return 0;
		}
		
		cout<<"Impossible";
		return 0;
	}

	int max=0;
	for (int i = 0; i < strlen(num); ++i)
	{
		if (max<((num[0]-'a')<0?num[0]-'0':num[0]-'a'+10))
		{
			max=((num[0]-'a')<0?num[0]-'0':num[0]-'a'+10);
		}
	}

	ll mid,low=max+1,high=a+1;//下界和上界
	ll minres=high;
	while(high>low){
		mid=(high+low)/2;
		b=cacvalue(num,mid);
		if (b>a||b<0)//处理long long溢出 
		{
			high=mid;
		}
		else if (a>b)
		{
			low=mid+1;
		}
		else
		{
			high=mid;
			if (mid<minres)
			{
				minres=mid;
			}
		}
	}
	
	if ((a+1)==minres)
	{
		cout<<"Impossible";
	}else{
		cout<<minres;
	}
}