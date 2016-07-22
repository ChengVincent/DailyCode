
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class DATE
{
public:

	DATE(int year=1900,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	DATE (DATE &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	int GetMonthDay(int year,int month);
	bool operator>(DATE d);
	bool operator==(DATE d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator<(DATE d)
	{
		return !((*this>d) || (*this == d));
	}
	bool operator<=(DATE d)
	{
		return !(*this > d);
	}
	bool  operator>=(DATE d)
	{
		return !(*this < d);
	}
	DATE operator+(int day);
	DATE operator-(int day);
	DATE operator++(int)
	{
		return (*this + 1);
	}
	DATE operator--(int)
	{
		return (*this - 1);
	}


	friend ostream & operator<< (ostream& os, const DATE& d);
	friend istream & operator>> (istream& is, DATE& d);

	DATE& operator=(DATE d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	friend int HowDay(DATE d1, DATE d2);

private:
	int _year;
	int _month;
	int _day;
	static int monthTable[13];
};

int DATE::monthTable[13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};

bool DATE::operator>(DATE d)   //好的手段^-^
{
	return (_year > d._year
		|| (_year == d._year && _month > d._month)
		|| (_month == d._month && _day > d._day));
}

DATE DATE::operator+(int day)
{
	if (day<0)
	{
		return (*this - (-day));
	}
	DATE temp=*this;   //定义在哪
	temp._day += day;
	while (temp._day > GetMonthDay(temp._year, temp._month))
	{
		temp._day -= GetMonthDay(temp._year, temp._month);
		if (temp._month == 12)
		{
			temp._month = 1;
			temp._year += 1;
		}
		else
		{
			temp._month += 1;
		}
	}
	return temp;
}

DATE DATE::operator-(int day)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
{
	if (day < 1)   //注意最小月
	{
		return (*this + (-day));
	}
	DATE temp = *this;
	temp._day -= day;
	while (temp._day < 0)
	{

		if (temp._month == 1)
		{
			temp._year -= 1;
			temp._month = 12;
		}
		else
		{
			temp._month -= 1;
		}
		temp._day += GetMonthDay(temp._year, temp._month);
	}
	return temp;
}

int DATE::GetMonthDay(int year,int month)
{
	if (month == 2)
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			return monthTable[0];
		else
			return monthTable[2];
	}
	else
	{
		return monthTable[month];
	}
}

ostream & operator<<(ostream& os, const DATE& d)
{
	os << d._year<<"年" << d._month<<"月" << d._day<<"日" << endl;
	return os;
}


istream & operator>> (istream& is, DATE& d)
{
	cout << " 请分别输入年月日： " << endl;
	is >> d._year;
	is >> d._month;
	is >> d._day;

	return is;
}

int HowDay(DATE d1,DATE d2)
{
	int day = 0;
	if (d1 > d2)
	{
	return	HowDay(d2, d1);
	}
	while (!(d1 == d2))
	{
		d1 = (d1 + 1);
		day++;
	}
	return day;
}




int main()
{
	while (1)
	{
		DATE d1;
		DATE d2;
		int day = 0;
		cout << "       日期计算器     " << endl;
		cout << "1>输入天数计算几天以后是什么日子" << endl;
		cout << "2>输入两个日期计算时间差" << endl;
		cout << "3>退出" << endl;
		cout << "请输入>";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			system("cls");
			cout << "请输入初始日期->";
			cin >> d1;
			cout << "请输入天数" << endl;
			cin >> day;
			cout << day << "天后是" << (d1 + day) << endl;
			cout << "按任意键退回主界面" << endl;
			_getch();
			; break;
		case 2:
			system("cls");
			cout << "请输入第一个日子->";
			cin >> d1;
			cout << "请输入第二个日子->";
			cin >> d2;
			cout<<"相差"<<HowDay(d1, d2)<<"天"<<endl;
			cout << "按任意键返回主界面" << endl;
			_getch();
			break;
		case 3:return 0; break;
		default:break;
		}
		system("cls");
	}
	return 0;
}
