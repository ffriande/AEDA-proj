#ifndef RESERVATION_H
#define RESERVATION_H

//#include "Voo.h"
#include "Voo.h"
#include "Date.h"
#include "Passenger.h"

using namespace std;

class Reservation
{
	static unsigned int globalID;
	unsigned int id;
	//float initialPrice;
	double purchasePrice;
	string vooID, origin, destination;
	Passenger* passID;
	///
	string orig;
	string dest;


public:

	Reservation(double purchasePrice,string vooid, string orig,string dest,Passenger *p);
	Reservation();

	unsigned int getID() const;
	//float getInitialPrice() const;
	double getPurchasePrice() const;

	Passenger* getPassID() const;
	string getVooID() const;

	void setPurchasePrice(double purchasePrice);

//	void setPassID(Passenger passID);
	bool isAlugado() const;

	string getDest() const{return this->dest;};
	string getOrig() const{return this->orig;};

};



#endif
