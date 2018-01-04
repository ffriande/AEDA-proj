#include "Passenger.h"
#include <sstream>

unsigned int Passenger::globalIDcartao=0;
unsigned int Passenger::globalIDocasional;


//PASSENGER//

string Passenger::getProfession()const {
	return "a";
}

unsigned int Passenger::getAnnualVoos() const{
	return 0;
}

Date Passenger::getLastPurchase() const{
	return Date();
}

Passenger::Passenger(string name, Date birthday) {
	this->name = name;
	this->birthday = birthday;
}


Passenger::~Passenger()
{
}

string Passenger::getName() const {
	return name;
}

Date Passenger::getBirthday() const { 
	return birthday;
}

void Passenger::setName(string name) {
	this->name = name;
}

void Passenger::setBirthday(Date birthday) {
	this->birthday = birthday;
}


	unsigned int Passenger::getIdCartao() const{
		return globalIDcartao;
	}

	unsigned int Passenger::getIdOcasional() const{
		return globalIDocasional;
	}

	void Passenger::incrementIdCartao(){
		globalIDcartao++;
	}
	void Passenger::incrementIdOcasional(){
		globalIDocasional++;
	}


//PASSAGEIROS COM CARTAO

	Passenger_comCartao::~Passenger_comCartao()
	{
	}

Passenger_comCartao::Passenger_comCartao(string name, string profession, Date birthday, unsigned int annualVoos, Date last):Passenger(name, birthday){
	this->annualVoos=annualVoos;
	this->profession=profession;
	stringstream ss;
	ss << getIdCartao();
	this->id= "MEM " + ss.str();
	incrementIdCartao();
	this->lastPurchase=last;
}

string Passenger_comCartao::getProfession() const {
	return profession;
}


unsigned int Passenger_comCartao::getAnnualVoos() const {
	return annualVoos;
}

void Passenger_comCartao::setProfession(string profession) {
	this->profession = profession;
}

void Passenger_comCartao::setAnnualVoos(unsigned int anualVoos) {
	this->annualVoos = anualVoos;
}


bool Passenger_comCartao::isMember() const {
	return true;
}


string Passenger_comCartao::getID() const{
	return id;
}



Date Passenger_comCartao::getLastPurchase() const{
	return this->lastPurchase;
}


void Passenger_comCartao::setLastPurchase(Date d){
	this->lastPurchase=d;
}
//PASSAGEIROS OCASIONAIS


Passenger_ocasional::~Passenger_ocasional()
	{
	}
Passenger_ocasional::Passenger_ocasional(string name, Date birthday):Passenger(name,birthday){

	stringstream ss;
	ss << getIdOcasional();
	this->id=ss.str();
	incrementIdOcasional();
}

bool Passenger_ocasional::isMember() const {
	return false;
}

string Passenger_ocasional::getID() const{
	return id;
}

