#include<iostream>
#include <cstring>
#include "Company.h"
#include <ctime>
#include "Date.h"

using namespace std;

Company c;

void planes();
void menu();
void setname(){

	cout<<"Name your company:\n";
	char s[40];
	cin.get(s, 40);
	for(unsigned int i = 0;i<strlen(s); i++)
	       s[i] = toupper(s[i]);
	string nome(s);
	c.setName(nome);
	cout << string(50, '\n');
}

void planeCheckup(){
	cout << "-------Plane manteinance MENU-------" << endl;
	cout << "**The planes shown are ordered by the next checkup date**" << endl<<endl;
	cout<<"List all planes(1)"<<endl;
	cout<<"List planes whith checkup within the next X days(2)"<<endl;
	cout<<"List planes whith checkup until the date(dd/mm/yyyy)(3)"<<endl;
	cout<<"Preform plane manteinance(4)"<<endl;
	cout<<"Reschedule plane manteinance(5)"<<endl<<endl;
	cout<<"BACK TO PLANE MENU(6)"<<endl;

	int number;
	cin>>number;

	switch(number)
	{
	case 1:
		c.showPlanes_ordered();
		planeCheckup();
		break;
	case 2:
		c.showPlanes_nextdays(c.input_no_ofdays());
		planeCheckup();
		break;
	case 3:
		c.showPlanes_nextdate(c.input_date());
		planeCheckup();
		break;
	case 4:
		c.doCheckUp(c.input_planeid());
		planeCheckup();
		break;
	case 5:
		c.set_newCheckUpTime(c.input_planeid(),c.input_date());
		planeCheckup();
		break;

	case 6:
		planes();
		break;
	}
}


void planes()
{

	cout<<"------Planes-------"<<endl;
	cout<<"See all Planes(1)"<<endl;
	cout<<"Create a new Plane(2)"<<endl;
	cout<<"Planes Maintenance menu(3)"<<endl;
	cout<<"MENU(5)"<<endl;

	int number;
	cin>>number;

	switch(number)
	{
	case 1:
		c.seeAllPlanes();
		planes();
		break;
	case 2:
		c.createPlane();
		planes();
		break;
	case 3:
		planeCheckup();

		break;
	case 5:
		menu();
		break;
	}
}
void reservations()
{

	cout<<"------Reservations-------"<<endl;

	cout<<"See all flights(1)"<<endl;
	cout<<"Ticket reservation(2)"<<endl;
	cout<<"Flight reservation $$$(3)"<<endl;
	cout<<"Add new commercial flight(4)"<<endl;
	cout<<"MENU(5)"<<endl;

	int number;
	cin>>number;


	switch(number)
	{

		case 1:
			c.seeAllVoos();
			reservations();
			break;
		case 2:
			c.doReservation();

			reservations();
			break;
		case 3:
			c.reservationPlane();

			reservations();
			break;
		case 4:
					c.createVoo();

					reservations();
					break;

		case 5:
			menu();

			break;
	}
}


void passengers()
{

	cout<<"------Members-------"<<endl;
	cout<<"List Passengers per flight(1)"<<endl;
	cout<<"Add new Members(2)"<<endl;
	cout<<"List all members(3)"<<endl;
	cout<<"Eliminate Members(4)"<<endl;
	cout<<"MENU(5)"<<endl;


	int number;
	cin>>number;


	switch(number)
	{
	case 1:
		c.showPassagengers();
		passengers();
		break;
	case 2:
		c.creatPassenger();
		passengers();
		break;
	case 3:
		c.seeallMembers();
		passengers();
		break;
	case 4:
		c.elimPassenger();
		passengers();
		break;
	case 5:

		menu();
	}
}

void operators(){
	cout<<"------Operators-------"<<endl;
	cout<<"List All Operators(1)"<<endl;
	cout<<"Add new Operator(2)"<<endl;
	cout<<"MENU(5)"<<endl;

	int number;
	cin >> number;

	switch (number) {
		case 1:
			c.list_operators();
			operators();
			break;
		case 2:
			//c.add_new_operator():
		case 5:
			menu();
	}
}
void menu()
{
	cout << string(50, '\n');
	time_t t = time(0);
	struct tm * now = localtime( & t );
	cout <<"Current time and date:" << asctime(now)<<endl;
	cout<<"-------------"<<c.getName()<<"--------------"<<endl;
	cout<<"Passengers(1)"<<endl;
	cout<<"Reservas(2)"<<endl;
	cout<<"Planes(3)"<<endl;
	cout<<"Leave menu(4)"<<endl;
	cout<<"Operators(5)"<<endl;

	int number;
	cin>>number;


	switch(number)
	{
	case 1:
		passengers();
		break;
	case 2:
		reservations();
		break;
	case 3:
		planes();
		break;
	case 5:
		operators();
		break;
	case 4:
		c.actualizarMemPasstxt();
		c.actualizarCasPasstxt();
		c.actualizarFlightstxt();
		c.actualizarComResertxt();
		exit(1);

	}

}

int main()

{


	setname();
	c.loadPassengers();
	c.loadPassengersCasual();
	c.loadPlanes();
	c.loadVoos();
	c.loadReservations();
	//c.loadReservationsALU();
	menu();


}
