//
// Created by vordep on 27-12-2017.
//

#include "Operator.h"
Operator::Operator(const string nome, const vector<string> models, bool available)
    : nome(nome), models(models), available(available) {}


const vector<string> &Operator::getModels() const {
  return models;
}
void Operator::setModels(const vector<string> &models) {
  Operator::models = models;
}
void Operator::Addmodel(const string model) {
  this->models.insert(models.end(),model);
}
bool Operator::isAvailable() const {
  return available;
}
void Operator::setAvailable(bool available) {
  Operator::available = available;
}
string Operator::getName() const{
	return nome;
}

bool Operator::operator<(const Operator &rhs) const {
	if(available && !rhs.available){
	  return false;
	}
	if(!available && rhs.available){
		return true;
	}
	if(working_days_ > rhs.working_days_){
		return true;
	}
	return false;
}

bool Operator::operator==(const Operator &rhs) const {
  return nome == rhs.nome;
}
/**
 * Add Plane to maintenance queue
 */
void Operator::addPlaneToQueue(Plane p) {
  planes_to_repair_.push(p);
}
/**
 * Increase working days of Maintenance tech
 */
void Operator::increaseWorkingDays() {
	working_days_=working_days_+average_repair;
}
/*
 * Prints the planes in queue to maintenance
 */
void Operator::printPlanesForMaintenance(){
	HEAP_PLANES temp = planes_to_repair_;
	int size = planes_to_repair_.size();

	for(int i = 0 ; i < size ; i++){
		cout << "Id: "<<temp.top().getID()<<"Model: "<<temp.top().getModel()<<endl;
		temp.pop();
	}

}
/**
 * Prints the maintenance technician
 */
void Operator::print_operator(){
	cout << "name : "<< nome << endl;
	cout << "Air plane Models Proficiency :"<<endl;
	for( unsigned  i = 0 ; i < models.size();i++){
		cout <<"\t"<<models[i];
	}
	cout <<endl;
	cout << "Occupied" << available<<endl;


	//Planes in for maintenance maintenance
	cout << "Planes maintenance queue"<<endl;
	printPlanesForMaintenance();

}


