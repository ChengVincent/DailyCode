#ifndef _HEAD_H_
#define _HEAD_H_

#include<iostream>
#include<assert.h>
using namespace std;

class Base
{
public:
	Base()
		:_d1(0)
	{
		cout << "this is Base constructor(无参)" << endl;
	}

	Base(int t1)
		:_d1(t1)
	{
		cout << "this is Base construtor(有参数)" << endl;
	}


	Base(Base &b1)
		:_d1(b1._d1)
	{
		cout << "this is Base Copy constructor" << endl;
	}

	Base& operator=(Base &b1)
	{
		_d1 = b1._d1;
		cout << "this Base operator=" << endl;
		return *this;
	}

protected:
	int _d1;
};


class Drived
{
public:
	Drived(Base &b1)
		//:_d1(b1)
	{
		_d1=b1;
		cout << "this is Drived copy constructor" << endl;
	}
protected:
	Base _d1;
};

#endif