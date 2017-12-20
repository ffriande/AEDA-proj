#ifndef PLANE_H
#define PLANE_H

#include<string>
#include "Date.h"

using namespace std;

class Plane {

	Date lastCheckUp, nextCheckUp;
	unsigned int checkUpRoutine;
	static unsigned int globalID;
	unsigned int ID;
	unsigned int capacity;
	string model;
	string location;
	bool alocated=false;
	
public:
	Plane(unsigned int capacity, string model, string location, Date lastCheck, unsigned int days_until_check);
	//Plane();
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


	void calculateNextCheckup(); //ver qual a melhor opçao aqui, se void ou Date
	unsigned int funcao_aux(unsigned int &d, unsigned int &m,unsigned int &y, unsigned int next);


	bool operator < (const Plane & p) const
	{ return checkUpRoutine < p.checkUpRoutine; }
	bool operator == (const Plane & p) const
	{ return checkUpRoutine == p.checkUpRoutine; }

};

#endif
