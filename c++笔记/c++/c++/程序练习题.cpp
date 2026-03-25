#include<iostream>
using namespace std;

//30页
//第五题
//int main()
//{
//	int i;
//	for (i = 0; i <= 10; i++)
//	{
//		cout << "我努力，第" << i << "天" << endl;
//	}
//	cout << "一分耕耘，一份收获，我成功了！" << endl;
//	return 0;
//}



//第六题
//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j < 10; j++)
//			cout << j << "*" << i << "=" << j * i << " \t";
//		cout << endl;
//
//	}
//	return 0;
//}


//49页
#include<iomanip>  //精确小数点后几位函数所需的头文件
//fixed<<setprecision(需要精确的位数)<<
//int main()
//{    //const用于锁定变量的值，更安全
//	const float PI = 3.1415926;
//	const float RAILING_PRICE = 35;
//	const float TILE_PRICE = 20;
//	float rad,railingTotal,tileTotal;
//	cout << "请输入泳池的半径：";
//	cin >> rad;
//	railingTotal = RAILING_PRICE * 2 * PI * rad;
//	tileTotal = TILE_PRICE * (PI * (rad + 3) * (rad + 3) - PI * rad * rad);
//	cout << "栏杆的价格是；" << fixed << setprecision(2) << railingTotal << "元" << endl;
//	cout << "地砖的价格是: " << fixed << setprecision(2) << tileTotal << "元" << endl;
//	return 0;
//}



//57页
//int main()
//{
//	int year;
//	cout << "输入年份：";
//	cin >> year;
//	cout << year << "年是" << ((year % 100 != 0 && year % 4 == 0 || year % 400 == 0) ? "闰年" : "平年") << endl;
//	//!=表示不等于，&&表示并且 ,||表示或者 ，满足条件返回第一个""中的内容。 注意格式
//	return 0;
//}



//58页
//条件语句
//int main()
//{
//	int a, b;
//	cout << "请输入a和b的值：";
//	cin >> a >> b;
//	cout << "a+|b|=" << (b > 0 ? a + b : a - b);
//	//当b>0输出a+b，反之
//	return 0;
//}

//等价于
//int main()
//{
//	int a, b;
//	cout << "请输入a和b的值：";
//	cin >> a >> b;
//	if (b > 0)
//	{
//		cout << "a+|b|=" << a + b;
//	}
//	else
//	{
//		cout << "a+|b|=" << a - b;
//	}
//	return 0;
//
//}


//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	int a, b;
//	cout << "输入变量a和b的值：";
//	cin >> a >> b;
//	cout << "交换前a=" << a << ",b=" << b << endl;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	cout << "=====================" << endl;
//	cout << "交换后a=" << a << ",b=" << b << endl;
//	return 0;
//}




//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	
//	string userName = "";
//	string passWord = "";
//	cout << "请输入账号和密码：";
//	cin >> userName;
//	cin >> passWord;
//	if (userName == "张三" && passWord == "123456")
//	{
//		cout << "登陆成功!" << endl;
//	}
//	else
//	{
//		if (userName == "张三")
//		{
//			cout << "密码错误" << endl;
//		}
//		else 
//		{
//			cout << "账号错误" << endl;
//		}
//	}
//	return 0;
//}



#include<windows.h>
int main()
{
	string name;
	string id;
	cout << "请输入姓名：";
	cin >> name;
	cout << "身份证号码：";
	cin >> id;
	cout << "****************************" << endl;
	cout << "姓   名：" << name << endl;
	cout << "身份证号：" << id << endl;
	cout << "出生年月:" << id.substr(6, 4) << "年" << id.substr(10, 2) << "月" << id.substr(12, 2) << "日" << endl;
	string year;
	year = id.substr(6, 4);
	SYSTEMTIME st;
	GetLocalTime(&st);
	int iyear = atoi(year.c_str());
	cout << "年   龄：" << st.wYear - iyear << endl;
	return 0;
}