#ifndef PLANE_H
#define PLANE_H

#include <string>
#include "Date.h"
#include <ctime>

using namespace std;

class Plane {

	Date lastCheckUp, nextCheckUp;
	unsigned int checkUpRoutine;

	unsigned int ID;
	unsigned int capacity;
	string model;
	string location;
	bool alocated=false;
	
public:
	static unsigned int globalID_p;
	Plane(unsigned int capacity, string model, string location, Date lastCheck, unsigned int days_until_check);
	Plane();
	unsigned int getID() const;
	unsigned int getCapacity() const;
	string getModel() const;
	string getLocation() const;
	bool getAlocated() const;
	Date getlastCheckUp() const;
	Date getnextCheckup() const;
	unsigned int getcheckUpRoutine() const;


	
	void setID(unsigned int id);
	void setCapacity(unsigned int capacity);
	void setModel(string model);
	void setLocation(string location);
	void setAlocated(bool aloc);
	void setcheckUpRoutine(unsigned int c);
	void setnextCheckup(Date d) ;
	void setlastCheckup(Date d) ;

	void increaseGlobalID();

	void calculateNextCheckup(); //ver qual a melhor opçao aqui, se void ou Date
	unsigned int funcao_aux(unsigned int &d, unsigned int &m,unsigned int &y, unsigned int next);


	bool operator < (const Plane & p) const
	{
		time_t t = time(0);
		struct tm * now = localtime( & t );
		Date curr(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
		return (time_untilCheck(nextCheckUp, curr)) < (time_untilCheck(p.nextCheckUp, curr)); }
	bool operator == (const Plane & p) const
	{ time_t t = time(0);
	struct tm * now = localtime( & t );
	Date curr(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	return (time_untilCheck(nextCheckUp, curr)) == (time_untilCheck(p.nextCheckUp, curr));  }

};

#endif
