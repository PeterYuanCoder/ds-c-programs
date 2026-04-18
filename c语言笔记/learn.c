#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//
//int main()
//{
	//long age = 20;
	//char price = 66.6;
//	return 0;
//}


int main()
{
    printf("C语言学习程序运行成功！\n");
    return 0;
}
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
// ��2����֮��
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


//const����ֻ��������a��ֵ�����޸ģ������ʼ��
//int main()
//{
//	const int a = 100;
//	printf("a=%d\n", a);
//	return 0;
//}

//�����[]���������const���α���Ϊ��ֵ���ǻ���Ϊ����
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
//ö�ٳ���    enum
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
//	printf("�������\n");
//	printf("Ҫ�ú�ѧϰ��(1/0)��");
//
//	scanf("%d", &input);
//	if (input == 0)
//	{
//
//		printf("��offer\n");
//	}
//	else
//	{
//		printf("������\n");
//	}
//	return 0;
//}


//int main()
//{
//	int blue = 0;
//	printf("�������\n");
//
//	while (blue < 20000)
//	{
//
//		printf("д����:%d\n", blue);
//		blue++;
//	}
//	if (blue >= 20000)
//	{
//		printf("��offer\n");
//	}
//	else
//	{
//		printf("��������\n");
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
//	int n1 = 10;     /* 10��������������*/
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
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };    /*�����±��0��ʼ*/
//	printf("%d\n",arr[4]);      /*arr�ɱ䲻Ӱ��*/
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
//int main()           ����
//{
//	int b = (8 + 22) * a - 10 + c / 2;
//	printf("%d\n", b);
//	return 0;
//}



//int main()
//{
//
//	char arr[4] = { 'a','b','c' };
//	printf("%d\n",strlen(arr));           /* ������arr�е�������Ϊ���ֵ*/
//	return 0;
//}                                     []��ֻ���Գ������������Ǳ���         c99��׼








//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()                                  /*��2�����еĽϴ�ֵ*/
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int c = Max(a, b);
//	printf("%d\n", c);
//	return 0;
//}




//int main()                   /*��֪һ������f(x),��x<0ʱ��y=1����x=0ʱ��y=0,��x>0ʱ��y=-1*/
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
//	float a = 7 / 2.0;         /*���ŵ����˶���������ִ�������������������ֻҪ��һ���������Ϳ���ִ�и�������������Ҫ��float,,,����ĳ�f*/
//	int b = 7 % 2;       
//	/*%��ȡ�������ţ�ȡ�������������*/       /*ȡ���������Ҫ������*/
//	printf("%.2f\n", a);      /* ��0.����������*/
//		printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	int a = 2;          /*��ʼ��*/
//		a = 20;         /*��ֵ*/
//	return 0;
//  }




////c������
////0��ʾ��
////��0��ʾ��
//int main()
//{
//	int flog = 2;
//	if (!flog)
//	{                          !�߼��������������ɼ�
//		printf("hehe\n");
//	}
//	return 0;
//}



//����++    ����--

//int main()
//{
//	int a = 10;
//	int b = a++;        
//	/*int b = a; a = a + 1;*/
//	/*����++��     ��ʹ�ã���++*/
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}



//ǰ��++    ǰ��--


//int main()
//{
//	int a = 10;
//	int b = ++a;        
//	//a = a + 1; b = a;
//	/*ǰ��++��      ǰ++����ʹ��*/
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}



//ǿ������ת��   (����)

//int main()
//{
//	int b = (int)3.14;    /*����������*/
//	//3.14 ���渡������������Ĭ��Ϊ����double����
//	printf("%d\n", b);
//	return 0;
//}



//int main()
//{
//	/*&&  �߼�-  ����
//	�����߼�-  ����*/
//
//	
//	/*int a = 10;
//	int b = 20;
//	if (a && b)
//	{
//		printf("hehe");
//	}*/
//
//                       //==���ڲ������
//	return 0;
//}



//����������
//exp1 ? exp2 : exp3 
//��      ��     ��
//��      ��     ��

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = (a > b ? a : b);
//	return 0;
//}



//���ű���ʽ���Ƕ��Ÿ�����һ������ʽ
//���ű���ʽ���ص���:�����������μ��㣬��������ʽ�Ľ�������һ������ʽ�Ľ��,ǰ�������Ӱ�������

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
//	pdd[3] = 20;     /* []�����±����ò�������pdd��3����[]������*/
//
//	printf("%d\n",pdd[3]);
//	return 0;
//}



//����������()             ����

//int pdd(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int sum = pdd(2, 3);          /*()���Ǻ����Ĳ�������pdd��2��3����()�Ĳ�����*/
//	return 0;
//}






//static
//1.���ξֲ�����
//2.����ȫ�ֱ���
//3.���κ���

//1,���ξֲ�����
//void pdd()             /*void ��ʾ����Ҫ����*/
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



//2,����ȫ�ֱ���             ����	
//int a = 100;
//               //extern �����ⲿ����
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}


//3�����κ���       ���ᣬҪ�ٽ�һ���ĵ�
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
//	/*�Ĵ�������*/
//		register int num = 2;     /* ���飺2����ڼĴ���*/
//	return 0;
//}






//#define���÷�

//1��#define�Ķ����ʶ������
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

//2��#define �����        �滻
//�����в���

//#define add(x,y)    ((x)+(y))        /* �����д����  */     /*add�Ǻ������      xy�Ǻ�Ĳ��� ������������     x+y�Ǻ���*/
//
//int main()
//{
//	int a = 10;
//	int b = 20;	
//	int c = add(a, b);
//	printf("%d\n", c);
//	return 0;
//}





//ָ�����

//int main()
//{
//	int a = 10;           /*���ڴ�����4���ֽڣ��洢10*/
//	/*&a;*/   /*ȡ��ַ������*/
//	//��p��ӡȡ��ַ
//	printf("%p\n", &a);
//	int* b = &a;
//	//b����ָ�����         *a˵��b��ָ�����    int˵��bָ��Ķ�����int ���͵�
//	*b = 20;      /*�����ò���������˼��ͨ��b�д�ŵĵ�ַ���ҵ�b��ָ��Ķ���*b����bָ��Ķ���*/
//	printf("%d\n", a);
//	return 0; 
//}



//ָ������Ĵ�С    �����   23����ĩβ





//�ṹ�� struct

//ѧ��
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



//��ҵ
//������������a��b����a����b�������̺�����
//int main()
//{
//	int a = 0;
//	int b = 0;
//	//����
//	scanf("%d %d", &a, &b);
//	//����
//	int c = a / b;
//	int d = a % b;
//	//���
//	printf("%d %d\n", c, d);
//	return 0;
//}



//if���÷�

//int main()
//{
	//int a = 10;
	//if (a = 3)    /*�����Ⱥ����жϵ���˼Ϊ�پʹ�ӡ����������֮*/   /* һ���Ⱥ��и�ֵ����˼*/
	//	printf("hehe\n");


	//int age = 19;
	//if (age > 18)       /*���������ڵ���������������ӡ*/
	//	printf("����\n");
	//	return 0;


	//int age = 20;
	//if (age > 18)      /*if����ֻ���Խ�һ��printf��Ҫ������������ô���������*/
	//{
	//	printf("����\n");
	//	printf("������\n");
	//}
	//else                               /*����if������ӡif��ģ������㼰��ӡelse�е�����*/
	//	printf("δ����\n");

//���֧
//int age = 10;
//	scanf("%d", &age);
//	if (age < 18)            /*Ϊ�پ͵�����*/
//		printf("������\n");
//	else if (age >= 18 && age < 28)
//		printf("����\n");
//	else if (age >= 28 && age < 40)
//		printf("����\n");
//	else if (age > 40 && age < 60)
//		printf("׳��\n");
//	else
//		printf("����\n");
//}



//int main()
//{
//	int age = 10;
//	if (age < 18)
//		printf("δ����\n");
//	else
//	{
//		printf("����\n");           ���֧Ҳ��Ҫ�ô����     ��{}��Ϊ�����
//		printf("����Ϸ\n");
//	}
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)         /* a������1�������ݲ������b����2��������޽��*/
//		if (b == 2)
//			printf("˧��\n");
//		else                   /*else������������ifƥ��*/
//			printf("˧��\n");
//	return 0;
//}




//���1��100֮�������
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{                                      /*����һ*/
//		if (i % 2 == 1)
//			printf("%d", i);
//		i = i++;
//	}
//	return 0;
//}


//int main()                             /*������*/
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		printf("%d", i);
//			i+=2;        /* i=i+2*/
//	}
//	return 0;
//}
 



//switch���   ���ڶ��֧     ����Ƕ��
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//
//	switch (day)             /* ()�ڱ���������*/
//	{
//	case 1:                   /* case ���γ�������ʽ;*/
//		printf("����һ\n");
//		break;                /*��break����case*/
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7: 
//		printf("������\n");
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
////	default:         /*��ֹ�������*/        /*��case�ı�ǩ��ƥ�����default*/
////		printf("ѡ�����\n");
////		break;
////	}
//}





//whileѭ��
//while�е�break���������õ���ֹ
//continue ��������ѭ������Ĵ��룬ֱ��ȥ�жϲ��֣�������һ��ѭ�����ж�
//int main()
//{
//	int a = 1;
//	while (a <= 10)
//	{
//		if (5 == a)        /*��a=5��ͨ��break����ѭ�������1��2��3��4*/
//			/*break;*/
//			continue;    /* ֱ����������Ĵ��룬��������ѭ��*/
//		printf("%d", a);
//		a++;
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	                //getchar��ȡ�ַ�
//	/*while (getchar())*/
//	int ch = getchar();
//	pritntf("%c\n", ch);
//	putchar(ch);
//	return 0;
//}
//crtl C,crt v,alt tab,ctrl z,crtl x,ctrl a, ctrl s,ctrl d,ctrl f,ctrl r,ctrl tab
//ctrl ���Ҽ���



//whileѭ��
//
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		printf("%d ", i);     //%d���һ���ո�������������м����
//		i++;
//	}
//	return 0;
//}


                        // continue��forѭ����whileѭ����������ͬ

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)       Ҳ����int i = 1
//	{
//		if (i == 5)           
//			continue;       // �����break�Ļ������1234
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


//forѭ�����жϲ���ʡ����ζ���жϻ�����

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{                                      //�����3*3��hehe
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}



//���9*9�˷���
// �����ǳ˷���
//
//int main()
//{
//	 int i = 0;
//	 int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <=i; j++)                      //��סj<=i
//		{
//			printf("%d*%d=%2d ", j, i, i * j);
//		}
//		printf(" \n");
//	}
//	return 0;
//}




// �����ǳ˷���

	// int main()
 //{
	// int i = 0;
	// int j = 0;
	// for (i = 1; i < 10; i++)
	// {
	//	 for (j = i; j < 10; j++)                       //��סj=i
	//	 {
	//		 printf("%d*%d=%2d ", i, j, i * j);
	//	 }
	//	 printf("\n");
	// }
	// return 0;
 //}



//                        1������n�Ľ׳�
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;                       ret�����ۻ�
//	}
//	printf("%d\n", ret);
//	return 0;
//}


//                          2������1��+2��+3��+......+10!
//��һ
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;             //����ret��ֹ�����۳˳���
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//����
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



                    //3,��һ���������в��Ҿ����ĳ������n��(������ֲ���)Ҳ���۰����


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);           //��Ԫ�ظ���
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//      int mid=left+(left+right)/2                  //��ֹ������Χ
//		int mid = (left + right) / 2;                //midһ��Ҫ����while����      
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
//			printf("�ҵ��ˣ��±���:%d\n", mid);
//			break;
//		}
//		if (left > right)                    //���������ݲ����������ǳ����������
//		{
//			printf("�Ҳ���\m");
//		}
//	}
//	return 0;
//}

                // 4����д����,��ʾ����ַ��������ƶ������м�㼯

//int main()
//{            // ��ε�left��right��ʾ�����±�           ����������û��\0�����ַ����Ľ�����־
//		char arr1[] = "welcome to bit!!!!";
//		char arr2[] = "###################";
//		int left = 0;
//		int sz = sizeof(arr1) / sizeof(arr1[0]);
//		int right = sz - 2;     //Ҳ������int right=strlen(arr2)-1;      strlen����\0ֵǮ��Ԫ�صĸ���
//		while (left <= right)
//		{
//			arr2[left] = arr1[left];
//			arr2[right] = arr1[right];
//			printf("%s\n", arr2);
//			Sleep(1000);       //ʹ����������
//			system("cls");      //һ�д��뽥��
//			left++;
//			right--;
//		}
//		printf("%s\n", arr2);            //���������Ľ��
//	return 0;
//}


//             5����д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼����
//		��ֻ���������������룬���������ȷ����ʾ��¼�ɹ������������������˳�����


//int main()
//{
//	int i = 0;
//	int password = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:>");
//		scanf("%d",&password);     //�������ͱ��봫ȡ��ַ���ţ��ַ����Ͳ�Ҫ��ȡ��ַ����
//		if (password == 123456))
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("�����������������˳�����\n");
//	}
//	return 0;
//}