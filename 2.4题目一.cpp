#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int n,p1,p2,s,cnt=2;

signed main()
{
	SetConsoleOutputCP(CP_UTF8);
	//运行时发现输出中文出现乱码，网上查阅后发现需要改变输出流为UTF-8编码方式。
	cin>>n;srand(n);
	p1=rand()%6+1;p2=rand()%6+1;
	s=p1+p2;
	printf("第1轮骰子点数为：%d 和 %d，和数为 %d\n",p1,p2,p1+p2);
	if(s==7 || s==11)
		{printf("你赢了\n");return 0;}
	if(s==2 || s==3 || s==12)
		{printf("你输了\n");return 0;}
	system("pause");
	p1=rand()%6+1;p2=rand()%6+1;
	printf("第2轮骰子点数为：%d 和 %d，和数为 %d\n",p1,p2,p1+p2);
	while(s!=p1+p2)
	{
		s=p1+p2;
		if(s==7){printf("你输了\n");return 0;}
		system("pause");
		p1=rand()%6+1;p2=rand()%6+1;
		printf("第%d轮骰子点数为：%d 和 %d\n，和数为 %d\n",++cnt,p1,p2,p1+p2);
	}
	printf("你赢了\n");
	return 0;
}
