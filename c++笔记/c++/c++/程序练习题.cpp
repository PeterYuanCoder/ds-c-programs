#include<iostream>
using namespace std;

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
int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
			cout << j << "*" << i << "=" << j * i << " \t";
		cout << endl;

	}
	return 0;
}