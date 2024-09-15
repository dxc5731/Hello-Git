#include<bits/stdc++.h>

using namespace std;

int n;
long long ans;

signed main()
{
	cin>>n;
	n*=100;
	for(int i=0;i*5<=n;i++)
		for(int j=0;i*5+j*2<=n;j++)
			ans++;//因为每种i,j取值总能用1分硬币补足，因此均有一种方法。
	printf("%lld\n",ans);
	//令N=100n,则此解法时间复杂度为O(N^2)，空间复杂度为O(1)。
}
