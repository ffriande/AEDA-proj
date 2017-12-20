#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
private:
	unsigned int month, day, year;
	unsigned int hour, minutes;
public:

	Date(unsigned int day, unsigned int month, unsigned int year, unsigned int hour, unsigned int minutes);
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date();
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	unsigned int getHour() const;
	unsigned int getMinutes() const;

	void setDay(unsigned int day);
	void setMonth(unsigned int month);
	void setYear(unsigned int year);
	void setMinutes(unsigned int minutes);
	void setHour(unsigned int h);
	
	Date operator-(const Date&d){
		Date date;
		date.year=this->year-d.year;
		date.month=this->month-d.month;
		date.day=this->day-d.day;
		date.hour=this->hour-d.hour;
		date.minutes=this->minutes-d.minutes;
		return date;
	}
	
};

class InvalidYear{
public:
	unsigned int year;
	InvalidYear(unsigned int year){this->year=year;}
};

std::ostream & operator<<(std::ostream &out, const InvalidYear &c);

#endif
