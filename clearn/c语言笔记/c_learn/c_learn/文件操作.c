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


//int main()
//{
//	FILE* pf = fopen("../../test.txt", "w");    //注意如果是绝对路径的，小心\转义字符       
//	//以w形式打开文件，即使文件不存在也会自己创建一个文件，如果里面有内容 打开后会全删掉
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		printf("打开文件成功\n");
//	}
//	//读文件
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}



//5.1流和标准流
// 三个标准流的类型事：FILE*，通常称为文件指针
//标准输入流 stdin
//标准输出流 stdout
//标准错误流 stderr


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


//  6.文件的顺序读写

//fputc

//int fputc(int character, FILE* stream);

//character:被写入的字符

//功能：将参数character指定的字符写⼊到stream指向的输出流中，通常⽤于向⽂件或标准输出流写⼊字符。
//在写⼊字符之后，还会调整指⽰器。字符会被写⼊流内部位置指⽰器当前指向的位置，随后该指⽰器⾃动向前移动⼀个位置。
//从输入流中读取一个字符

//返回值：
//成功时返回写入的字符（以int形式）
//失败时返回EOF（通常是-1）,错误指示器会被设置，可通过perror()检查具体错误

//int main()
//{
//	FILE* pf = fopen("test.txt", "w"); //以w的形式打开⽂件，才能正确的写⽂件
//
//	if (pf == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	//写文件
//	/*fputc('a', fp);
//	fputc('b', fp);
//	fputc('c', fp);*/
//	
//	//循环写入
//	for (char ch = 'a'; ch <= 'z'; ch++)
//	{
//		//写入文件
//		fputc(ch, pf);
//		//输出到屏幕
//		fputc(ch, stdout);   //stdout  标准输出流
//	}
//
//	//关闭⽂件
//	fclose(pf);
//	pf = NULL; //将指针置为NULL避免成为野指针。
//	return 0;
//}


//fgetc函数

//int fgetc(FILE* stream);

//功能：从参数stream指向的流中读取⼀个字符。
//函数返回的是⽂件指⽰器当前指向的字符，读取这个字符之后，⽂件指⽰器⾃动前进道下⼀个字符(从输出流中写入一个字符)

//返回值：
//成功是返回读取的字符 （以int形式）

//若调⽤时流已处于⽂件末尾，函数返回EOF ,并设置流的⽂件结束指⽰器(feof)
//若发⽣读取错误，函数返回EOF,并设置流的错误指⽰器（ferror).


//从文件中读

//int main()
//{
//	FILE* pf = fopen("test.txt", "w"); //以w的形式打开⽂件，才能正确的写⽂件
//
//	if (pf == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	//读文件
//	int ch = 0;
//	while (ch = fgetc(pf) != EOF)
//	{
//		printf("%c\n", ch);
//	}
//	//关闭⽂件
//	fclose(pf);
//	pf = NULL; //将指针置为NULL避免成为野指针。
//	return 0;
//}

//从键盘中读

//int main()
//{
//	int ch;
//	while (ch = fgetc(stdin) != EOF)   //stdin  键盘
//	{
//		printf("%c\n", ch);
//	}
//	return 0;
//}


//feof和ferror

//int feof(FILE* stream);
//检测stream指针指向的流是否遇到文件末尾

//如果在读取⽂件的过程中，遇到了⽂件末尾，⽂件读取就会结束。
//这时读取函数会在对应的流上设置⼀个⽂件结束的指⽰符，这个⽂件结束指⽰符可以通过feof函数检测到。
//如果feof函数检测到⽂件结束指⽰符已经被设置，则返回⾮0的值，如果没有设置则返回0

//int ferror(FILE* stream)
//检测stream指针指向的流是否发生读/写错误

//如果在读/写⽂件的过程中，发⽣了读/写错误，⽂件读取就会结束。这时读/写函数会在对应的流上设置⼀个错误指⽰符，这个错误指⽰符可以通过ferror函数检测到。
//如果ferror函数检测错误指⽰符已经被设置，则返回⾮0的值，如果没有设置则返回0


//检测feof函数

//int main()
//{
//	FILE* fp = fopen("test.txt", "r");
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int c = fgetc(fp);
//		if (c == EOF)
//		{
//			if (feof(fp))
//				printf("遇到文件末尾了\n");
//			else if (ferror(fp))
//				printf("读取发生了错误\n");
//		}
//		else
//		{
//			fputc(c, stdout);
//		}
//		//fputc(c, stdout);//使用fputc 在标准输出流上打印1字符
//	}
//	//不再使用文件时，需要关闭文件
//	fclose(fp);
//	fp = NULL;   //避免野指针
//	return 0;
//}



//检测ferror函数

//以写的形式打开文件后，再去读文件，就会发生错误   不支持读操作
//int main()
//{
//    FILE* fp = fopen("test.txt", "w");
//    if (fp == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //读⽂件
//    int c = fgetc(fp);
//    if (c == EOF)
//    {
//        if (feof(fp))
//            printf("遇到⽂件末尾了\n");
//        else if (ferror(fp))
//        {
//            printf("读⽂件发⽣了错误\n");
//        }
//    }
//    else
//    {
//        fputc(c, stdout);//使用fputc在标准输出流上打印字符
//    }
//    //关闭文件
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}



//fputs函数

//int fputs(const char* str, FILE* stream);

//功能：将参数str指向的字符串写入到参数stream指定的流中（不包含结尾的\0),适用与文件流或标准输出（stdout)

//参数：
//str:str是指针,指向要写入的字符串(必须以\0结尾)
//stream:是FILE指针，指向要写入字符串的流

//int main()
//{
//	FILE* fp = fopen("test.txt", "w");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	int i = 0;
//	fputs("he\0llo", fp);
//	fputs("world", fp);
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//fgets函数

//char* fgets(char* str, int num, FILE* stream);

//功能：
//从stream指定输⼊流中读取字符串，⾄读取到换⾏符、⽂件末尾（EOF）或达到指定字符数（包含结尾的空字符\0），然后将读取到的字符串存储到str指向的空间中。

//参数：num:最大读取字符数(包含结尾的\0,实际上最多读取num-1个字符）

//返回值
//成功则返回str指针
//若遇到文件结尾,设置文件结束指示器，并返回NULL,用feof检测
//若读取错误，设置流错误指示器,并返回NULL,用ferror检测

//int main()
//{
//	FILE* fp = fopen("test.txt", "r");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	//读文件
//	char arr[20] = "------------";
//	//fgets(arr, 5, fp);//abcd\0
//
//	while (fgets(arr, 5, fp) != NULL)
//	{
//		printf("%s", arr);
//	}
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//fprintf函数   写入

//int fprintf ( FILE * stream, const char * format, ... );

//fprintf是将格式化数据写入指定文件流的函数。它与printf类似，但可以输出到任意流，而不仅限于控制台

//参数：...:可变参数列表

//返回值：成功时，返回写入的字符总数(非负值)
//失败时，先设置对应流的错误指示器，再返回负值，可以通过ferror检测


//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct Stu s = { "张三",20,95.5f };
//	FILE* fp = fopen("test.txt", "w");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	//写文件
//	fprintf(fp,"名字：%s 年龄：%d 成绩：%f\n", s.name, s.age, s.score);
//	
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//fscanf函数   读出

//int fscanf ( FILE * stream, const char * format, ... );

//fscanf是从指定⽂件流中读取格式化数据的函数,类似与scanf,可以指定输入源


//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct Stu s = { 0 };
//	FILE* fp = fopen("test.txt", "r");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	//读文件
//	
//	fscanf(fp, "名字：%s 年龄：%d 成绩：%f\n", s.name, &(s.age), &(s.score));    //name是指针，无需取地址
//	fprintf(stdout, "名字：%s 年龄：%d 成绩：%f\n", s.name, s.age, s.score);
//
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//sprintf函数
//将格式化数据转换成一个字符串

//sscanf函数
//从字符串中读取格式化数据（解析字符串中的结构化数据）

//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct Stu s = { "zhangsan",20,95.5f };
//	char arr[30] = { 0 };
//	sprintf(arr, "%s %d %f", s.name, s.age, s.score);
//	printf("%s\n", arr);
//	
//	//从arr中解析一个结构体数据
//	struct Stu t = { 0 };
//	sscanf(arr, "%s %d %f", t.name, &(t.age),&(t.score));
//	fprintf(stdout, "%s %d %f", s.name, s.age, s.score);
//
//	return 0;
//}

//fwrite函数
//size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);

//功能：函数用于将数据块写入stream指向的文件流中，是以2进制的形式写入的

//参数
//ptr:要写入的数据块的指针
//size:要写⼊的每个数据项的⼤⼩（以字节为单位）
//count:要写入的数据项的数量

//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = { "zhangsan",20,95.5f };
//	FILE* fp = fopen("test.txt", "wb");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	//写文件
//	fwrite(&s, sizeof(struct Stu), 1, fp);
//
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}



//fread函数

//功能：从stream指向的文件中读取数据块，并储存到ptr指向的内存缓冲区

//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s = { 0 };
//	FILE* fp = fopen("test.txt", "rb");
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	fread(&s, sizeof(struct Stu), 1, fp);
//	printf("%s %d %.2f", s.name,s.age,s.score);
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

