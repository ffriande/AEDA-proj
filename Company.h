#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include "Reservation.h"
#include "Plane.h"
#include "Passenger.h"
#include "BST.h"

#include "Voo.h"
#include "Date.h"
#include <vector>

using namespace std;


class Company {
	Date currDate;
	string nome;
	vector<Passenger*> passengers;      ////A COMPANHIA GUARDA OS DADOS, TANTO DOS PASSAGEIROS REGISTADOS COMO OCASIONAIS
	vector<Voo*> voos;
	vector<Reservation> reservations;
	BST<Plane> planes;
	bool lastminuteDesconto=false;
	//unsigned int globalID_p;

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

	int searchPassengersIDmem(string pass);
	int searchPassengersID(string pass);
	int searchVoostr(string vooid);
	Plane searchPlaneID(unsigned int planeid);
	Plane searchPlane_origin(string origin);


	////////////////passengers////////////////
	void loadPassengers();							///carrega de um txt a lista de todos os passengers da Company socios e nao socios
	void loadPassengersCasual();
	void addPassenger(Passenger* Passenger);			///adiciona um Passenger a lista de passengers da Company
	void showPassagengers() const;
	void creatPassenger();								///cria um Passenger
	void seeallMembers();								///ver todos os socios da Company
	void elimPassenger();							///elimina um Passenger da lista de passengers
	void changedataPassenger();							///muda dados de um Passenger, podendo este tornar se um socio ou mesmo deixar de o ser



	//////////////////RESERVATIONS////////////////
	void loadReservations();	
	void loadReservationsALU();
	void addReservation(Reservation reserv);
	void seeallReservations();

	void doReservation();

	double precoReserva(double precoOrig, bool socio, int mediavoos, float ocupPercent, bool menos_48h, Passenger* passID);
	double precoReserva(double precoOrig, bool socio, float ocupPercent, bool menos_48h);
	void lastminuteDiscount(bool t);

	//////////////////PLANES//////////////////////
	void print_availablePlanes();
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
	void allVoos();
	void addVoo(Voo* voo);
	void createVoo();
	void reservationPlane();


	///////////////////DATE///////////
	Date getcurrDate();



	void updatecurrDate();

	bool lessthan48(Date a,Date b); //a is the time of the flight and b is the current time


};
#endif
