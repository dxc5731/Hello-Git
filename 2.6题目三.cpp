#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int ans[100005],tot,n;
//ans数组记录最终结果，tot用于记录ans的最高数位的位置。

void up()//进位操作
{
	for(int i=0;i<=tot;i++)
		if(ans[i]>9)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
			tot=max(tot,i+1);//更新最高位
		}
}

void cal()//乘2操作
{
	for(int i=0;i<=tot;i++)
		ans[i]<<=1;
}

signed main()
{
	cin>>n>>ans[0];
	up();//此时整个数都挤在个位上，需要进位。
	n--;//第n号猴才刚醒，没来得及拿桃。
	for(int i=1;i<=n;i++)
		cal(),ans[0]++,up();//每个猴拿之前的桃数为当前的2倍加1，这里需要高精度。
	for(int i=tot;i>=0;i--)
		printf("%d",ans[i]);
	printf("\n");return 0;
}
