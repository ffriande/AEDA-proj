#include "Reservation.h"
unsigned int Reservation::globalID=0;

Reservation::Reservation(double purchasePric, string vooID, string origin, string destination, Passenger* p)  //tirei rvsid e float initialPrice,
{

	this->id = globalID++;				//adicionei
	this->passID=p;							//adicionei
	this->vooID=vooID;							//adicionei
	this->origin=origin;							//adicionei
	this->destination=destination;
	this->purchasePrice=purchasePric;


}


Passenger* Reservation::getPassID() const              ////adicionei
{
	return passID;
}

unsigned int Reservation::getID() const {
	return id;
}


double Reservation::getPurchasePrice() const {
	return purchasePrice;
}



void Reservation::setPurchasePrice(double purchaseprice) {
	this->purchasePrice=purchaseprice;
}





string Reservation::getVooID() const{
	return  this->vooID;
}




bool Reservation::isAlugado() const{
	if  (vooID.substr(0, 3) == "ALU")
	return true;
	else return false;
}
