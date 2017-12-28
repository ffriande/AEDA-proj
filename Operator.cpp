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
  return available < rhs.available;
}
bool Operator::operator==(const Operator &rhs) const {
  return nome == rhs.nome;
}
void Operator::addPlaneToQueue(Plane p) {
  planes_to_repair_.push(p);
}


