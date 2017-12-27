//
// Created by vordep on 27-12-2017.
//

#include "Operator.h"

Operator::Operator(const vector<string> &models) : models(models) {}

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


Operator::Operator(const string &nome, const vector<string> &models, bool available)
    : nome(nome), models(models), available(available) {}
