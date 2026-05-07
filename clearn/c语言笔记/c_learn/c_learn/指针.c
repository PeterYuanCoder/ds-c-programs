#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//                                             指针初识
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%d\n", a);
//	printf("%d\n", *p);   //*p解引用   间接访问&a这个地址所表示的内存
//	
//	*p = 100;
//	
//	printf("%d\n", a);
//	printf("%d\n", *p);
//
//	return 0;
//}



//int main()
//{
//	//在指针当中，指针的大小和指针的类型没有关系和操作系统是多少位有关系   32位：4   64位：8
//	//指针在间接访问的时候访问几个字节？取决于指针的类型！
//	printf("%zd\n", sizeof(char*));
//	printf("%zd\n", sizeof(short*));
//	printf("%zd\n", sizeof(int*));
//	printf("%zd\n", sizeof(double*));
//	return 0;
//}



//指针运算
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];     //数组是什么类型   指针就要是什么类型
//	//printf("%d\n", p);
//	//printf("%d\n", p+1);   //因为p是int类型所以+1是加4个字节   指针+整数加几个字节和指针类型相关
//
//	printf("p+1=%p\n", p + 1);
//	printf("&arr[1]=%p\n", &arr[1]);
//
//	printf("*(p+1)=%d\n", *(p + 1));
//	printf("arr[1]=%d\n", arr[1]);
//
//	return 0;
//}




//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(p + i));
//		printf("%d\n", p[i]);   //[i]  相当于*(数组名+i)    
//		//数组名  =  元素首元素的地址   
//		//1.sizeof(arr)在定义数组的同一个位置这个代表整个数组的字节大小
//		//2.&arr代表整个数组的地址
//	   
//	}
//	return 0;
//}


//指针-指针=元素个数
//前提：两个指针的类型是一样的且两个指针指向的是同一个内存
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p1 = &arr[2];
//	int* p2 = &arr[4];
//	printf("%d", p2 - p1);
//	return 0;
//}



//指针的关系运算
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (p < arr + sz)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}



//const修饰   
//const修饰必须进行初始化 
//被修饰之后，在语法是加了限制，无法直接修改n  ,但n属性还是变量
//如果绕过n,使用n的地址，去修改能做到
//int main()
//{
//	const int a = 10;
//	//通过指针修改b
//	const int b = 10;   //修饰的是*b
//	int* pb = &b;
//	*pb = 99;
//	printf("%d\n", b);
//	printf("%d\n", *pb);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 10;
//	//const修饰pb ,pb的值指向&b不能改变 ，但是*p能变
//	int* const pb = &b;
//	*pb = 99;
//	return 0;
//
//}



//assert 断言
// 我们可以用它检查一个指针是否是NULL
// #include<assert.h>
// 
//int main()
//{
//	int* p = NULL;
//	//断言只能在debug情况下有效
//	assert(p == NULL);
//	printf("hehe");
//	
//	if (p == NULL)
//	{
//		printf("当前指针为空\n");
//		return -1;
//	}
//	*p = 100;
//	return 0;
//}
//


//野指针
//指针指向的位置未知

//1.指针未初始化
//int main()
//{
//	int* p;
//	*p = 10;
//	return 0;
//}

//2.指针的越界访问
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr[0];
//	int i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		//当指针超出指向范围时，p就是野指针
//		*(p++) = i;
//	}
//	return 0;
//}


//指针指向的空间释放

//int* text()  //n是整形 返回&n用int*返回
//{
//	int n = 100;   //可以用static修饰延长生命周期
//	return &n;  //n局部变量在函数结束是销毁，返回的地址是无效的
//}
//
//int main()
//{
//	int* p = test();
//	printf("%d\n", *p);
//	return 0;
//}


//strlen     输出绝对长度不带字符串后面的\0
// #include<string.h>
// 
// 
//int main()
//{
//	char* str = "hello";
//	printf("%s\n", str);
//	str++;
//	printf("%s\n", str);      //以此内推  ，当str为\0是计算字符串的长度
//	return 0;
//}

//int main()
//{
//	char* str = "hello";
//	int len = strlen(str);
//	printf("%d\n", len);
//	return 0;
//}

//用函数来表示是strlen

//#include<assert.h>
//size_t my_strlen(const char* p)    //加const防止在计算长度时修改了字符的值     size_t是无符号整数
//{
//	assert(p!=NULL);
//	size_t len = 0;
//	while (*p != '\0')
//	{
//		len++;
//		p++;
//	}
//	return len;
//}
//int main()
//{
//	char* str = "hello";
//	size_t len = my_strlen(str);
//	printf("%zu\n", len);
//	return 0;
//}


//按址传递
//void swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	printf("%d,%d\n", a, b);
//	swap(&a, &b);
//	printf("%d,%d\n", a, b);
//
//	return 0;
//
//}




//                                           指针进阶


//二级指针

//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//
//	int** p2 = &p1;   //p2存p1的地址
//	printf("%d\n", p1);
//	printf("%d\n", *p2);   //一次解引用，返回p1的地址
//	return 0;
//}


//理解数组名

//数组名字表示首元素的地址
//sizeof(数组名),这里数组名表示整个数组，计算的是整个数组的大小，单位是字节
//&数组名 表示的是整个数组的地址

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	printf("%p\n", arr);//数组名字表示首元素的地址
//
//	printf("%p\n", &arr[0]);//数组名字表示首元素的地址
//
//	printf("%p\n", &arr);  //值虽然相等但是意义不同  ，这表示整个数组的地址
//
//	printf("%p\n", &arr+1);//上面的+1都是加4个字节 ，这里是加一整个数组的字节大小
//	return 0;
//}


//使用指针的方式打印数组的内容
//void print_arr(int *p, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int len = sizeof(arr)/sizeof(arr[0]);  //len一定要在main函数中计算再传进函数中
//	print_arr(arr, len);
//	return 0;
//}



//数组指针
//数据类型 (*指针名)[数组长度]
//int (*p)[4];
//int main()
//{
//	int arr[4] = { 1,2,3,4 };
//	int (*p)[4] = &arr;
//	printf("%p\n", *p);    //输出首元素的地址
//	printf("%p\n", (*p)[1]);  //(*p)[1] ===>*((*p)+1)
//	return 0;
//}



//二维数组  的数组名代表第一行的地址
//void print_arr(int (*arr)[3], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[2][3] = { 1,2,3,4,5,6 };
//	print_arr(arr, 2, 3);
//	return 0;
//}


//指针数组
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	int len = sizeof(arr)/sizeof(arr[0]);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%p\n", arr[i]);  //打印地址
//		printf("%d\n", *(arr[i]));//打印值
//
//	}
//
//	return 0;
//}


//函数指针

//void test()
//{
//	printf("hehe\n");
//}
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	printf("test: %p\n", test);
//	printf("&test: %p\n", &test);
//	void (*pf1)() = test;
//	int (*pf2)(int, int) = add;
//	//调用
//	int ret = (*pf2)(1, 2);
//	printf("%d\n", ret);
//	return 0;
//}



//写出输出结果

//习题1
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };  //逗号运算符    它会从左到右执行表达式，最终结果是最右边那个值
//	int* p = a[0];
//	printf("%d", p[0]);  //printf("%d",*(p+0));
//}


//习题2
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d %d", *(a + 1), *(ptr - 1));
//	return 0;
//}



//习题3

//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}


//习题4
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%zu\n", sizeof(a));//16  求整个数组的字节大小
//	printf("%zu\n", sizeof(a+1));
//	printf("%zu\n", sizeof(a[1]));
//	printf("%zu\n", sizeof(&a));
//	printf("%zu\n", sizeof(&a+1));
//	printf("%zu\n", sizeof(&a[0]));
//	printf("%zu\n", sizeof(&a[0]+1));
//
//	return 0;
//}



//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

//void swap(int p[], int n)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left < right)
//	{
//		while (left < right && p[left] % 2 != 0)
//		{
//			left++;
//		}
//		while (left < right && p[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = p[left];
//			p[left] = p[right];
//			p[right] = tmp;
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[1000];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	swap(arr,n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}



//写一个函数，可以逆序一个字符串的内容。
//void swap(char arr[],int len)
//{
//	
//	int left = 0;
//	int right = len - 2;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = sizeof(arr) / sizeof(arr[0]);
//	swap(arr, len);
//	for (int j = 0; j < len; j++)
//	{
//		printf("%c\n", arr[j]);
//	}
//	return 0;
//}




//输出杨辉三角     每个数等于它左上方和上方的两数之和。
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int arr[30][30] = { 0 };
//	for (int i = 0; i < a; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (int i = 0; i < a; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//
//int search(int arr[20][20], int row, int col, int k)
//{
//	int i = 0;
//	int j = col - 1;
//	while (i < row && j>=0)
//	{
//		if (arr[i][j] == k)
//		{
//			return 1;
//		}
//		else if (arr[i][j] > k)
//		{
//			j--;
//		}
//		else
//		{
//			i++;
//		}
//		
//	}
//	return 0;
//
//}
//int main()
//{
//	int row,col;
//	scanf("%d %d", &row,&col);
//	int arr[20][20] = { 0 };
//	int num = 1;
//	//矩阵
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			arr[i][j] = num++;
//		}
//	}
//	//输出矩阵
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	//查找元素
//	int k;
//	scanf("%d", &k);
//	//查找
//	int n = search(arr, row, col, k);
//	if (n == 1)
//	{
//		printf("存在\n");
//	}
//	else
//	{
//		printf("不存在\n");
//	}
//	
//	return 0;
//}



//KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
//int main()
//{
//
//        int a, b;
//        while (scanf("%d %d", &a, &b) != EOF) { // 注意 while 处理多个 case
//            // 64 位输出请用 printf("%lld") to 
//            if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
//            {
//                printf("31");
//            }
//            else if (b == 2)
//            {
//                if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
//                {
//                    printf("29");
//                }
//                else {
//                    printf("28");
//                }
//            }
//            else {
//                printf("30");
//            }
//        }
//      
//	return 0;
//}


//          鹏哥指针


//重温数组指针     指向的是指针
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (*p)[10] = &arr;  //&数组名 指的是整个数组的地址
//	//p就是数组是指针变量
//
//	return 0;
//}


//数组指针应用
//void print(int (*arr)[5], int r, int c)     //
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print(arr, 3, 5);
//	return 0;
//}


//函数指针
//函数名指的是函数的地址
//&函数名指的也是函数的地址
//void test()
//{
//	printf("hehe");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	int (*pf)() = test;
//	//pf就是函数指针变量
//	return 0;
//}


//强制类型转换
//*(void(*)())0
//将0这个整形强制转换成函数指针类型
//*(short)0
//将0这个整形强制转换成短整型



//typedef关键字
//用于类型的重命名，可以将复杂的类型，简单化      注意是类型
//typedef unsigned int unit;
//int main()
//{
//	unsigned int num1 = 0;
//	unit num2 = 0;
//	//两个定义是一样的
//	return 0;
//}


//指针的重命名
//typedef int* pint_t;
//int main()
//{
//	int* p1;
//	pint_t p2;
//	return 0;
//}


//typedef应用

//typedef int* pint_t;
//int main()
//{
//	int* p1, p2;
//	//p1是指针变量
//	//p2是整形
//	int* p1, * p2;
//	//p1,p2都是指针变量
//
//	pint_t p1, p2;
//	//p1和p2都是指针变量
//}


//数组指针的重命名
//typedef int (*parr_t)[5];     //放到括号里面
//int main()
//{
//	int arr[5] = { 0 };
//	int (*pa)[5] = &arr;
//	parr_t pb = &arr;
//	return 0;
//}

//函数指针的重命名
//int Add(int x, int y)
//{
//	return x + y;
//}
//typedef int (*parr_t)(int,int);
//int main()
//{
//	int (*pf)(int, int) = Add;
//	parr_t pf2 = Add;
//}