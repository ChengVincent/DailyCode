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
		cout << "ģ����template<class T1,class T2>" <<endl;
	}
private:
	T1 value1;
	T2 value2;
};

//ȫ�ػ�
template<>
class Test<int,char>
{
public:
	Test(int newValue1, char newValue2)
		:value1(newValue1)
		, value2(newValue2)
	{
		cout << "ȫ�ػ�ģ����template<>" << endl;
	}
private:
	int value1;
	char value2;
};

//ƫ�ػ�
template<class T1>
class Test<T1, int>
{
public:
	Test(T1 newValue1, int newValue2)
		:value1(newValue1)
		, value2(newValue2)
	{
		cout << "ƫ�ػ�ģ����template<>" << endl;
	}
private:
	T1 value1;
	int value2;
};

int main()
{
	//ȫ�ػ�����
	Test<int, char> T1(20, 's');
	//ƫ�ػ�����
	Test<int,int> T2(20, 50);
	Test<char,int> T3('s', 50);
	Test<double, int> T4(4.0, 50);
	//����ģ����
	Test<char, char> T5('s', 's');

	return 0;
}