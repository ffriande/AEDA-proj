#include<iostream>
#include "Date.h"


unsigned int Date::getDay( ) const
{
		return day;
}

unsigned int Date::getMonth( ) const
{
		return month;
	} 


unsigned int Date::getYear( ) const
{
		return year;
	}


unsigned int Date::getHour( ) const
{
		return hour;
	}


unsigned int Date::getMinutes( ) const
{
		return minutes;
	}



void Date::setDay(unsigned int d)
{
	if (d < 1 || d > 31)
		cerr << "The day is invalid" << endl;
	else
	this->day = d;

}
void Date::setMonth(unsigned int m)
{
	if (m < 1 || m > 12)
		cerr << "The month is invalid" << endl;
	else
	this->month = m;

}
void Date::setYear(unsigned int y)
{
	if (y < 1900 || y > 2050)
		cerr << "The year is invalid" << endl;
	else
	this->year = y;
}

void Date::setHour(unsigned int h)
{
	if (h < 0 || h > 23)
		cerr << "The hour is invalid" << endl;
	else
	this->hour = h;

}
void Date::setMinutes(unsigned int min)
{
	if (min < 0 || min> 59)
		cerr << "The hour is invalid" << endl;
	else
	this->minutes = min;
}

Date::Date(unsigned int d,unsigned int m,unsigned int y, unsigned int h, unsigned int minutos)
{
	day=d;
	month=m;
	year=y;
	hour=h;
	minutes=minutos;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	this->day=day;
	this->month=month;
	this->year=year;

}

Date::Date()
{
	this->day=0;
	this->minutes=0;
	this->hour=0;
	this->year=0;
	this->month=0;
}

std::ostream & operator<<(std::ostream &out, const InvalidYear &c) {
	cout << "Year Input " << c.year << " is invalid!\n";
	return out;
}
