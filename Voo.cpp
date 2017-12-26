#include<iostream>
#include "Voo.h"



int Voo::idC=0;
int Voo::idA=0;


//VOO



Voo::Voo(Plane* planes, Date data_partida,  float preco)
{
	plane = planes;
	this->data_partida=data_partida;

	this->preco_inicial = preco;
	lugares_ocupados=0;
	planes->setAlocated(true);

}

Voo::~Voo() 
{
}

 void Voo::ocupar_vooInteiro() {}

void Voo::removerPassenger(Passenger *p){
	for(unsigned int i=0;i<Passengers.size();i++){
			if (p->getID()==Passengers[i]->getID()){
				Passengers.erase(Passengers.begin()+i);
				lugares_ocupados--;
			}
	}
}



void Voo::adicionarPassenger(Passenger * p) {
	this->Passengers.push_back(p);
	this->lugares_ocupados = lugares_ocupados + 1;
}


int Voo :: getLugares_ocupados() const
{
	return lugares_ocupados;
}

int Voo::No_lugares_vazios() const
{
	return (*plane).getCapacity() -lugares_ocupados;
}

Date Voo::getDate() const
{
	return this->data_partida;
}

float Voo::getPrecoInicial() const {
	return preco_inicial;
}



Plane* Voo::getPlane() {
	return plane;
	
}


void Voo::incrementIdC(){
	this->idC++;
}

void Voo::incrementIdA(){
	this->idA++;
}

int Voo::getIdC() const{
	return idC;
}
int Voo::getIdA() const{
	return idA;
}



void Voo::setLugaresocupados(int l){
	this->lugares_ocupados=l;
}




vector <Passenger *> Voo::getPassengers() const{
	return this->Passengers;
}

/////VOO COMERCIAL
VooComercial::~VooComercial()
{
}

VooComercial::VooComercial(Plane* planes, Date data_partida, float preco, string partida, string destino):Voo(planes, data_partida,  preco)
{
	this->partida=partida;
	this->destino=destino;
	setId_vooC();
}

void VooComercial::setId_vooC()
{
	string ss;
	stringstream s;
	s<<getIdC();
	s>>ss;
	this->id_voo = "COM " +ss;
	incrementIdC();

}
string VooComercial::getId_voo() const
{
	return id_voo;
}

float VooComercial::ocupacao_Voo_percent()  {
	return (100*getLugares_ocupados()/(getPlane()->getCapacity()) );
}
string VooComercial::getPartida()const{
	return partida;
}
string VooComercial::getDestino()const{
	return destino;
}


//////VOO ALUGADO

VooAlugado::~VooAlugado()
{

}
VooAlugado::VooAlugado(Plane* planes, Date data_partida,  float preco, string partida, string chegada):Voo(planes, data_partida, preco)
{
	this->partida=partida;
	this->destino=chegada;
	setId_vooA();
}

void VooAlugado::setId_vooA()
{
	string ss;
	stringstream s;
	s<<getIdA();
	s>>ss;
	this->id_voo = "ALU " + ss  ;
	incrementIdA();

}
string VooAlugado::getId_voo() const
{
	return id_voo;
}


float VooAlugado::ocupacao_Voo_percent(){
	return (100*getLugares_ocupados()/(getPlane()->getCapacity()) );
}
string VooAlugado::getPartida() const{
	return partida;
}
string VooAlugado::getDestino() const{
	return destino;
}

void VooAlugado::ocupar_vooInteiro(){
	setLugaresocupados(getPlane()->getCapacity());
}



