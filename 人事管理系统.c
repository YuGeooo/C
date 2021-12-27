#include<stdio.h>
#include<string.h>
#define N 50

struct worker
{
	char id[20];         //工号
	char name[20];       //姓名
	char sex[10];        //性别
	char  age[5];       //年龄
	char edu[20];        //学历
	char  duty[10];      //职务
	char political[20];  //政治面貌
	char tittle[10];     //职称
	char history[20];    //来院时间
	char ago[5];        //任职时间(年)
	char range[20];      //人员类别
}worker[N];

void  save(int n)     //保存函数，保存n个记录
{
	FILE *fp;
	int i;
	if ((fp = fopen("worker.txt", "wb")) == NULL)        //以只写方式为输出打开一个二进制文件
	{
		printf("\n无法打开文件\n");
	}
	for (i = 0;i < n;i++)
		if (fwrite(&worker[i], sizeof(struct worker), 1, fp) != 1)
			printf("写入错误\n");
	fclose(fp);
}

add(int n)
{
	FILE *fp;
	int i;
	if ((fp = fopen("worker.txt", "ab")) == NULL)        //以追加方式为输出打开一个二进制文件
	{
		printf("\n无法打开文件\n");
	}
	for (i = 0;i < n;i++)
		if (fwrite(&worker[i], sizeof(struct worker), 1, fp) != 1)
			printf("写入错误\n");
	fclose(fp);
}

int load()    //加载函数
{
	FILE *fp;
	int i;
	if ((fp = fopen("worker.txt", "rb")) == NULL)
	{
		printf("\n无法打开文件\n");
		return NULL;
	}
	for (i = 0;!feof(fp);i++)
		fread(&worker[i], sizeof(struct worker), 1, fp);
	fclose(fp);
	return(i - 1);
}

void no_input(int i, int n)   //工号输入函数，i表示第i个职工的信息，n表示比较到第n个职工
{
	int j, k, w1;
	do
	{
		w1 = 0;
		printf("工号：");
		scanf("%s", worker[i].id);
		for (j = 0;worker[i].id[j] != '\0';j++)
			if (worker[i].id[j]<'0' || worker[i].id[j]>'9')     //判断工号是否为数字
			{
				puts("请重新输入！\n");
				w1 = 1;break;
			}
		if (w1 != 1)
			for (k = 0;k < n;k++)               //比较到第N个职工
				if (k != i && strcmp(worker[k].id, worker[i].id) == 0)  //判断职工号是否有雷同
				{
					puts("请重新输入！\n");
					w1 = 1;break;
				}
	} while (w1 == 1);
}

void input(int i)       //输入一个记录的函数
{
	no_input(i, i);
	printf("姓名:");scanf("%s", worker[i].name);
	printf("性别:");scanf(" %s", worker[i].sex);
	printf("年龄:");scanf("%s", worker[i].age);
	printf("职务:");scanf("%s", worker[i].duty);
	printf("学历:");scanf("%s", worker[i].edu);
	printf("政治面貌:");scanf("%s", worker[i].political);
	printf("职称:");scanf("%s", worker[i].tittle);
	printf("来院时间:");scanf("%s", worker[i].history);
	printf("任职时间(年):");scanf("%s", worker[i].ago);
	printf("人员类别:");scanf("%s", worker[i].range);
}

void printf_one(int i)   //显示一个记录的函数
{
	printf("%10s %8s %5s %5s %8s %8s %10s %10s %15s %6s %15s\n",
		worker[i].id, worker[i].name, worker[i].sex, worker[i].age,worker[i].duty, worker[i].edu,
		worker[i].political, worker[i].tittle, worker[i].history, worker[i].ago, worker[i].range);
}

void printf_back()             //一个任务结束后选择浏览还是返回
{
	int k, w;
	printf("\n\n\t输入成功^-^.\n\n");
	printf("请选择要执行的操作:\n\n\t1).浏览全部\t2).返回: [ ]\b\b");
	scanf("%d", &w);
	if (w == 1)browse();
	else menu();
}

modify_data(int i, int n)       //修改函数
{
	int c, w1;
	do
	{
		puts("\n请选择=>\n\n 1).工号 2).姓名 3).性别 4).年龄 5).职务 6).学历 7).政治面貌 8).职称 9).来院时间 10)任职时间. 11).人员类别  0).取消");
		printf("选择:[ ]\b\b");
		scanf("%d", &c);
		if (c > 11 || c < 0)
		{
			puts("\n选择有误，请重选");
			getchar();
		}
	} while (c > 11 || c < 0);
	do
	{
		switch (c)
		{
		case 1:no_input(i, n);break;
		case 2:printf("姓名:");scanf("%s", worker[i].name);break;
		case 3:printf("性别:");scanf("%s", worker[i].sex);break;
		case 4:printf("年龄:");scanf("%s", worker[i].age);break;
		case 5:printf("职务:");scanf("%s", worker[i].duty);break;
		case 6:printf("学历:");scanf("%s", worker[i].edu);break;
		case 7:printf("政治面貌:");scanf("%s", worker[i].political);break;
		case 8:printf("职称:");scanf("%s", worker[i].tittle);break;
		case 9:printf("来院时间:");scanf("%s", worker[i].history);break;
		case 10:printf("任职时间");scanf("%s", worker[i].ago);break;
		case 11:printf("人员类别");scanf("%s", worker[i].range);break;
		case 0:menu();break;
		}
		puts("\n修改完成:\n");
		printf_face();
		printf_one(i);
		printf("\n确定?\n\n\t1).是 2).否，重新修改 3).不保存退出 [ ]\b\b");
		scanf("%d", &w1);
		if (w1 == 1)save(n);
	} while (w1 == 2);
	return(w1);
}

printf_face()         //显示数据结构项目
{
	printf("\n      工号    姓名    性别  年龄    职务     学历     政治面貌     职称     来院时间    任职时间(年)   人员类别\n\n");
}

void enter()           //输入模块
{
	int i, n;
	printf("新增多少个职工信息(0-%d):", N - 1);
	scanf("%d", &n);
	printf("\n 请输入职工信息\n\n");
	for (i = 0;i < n;i++)
		input(i);
	if (i != 0)
		add(n);
	printf_back();
}

browse()          //浏览模块
{
	int i, j, n;
	n = load();
	printf_face();
	for (i = 0;i < n;i++)
	{
		if ((i != 0) && (i % 10 == 0))
		{
			printf("\n\n按任意键显示下一页...");
			getch();
			puts("\n\n");
		}
		printf_one(i);
	}
	printf("\n\t这里有 %d 条记录.\n", n);
	printf("\n是否进行排序？1).是 2).否  [ ]\b\b");
	scanf("%d", &j);
	if (j == 1)rank();
	putchar(10);
	system("pause");
	menu();
}

modify()            //修改模块
{
	struct worker s;
	FILE *fp;
	int i, n, k, w0 = 1, w1, w2 = 0;
	n = load();
	do
	{
		k = -1;
		printf_face();
		for (i = 0;i < n;i++)
		{
			if ((i != 0) && (i % 10 == 0))        //目的是分屏显示
			{
				printf("\n\n记住要修改的工号.按任意键显示下一页");
				getch();
				puts("\n\n");
			}
			printf_one(i);              //调用显示一个记录的函数
		}
		do
		{
			printf("\n\n输入要修改的职工工号:");
			scanf("%s", s.id);     //输入要修改的ID
			for (i = 0;i < n;i++)       //查找要修改的数据
				if (strcmp(s.id, worker[i].id) == 0)
				{
					k = i;              //找到要修改的记录
					s = worker[i];      //把worker[i]备份，以便恢复
				}
			if (k == -1)
				printf("\n\n未找到 请重输");
		} while (k == -1);         //当k=-1表示没有找到
		printf_face();        //调用显示数据结构项目的函数
		printf_one(k);        //调用显示一个记录的函数
		w1 = modify_data(k, n);  //修改记录并返回保存控制值w1，w1=1表示用户已确认修改
		if (w1 == 1)
		{
			printf("\n修改成功^_^.\n\n是否修改另一个？\n\n\t1).是 2).否，保存退出\t[ ]\b\b");
			scanf("%d", &w0);
			w2 = 1;                 //用来控制保存，使w2=1是标记已有过修改
		}
		else
		{
			w0 = 0;
			if (w2 == 1)
				worker[k] = s;
		}
		if (w0 != 1 && w2 == 1)
			save(n);
	} while (w0 == 1);
	menu();
}

search()       //查询模块
{
	int c, w1;
	do
	{
		printf("\n请选择查找依据=>\n\n1).工号 2}.姓名 3).取消并返回:  [ ]\b\b");
		scanf("%d", &c);
		if (c > 3 || c < 1)
		{
			puts("\n选择有误！请重选");
			getchar();
		}
	} while (c > 3 || c < 1);
	{switch (c)
	{
	case 1:search1();break;
	case 2:search2();break;
	case 3:menu();break;
	}
	}
}

search1()          //按工号查询模块
{
	int i, n, k, w1 = 1, w2, w3;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n\n输入要查询的工号:");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].id) == 0)
				{
					k = i;
					printf_one(k);break;
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n继续查找?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w3 = 0;
		if (k != -1)
		{
			printf("\n\n请选择下一步执行的操作:\n\t1).查找另一个  2).修改  3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:search1();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();break;}
			}
		}
	} while (w2 == 1);
	menu();
}

search2()     //按姓名查询模块
{
	int i, n, k, w1 = 1, w2, w3, w4;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n\n请输入你要查询的姓名：\n");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].name) == 0)
				{
					k = i;
					printf_one(k);
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n继续查找?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w4 = 0;w3 = 0;
		if (k != -1)
		{
			printf("\n\n请选择下一步执行的操作:\n\t1).查找另一个  2).修改 3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:search2();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();
				break;
			}
			}

		}
	} while (w2 == 1);
	menu();
}

statistics()      //统计模块
{
	int c, w1;
	do
	{
		printf("\n请选择统计依据=>\n\n1).政治面貌 2}.姓别 3).学历 4).职称 5).人员类别 6).取消并返回:  [ ]\b\b");
		scanf("%d", &c);
		if (c > 6 || c < 1)
		{
			puts("\n选择有误！请重选");
			getchar();
		}
	} while (c > 6 || c < 1);
	{switch (c)
	{
	case 1:statistics1();break;
	case 2:statistics2();break;
	case 3:statistics3();break;
	case 4:statistics4();break;
	case 5:statistics5();break;
	case 6:menu();break;
	}
	}
}

statistics1()      //按政治面貌统计
{
	int i, n, k, w1 = 1, w2, w3, num = 0;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n输入要统计的政治面貌:");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].political) == 0)
				{
					k = i;
					printf_one(k);
					num++;
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n重新统计?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w3 = 0;
		if (k != -1)
		{
			printf("\n检索到%d条信息", num);
			printf("\n\n请选择下一步执行的操作:\n\t1).统计另一项  2).修改  3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:statistics();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();break;}
			}
		}
	} while (w2 == 1);
	menu();
}

statistics2()//按性别统计
{
	int i, n, k, w1 = 1, w2, w3, num = 0;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n请输入选择的性别:");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].sex) == 0)
				{
					k = i;
					printf_one(k);
					num++;
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n重新统计?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w3 = 0;
		if (k != -1)
		{
			printf("\n检索到%d条信息", num);
			printf("\n\n请选择下一步执行的操作:\n\t1).统计另一项  2).修改  3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:statistics();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();break;}
			}
		}
	} while (w2 == 1);
	menu();
}

statistics3()//按学历统计
{
	int i, n, k, w1 = 1, w2, w3, num = 0;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n请输入学历:");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].edu) == 0)
				{
					k = i;
					printf_one(k);
					num++;
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n重新统计?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w3 = 0;
		if (k != -1)
		{
			printf("\n检索到%d条信息", num);
			printf("\n\n请选择下一步执行的操作:\n\t1).统计另一项  2).修改  3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:statistics();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();break;}
			}
		}
	} while (w2 == 1);
	menu();
}

statistics4()  //按职称统计
{
	int i, n, k, w1 = 1, w2, w3, num = 0;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n请输入职称:");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].tittle) == 0)
				{
					k = i;
					printf_one(k);
					num++;
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n重新统计?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w3 = 0;
		if (k != -1)
		{
			printf("\n检索到%d条信息", num);
			printf("\n\n请选择下一步执行的操作:\n\t1).统计另一项  2).修改  3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:statistics();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();break;}
			}
		}
	} while (w2 == 1);
	menu();
}

statistics5()  //按人员类别进行统计
{
	int i, n, k, w1 = 1, w2, w3, num = 0;
	char s[20];
	n = load();
	do
	{
		do
		{
			k = -1;
			printf("\n请输入人员类别:");
			scanf("%s", s);
			printf_face();
			for (i = 0;i < n;i++)
				if (strcmp(s, worker[i].range) == 0)
				{
					k = i;
					printf_one(k);
					num++;
				}
			if (k == -1)
			{
				printf("\n\n无符合项！");
				printf("\n\n重新统计?\n\t1).是  2).否，返回  [ ]\b\b");
				scanf("%d", &w1);
				if (w1 == 2) menu();
			}
		} while (k == -1 && w1 == 1);
		w3 = 0;
		if (k != -1)
		{
			printf("\n检索到%d条信息", num);
			printf("\n\n请选择下一步执行的操作:\n\t1).统计另一项  2).修改  3).返回菜单  [ ]\b\b");
			scanf("%d", &w2);
			switch (w2)
			{
			case 1:statistics();break;
			case 2:w3 = modify_data(k, n);break;
			case 3: {menu();break;}
			}
		}
	} while (w2 == 1);
	menu();
}

rank()
{
	int c;
	do
	{
		printf("\n请输入排序依据: 1).工号 2).来院时间 3).取消并返回  [ ]\b\b");
		scanf("%d", &c);
		if (c > 3 || c < 1)
		{
			puts("\n选择有误！请重选");
			getchar();
		}
	} while (c > 3 || c < 1);
	switch(c)
	{
	case 1:rank1();break;
	case 2:rank2();break;
	case 3:menu();break;
	}
}

rank1()//按工号进行排序
{
	struct worker t;
	int n=1, c, m=0, v, k = 1, i;
	v = load();
	do
	{
		printf("\n1).递增 2).递减  [ ]\b\b");
		scanf("%d", &c);
		if (c > 2 || c < 1)
		{
			puts("\n选择有误！请重选");
			getchar();
		}
	} while (c > 2 || c < 1);
	if (c == 1)
	{
		for (m = 0;m < v - 1;m++, k++)
		{
			for (n = k;n < v;n++)
			{
				if (strcmp(worker[m].id, worker[n].id) > 0)
				{
					t = worker[m];
					worker[m] = worker[n];
					worker[n] = t;
				}
			}
		}
	}
	else
	{
		for (m = 0;m < v - 1;m++, k++)
		{
			for (n = k;n < v;n++)
			{
				if (strcmp(worker[m].id, worker[n].id) < 0)
				{
					t = worker[m];
					worker[m] = worker[n];
					worker[n] = t;
				}
			}
		}
	}
	printf_face();
	for (i = 0;i < v;i++)
		printf_one(i);
	save(v);
}

rank2()//按来院时间进行排序
{
	struct worker t;
	int n = 1, c, m = 0, v, k = 1, i;
	v = load();
	do
	{
		printf("\n1).顺序 2).倒序 [ ]\b\b");
		scanf("%d", &c);

		if (c > 2 || c < 1)
		{
			puts("\n选择有误！请重选");
			getchar();
		}
	} while (c > 2 || c < 1);
	if (c == 1)
	{
		for (m = 0;m < v - 1;m++, k++)
		{
			for (n = k;n < v;n++)
			{
				if (strcmp(worker[m].history, worker[n].history) > 0)
				{
					t = worker[m];
					worker[m] = worker[n];
					worker[n] = t;
				}
			}
		}
	}
	else 
	{
		for (m = 0;m < v - 1;m++, k++)
		{
			for (n = k;n < v;n++)
			{
				if (strcmp(worker[m].history, worker[n].history) < 0)
				{
					t = worker[m];
					worker[m] = worker[n];
					worker[n] = t;
				}
			}
		}
	}
	printf_face();
	for (i = 0;i < v;i++)
		printf_one(i);
	save(v);
}

delete_file()
{
	int i, n, k, w1 = 1, w2;
	char s[20];
	n = load();
	printf_face();
	for (i = 0;i < n;i++)
		printf_one(i);
	do
	{
		k = -1;
		printf("\n\n输入要删除的工号:");
		scanf("%s", s);
		printf_face();
		for (i = 0;i < n;i++)
			if (strcmp(s, worker[i].id) == 0)
			{
				k = i;
				printf_one(k);break;
			}
		if (k == -1)
		{
			printf("\n\n无符合项！");
			printf("\n\n重新查找?\n\t1).是  2).否，返回  [ ]\b\b");
			scanf("%d", &w1);
			if (w1 == 2) menu();
		}
	} while (k == -1 && w1 == 1);
	if (k != -1)
	{
		printf("\n\n确认删除?\n\t1).是  2).否  [ ]\b\b");
		scanf("%d", &w2);
		switch (w2)
		{
		case 1:delete__(k, n);break;
		case 2:menu();break;
		}
	}
}

delete__(int k, int n)
{
	int i, w;
	for (i = k;i < n - 1;i++)
	{
		worker[i] = worker[i + 1];
	}
	save(n - 1);
	printf("删除成功！\n");
	system("pause");
	menu();
}

menu()
{
	int n, w1;
	do
	{
		system("cls");
		puts("\t\t*******************菜单*******************\n");
		puts("\t\t\t\t1.浏览职工信息");
		puts("\t\t\t\t2.查询职工信息");
		puts("\t\t\t\t3.新增职工信息");
		puts("\t\t\t\t4.修改职工信息");
		puts("\t\t\t\t5.删除职工信息");
		puts("\t\t\t\t6.统计职工信息");
		puts("\t\t\t\t7.退出");
		puts("\n\t\t*****************************************\n\n");
		printf("请选择(1~7): [ ]\b\b");
		scanf("%d", &n);
		if (n < 1 || n>7)         //对选择的数字作判断
		{
			w1 = 1;getchar();
		}
		else w1 = 0;
	} while (w1 == 1);
	switch (n)
	{
	case 1:browse();break;      //浏览
	case 2:search();break;      //查询
	case 3:enter();break;       //新增
	case 4:modify();break;      //修改
	case 5:delete_file();break; //删除
	case 6:statistics();break;  //统计
	case 7:exit(0);             //退出
	}
}

main()
{
	menu();
}
