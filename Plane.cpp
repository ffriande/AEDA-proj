#include "Plane.h"

unsigned int Plane::globalID=0;

Plane::Plane(unsigned int capacity, string model, string location, Date lastCheck, unsigned int days_until_check)
{
	this->capacity = capacity;
	this->model = model;
	this->location = location;
	this->ID=globalID++;
	this->alocated=false;
	this->checkUpRoutine=days_until_check;
	this->lastCheckUp=lastCheck;
	//this->nextCheckup=calculateNextCheckup();
	calculateNextCheckup();
}

/*Plane::Plane()					///adicionei
{

	this->capacity=capacity;
	this->capacity = capacity;
	this->model = model;
	this->location = location;
	this->ID=globalID++;
}*/


unsigned int Plane::getID() const {
	return ID;
}
unsigned int Plane::getCapacity() const {
	return capacity;
}
string Plane::getModel() const {
	return model;
}

string Plane::getLocation() const {
	return location;
}

void Plane::setCapacity(unsigned int capacity) {
	this->capacity = capacity;
}

void Plane::setModel(string model) {
	this->model = model;
}

void Plane::setLocation(string location) {
	this->location = location;
}

void Plane::setID(unsigned int id)     //adicionei
{
	this->ID=id;

}

void Plane::setAlocated(bool aloc){
	this->alocated=aloc;
}

bool Plane::getAlocated() const{
	return alocated;
}

/*

Date Plane::calculateNextCheckup(){

	unsigned int month, day, year, nextCheck=this->checkUpRoutine;
	month=lastCheckUp.getMonth();
	day=lastCheckUp.getDay();
	year=lastCheckUp.getYear();

	while(nextCheck!=0)
		nextCheck=funcao_aux(day,month,year,nextCheck);

	Date ret(day,month,year);
	return ret;

}
*/

void Plane::calculateNextCheckup(){

	unsigned int month, day, year, nextCheck=this->checkUpRoutine;
	month=lastCheckUp.getMonth();
	day=lastCheckUp.getDay();
	year=lastCheckUp.getYear();

	while(nextCheck!=0)
		nextCheck=funcao_aux(day,month,year,nextCheck);

	Date ret(day,month,year);
	this->nextCheckUp=ret;

}
unsigned int Plane::funcao_aux(unsigned int &d, unsigned int &m,
		unsigned int &y, unsigned int next) {

	switch (m) {
	case 1:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 2:
		if (next > 28 - d) {
			next -= (28 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 3:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 4:
		if (next > 30 - d) {
			next -= (30 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;

	case 5:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 6:
		if (next > 30 - d) {
			next -= (30 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 7:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 8:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 9:
		if (next > 30 - d) {
			next -= (30 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 10:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 11:
		if (next > 30 - d) {
			next -= (30 - d);
			m++;
			d = 0;
		} else {
			d += next;
			next = 0;
		}
		break;
	case 12:
		if (next > 31 - d) {
			next -= (31 - d);
			m++;
			d = 0;
			y++;
		} else {
			d += next;
			next = 0;
		}
		break;

	}
	return next;
}


Date Plane::getlastCheckUp() const{
	return this->lastCheckUp;
}
Date Plane::getnextCheckup() const{
	return this->nextCheckUp;
}
unsigned int Plane::getcheckUpRoutine() const{
	return this->checkUpRoutine;
}
void Plane::setnextCheckup(Date d) {
	this->nextCheckUp=d;
}
void Plane::setcheckUpRoutine(unsigned int c){
	this->checkUpRoutine=c;
}

void Plane::setlastCheckup(Date d) {
	this->lastCheckUp=d;
}

