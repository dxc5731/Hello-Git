#include<bits/stdc++.h>
#define N 10005

using namespace std;

int a[N],b[N],ans[N*2];
int n,x,y,m1,m2,m3;
string s;
//a,b,ans数组分别存储两个乘数和答案，m1,m2,m3分别记录a,b,ans的最高位

void up(int p)//进位
{
	m3=max(m3,p);
	while(ans[p]>9)
	{
		ans[p+1]+=ans[p]/10;
		ans[p]%=10;p++;
		m3=max(m3,p);//更新最高位
	}
}

signed main()
{
	cin>>n>>s;m1=s.length()-1;
	for(int i=m1;i>=0;i--) a[i]=s[i]-'0';
	cin>>s;m2=s.length()-1;
	for(int i=m2;i>=0;i--) b[i]=s[i]-'0';
	//以字符串形式读入两个数再转化为int数组
	for(int i=0;i<=m1;i++)
		for(int j=0;j<=m2;j++)
			ans[i+j]+=a[i]*b[j],up(i+j);//两个数的i,j位相乘时结果的最低位应在i+j处
	for(int i=m3;i>=0;i--)
		printf("%d",ans[i]);
	printf("\n");return 0;
}
