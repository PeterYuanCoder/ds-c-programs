#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//分支语句  if . switch
//循环语句 while ，for , do while
//转向语句 break语句 ， goto语句 ，  continue语句

//一，分支语句
//if语法
// 
//单分支
//if(表达式)
//	语句1;
//else
//	语句2;
// 
//多分支
//if (表达式1)
//	语句1;
//else if (表达式2)
//	语句2;
//else
//	语句3;


//                               单分支
//int main()
//{
//	int age = 10;
//	if (age >= 18)
//	{                                //  if 后面默认跟一条语句，要想跟多语句要用大括号括起
//		printf("未成年\n");     
//		printf("不能饮酒\n");
//	}
//	else
//		printf("成年\n");
//
//	return 0;
//}
// 
// 
// 
// 
//                              多分支              &&  表示并且的意思       0表示假，非0表示真
//int main()
//{
//	int age = 10;
//	if (age < 18)
//		printf("青少年\n");
//	else if (age >= 18 && age < 28)
//		printf("青年\n");
//	else if ("age>=28&&age<40")
//		printf("中年\n");
//	else if (age > 40 && age < 60)
//		printf("壮年\n");
//	else
//		printf("老年\n");
//	return 0;
//}


//             注意    else与最近的if是一个语句，所以结果不打印
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//	else                               
//			printf("haha\n");
//	return 0;
//}
//
////优化
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	}
//	return 0;
//}


//               练习1，  判断一个数是否是奇数
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	if (n % 2 == 1)
//		printf("奇数\n");
//	else
//		printf("偶数\n");
//	return 0;
//}


//               练习2， 输出1-100之间的奇数
//     1,for 循环
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);    //d后面加空格输出结果就有空格，\n每一个数字占一行   加 ，就是用逗号隔开
//	}
//	return 0;
//}

//      2，while 循环
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);
//	i++;
//	}
//		
//	return 0;
//}



 

//switch语句
//
//switch (整形表达式)       必须是整形   字符也是整形
//{
//	语句项:
//}

//语句项
//是一些case语句:
//如下
//case 整形常量表达式:           case确定入口
//	语句；

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch(day)
//	{
//	case 1:
//		printf("星期1\n");
//		break;
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//
//	case 5:
//		printf("星期5\n");
//		break;
//
//	case 6:
//		printf("星期6\n");
//		break;
//
//	case 7:
//		printf("星期7\n");
//		break;
//	default:                        //当case不能匹配的就到这里
//		printf("选择错误\n");
//		break;
//	}
//	return 0;
//}







//二，循环语句
//while循环



//break  跳出后面所有的循环
//continue 跳出当前循环
/*
int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (i == 5)
			break;
		printf("%d ", i);
		i++;
	}
}
*/


/*
int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
		i++;
	}
}
*/

/*
int main()
{
	int ch = getchar();   //getchar获取一个字符
	printf("%c\n", ch);
	putchar(ch);
	return 0;
}
*/


/*
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)     //    !=  不等于
	{
		putchar(ch);
	}
	return 0;
}
*/


//   作业一,将ASCLL码对应字符并输出他们

//int main()
//{
//	int arr[] = { 73,32,99,96,70,111,100 };
//	int i = 0;
//	//sizeof(arr)   计算的是数组的总大小，单位是字节
//	//sizeof(arr[0])   计算的是数组元素的大小
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (i < sz)
//	{
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}







//for 循环
//for (初始化; 判断部分; 调整部分);
//不要再for循环体内修改循环变量，防止for循环失去控制
//建议for语句的循环控制变量的取值采用“前闭后开区间”写法




/*
int main()
{
	int i = 0;
	for (i =1; i <= 10; i++)
	{
		printf("%d ", i);
		printf("hehe\n");
	}
	return 0;
}
*/


/*
int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			break;
		printf("%d ", i);
	}
	return 0;
}
*/



//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}




//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}





//do...while()循环
//do
//	循环语句;
//while (表达式);




//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} 
//	while (i <= 10);
//	return 0;
//}







//作业一 ，    计算n的阶乘

//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		
//	}
//	printf("%d", ret);
//	return 0;
//}


//  作业二，计算1到10的阶乘之和


//法一
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 1;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = ret + sum;
//	}
//	printf("%d", sum);
//	return 0;
//}


//法二
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//	return 0;
//}


//作业三，在一个有序数组中查找具体的某个数n

//一个一个查找
//int main()
//{
//	int arr[] = { 1,2.3,4,5,6,7,8,9,10 };
//	int k = 8;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("找到了，下标是:%d\n",i);
//			break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}
//


//折半查找法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{  //int mid=left+(right-left)\2;
//		int mid = (left + right) / 2;
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]=k)
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}





//作业四，编写代码，演示多个字符从两端移动，向中间汇集


//strlen 计算\0  前的元素个数
//字符串\0结尾

//#include<windows.h>      //Sleep
//#include<stdlib.h>       //system
//int main()
//{
//	char arr1[] = "welcome  to  bit  !!!!";
//	char arr2[] = "######################";
//	int left = 0;
//	int right = strlen(arr2) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);   //控制运行速度
//		//清空屏幕   在一行中移动
//		system("cls");
//		left++;
//		right--;
//	}
//	return 0;
//}


// 作业五，编写代码，模拟用户登录情景，并且只能登录三次。
// （只允许输入三次密码，如果密码正确则提示登录成功，如果三次军输入错误，则退出程序）
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);  //数组名本来就是地址不需要取地址
//		if (strcmp(password ,"abcdef")==0)     //比较2个字符串是否相等，不能用==，而应该使用一个库函数:strcmp
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//		
//	}
//	if (i == 3)
//	{
//		printf("三次密码均输入，退出程序\n");
//	}
//	return 0;
//}




//电脑产生一个随机数（1-100）
//猜数字
//猜大了
//猜小了
//直到猜对


viod
int main()
{
	
	return 0;
}