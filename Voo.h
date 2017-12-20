#ifndef VOO_H
#define VOO_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Passenger.h"
#include "Date.h"
#include "Plane.h"

using namespace std;



class Voo
{

	Date data_partida;
	Plane* plane;
	vector <Passenger *> Passengers;    
	int lugares_ocupados;
	float preco_inicial;
	static int idC, idA;

public:

	Voo(Plane* plane, Date data_partida, float preco);//posteriormente adicionar aeroporto de partida/chegada

	virtual ~Voo();

	/**
	 * @brief Obtaining the occupation of the Voo in percentage
	 *
	 * @return Percentage of taken seats (float)
	 */
	virtual float ocupacao_Voo_percent() =0;

	virtual void ocupar_vooInteiro();

	/**
	 * @brief Gets Voo's id
	 *
	 * @return oVoo's id (string)
	 */
	virtual string getId_voo() const =0;

	/**
	 * @brief Obtaining the filght's destination
	 *
	 * @return the destination of the Voo (string)
	 */
	virtual string getDestino() const =0;

	/**
	 * @brief Obtaining the filght's Origin
	 *
	 * @return the origin of the Voo (string)
	 */
	virtual string getPartida() const =0;

	/**
	 * @brief Obtaining the filght's departure date
	 *
	 * @return the time of the flight(Date class)
	 */
	Date getDate() const;

	/**
	 * @brief Adds a passeger to the Voo (a seat is taken)
	 *
	 * @param A passager object (Passenger)
	 */
	void adicionarPassenger(Passenger * p);

	/**
	 * @brief Retrieves a passeger from the Voo (seat becomes empty)
	 *
	 * @param A passager object (Passenger)
	 */
	void removerPassenger(Passenger *p);

	/**
	 * @brief Function gets occupied seats of the Voo
	 *
	 * @return number of taken seats (int)
	 */
	int getLugares_ocupados() const;

	/**
	 * @brief Function's purpose is getting the number of non-taken seats of a Voo
	 *
	 * @return number of empty seats (int)
	 */
	int No_lugares_vazios() const;

	float getPrecoInicial() const;

	//fazer documentacao
	int getIdC() const;

	int getIdA() const;

	void incrementIdC();

	void incrementIdA();
	Plane* getPlane();

	void setLugaresocupados(int l);


	vector <Passenger *> getPassengers() const;
};


class VooComercial: public Voo
{
	string partida, destino;
	string id_voo;

public:
	VooComercial(Plane* Plane,Date data_partida, float preco,string partida, string destino);
	~VooComercial() ;
	/**
	* @brief Generates an ID for a Comercial Voo e.g. "COM a984"
	*/
	void setId_vooC();
	float ocupacao_Voo_percent() ;



	string getId_voo() const;
	string getDestino() const;
	string getPartida() const;
};


class VooAlugado: public Voo
{
	string partida, destino;
	string id_voo;

public:
	VooAlugado(Plane* Plane, Date data_partida, float preco, string partida, string destino);
	~VooAlugado();

	/**
	* @brief Generates an ID for Rented Voo e.g. "ALU y652"
	*/
	void setId_vooA();

	float ocupacao_Voo_percent() ;
	void ocupar_vooInteiro();

	string getId_voo() const;
	string getPartida() const;
	string getDestino() const;
};


# endif
