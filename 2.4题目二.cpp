#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

struct stu{//此结构体用于存储学生数据
	string name,gender,hobby;
	int age,id;
	double score;
	bool del;//此变量用于标识此条学生数据是否已被删除。
}s[10001];

int tot,opt,tmp;
string x;
map<int,int>mp;
//map用于查重以及删除操作时的检索，考虑到实际中会有重名情况，因此以学号为关键字。

bool cmp1(stu u,stu v){return u.name<v.name;}
bool cmp2(stu u,stu v){return u.id<v.id;}
bool cmp3(stu u,stu v){return u.score<v.score;}
bool cmp4(stu u,stu v){return u.score>v.score;}

void dataprint()//输出操作
{
	printf("名字        年龄    性别    学号      爱好            绩点\n");
	for(int i=1;i<=tot;i++)
	{
		if(s[i].del)continue;
		printf("%-12s%-8d%-8s%-10d%-16s%.3f\n",s[i].name.c_str(),s[i].age,s[i].gender.c_str(),s[i].id,s[i].hobby.c_str(),s[i].score);
	}
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	//locale china("chs");
	//之前查阅资料后，试图通过使用以上代码支持中文字符串的处理，但发现未找到相应locale，
	//再次查阅资料发现windows系统可能需要安装ICU库之类的第三方库来支持中文的locale，目前还在研究如何安装并使用。
	ifstream fin;fin.open("StudentData.txt");
	//这里先前使用freopen打开文件后，之后即使使用freopen("CON","r",stdin)似乎也无法再从屏幕直接读取数据，
	//目前未找出原因，只得使用ifstream代替。
	getline(fin,x);//文件最上面一行是表头，需要先吞掉。
	while(1)
	{
		fin>>s[++tot].name;
		if(fin.eof()) break;
		fin>>s[tot].age>>s[tot].gender>>s[tot].id>>s[tot].hobby>>s[tot].score;
		mp[s[tot].id]=tot;
	}
	tot--;//最后一条为EOF输入
	printf("当前信息表如下：\n");
	dataprint();
	while(1)
	{
		printf("----------------------------\n");
		printf("添加数据请输入1\n删除数据请输入2\n排序操作请输入3\n保存数据请输入4\n结束程序请输入5\n");        
		cin>>opt;         
		if(opt==5) return 0;                  
		else if(opt==4)         
		{
			freopen("StudentData.txt","w",stdout);
			dataprint();
			fclose(stdout);
			freopen("CON","w",stdout);
			printf("保存完成\n");
		}               
		else if(opt==1)      
		{
			printf("请输入新同学信息，每项信息之间以空格隔开\n输入多名同学信息需换行，以单独的一行0作为终止命令\n");
			while(1)
			{
				cin>>s[++tot].name;
				if(s[tot].name[0]=='0') break;
				cin>>s[tot].age>>s[tot].gender>>s[tot].id>>s[tot].hobby>>s[tot].score;
				if(mp.find(s[tot].id)!=mp.end() && !s[mp[s[tot].id]].del)//map已有此关键字 且 该条数据未被删除
					s[tot].del=1,printf("学号与已有同学重复，请重新输入\n");
				else mp[s[tot].id]=tot,s[tot].del=0;
			}
			tot--;
			printf("操作完成，当前信息表如下：\n");
			dataprint();
		}
		else if(opt==2)
		{
			printf("请输入删除同学的学号，输入多名同学需空格隔开或换行，以单独的一个0作为终止命令\n");
			while(1)
			{
				cin>>tmp;
				if(!tmp) break; 
				if(mp.find(tmp)==mp.end()||s[mp[tmp]].del) printf("表中未找到此同学信息，请重新输入\n");
				else s[mp[tmp]].del=1;
			}
			printf("操作完成，当前信息表如下：\n");
			dataprint();
		}
		else
		{
			printf("名字字典序请输入1\n学号排序请输入2\n绩点升序请输入3\n绩点降序请输入4\n");
			cin>>opt;
			if(opt==1)sort(s+1,s+tot+1,cmp1);
			if(opt==2)sort(s+1,s+tot+1,cmp2);
			if(opt==3)sort(s+1,s+tot+1,cmp3);
			if(opt==4)sort(s+1,s+tot+1,cmp4);
			for(int i=1;i<=tot;i++) mp[s[i].id]=i;
			printf("操作完成，当前信息表如下：\n");
			dataprint();
		}
	}
}
