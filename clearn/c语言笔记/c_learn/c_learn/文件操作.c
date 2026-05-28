#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//                           文件操作

//1. 为什么要使用文件

//如果没有⽂件，我们写的程序的数据是存储在电脑的内存中，如果程序退出，内存回收，数据就丢失
//了，等再次运⾏程序，是看不到上次程序的数据的，如果要将数据进⾏持久化的保存，我们可以使⽤
//⽂件
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	if (n = 1)              //当输入1 正常运行之后数组内存的数据在第二次输入0是不会输出      ，输入数组的数据没有保存 return 0 后内存回收
//	{
//		for (i = 0; i < 10; i++)
//		{
//			scanf("%d", arr + i);
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//2.文件名

//⼀个⽂件要有⼀个唯⼀的⽂件标识，以便⽤⼾识别和引⽤。
//⽂件名包含3部分：⽂件路径 + ⽂件名主⼲ + ⽂件后缀

//2.1 绝对路径和相对路径
//绝对路径： 带根目录的 D : \project\clearn\c语言笔记\c_learn\c_learn
//绝对路径：.表示当前目录   ..表示上一级目录
//..\..\c语言笔记  表示向上两级进入c语言笔记文件夹中

//3. 程序文件

//程序⽂件包括源程序⽂件（后缀为.c）, ⽬标⽂件（windows环境后缀为.obj）, 可执⾏程序（windows
//环境后缀为.exe）。


//4. 二进制文件和文本文件


//根据数据的组织形式，数据⽂件被分为⽂本⽂件和⼆进制⽂件。
//数据在内存中以⼆进制的形式存储，如果不加转换的输出到外存的⽂件中，就是⼆进制⽂件。
//如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。以ASCII字符的形式存储的⽂件就是⽂
//本⽂件。


//5. 文件的打开和关闭
//fopen 打开文件   fclose 关闭文件

//int main()
//{
//
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");    //打开文件   "wb"表示打开一个二进制文件
//	fwrite(&a, 4, 1, pf);//⼆进制的形式写到⽂件中
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}




//fopen函数

//FILE* fopen(const char* filename, const char* mode)

//filename：表示打开文件的名字，可以是绝对路径，也可以是相对路径
//mode：表示打开文件的操作方式

//fopen函数是⽤来打开参数功能：
//后续对流的操作是通过filename指定的⽂件，同时将打开的⽂件和⼀个流进⾏关联，fopen函数返回的指针来维护。
//具体对流（关联的⽂件）的操作是通过参数mode来指定的

//返回值
//若⽂件成功打开，该函数将返回⼀个指向FILE对象的指针，该指针可⽤于后续操作中标识对应的流。
//若打开失败，则返回NULL指针，所以⼀定要fopen的返回值判断,来判读文件是否打开成功



//fclose函数

//int fclose ( FILE * stream );

//stream:指向要关闭的流的FILE对象的指针

//功能：：关闭参数stream关联的⽂件，并取消其关联关系。
//与该流关联的所有内部缓冲区均会解除关联并刷新：任何未写⼊的输出缓冲区内容将被写⼊，任何未读取的输⼊缓冲区内容将被丢弃

//关闭成功stream指向的流会返回0，否则会返回EOF


int main()
{
	FILE* pf = fopen("../../test.txt", "r");    //注意如果是绝对路径的，小心\转义字符
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	else
	{
		printf("打开文件成功\n");
	}
	//读文件
	//关闭文件
	fclose(pf);
	pf = NULL;
}



//5.1流和标准流
// 三个标准流的类型事：FILE*，通常称为文件指针


//5.2 文件指针
//struct _iobuf {
//	char* _ptr;
//	int   _cnt;
//	char* _base;
//	int   _flag;
//	int   _file;
//	int   _charbuf;
//	int   _bufsiz;
//	char* _tmpfname;
//};
//typedef struct _iobuf FILE;