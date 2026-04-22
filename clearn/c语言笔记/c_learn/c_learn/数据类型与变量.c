#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	//定义无符号类型的变量    只能输出正数   不写unsigned就是有符号类型
//	unsigned char a = -1;
//	printf("%d\n", a);
//	return 0;
//}



//int main()
//{
//	//float 一般是精确到小数点后6位
//	float f = 12.4f;//f后缀表示这是一个float常量    标记作用
//	printf("%f\n", f);
//	return 0;
//}



//A转a
//int main()
//{
//	char ch = 'a';
//	printf("%c\n", ch - 32);
//	return 0;
//}



//布尔类型
//#include<stdbool.h>
//int main()
//{
//	_Bool flg = true;
//	if (flg)
//	{
//		printf("This is true!\n");
//	}
//	return 0;
//}





//   在不同的编译器上不同    sizeof  来求字节数
//64位                      32位
//char     1                1
//_Bool    1                1
//short    2                2
//int      4                4
//long     8                4
//long long 8               8
//float    4                4
//double   8                8





//进制的转换  bit  第三节课数据类型与变量  第一小时
//  1个字节（8个bit位）  0-255
//有符号的数字 最高位为符号位   不加 unsigned  就是有符号的数字

//负数    的  反码（符号位保持不变，原码的其他各数值位按位取反（1变0，0变1））
// 负数    的  补码（反码+1）
// 1000 0000 表示-128 .-128的原码和补码一样
//正数  的   原码，反码，补码全一样

//int main()
//{
//	char a = 128;   //输出-128
//	printf("%d\n", a);
//	return 0;
//}


//printf  如果有n个占位符，printf()参数应该有n+1个


//scanf   注意取地址符号  scanf中的%d后面不加\n  ,要想运行就在输入的数据后面加\n  
//注意%d  和%d之间的连接符号 
//scanf()的返回值是一个整数，表示成功读取的变量个数
// 如果成功读取任何数据之前，发生了读取错误或者遇到读取到文件结尾，则返回常量EOF（-1）
//如果没有读取任何项，或者匹配失败，则返回0

//int main()
//{
//	char name[11];   //只能输入10个字符，默认\0作为结束标记
//	scanf("%s", name);  //数组本身就是取地址无需再加取地址符号
//	printf("%s\n", name);
//	return 0;
//}


//循环读入    3个ctrl+z表示文件结尾
//while (scanf("%d %d", &a, &b) != EOF)
//{
//
//}
