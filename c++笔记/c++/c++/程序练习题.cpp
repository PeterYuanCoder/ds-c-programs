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
int main()
{    //const用于锁定变量的值，更安全
	const float PI = 3.1415926;
	const float RAILING_PRICE = 35;
	const float TILE_PRICE = 20;
	float rad,railingTotal,tileTotal;
	cout << "请输入泳池的半径：";
	cin >> rad;
	railingTotal = RAILING_PRICE * 2 * PI * rad;
	tileTotal = TILE_PRICE * (PI * (rad + 3) * (rad + 3) - PI * rad * rad);
	cout << "栏杆的价格是；" << fixed << setprecision(2) << railingTotal << "元" << endl;
	cout << "地砖的价格是: " << fixed << setprecision(2) << tileTotal << "元" << endl;
	return 0;
}
int main()