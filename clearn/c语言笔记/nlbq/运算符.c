#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	float x = 6.0 / 4;     //要想输出是浮点数，2者之间就必须要有一个是浮点数
//	int y = 6 / 4;
//	printf("%f\n", x);
//	printf("%d\n", y);
//
//	return 0;
//}


//%取余
//int main()
//{
//	printf("%d\n", 10 % 3);
//	printf("%d\n", -10 % 3);
//	printf("%d\n", 10 % -3);
//	printf("%d\n", -10 % -3);
//	return 0;
//}


//=号赋值  ==  判断


//复合赋值符
//int main()
//{
//	int a = 10;
//	a += 3;   //a=a+3
//	a -= 2;   //a=a-2
//	printf("%d\n", a);
//	return 0;
//}



//前置和后置
//int main()
//{
//	int a = 10;
//	//int b = a++;  //先使用  后++   int b =a;  a++
//	int b = ++a;    //先++  后使用
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}


//移动运算符    位指的是比特位
//10指的是初始值          如果是负数则是向下取整
//左移  左移n位  10*2^n     <<
//右移  右移n位  10/2^n     >>     -1是个特例
//int main()
//{
//	int a = 5;
//	printf("%d\n", a << 1);
//	return 0;
//}



//位操作符
//      &  按位与     对应位上都是1  则对应位结果就是1  否则都是0
//      |   按位或     对应位上有1  则对应的结果就是1
//      ^   按位异或   只要对应位上 不一样  结果就是1
//      ！  按位取反   把对应比特位的1改成0 0改成1


//三目运算符
//表达式1？表达式2:表达式3;
//如果1为真，返回2 否则返回3
//int main()
//{
//	int a = 11;
//	int b = 12;
//	int max = a > b ? a : b;
//	printf("max:%d\n", max);
//	return 0;
//}


//逗号表达式
//就是用多个逗号隔开的表达式，从左往右依次计算所有的子表达式，最终结果是最后一个子表达式的结果
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c=(a > b, a = b + 10, a, b, b = a + 1);
//	printf("c=%d\n", c);
//	return 0;
//}

//运算符的优先级

