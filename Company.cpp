#include "Company.h"
#include "../../../../usr/include/c++/7/vector"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iomanip>
#include <limits>
#include <vector>
#include <cstddef>
#include <sstream>
#include <ctime>


//
//Plane *a= new Plane(0,"","",Date(0,0,0),10000);
Company::Company():planes(Plane()){
	Operator op = Operator("guedes",{"AirbusA310","AirbusA319"},false);
	Operator op1 = Operator("Joao",{"AirbusA32"},true);
	operators.push(op);
	operators.push(op1);

}


Company::~Company()
{

}


void Company::setName(string name){
	this->nome=name;
}

vector<Passenger*> Company::getPassengers() const
{
	return passengers;
}

vector<Voo*> Company::getVoos() const
{
	return voos;
}

vector<Reservation> Company::getReservations() const
{
	return reservations;
}

BST<Plane> Company::getPlanes() const
{
	return planes;

}

string Company::getName() const{
	return this->nome;
}


void Company::actualizarMemPasstxt()
{
	ofstream passengersx;
	passengersx.open("premiumclients.txt",fstream::out|fstream::trunc);

	for(size_t i=0; i<passengers.size();i++)
	{
		if (passengers[i]->isMember()){
			if(i==passengers.size()-1)
			passengersx << passengers[i]->getName() << ";"
									<< passengers[i]->getProfession() << ";"
									<< passengers[i]->getBirthday().getDay() << "/"
									<< passengers[i]->getBirthday().getMonth() << "/"
									<< passengers[i]->getBirthday().getYear() << ";"
									<< passengers[i]->getAnnualVoos();
			else passengersx << passengers[i]->getName() << ";"
					<< passengers[i]->getProfession() << ";"
					<< passengers[i]->getBirthday().getDay() << "/"
					<< passengers[i]->getBirthday().getMonth() << "/"
					<< passengers[i]->getBirthday().getYear() << ";"
					<< passengers[i]->getAnnualVoos() << "\n";}
	}
	passengersx.clear();
	passengersx.close();
}
void Company::actualizarFlightstxt()
{
	ofstream flights;
	flights.open("cflights.txt",fstream::out|fstream::trunc);

	for (size_t i = 0; i < voos.size(); i++) {
		if(voos[i]->getId_voo().substr(0,3)=="COM"){
		if(i==voos.size()-1)
			flights << voos[i]->getPartida() << ";" << voos[i]->getDestino() << ";"
							<< voos[i]->getPrecoInicial() << ";"
							<< voos[i]->getDate().getDay() << "/"
							<< voos[i]->getDate().getMonth() << "/"
							<< voos[i]->getDate().getYear() << "/"
							<< voos[i]->getDate().getHour() << "/"
							<< voos[i]->getDate().getMinutes();
		else flights << voos[i]->getPartida() << ";" << voos[i]->getDestino() << ";"
				<< voos[i]->getPrecoInicial() << ";"
				<< voos[i]->getDate().getDay() << "/"
				<< voos[i]->getDate().getMonth() << "/"
				<< voos[i]->getDate().getYear() << "/"
				<< voos[i]->getDate().getHour() << "/"
				<< voos[i]->getDate().getMinutes()<< "\n";
	}}
	flights.clear();
	flights.close();
}
void Company::actualizarCasPasstxt()
{
	ofstream passengersy;
	passengersy.open("casualclients.txt",fstream::out|fstream::trunc);

	for(size_t i=0; i<passengers.size();i++)
	{

		if (!passengers[i]->isMember()){
			 passengersy << passengers[i]->getName() << ";"
					<< passengers[i]->getBirthday().getDay() << "/"
					<< passengers[i]->getBirthday().getMonth() << "/"
					<< passengers[i]->getBirthday().getYear()<< "\n";
		}
	}
	passengersy.clear();
	passengersy.close();
}
void Company::actualizarComResertxt()
{
	ofstream reserv;
	reserv.open("comreservations.txt",fstream::out|fstream::trunc);

	for(size_t i=0; i<reservations.size();i++)
	{
		if(!reservations[i].isAlugado()){

			reserv << reservations[i].getPurchasePrice() << ";"
					<< reservations[i].getVooID() << ";"
					<< reservations[i].getPassID()->getID()<< "\n";
	}}
	reserv.clear();
	reserv.close();
}
/*
void Company::actualizarAluResertxt()
{
	ofstream reserv;
	reserv.open("alureservations.txt",fstream::out|fstream::trunc);
	int k;
	for(size_t i=0; i<reservations.size();i++)
	{
		if(reservations[i].isAlugado()){

			k=searchVoostr(reservations[i].getVooID());
			reserv  <<voos[k]->getPlane()->getID() << ";"
					<<reservations[i].getPassID()
					<< voos[k]->getDate().getDay() << "/"
					<< voos[k]->getDate().getMonth() << "/"
					<< voos[k]->getDate().getYear() << "/"
					<< voos[k]->getDate().getHour() << "/"
					<< voos[k]->getDate().getMinutes()
					<<reservations[i].getPurchasePrice() << ";"
					<< reservations[i].getOrig() << ";"
					<< reservations[i].getDest()<<"\n";}

		}
	reserv.clear();
	reserv.close();
}
*/

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////passengers/////////////////////////////////////

void Company::addPassenger(Passenger *passag)
{
	if(passag->getBirthday().getYear()<1890)
		throw InvalidYear(passag->getBirthday().getYear());
	else passengers.push_back(passag);
}

vector<unsigned int> Company::decomposeStringData(string linebirthday)
{
	string element;
	unsigned int elementx;
	int x=0,k;
	vector<unsigned int> vectorbirthday;

	while(x != -1)
	{
		x=linebirthday.find("/");
		element=linebirthday.substr(0,x);
		elementx=atoi(element.c_str());

		vectorbirthday.push_back(elementx);

		k=linebirthday.length();

		linebirthday=linebirthday.substr(x+1,k);
	}

	return vectorbirthday;
}

void Company::loadPassengers()
{
	ifstream inficheiro("premiumclients.txt");

string line;


	while (getline(inficheiro,line))
	{

	string args[4];
	int averageVoos;
		stringstream linestream(line);
		string value;
		args->clear();
		vector<unsigned int> birthday;
		int i=0;

		while(getline(linestream,value,';'))
		{

			args[i]=value;
			i++;
		}


		averageVoos=atoi(args[3].c_str());

		birthday=decomposeStringData(args[2]);
		Date d(birthday[0],birthday[1],birthday[2]);

		Passenger *p= new Passenger_comCartao(args[0],args[1],d,averageVoos);

		addPassenger(p);
	}

	inficheiro.clear();
	inficheiro.close();

}
void Company::loadPassengersCasual()
{
	ifstream inficheiro("casualclients.txt");

string line;


	while (getline(inficheiro,line))
	{

	string args[2];
	stringstream linestream(line);
	string value;
	args->clear();
	vector<unsigned int> birthday;


		int i=0;

		while(getline(linestream,value,';'))
		{

			args[i]=value;
			i++;
		}
		birthday=decomposeStringData(args[1]);
		Date d(birthday[0],birthday[1],birthday[2]);

		Passenger *p= new Passenger_ocasional(args[0],d);

		addPassenger(p);
	}

	inficheiro.clear();
	inficheiro.close();

}

/////QUANDO O VOO � ALU NAO MOSTRA O PASSENGER
void Company::showPassagengers() const
{
	string idVoo;

	cout<<"Type your flight's ID";
	cin.ignore();
	getline(cin,idVoo);

	cout << "\n--------Flight's passengers--------\n";

	cout << "\nID\t\tName\t\tBirthday\t\tAnnual flights" << endl;

	for (size_t j = 0; j < voos.size(); j++) {

		if(voos[j]->getId_voo()==idVoo){
		for (size_t i = 0; i < voos[j]->getPassengers().size(); i++) {
			cout << voos[j]->getPassengers()[i]->getID() << "\t\t" << voos[j]->getPassengers()[i]->getName()
					<< "\t\t" << voos[j]->getPassengers()[i]->getBirthday().getDay() << "/"
					<< voos[j]->getPassengers()[i]->getBirthday().getMonth() << "/"
					<< voos[j]->getPassengers()[i]->getBirthday().getYear() << "\t\t"
					<< voos[j]->getPassengers()[i]->getAnnualVoos() << endl;
		}
		}
	}
}


void Company::creatPassenger() {
	string nome, profissao, nascimento;
	vector<unsigned int> birthday;


	cout << "Indique o nome do cliente:" << endl;
	cin >> nome;


	cout << "Profissao:" << endl;
	cin >> profissao;
	cin.ignore();
	cout << "Data de nascimento(dd/mm/yyyy)" << endl;
	cin >> nascimento;

	birthday = decomposeStringData(nascimento);
	Date d(birthday[0], birthday[1], birthday[2]);


	Passenger *xPassenger= new Passenger_comCartao(nome,profissao, d, 0);

	addPassenger(xPassenger);

	cout<<"\nNew member ID is: "<<xPassenger->getID()<<endl;
	ofstream passengersx;
	passengersx.open("premiumclients.txt", fstream::app);
	passengersx << xPassenger->getName() << ";" << xPassenger->getProfession()
			<< ";" << xPassenger->getBirthday().getDay() << "/"
			<< xPassenger->getBirthday().getMonth() << "/"
			<< xPassenger->getBirthday().getYear() << ";"
			<< xPassenger->getAnnualVoos() << endl;
	passengersx.clear();
	passengersx.close();

}


void Company::seeallMembers()
{

	cout << "\n---------Company's Associates-----------\n";

	cout << "\nID\tName\t\tProfession\t\tBirthday\t\tAnnual flights\n" << endl;
	for (size_t i = 0; i < passengers.size(); i++) {
	if (passengers[i]->isMember() == 1) {
			cout << passengers[i]->getID()
					<< "\t" << passengers[i]->getName() << "\t"
					<< "\t" << passengers[i]->getProfession() <<"\t\t"
					<< passengers[i]->getBirthday().getDay() << "/"
					<< passengers[i]->getBirthday().getMonth() << "/"
					<< passengers[i]->getBirthday().getYear() << "\t\t"
					<< passengers[i]->getAnnualVoos() << endl;

		}
	}
}

//ver isto
void Company::elimPassenger()
{
	cout<<"\n--------------REMOVE MEMBER---------------\n"<<endl;
	cout<<"Member's ID:  "<<endl;
	string name;

	cin.ignore();
	getline(cin,name);
	int k=searchPassengersID(name);
	passengers.erase(passengers.begin()+k);
	cout<<"\nMember "<<name<< " successfully removed\n";

}

/////////////////////////////////////RESERVAS///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void Company::addReservation(Reservation reserv)
{
	reservations.push_back(reserv);
}


/////FICHEIRO RESERVAS TEM DE TER PRECO;VOOID;MEMID
void Company::loadReservationsALU()
{
	fstream inficheiro("alureservations.txt");

	string line;
	string args[6];



	while (getline(inficheiro,line))
	{
		string passID;
		unsigned int idPlane;
		float preco;
		stringstream linestream(line);
		string value;
		string orig, dest, dat1;
		args->clear();
		int pass;
		Plane plane;
		vector<unsigned int> departureDate;
		stringstream s;

		int i=0;

		while(getline(linestream,value,';'))
		{

			args[i]=value;
			i++;
		}

		dat1=args[2];
		departureDate=decomposeStringData(dat1);
		Date d(departureDate[0],departureDate[1],departureDate[2],departureDate[3],departureDate[4]);

		s<<args[3];
		s >>preco;
		passID = args[1];
		idPlane=atoi(args[0].c_str());
		pass=searchPassengersIDmem(passID);
		plane=searchPlaneID(idPlane);
		planes.remove(plane);
		orig = args[4];
		dest = args[5];

		Voo *x=new VooAlugado(&plane,d,preco,orig,dest);
		Reservation r(preco,x->getId_voo(),orig,dest,passengers[pass]);
		x->ocupar_vooInteiro();
		addVoo(x);
		addReservation(r);
		planes.insert(plane);
	}

	inficheiro.clear();
	inficheiro.close();
	}


void Company::loadReservations()
{
	fstream inficheiro("comreservations.txt");

	string line;
	string args[3];



	while (getline(inficheiro,line))
	{
		string vooID, passID;
		float preco;
		stringstream linestream(line);
		string value;
		string orig, dest;
		args->clear();
		int v=0, p=0;
		stringstream s;

		int i=0;

		while(getline(linestream,value,';'))
		{

			args[i]=value;
			i++;
		}

		s<<args[0];
		s >>preco;
		vooID = args[1];
		passID = args[2];
		v=searchVoostr(vooID);
		p=searchPassengersID(passID);
		orig = voos[v]->getPartida();
		dest = voos[v]->getDestino();
		if (passengers[p]->isMember()) {
					passengers[p]->setAnnualVoos(passengers[p]->getAnnualVoos() + 1);
					voos[v]->adicionarPassenger(passengers[p]);
					Reservation r(preco,vooID,orig,dest,passengers[p]);
					addReservation(r);
				}
		else {
			Reservation r(preco,vooID,orig,dest,passengers[p]);
			addReservation(r);
		}
	}

	inficheiro.clear();
	inficheiro.close();
	}


void Company::seeallReservations()
{

	cout<< "\n---------All Reservations-----------\n";

	for (size_t i=0; i<reservations.size(); i++)
	{

		//cout<<"\nID\t\tNome\t\tData de inscricao\t\tMontante"<<endl;
		//cout<<reservations[i]->getRsvID()<<"\t"<<reservations[i]->getInitialPrice()<<"\t"<< reservations[i]->getPurchasePrice() <<"\t"<< reservations[i]->getDestination()<<"\t"<<reservations[i]->getOrigin()<<endl<<"\t"<<reservations[i]->getPassID()<<endl;

	}
}


void Company::doReservation()
{
	vector<unsigned int> birthday;
	string name;
	string bday;
	string idPass;
	string idVoo;
	int voo;
	int jPass;
	char yn;
	double preco;

	cout << "-------Do Reservation-------" << endl;
	cout
			<< "id\tprice\torigin\tdestination\tdate(dd/MM/YYYY/hh/mm)\tInitial Price"
			<< endl;

	for (size_t i = 0; i < voos.size(); i++) {
		cout << voos[i]->getId_voo() << "\t" << voos[i]->getPrecoInicial()
				<< "\t" << voos[i]->getPartida() << "   "
				<< voos[i]->getDestino() << "  \t"
				<< voos[i]->getDate().getDay() << "/"
				<< voos[i]->getDate().getMonth() << "/"
				<< voos[i]->getDate().getYear() << "/"
				<< voos[i]->getDate().getHour() << "/"
				<< voos[i]->getDate().getMinutes() << "  \t"
				<< voos[i]->getPrecoInicial() << endl;

	}

	cin.ignore();
	cout << "Chose flight by ID" << endl;
	getline(cin,idVoo);
	if(idVoo.c_str()[0]=='A'){
		cout<<"This is a rented(particular) flight\n";
		return ;
	}
	else{

	voo=searchVoostr(idVoo);
	}

	cin.clear();


	cout<<"If you're a member, type your identification(""MEM x"")\n If not, type (-1)"<<endl;
	getline(cin,idPass);
	//cin.ignore();


	if (idPass!="-1")             //se for membro
		jPass=	searchPassengersID (idPass);

	cin.clear();
			cout << "\n\nHello  "<<passengers[jPass]->getName()<<endl;

			preco = precoReserva(voos[voo]->getPrecoInicial(),
					passengers[jPass]->isMember(),
					passengers[jPass]->getAnnualVoos(),
					voos[voo]->ocupacao_Voo_percent(), lessthan48(voos[voo]->getDate(), getcurrDate()), passengers[jPass]);

			cout<<"The ticket price is "<< preco;
			if(lastminuteDesconto)
				cout<<"\nLess that 48 hours until departure discount applied";
			cout<<"\nDiscount based on your yearly flights applied";

			cout<<"\n\nCare to proceed?(y/n)\n";

			cin>>yn;
			if(yn=='y'){
			Reservation r(preco,
					voos[voo]->getId_voo(), voos[voo]->getPartida(),
					voos[voo]->getDestino(), passengers[jPass]);
			addReservation(r);
			voos[voo]->adicionarPassenger(passengers[jPass]);
			passengers[jPass]->setAnnualVoos(passengers[jPass]->getAnnualVoos()+1);
			cout << "\nSuccess!!!";
			cout << "\nSuccess!!!";
			cout << "\nSuccess!!!\n";
			}


	else {
		cout << "Introduce name" << endl;
		getline(cin, name);//se nao for membro
		cout << "\n\nHello  "<<name<<endl;

		preco = precoReserva(voos[voo]->getPrecoInicial(),
				false,
				voos[voo]->ocupacao_Voo_percent(), lessthan48(voos[voo]->getDate(), getcurrDate()));

		cout<<"\nThe ticket price is "<< preco;
		if(lastminuteDesconto)
			cout<<"\nLess that 48 hours until departure discount applied";

		cout<<"\n\nCare to proceed?(y/n)\n";
		cin.clear();
		cin>>yn;
		if (yn == 'y') {
			cout << "Introduce you birthday(dd/mm/yyyy)\n";
			cin.ignore();
			cin >> bday;
			birthday = decomposeStringData(bday);
			Date d(birthday[0], birthday[1], birthday[2]);
			Passenger *o = new Passenger_ocasional(name, d);
			addPassenger(o);

			Reservation r(preco, voos[voo]->getId_voo(),
					voos[voo]->getPartida(), voos[voo]->getDestino(), o);
			addReservation(r);
			voos[voo]->adicionarPassenger(o);
			cout << "\nSuccess!!!";
			cout << "\nSuccess!!!";
			cout << "\nSuccess!!!\n";
		}
		else return;

	}
}






void Company::reservationPlane() {
	string name;
	unsigned int id;
	Plane idplane;
	string depart, destination;
	string idPass;
	string date;
	int passnr;
	double precototal;
	int preco1;
	vector <unsigned int> departureDate;
	char yn;

	cout << "-------Book an entire flight's seats-------" << endl;
	/*cout << "id\tprice\torigin\tdestination\tdate(dd/MM/YYYY/hh/mm)" << endl;
	for (size_t i = 0; i < voos.size(); i++) {
		cout << voos[i]->getId_voo() << "\t" << voos[i]->getPrecoInicial()
				<< "\t" << voos[i]->getPartida() << "   "
				<< voos[i]->getDestino() << "  \t"
				<< voos[i]->getDate().getDay() << "/"
				<< voos[i]->getDate().getMonth() << "/"
				<< voos[i]->getDate().getYear() << "/"
				<< voos[i]->getDate().getHour() << "/"
				<< voos[i]->getDate().getMinutes() << "  \t" << endl;

	}*/

	cout
			<< "\nYou're now about to book every seat on a plane"
			;

	cout
			<< "\nChoose the airport you wish to depart from\n";
	cin >> depart;

	cout<< "***AVAILABLE PLANES***\n";

	BSTItrIn<Plane> it(planes);
		     while (!it.isAtEnd())
		     {
				if (it.retrieve().getAlocated()==false && it.retrieve().getLocation()==depart){
				cout<<"\nID\tModel of the Plane\tCapacity\tLocation"<<endl;
				cout<<it.retrieve().getID()<<"\t"<<it.retrieve().getModel()<<"\t\t"<<it.retrieve().getCapacity()<<"\t\t"<<it.retrieve().getLocation()<<endl;}
		     it.advance();

	}
	cin.ignore();
	cout<< "\n\nChoose plane by id\n";
	cin>>id;
	cin.ignore();
	idplane=searchPlaneID(id); //pode causar problemas por já nao ser apontador, ao ocupar os seats tds


	cout<<"\nIf you're a member, type your identification(MEM x)\n If not, type (-1)\n"<<endl;
	getline(cin,idPass);

	cin.ignore();
	cin.clear();
	if(idPass=="-1"){

		cout<<"\nYou need to be a registered client to book this kind of flight, please register\n";

		creatPassenger(); ///CORRIGIR PROBLEMAS NAO L� A PROFISSAO - PROBLEMA DOS GETLINES E ASSIM

		cout << "\nNow enter your id\n";
		getline(cin,idPass);

	}
	passnr=searchPassengersIDmem(idPass);

	//cin.ignore();

	cout<< "\nNow enter your destination\n";
	cin>>destination;


	cout<< "\nWrite the time of the flight(departure) in the form of (dd/mm/yyyy/h/min)\n";
	cin.ignore();
	cin>>date;
	//cin.ignore();

	departureDate=decomposeStringData(date);
	srand (time(NULL));
	preco1=rand()%151+100;
	precototal=preco1*(idplane.getCapacity());

	cout<<"\nThis flight will cost you\n"
			<<"(Unitary ticket cost * number of seats = Total price)\n"
			<<preco1<<" * "<<idplane.getCapacity()<<" =  "<<precototal;

	cout<<"\n\nCare to proceed?(y/n)\n";

			cin>>yn;
	if (yn == 'y') {

		Date d(departureDate[0], departureDate[1], departureDate[2],
				departureDate[3], departureDate[4]);

		Voo *v = new VooAlugado(&idplane, d, precototal, depart,
				destination);
		v->ocupar_vooInteiro();
		addVoo(v);

		Reservation reser(precototal, v->getId_voo(), v->getPartida(),
				v->getDestino(), passengers[passnr]);
		v->adicionarPassenger(passengers[passnr]);
		addReservation(reser);

		cout << "\nSuccess!!!";
		cout << "\nSuccess!!!";
		cout << "\nSuccess!!!\n";
		cin.ignore();
	}
	else return;


}


	void Company::lastminuteDiscount(bool t){
		this->lastminuteDesconto = t;
	}

	double Company::precoReserva(double precoOrig, bool socio, int mediavoos, float percentOcup, bool lessthan48, Passenger *passID)
	{
		double precoCompra;

		if ((percentOcup < 50) && lessthan48)
		{
			lastminuteDiscount(true);
			if (passID->isMember())
			{
				if (mediavoos < 99 && mediavoos>0)
				{
					precoCompra = precoOrig * ((100.0 - mediavoos) / 100.0) * 0.9;
				}
				else precoCompra = precoOrig * 0.1 * 0.9;
			}
			else precoCompra = precoOrig * 0.9;
		}
		else if (passID->isMember()){
			lastminuteDiscount(false);
			if (mediavoos < 99 && mediavoos>0)
				precoCompra = precoOrig * ((100.0 - mediavoos) / 100.0) * 0.9;
			else precoCompra = precoOrig * 0.1 * 0.9;}

		else {precoCompra = precoOrig;
		lastminuteDiscount(false);
		}

		return precoCompra;
	}


	double Company::precoReserva(double precoOrig, bool socio, float percentOcup, bool lessthan48)
	{
		double precoCompra;

		if ((percentOcup < 50) && lessthan48){
			 precoCompra = precoOrig * 0.9;
				lastminuteDiscount(true);}
		else{ precoCompra = precoOrig ;
		lastminuteDiscount(false);}

		return precoCompra;
	}



/////////////////////////////////////PLANES///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void Company::loadPlanes()
{
	ifstream inficheiro("planes.txt");

	string line;
	string args[5];

	while (getline(inficheiro, line))
	{
		string plane,location;
		unsigned int capacity, nr_days;
		stringstream linestream(line);
		string value;
		args->clear();
		vector<unsigned int> date;
		string dat1;

		int i = 0;

		while (getline(linestream, value, ';'))
		{

			args[i] = value;
			i++;
		}

		plane = args[0];
		capacity = atoi(args[1].c_str());
		location=args[2];
		dat1=args[3];
		nr_days = atoi(args[4].c_str());

		date=decomposeStringData(dat1);

		Date d(date[0],date[1],date[2]);



		Plane::globalID_p++;
		Plane *a= new Plane(capacity,plane,location,d,nr_days);

		addPlane(*a);
	}

	inficheiro.clear();
	inficheiro.close();
}

void Company::addPlane(Plane plane)
{
		planes.insert(plane);
}

void Company::seeAllPlanes()
 {
	BSTItrIn<Plane> it(planes);
		     while (!it.isAtEnd())
		     {
		    	 cout << "\nID\tModel of the Plane\tCapacity\tLocation" << endl;
		    	 		cout << it.retrieve().getID() << "\t" << it.retrieve().getModel() << "\t\t"
		    	 				<< it.retrieve().getCapacity() << "\t\t"
		    	 				<< it.retrieve().getLocation() << endl;
		     it.advance();
		     }
	}

void Company::createPlane(){
	string model, location;
	unsigned int capacity,n;
	cout<<"\nType the airplane model you wish to add:\n";
	cin>> model;
	cin.ignore();
	cout<<"\nWhat airport is the plane at?\n";
	cin>> location;
	cin.ignore();
	cout<<"\nHow many seats are there in this plane?\n";
	cin>>capacity;
	cout<<"\nHow many days until next manteinance?\n";
	cin>>n;

	Plane::globalID_p++;
	Plane *a= new Plane(capacity,model,location,getcurrDate(),n);
	addPlane(*a);

}


void Company::doCheckUp(Plane plane) {
	planes.remove(plane);
	plane.setlastCheckup(getcurrDate());
	plane.calculateNextCheckup();
	planes.insert(plane);

}

void Company::set_newCheckUpTime(Plane plane, Date d) {
	planes.remove(plane);
	plane.setnextCheckup(d);
    //add_plane_to_operator(plane);

	planes.insert(plane);

}

void Company::showPlanes_ordered() {
	BSTItrIn<Plane> it(planes);
	while (!it.isAtEnd()) {
		cout
				<< "\nID\tModel of the Plane\tCapacity\tLocation\tPlane mantenance date(dd/mm/yyyy)"
				<< endl;
		cout << it.retrieve().getID() << "\t" << it.retrieve().getModel()
				<< "\t\t" << it.retrieve().getCapacity() << "\t\t"
				<< it.retrieve().getLocation() << "\t\t"
				<< it.retrieve().getnextCheckup().getDay() << "/"
				<< it.retrieve().getnextCheckup().getMonth() << "/"
				<< it.retrieve().getnextCheckup().getYear() << endl;
		it.advance();
	}

}

void Company::showPlanes_nextdays(unsigned int days) {
	BSTItrIn<Plane> it(planes);

	while (!it.isAtEnd()) {
		unsigned int d=time_untilCheck(it.retrieve().getnextCheckup(),this->getcurrDate());
		if ( d<= days){
			cout
					<< "\nID\tModel of the Plane\tCapacity\tLocation\tPlane maintenance date(dd/mm/yyyy)\tDays until maintenance"
					<< endl;
		cout << it.retrieve().getID() << "\t" << it.retrieve().getModel()
				<< "\t\t" << it.retrieve().getCapacity() << "\t\t"
				<< it.retrieve().getLocation() << "\t\t"
				<< it.retrieve().getnextCheckup().getDay() << "/"
				<< it.retrieve().getnextCheckup().getMonth() << "/"
				<< it.retrieve().getnextCheckup().getYear() << "\t\t"
				<< d << endl;

		}
		it.advance();
	}
}

void Company::showPlanes_nextdate(Date d) {
	BSTItrIn<Plane> it(planes);

	while (!it.isAtEnd()) {
		unsigned int nrdays=time_untilCheck(it.retrieve().getnextCheckup(),this->getcurrDate());
		unsigned int days=time_untilCheck(d,this->getcurrDate());
		if ( nrdays<= days){
			cout
					<< "\nID\tModel of the Plane\tCapacity\tLocation\tPlane maintenance date(dd/mm/yyyy)\tDays until maintenance"
					<< endl;
		cout << it.retrieve().getID() << "\t" << it.retrieve().getModel()
				<< "\t\t" << it.retrieve().getCapacity() << "\t\t"
				<< it.retrieve().getLocation() << "\t\t"
				<< it.retrieve().getnextCheckup().getDay() << "/"
				<< it.retrieve().getnextCheckup().getMonth() << "/"
				<< it.retrieve().getnextCheckup().getYear() << "\t\t\t\t"
				<< nrdays << endl;
	}
		it.advance();
	}
}


unsigned int Company::input_no_ofdays(){
	unsigned int i;
	cout<< "\nWrite the number of days:\n";
	cin>>i;
	return i;

}
Date Company::input_date(){
	string date;
	vector<unsigned int> d;
	cout<< "\nWrite the checkup date in the form of (dd/mm/yyyy)\n";
	cin>>date;
	d=decomposeStringData(date);
	Date da(d[0], d[1], d[2]);
	return da;

}

Plane Company::input_planeid(){
	unsigned int i;
	Plane p;
	cout<< "\nWrite plane id to preform it's checkup:\n";
	cin>>i;
	p=searchPlaneID(i);
	return p;
}
/////////////////////////////////////VOO///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


void Company::createVoo() {
	string depart, destination, date;
	int id;
	Plane idplane;
	float preco= 300;
	vector<unsigned int> departureDate;
	//(Plane* Plane,Date data_partida, float preco,string partida, string destino)
	cout<< "\n--------NEW COMMERCIAL FLIGH-------\n";
	cout << "Type the departure airport:" << endl;
	cin >> depart;
	cout<< "***AVAILABLE PLANES***\n";

	BSTItrIn<Plane> it(planes);
		     while (!it.isAtEnd())
		     {
				if (it.retrieve().getAlocated()==false && it.retrieve().getLocation()==depart){
				cout<<"\nID\tModel of the Plane\tCapacity\tLocation"<<endl;
				cout<<it.retrieve().getID()<<"\t"<<it.retrieve().getModel()<<"\t\t"<<it.retrieve().getCapacity()<<"\t\t"<<it.retrieve().getLocation()<<endl;}
		     it.advance();

	}
		cin.ignore();
		cout<< "\n\nChoose plane by id\n";
		cin>>id;
		cin.ignore();
		idplane=searchPlaneID(id);
		planes.remove(idplane);
		cout<< "\nNow enter the destination\n";
		cin>>destination;


		cout<< "\nWrite the time of the flight(departure) in the form of (dd/mm/yyyy/h/min)\n";
		cin.ignore();
		cin>>date;
		departureDate=decomposeStringData(date);

		Date d(departureDate[0], departureDate[1], departureDate[2],departureDate[3], departureDate[4]);
		Voo * x = new VooComercial(&idplane, d, preco, depart, destination);
		voos.push_back(x);
		idplane.setAlocated(true);
		planes.insert(idplane);
}

void Company::loadVoos()
{

	ifstream inficheiro("cflights.txt");

	string line;
	string args[4];



	while (getline(inficheiro, line))
	{
	Plane plane;
	//char voo_type;
	string origin, destination, dat1;
	double initialprice;
	vector<unsigned int> departureDate;
	stringstream linestream(line);
	string value;
	stringstream s;


		args->clear();

		int i = 0;

		while (getline(linestream, value, ';'))
		{

			args[i] = value;
			i++;
		}


		s<<args[2];
		origin=args[0];
		destination= args[1];
		s >>initialprice;
		dat1=args[3];
		s.clear();

		departureDate=decomposeStringData(dat1);

		Date d(departureDate[0],departureDate[1],departureDate[2],departureDate[3],departureDate[4]);


		//falta fazer um else

		plane=searchPlane_origin(origin);
		planes.remove(plane);

		if(initialprice<10000){
		Voo * x = new VooComercial(&plane, d, initialprice, origin, destination);
		voos.push_back(x);
		plane.setAlocated(true);
		planes.insert(plane);
		}
		else {
		Voo * y = new VooAlugado(&plane, d, initialprice, origin, destination);
		voos.push_back(y);
		plane.setAlocated(true);
		planes.insert(plane);
		}

	}
	inficheiro.clear();
	inficheiro.close();
}

void Company::seeAllVoos() {
	cout
			<< "id\tprice\torigin\tdestination\tdate(dd/MM/YYYY/hh/mm)\tPlane Model\tOccupation"
			<< endl;
	for (size_t i = 0; i < voos.size(); i++) {

		cout << voos[i]->getId_voo() << "\t" << voos[i]->getPrecoInicial()
				<< "\t" << voos[i]->getPartida() << "   "
				<< voos[i]->getDestino() << "  \t"
				<< voos[i]->getDate().getDay() << "/"
				<< voos[i]->getDate().getMonth() << "/"
				<< voos[i]->getDate().getYear() << "/"
				<< voos[i]->getDate().getHour() << "/"
				<< voos[i]->getDate().getMinutes() << "  \t"
				<< voos[i]->getPlane()->getModel() <<"  \t"
				<< voos[i]->getLugares_ocupados()<<
				endl;
	}

}


void Company::addVoo(Voo* voo)
{
	//fazer excepcao para quando a data e inferior a actual
	voos.push_back(voo);

}

////////////////DATE/////////////////


Date Company::getcurrDate() {
	updatecurrDate();
	return currDate;
}

bool Company::lessthan48(Date a,Date b){
	Date c=a-b;

	if((c.getDay()<2 && c.getMonth()==0 && c.getYear()==0)
			|| (c.getDay()==2 && c.getHour()>24 && c.getMinutes() >60)
			|| (c.getDay()==2 && c.getHour()==0 && c.getMinutes() >60)
			|| (c.getDay()==2 && c.getHour()>24 && c.getMinutes() ==0))
		return true;
	else return false;
}
	void Company::updatecurrDate()
	{
			time_t t = time(0);
			 struct tm * now = localtime( & t );
			 currDate= Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900,now->tm_hour,now->tm_min );
		}



	/////SEARCH
int Company::searchVoostr(string idVoo){
	int voo;
	for (size_t i = 0; i < voos.size(); i++) {  //procura voo
			if (voos[i]->getId_voo() == idVoo)
				voo = i;
		}
	return voo;
}
int Company::searchPassengersID(string passID){
	int p;
	for (size_t j = 0; j < passengers.size(); j++)
			if (passengers[j]->getID() == passID)
				p = j;

	return p;
}
int Company::searchPassengersIDmem(string idPass){
int passnr;
for (size_t i = 0; i < passengers.size(); i++) {
		if (idPass == passengers[i]->getID() && passengers[i]->isMember())
			passnr = i;
	}
return passnr;
}


//Plane plane_naoEncontrad(0,"","",Date(0,0,0),10000);

Plane Company::searchPlaneID(unsigned int p){
	vector<unsigned int>plane_info_int;
	vector<string>plane_info_str;
	Date temp;
	Plane plane;
	BSTItrIn<Plane> it(planes);
	     while (!it.isAtEnd())
	     {
			if (p == it.retrieve().getID()){
				plane_info_int.push_back(it.retrieve().getCapacity());
				plane_info_int.push_back(it.retrieve().getcheckUpRoutine());
				plane_info_str.push_back(it.retrieve().getModel());
				plane_info_str.push_back(it.retrieve().getLocation());
				temp=it.retrieve().getlastCheckUp();
				plane=planes.find(Plane(plane_info_int[0],plane_info_str[0],plane_info_str[1],temp,plane_info_int[1]));
			break;}
			else
	     it.advance();
	     }
	return plane;
}


Plane Company::searchPlane_origin(string origin){
	vector<unsigned int>plane_info_int;
	vector<string>plane_info_str;
	Date temp;
	Plane plane;
BSTItrIn<Plane> it(planes);
	     while (!it.isAtEnd())
	     {
			if ((it.retrieve().getAlocated()==false) && (it.retrieve().getLocation()==origin)){
				plane_info_int.push_back(it.retrieve().getCapacity());
				plane_info_int.push_back(it.retrieve().getcheckUpRoutine());
				plane_info_str.push_back(it.retrieve().getModel());
				plane_info_str.push_back(it.retrieve().getLocation());
				temp=it.retrieve().getlastCheckUp();
				plane=planes.find(Plane(plane_info_int[0],plane_info_str[0],plane_info_str[1],temp,plane_info_int[1]));
				break;

			}
			else
	     it.advance();
}
return plane;
}
void Company::list_operators() {
	HEAP_OPERATOR temp = operators;
    unsigned size = temp.size();
	for(unsigned i =0 ; i < size; i++){
		Operator el = temp.top();
		//operators.top().print_operator();
		cout<< el.getName()<<endl;

        temp.pop();
	}

}
string get_plane_model(){
  string model;
  cout << "Model of plane:" <<endl;
  cin >> model;
  return model;
}


void Company::add_new_operator() {
  string name,plane_model;
  vector <string> plane_models;

  int cont = 1;
  cout << "Name of Operator"<<endl;
  cin >> name;
  while(cont == 1){
    plane_model = get_plane_model();
    //validate plane model exists
    plane_models.push_back(plane_model);
    cout << "Add another model ? yes(1) No(0)"<< endl;
    cin >> cont;
  }
  Operator novo = Operator(name,plane_models,true);


  operators.push(novo);



}
bool Company::checkModelMatch(string model, vector<string> models) {
  for (unsigned i = 0; i < models.size(); ++i) {
    if(models[i] == model){
      return true;
    }

  }
  return false;

}
Operator Company::findOperator(Plane p) {

  string plane_model = p.getModel();
  HEAP_OPERATOR temp = operators;
  Operator found;
  unsigned size = operators.size();

  for (unsigned i = 0; i < size; ++i) {

    Operator el = operators.top();
    if(checkModelMatch(p.getModel(),el.getModels())){
      found = el;
      break;
    }
    //reset queue
    temp.pop();
  }
  
  return found;
}
void Company::add_plane_to_operator(Plane p) {

  unsigned size = operators.size();
  HEAP_OPERATOR temp;
  Operator to_add_plane = findOperator(p);
  Operator el;
  for (unsigned i = 0;  i < size ; ++i) {
    el = operators.top();
    if(to_add_plane==el){
      el.addPlaneToQueue(p);
    }
    temp.push(el);
    operators.pop();
  }

  operators=temp ;
}











