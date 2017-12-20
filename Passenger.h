#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

#include "Date.h"

using namespace std;

class Passenger {

	static unsigned int globalIDcartao, globalIDocasional;
	string name;
	Date birthday;

public:

	
	Passenger(string nome, Date birthday);
	virtual ~Passenger();


	string getName() const;
	Date getBirthday() const;
	unsigned int getIdCartao() const;
	unsigned int getIdOcasional() const;

	void setBirthday(Date birthday);
	void setName(string name);



	void incrementIdCartao();
	void incrementIdOcasional();

	virtual void setAnnualVoos(unsigned int annualVoos){};
	virtual string getID() const=0;
	virtual string getProfession()const ;
	virtual unsigned int getAnnualVoos()const  ;
	virtual bool isMember()const = 0;



};

class Passenger_comCartao:public Passenger{

	string profession;
	unsigned int annualVoos;
	string id;


public:
	Passenger_comCartao(string name, string profession, Date birthday, unsigned int annualVoos);
	~Passenger_comCartao();

	string getProfession() const;
	unsigned int getAnnualVoos() const;
	string getID() const;

	void setProfession(string profession);
	void setAnnualVoos(unsigned int annualVoos);

	bool  isMember()const;

};

class Passenger_ocasional:public Passenger{

	string id;
public:
	Passenger_ocasional(string name, Date birthday);
	~Passenger_ocasional();



	bool isMember()const;

	string getID() const;

};


#endif
