#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//
//int main()
//{
	//long age = 20;
	//char price = 66.6;
//	return 0;
//}
// 
// 
//int a = 10;
//int main()
//{
//	int b = 100;
//	printf("%d\n",a);
//	return 0;
//}
// 
// 
// 求2个数之和
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1, &num2);
//	int sum = num1 + num2;
//		printf("%d\n", sum);
//	return 0;
//}


//int a = 100;
//int main()
//{
//	{
//		printf("a=%d\n", a);
//	}
//
//	printf("a=%d\n", a);
//	return 0;
//}


//const定义只读常量，a的值不可修改，必须初始化
//int main()
//{
//	const int a = 100;
//	printf("a=%d\n", a);
//	return 0;
//}

//数组的[]里填常量，用const修饰变量为定值但是还是为变量
//int main()
//{
//	const int a = 100;
//	int arr[100] = { 0 };
//	return 0;
//}

//#define MAX 100
//#define STR "YUANSILE"
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	printf("%d\n", a);
//	printf("%s\n", STR);
//	return 0;
//}


//enum Color
//{
//	BLUD,
//	GREEN,
//	RED
//};
//枚举常量    enum
//int main()
//{
//	int num = 100;
//	enum Color c = RED;
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abc";
//		char arr2[] = { 'a','b','c','\0'};
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	return 0;
//}
//

//int main()
//{
//	printf("abc\n");
//	return 0;
//}


//int main()
//{
//	printf("abcde\0abcde");
//	return 0;
//}

//
//int main()
//{
//	printf("%s\n", "(are you ok\?\?)");
//	return 0;
//}



//int main()
//{
//	printf("%s\n","abcdef");
//	printf("\"");
//	return 0;
//}



//int main()
//{
//	printf("%s\n","abc\\0def");
//	return 0;
//}


//int main()
//{
//	printf("%s\n", "c:\\learn\\learn.c");
//	return 0;
//}



//int main()
//{
//	printf("abc\nd\tef");
//	return 0;
//}


//int main()
//{
//	printf("%c\n", '\130');
//	return 0;
//}



//int main()
//{
//
//	printf("%c\n", '\x63');
//	return 0;
//}


//int main()
//{
//	printf("%d\n", strlen("abc  tdef"));
//	
//	return 0;
//}



//int main()
//{
//	printf("%d\n",strlen("c:\test\682\test.c"));
//	return 0;
//}


//int main()
//{
//	int input = 0;
//	printf("加入比特\n");
//	printf("要好好学习吗(1/0)？");
//
//	scanf("%d", &input);
//	if (input == 0)
//	{
//
//		printf("好offer\n");
//	}
//	else
//	{
//		printf("卖红薯\n");
//	}
//	return 0;
//}


//int main()
//{
//	int blue = 0;
//	printf("加入比特\n");
//
//	while (blue < 20000)
//	{
//
//		printf("写代码:%d\n", blue);
//		blue++;
//	}
//	if (blue >= 20000)
//	{
//		printf("好offer\n");
//	}
//	else
//	{
//		printf("继续加油\n");
//	}
//	return 0;
//}





//int add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int n1 = 10;     /* 10或着其他都可以*/
//	int n2 = 10;
//	scanf("%d %d", &n1, &n2);
//
//	/*int sum = n1 + n2;*/
//	int sum = add(n1, n2);
//	printf("%d\n", sum);
//	return 0;
//}
  

//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };    /*数组下标从0开始*/
//	printf("%d\n",arr[4]);      /*arr可变不影响*/
//	return 0;
//}


//int main()
//{
//	/*int pdd[] = {1,2,3,4,5,6};*/
//	int ch[] = { 'a','b','c','d'};
//	int i = 0;
//	while ( i<6)
//	{
//		printf("%s\n",ch[i]);
//		i = i + 1;
//	}
//	return 0;
//}




//int c = 212;
//int a = 40;
//int main()           计算
//{
//	int b = (8 + 22) * a - 10 + c / 2;
//	printf("%d\n", b);
//	return 0;
//}



//int main()
//{
//
//	char arr[4] = { 'a','b','c' };
//	printf("%d\n",strlen(arr));           /* 不标明arr中的数字则为随机值*/
//	return 0;
//}                                     []中只可以常量，不可以是变量         c99标准








//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()                                  /*求2个数中的较大值*/
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int c = Max(a, b);
//	printf("%d\n", c);
//	return 0;
//}




//int main()                   /*已知一个函数f(x),当x<0时，y=1；当x=0时，y=0,当x>0时，y=-1*/
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d", &x);
//	if (x > 0)
//		y = -1;
//	else if (x == 0)
//		y = 0;
//	else
//		y = 1;
//	printf("%d\n", y);
//	return 0;
//}





//int main()
//{
//	float a = 7 / 2.0;         /*除号的两端都是整数是执行整数除法，如果两端只要有一个浮点数就可以执行浮点数除法，，要用float,,,输出改成f*/
//	int b = 7 % 2;       
//	/*%是取余数符号，取计算的余数部分*/       /*取余两侧必须要是整数*/
//	printf("%.2f\n", a);      /* 用0.来控制余数*/
//		printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	int a = 2;          /*初始化*/
//		a = 20;         /*赋值*/
//	return 0;
//  }




////c语言中
////0表示假
////非0表示真
//int main()
//{
//	int flog = 2;
//	if (!flog)
//	{                          !逻辑反操作，把真变成假
//		printf("hehe\n");
//	}
//	return 0;
//}



//后置++    后置--

//int main()
//{
//	int a = 10;
//	int b = a++;        
//	/*int b = a; a = a + 1;*/
//	/*后置++；     先使用，后++*/
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}



//前置++    前置--


//int main()
//{
//	int a = 10;
//	int b = ++a;        
//	//a = a + 1; b = a;
//	/*前置++；      前++，后使用*/
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}



//强制类型转换   (类型)

//int main()
//{
//	int b = (int)3.14;    /*括号括类型*/
//	//3.14 字面浮点数，编译器默认为理解double类型
//	printf("%d\n", b);
//	return 0;
//}



//int main()
//{
//	/*&&  逻辑-  并且
//	！！逻辑-  或者*/
//
//	
//	/*int a = 10;
//	int b = 20;
//	if (a && b)
//	{
//		printf("hehe");
//	}*/
//
//                       //==用于测试相等
//	return 0;
//}



//条件操作符
//exp1 ? exp2 : exp3 
//真      对     错
//假      错     对

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = (a > b ? a : b);
//	return 0;
//}



//逗号表达式就是逗号隔开的一串表达式
//逗号表达式的特点是:从左向右依次计算，整个表达式的结果是最后一个表达式的结果,前面计算结果影响后面结果

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	//c = 8         a = 50            5
//	int d = (c = a - 2, a = b + c, c - 3);
//	printf("%d\n", d);
//	return 0;
//}




//int main()
//{
//	int pdd[] = { 0,1,2,3,4,500 };
//	pdd[3] = 20;     /* []就是下标引用操作符，pdd和3就是[]操作数*/
//
//	printf("%d\n",pdd[3]);
//	return 0;
//}



//函数操作符()             不懂

//int pdd(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int sum = pdd(2, 3);          /*()就是函数的操作符，pdd，2，3都是()的操作数*/
//	return 0;
//}






//static
//1.修饰局部变量
//2.修饰全局变量
//3.修饰函数

//1,修饰局部变量
//void pdd()             /*void 表示不需要返回*/
//{
//	static int a = 1;
//	a++;
//		printf("%d\n", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		pdd();
//		i++;
//	}
//	return 0;
//}



//2,修饰全局变量             不会	
//int a = 100;
//               //extern 声明外部符号
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}


//3，修饰函数       不会，要再建一个文档
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(a, b);
//	printf("%d\n", c);
	//return 0;
//


//register
//int main()
//{
//	/*寄存器变量*/
//		register int num = 2;     /* 建议：2存放在寄存中*/
//	return 0;
//}






//#define的用法

//1，#define的定义标识符常量
//#define pdd 100
//
//int main()
//{
//	///*printf("%d\n", pdd);
//	//int a = pdd;
//	//printf("%d\n", a);*/
//	////int arr[pdd] = { 0 };
//	return 0;
//}

//2，#define 定义宏        替换
//宏是有参数

//#define add(x,y)    ((x)+(y))        /* 宏的书写方法  */     /*add是宏的名字      xy是宏的参数 参数是无类型     x+y是宏体*/
//
//int main()
//{
//	int a = 10;
//	int b = 20;	
//	int c = add(a, b);
//	printf("%d\n", c);
//	return 0;
//}





//指针变量

//int main()
//{
//	int a = 10;           /*向内存申请4个字节，存储10*/
//	/*&a;*/   /*取地址操作符*/
//	//用p打印取地址
//	printf("%p\n", &a);
//	int* b = &a;
//	//b就是指针变量         *a说明b是指针变量    int说明b指向的对象是int 类型的
//	*b = 20;      /*解引用操作符，意思是通过b中存放的地址，找到b所指向的对象，*b就是b指向的对象*/
//	printf("%d\n", a);
//	return 0; 
//}



//指针变量的大小    不清楚   23课最末尾





//结构体 struct

//学生
//struct stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//	char tele[12];
//};
//int main()
//{
//	struct stu a = { "zhangsan",20, "nan","13873549879" };
//	printf("%s %d %s %s\n", a.age, a.name, a.sex, a.tele);
//	return 0;
//}



//作业
//给定两个整数a和b计算a除以b的整数商和余数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	//输入
//	scanf("%d %d", &a, &b);
//	//计算
//	int c = a / b;
//	int d = a % b;
//	//输出
//	printf("%d %d\n", c, d);
//	return 0;
//}



//if的用法

//int main()
//{
	//int a = 10;
	//if (a = 3)    /*两个等号有判断的意思为假就打印不出来，反之*/   /* 一个等号有赋值的意思*/
	//	printf("hehe\n");


	//int age = 19;
	//if (age > 18)       /*满足括号内的条件及可正常打印*/
	//	printf("成年\n");
	//	return 0;


	//int age = 20;
	//if (age > 18)      /*if后面只可以接一个printf，要想跟多条则需用打括号括起*/
	//{
	//	printf("成年\n");
	//	printf("能饮酒\n");
	//}
	//else                               /*满足if条件打印if里的，不满足及打印else中的内容*/
	//	printf("未成年\n");

//多分支
//int age = 10;
//	scanf("%d", &age);
//	if (age < 18)            /*为假就等于零*/
//		printf("青少年\n");
//	else if (age >= 18 && age < 28)
//		printf("青年\n");
//	else if (age >= 28 && age < 40)
//		printf("中年\n");
//	else if (age > 40 && age < 60)
//		printf("壮年\n");
//	else
//		printf("老年\n");
//}



//int main()
//{
//	int age = 10;
//	if (age < 18)
//		printf("未成年\n");
//	else
//	{
//		printf("成年\n");           多分支也需要用代码块     用{}的为代码块
//		printf("打游戏\n");
//	}
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)         /* a不等于1所以数据不会进入b等于2所以输出无结果*/
//		if (b == 2)
//			printf("帅哥\n");
//		else                   /*else和他里的最近的if匹配*/
//			printf("帅歌\n");
//	return 0;
//}




//输出1到100之间的奇数
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{                                      /*方法一*/
//		if (i % 2 == 1)
//			printf("%d", i);
//		i = i++;
//	}
//	return 0;
//}


//int main()                             /*方法二*/
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		printf("%d", i);
//			i+=2;        /* i=i+2*/
//	}
//	return 0;
//}
 



//switch语句   用于多分支     可以嵌套
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//
//	switch (day)             /* ()内必须是整形*/
//	{
//	case 1:                   /* case 整形常量表达式;*/
//		printf("星期一\n");
//		break;                /*用break跳出case*/
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7: 
//		printf("星期天\n");
//		break;
//	}
//}



////int main()
////{
////	int shu = 0;
////	scanf("%d", &shu);
////
////	switch (shu)
////	{
////	case 1:
////	case 2:
////	case 3:
////	case 4:
////	case 5:
////		printf("weekday\n");
////		break;
////	case 6:
////	case 7:
////		printf("weekend\n");
////		break;
////	default:         /*防止输出错误*/        /*与case的标签不匹配就用default*/
////		printf("选择错误\n");
////		break;
////	}
//}





//while循环
//while中的break是用于永久的终止
//continue 跳过本次循环后面的代码，直接去判断部分，进行下一次循环的判断
//int main()
//{
//	int a = 1;
//	while (a <= 10)
//	{
//		if (5 == a)        /*当a=5是通过break跳出循环，输出1，2，3，4*/
//			/*break;*/
//			continue;    /* 直接跳过后面的代码，导致有死循环*/
//		printf("%d", a);
//		a++;
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	                //getchar获取字符
//	/*while (getchar())*/
//	int ch = getchar();
//	pritntf("%c\n", ch);
//	putchar(ch);
//	return 0;
//}
//crtl C,crt v,alt tab,ctrl z,crtl x,ctrl a, ctrl s,ctrl d,ctrl f,ctrl r,ctrl tab
//ctrl 左右键，



//while循环
//
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		printf("%d ", i);     //%d后接一个空格输出的数字是有间隔的
//		i++;
//	}
//	return 0;
//}


                        // continue在for循环和while循环中有所不同

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)       也可以int i = 1
//	{
//		if (i == 5)           
//			continue;       // 如果事break的话结果是1234
//		printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//for循环的判断部分省略意味这判断会恒成立

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{                                      //结果是3*3遍hehe
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}



//输出9*9乘法表
// 上三角乘法表
//
//int main()
//{
//	 int i = 0;
//	 int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <=i; j++)                      //记住j<=i
//		{
//			printf("%d*%d=%2d ", j, i, i * j);
//		}
//		printf(" \n");
//	}
//	return 0;
//}




// 下三角乘法表

	// int main()
 //{
	// int i = 0;
	// int j = 0;
	// for (i = 1; i < 10; i++)
	// {
	//	 for (j = i; j < 10; j++)                       //记住j=i
	//	 {
	//		 printf("%d*%d=%2d ", i, j, i * j);
	//	 }
	//	 printf("\n");
	// }
	// return 0;
 //}



//                        1，计算n的阶乘
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;                       ret不断累积
//	}
//	printf("%d\n", ret);
//	return 0;
//}


//                          2，计算1！+2！+3！+......+10!
//法一
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;             //重置ret防止出现累乘出错
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//法二
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



                    //3,在一个有序组中查找具体的某个数字n。(讲解二分查找)也叫折半查找


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);           //求元素个数
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//      int mid=left+(left+right)/2                  //防止超出范围
//		int mid = (left + right) / 2;                //mid一定要放在while里面      
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是:%d\n", mid);
//			break;
//		}
//		if (left > right)                    //当查找数据不在数组内是出现这种情况
//		{
//			printf("找不到\m");
//		}
//	}
//	return 0;
//}

                // 4，编写代码,演示多个字符从两端移动，向中间汇集

int main()
{            // 这次的left和right表示的是下标           数组存的数字没有\0，是字符串的结束标志
		char arr1[] = "welcome to bit!!!!";
		char arr2[] = "###################";
		int left = 0;
		int sz = sizeof(arr1) / sizeof(arr1[0]);
		int right = sz - 2;     //也可以用int right=strlen(arr2)-1;      strlen计算\0值钱的元素的个数
		while (left <= right)
		{
			arr2[left] = arr1[left];
			arr2[right] = arr1[right];
			printf("%s\n", arr2);
			Sleep(1000);       //使其慢慢呈现
			system("cls");      //一行代码渐变
			left++;
			right--;
		}
		printf("%s\n", arr2);            //保留渐变后的结果
	return 0;
}


//             5，编写代码实现，模拟用户登录情景，并且只能登录三次
//		（只允许输入三次密码，如果密码正确则提示登录成功，如果均输入错误，则退出程序）


//int main()
//{
//	int i = 0;
//	int password = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%d",&password);     //数字类型必须传取地址符号，字符串就不要用取地址符号
//		if (password == 123456))
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均输入错误，退出程序\n");
//	}
//	return 0;
//}


