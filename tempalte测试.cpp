#include<iostream>
using namespace std;

template<class T1,class T2>
class Test
{
public:
	Test(T1 newValue1, T2 newValue2)
		:value1(newValue1)
		, value2(newValue2)
	{
		cout << "模板类template<class T1,class T2>" <<endl;
	}
private:
	T1 value1;
	T2 value2;
};

//全特化
template<>
class Test<int,char>
{
public:
	Test(int newValue1, char newValue2)
		:value1(newValue1)
		, value2(newValue2)
	{
		cout << "全特化模板类template<>" << endl;
	}
private:
	int value1;
	char value2;
};

//偏特化
template<class T1>
class Test<T1, int>
{
public:
	Test(T1 newValue1, int newValue2)
		:value1(newValue1)
		, value2(newValue2)
	{
		cout << "偏特化模板类template<>" << endl;
	}
private:
	T1 value1;
	int value2;
};

int main()
{
	//全特化部分
	Test<int, char> T1(20, 's');
	//偏特化部分
	Test<int,int> T2(20, 50);
	Test<char,int> T3('s', 50);
	Test<double, int> T4(4.0, 50);
	//正常模板类
	Test<char, char> T5('s', 's');

	return 0;
}