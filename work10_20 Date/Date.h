#pragma once
#include<iostream>
using namespace std;


class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1900, int month = 1,int day = 1)
	{
		if (year >= 0
			&& month > 0 && month < 13 &&
			day>0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
	}
	Date(const Date& d)//拷贝
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)//运算符重载
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//~Date();//析构函数
	inline bool operator>(const Date& d) const;
	inline bool operator<(const Date& d)const;
	inline bool operator>=(const Date& d)const;
	 bool operator<=(const Date& d)const;
	inline bool operator==(const Date& d)const;
	 bool operator!=(const Date& d)const;
	//缺省只在声明写，不在定义写
	Date operator+(int day)const;
	Date& operator+=(int day);
	Date operator-(int day)const;
	Date& operator-=(int day);

	int operator-(const Date& d);//日期减日期
	
	//函数重载，编译器区分前置++和后置++的方式，后置加加多传一个参数
	Date& operator++();//++d   d.operator++(&d)
	Date operator++(int);//d++  d.operator(&d,0)
	Date& operator--();//--d   d.operator++(&d)
	Date operator--(int);//d--  d.operator(&d,0)
	inline int GetMonthDay(int year, int month);//内联

	void Print();
};