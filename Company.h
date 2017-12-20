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
	//vector<Plane*> planes;
	BST<Plane*> planes;
	bool lastminuteDesconto=false;

	public:
	Company ();
	~Company ();

	vector<unsigned int> decomposeStringData(string linebirthday);

	void actualizarMemPasstxt();
	void actualizarFlightstxt();
	void actualizarCasPasstxt();
	void actualizarComResertxt();
	void actualizarAluResertxt();
	void setName(string name);

	string getName() const;
	vector<Passenger*> getPassengers();				///vector de passengers
	vector<Voo*> getVoos();
	vector<Reservation> getReservations();						///vector de reservas
	vector<Plane*> getPlanes();

	int searchPassengersIDmem(string pass);
	int searchPassengersID(string pass);
	int searchVoostr(string vooid);
	int searchPlaneID(unsigned int planeid);


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
	void loadPlanes();								///l� avioes do ficheiro
	void addPlane(Plane* plane);							///adiciona Plane
	void seeAllPlanes();
	void createPlane();
	void planeCheckup();
	void showPlanes_nextdays(int days); //fazeeer
	void showPlanes_ordered(); //fazeeer
	void doCheckUp(Plane* plane); //fazeerr
	void set_newCheckUpTime(Plane* plane, Date d); //fazeeer


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
