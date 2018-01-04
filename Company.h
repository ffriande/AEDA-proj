#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include "Reservation.h"
#include "Plane.h"
#include "Passenger.h"
#include "BST.h"
#include <unordered_set>

#include "Voo.h"
#include "Date.h"
#include <vector>

#include <algorithm>
#include <queue>
#include "Operator.h"
using namespace std;

class Passenger_inativo{
	Passenger* passenger;
public:
	Passenger_inativo(){passenger=NULL;};
	Passenger_inativo(Passenger* p);
	Passenger* getPassenger() const{return passenger;};

};

struct HashFunction{
	int operator() (const Passenger_inativo &p) const{
		int key=1;
		string id=p.getPassenger()->getID();
		for ( unsigned int i=0; i< id.size(); i++ )
			key = key + id[i];
		return key;
	}
};
struct HashEq {
	bool operator()(const Passenger_inativo &p1, const Passenger_inativo &p2) const {
	if((p1.getPassenger()->getID()==p2.getPassenger()->getID())&&
			(p1.getPassenger()->getName()==p2.getPassenger()->getName()))
			return true;

	else return false;
	}
	};


typedef unordered_set<Passenger_inativo,HashFunction,HashEq> passHash;
typedef unordered_set<Passenger_inativo,HashFunction,HashEq>::iterator hashItr;


typedef priority_queue<Operator> HEAP_OPERATOR;

class Company {
	Date currDate;
	string nome;
	vector<Passenger*> passengers;      ////A COMPANHIA GUARDA OS DADOS, TANTO DOS PASSAGEIROS REGISTADOS COMO OCASIONAIS
	vector<Voo*> voos;
	vector<Reservation> reservations;
	BST<Plane> planes;
	bool lastminuteDesconto=false;
	passHash inactive;

    HEAP_OPERATOR operators;

	public:
	Company();
	~Company ();

	vector<unsigned int> decomposeStringData(string linebirthday);

	void actualizarMemPasstxt();
	void actualizarFlightstxt();
	void actualizarCasPasstxt();
	void actualizarComResertxt();
	void actualizarAluResertxt();
	void setName(string name);

	string getName() const;
	vector<Passenger*> getPassengers() const;				///vector de passengers
	vector<Voo*> getVoos() const;
	vector<Reservation> getReservations() const;						///vector de reservas
	BST<Plane> getPlanes() const;
	passHash getInactive() const;


	int searchPassengersIDmem(string pass);
	int searchPassengersID(string pass);
	int searchVoostr(string vooid);
	Plane searchPlaneID(unsigned int planeid);
	Plane searchPlane_origin(string origin);
	Passenger* searchPassengerInactivo(string id) ;


	////////////////passengers////////////////
	void loadPassengers();							///carrega de um txt a lista de todos os passengers da Company socios e nao socios
	void loadPassengersCasual();
	void addPassenger(Passenger* Passenger);			///adiciona um Passenger a lista de passengers da Company
	void showPassagengers() const;
	void creatPassenger();								///cria um Passenger
	void seeallMembers();								///ver todos os socios da Company
	void elimPassenger();							///elimina um Passenger da lista de passengers
	void changedataPassenger();



	//////////////////RESERVATIONS////////////////
	void loadReservations();	
	void loadReservationsALU();
	void addReservation(Reservation reserv);

	void doReservation();
	double precoReserva(double precoOrig, bool socio, int mediavoos, float ocupPercent, bool menos_48h, Passenger* passID);
	double precoReserva(double precoOrig, bool socio, float ocupPercent, bool menos_48h);
	void lastminuteDiscount(bool t);

	//////////////////PLANES//////////////////////
	void loadPlanes();								///l� avioes do ficheiro
	void addPlane(Plane plane);							///adiciona Plane
	void seeAllPlanes();
	void createPlane();

	//funcoes do menu
	void showPlanes_nextdays(unsigned int days);
	void showPlanes_ordered();
	void doCheckUp(Plane plane);
	void set_newCheckUpTime(Plane plane, Date d);
	void showPlanes_nextdate(Date d) ;

	unsigned int input_no_ofdays();
	Date input_date();
	Plane input_planeid();

	/////////////////////VooS///////////////////////

	void loadVoos();
	void seeAllVoos();
	void addVoo(Voo* voo);
	void createVoo();
	void reservationPlane();


	///////////////////DATE///////////
	Date getcurrDate();

	//// OPERATORS///

	//// operator menu ///

    void list_operators();

    void add_new_operator();

    void edit_operator();

    void removeOperator();
  	void add_operator();

  	Operator findOperator(string name );
  	//todo menu editar
  	//todo menu remover
  	//todo load

    Operator findOperator(Plane p);
    bool checkModelMatch(string model, vector<string> models);

    void add_plane_to_operator(Plane p );






	void updatecurrDate();

	bool lessthan48(Date a,Date b); //a is the time of the flight and b is the current time

	//////////////INACTIVOS/////////////////
	void printHash();
	void insereHash();
};

#endif
