
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

bool DATE::operator>(DATE d)   //�õ��ֶ�^-^
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
	DATE temp=*this;   //��������
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
	if (day < 1)   //ע����С��
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
	os << d._year<<"��" << d._month<<"��" << d._day<<"��" << endl;
	return os;
}


istream & operator>> (istream& is, DATE& d)
{
	cout << " ��ֱ����������գ� " << endl;
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
		cout << "       ���ڼ�����     " << endl;
		cout << "1>�����������㼸���Ժ���ʲô����" << endl;
		cout << "2>�����������ڼ���ʱ���" << endl;
		cout << "3>�˳�" << endl;
		cout << "������>";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			system("cls");
			cout << "�������ʼ����->";
			cin >> d1;
			cout << "����������" << endl;
			cin >> day;
			cout << day << "�����" << (d1 + day) << endl;
			cout << "��������˻�������" << endl;
			_getch();
			; break;
		case 2:
			system("cls");
			cout << "�������һ������->";
			cin >> d1;
			cout << "������ڶ�������->";
			cin >> d2;
			cout<<"���"<<HowDay(d1, d2)<<"��"<<endl;
			cout << "�����������������" << endl;
			_getch();
			break;
		case 3:return 0; break;
		default:break;
		}
		system("cls");
	}
	return 0;
}
