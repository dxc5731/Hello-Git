#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool judge(ll u,ll v)
{
	for(int i=2;i<=v;i++)
		if(u%i==0 && v%i==0) return false;//判断是否存在公因数
	return true;
}

signed main()
{
	freopen("answer.txt","w",stdout);
	bool f=0;//f用于判断是否约掉了除0以外的数位，否则只约结尾0的分数太多了且没啥意思
	for(ll i=1e4;i<1e5;i++)//枚举寻找五位数的答案
	{
		for(ll j=1e4;j<i;j++)//枚举分子，仅枚举真分数
		{
			ll y1=1,y2=1,x1=i,x2=j;//y1,y2不断乘10，再用（x/y）mod 10得到每个数位
			while(x1/y1)//判断当前数位是否超过x1的最高位
			{
				y2=1;f=0;
				ll a=(x1/y1)%10;
				while(x2/y2 && a!=(x2/y2)%10) y2*=10;//寻找x2中最右的相同数位
				if(x2/y2)
				{
					x1=(x1/y1/10)*y1+x1%y1;
					x2=(x2/y2/10)*y2+x2%y2;
					//把匹配到的数位单独删去
					if(a)f=1;
				}
				else y1*=10;//如果没匹配到，继续判断i的下一位
			}
			if(f && x1!=i && x1 && x2 && j*x1==i*x2)//判断操作前后数值是否相等
				if(judge(x1,x2))//判断化简结果是否最简
					printf("%lld/%lld\n%lld/%lld\n\n",j,i,x2,x1);
		}
	}
	return 0;
}
