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


unsigned int time_untilCheck(const Date d, const Date curr) { //para aplicar d-->nextCheck - curr-->currTime

	unsigned int month, day, year, ret = 0;
		month = curr.getMonth();
		day = curr.getDay();
		year = curr.getYear();

		while (day != d.getDay() || month != d.getMonth() || year != d.getYear()) {
			if (d.getDay() > day) {
				ret += (d.getDay() - day);
				day += (d.getDay() - day);}
			else if (d.getDay() < day) {
				switch (month) {
				case 1:
					ret += (31 - day) + 1;
					day = 0;
					month++;
					break;
				case 2:
					ret += (28 - day) + 1;
					day = 0;
					month++;
					break;
				case 3:
					ret += (31 - day) + 1;
					day = 0;
					month++;
					break;
				case 4:
					ret += (30 - day) + 1;
					day = 0;
					month++;
					break;

				case 5:
					ret += (31 - day) + 1;
					day = 0;
					month++;
					break;
				case 6:
					ret += (30 - day) + 1;
					day = 0;
					month++;
					break;
				case 7:
					ret += (31 - day) + 1;
					day = 0;
					month++;
					break;
				case 8:
					ret += (31 - day) + 1;
					day = 0;
					month++;
					break;
				case 9:
					ret += (30 - day) + 1;
					day = 0;
					month++;
					break;
				case 10:
					ret += (31 - day) + 1;
					day = 0;
					month++;
					break;
				case 11:
					ret += (30 - day) + 1;
					day = 0;
					month++;
					break;
				case 12:
					ret += (31 - day) + 1;
					day = 0;
					month=1;
					year++;
					break;

				}

			}

			else {
				switch (month) {
				case 1:
					ret += 31;
					month++;
					break;
				case 2:
					ret += 28;
					month++;
					break;
				case 3:
					ret += 31;
					month++;
					break;
				case 4:
					ret += 30;
					month++;
					break;

				case 5:
					ret += 31;
					month++;
					break;
				case 6:
					ret += 30;
					month++;
					break;
				case 7:
					ret += 31;
					month++;
					break;
				case 8:
					ret += 31;
					month++;
					break;
				case 9:
					ret += 30;
					month++;
					break;
				case 10:
					ret += 31;
					month++;
					break;
				case 11:
					ret += 30;
					month++;
					break;
				case 12:
					ret += 31;
					month=1;
					year++;
					break;

				}

			}
		}
		return ret;
}








