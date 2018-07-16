#include<iostream>
#include<cstdio>
#include<cstring>

#define MAXA 10010
#define MAXB 110

#define maxn 100

using namespace std;

struct bign
{
    int len,s[maxn];
    bign(){memset(s,0,sizeof(s));len=1;}
    bign operator = (const char *num)
    {
        len=strlen(num);
        for(int i=0;i<len;i++)
        s[i]=num[len-i-1]-'0';
        return *this;
    }
    bign operator = (int num)
    {
        char s[maxn];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }
    bign(int num)
    {
        *this =num;
    }
    bign(const char *num)
    {
        *this=num;
    }
    string str() const
    {
        string res="";
        for(int i=0;i<len;i++)
        res=(char)(s[i]+'0')+res;
        if(res=="")
        res="0";
        return res;
    }
    bign operator + (const bign& b) const
    {
        bign c;c.len=0;
        for(int i=0,g=0;g||i<max(len,b.len);i++)
        {
            int x=g;
            if(i<len) x+=s[i];
            if(i<b.len) x+= b.s[i];
            c.s[c.len++]=x%10;
            g=x/10;
        }
        return c;
    }
    bool operator < (const bign& b) const
    {
        if(len!=b.len)
        return len<b.len;
        for(int i=len-1;i>=0;i--)
        if(s[i]!=b.s[i])
        return s[i]<b.s[i];
        return false;
    }
};

istream& operator >>(istream &in,bign& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator <<(ostream &out,const bign &x)
{
    out << x.str();
    return out;
}


char a[MAXA];
char b[MAXB];
int na,nb;
bign dp[MAXA][MAXB];

void solve(){
	for (int i = 0; i < na; ++i)
	{
		for (int j = 0; j < nb; ++j)
		{
			if (j>i)
			{
				dp[i][j]=0;
			}else{
				dp[i][j]=1;
			}
		}
	}
	for (int i = 1; i <= na; ++i)
	{
		for (int j = 1; j <= nb; ++j)
		{
			if (a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//母串考虑当前的dii个字符，那么比上一阶段（前i-1个字符）多出来的情况为：i-1个子串在i-1个母串中满足条件的出现
			}else{
				dp[i][j]=dp[i-1][j];//即为子串在前i-1母串中满足条件的出现
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>a>>b;
		na=strlen(a);
		nb=strlen(b);

		solve();
		cout<<dp[na][nb]<<endl;
	}
}