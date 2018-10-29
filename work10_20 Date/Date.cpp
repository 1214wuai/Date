#include"Date.h"

bool Date:: operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day == d._day)
				return true;
		}
	}
	return false;
}
void Date::Print()
{
	printf("%d-%d-%d\n", _year, _month, _day);
}
bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}
bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year&&
		_month == d._month&&
		_day == d._day;
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

int Date::GetMonthDay(int year, int month)
{
	static const int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//放在静态区，每次访问就不需要创建
	if ((month==2)&&(year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)//自转23多个小时
	{
		return 29;
	}
	return monthDay[month];
}

//d1+100，d1没后改变
Date Date::operator+(int day)const
{
	//Date ret(*this);
	//ret._day += day;
	//while (ret._day > GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	++ret._month;
	//	if (ret._month == 13)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//}
	//return ret;

	Date ret = *this;//此处复用+=函数
	ret = *this + day;
	return ret;
}

//d1+=100,把d1改变了
//d1-=100
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month+=1;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;

	//*this = *this + day;
	//return *this;
}
Date Date::operator-(int day)const
{
	/*Date ret = *this;
	ret._day -= day;
	while (ret._day<0)
	{
		ret._day = GetMonthDay(ret._year, ret._month);
		ret._month--;
		if (ret._month == 0)
		{
			ret._month = 12;
			ret._year--;
		}
	}
	return ret;*/


	Date ret = *this;//此处复用-=函数
	ret = *this - day;
	return ret;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
		
	}
	return *this;
}

int Date::operator-(const Date& d)//日期减日期
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min < max)
	{
		++min;
		++n;
	}
	return n * flag;
}

//以下四个函数有重载
//前置：返回的值是加加以后的值
//后置：返回的值是加加以前的值
Date& Date::operator++()//++d   d.operator++(&d)
{
	*this += 1;
	return *this;

	
}
Date Date::operator++(int)//d++  d.operator(&d,0)
{
	Date ret(*this);//拷贝构造一个对象
	*this += 1;
	return ret;
}
Date& Date::operator--()//--d   d.operator++(&d)
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)//d--  d.operator(&d,0)
{
	Date ret(*this);
	*this += 1;
	return ret;
}
int GetMonthDay(int year, int month)
{
	return 0;
}