//
// Created by vordep on 27-12-2017.
//
#pragma once
#ifndef AEDA_PROJ_MASTER_OPERATOR_H
#define AEDA_PROJ_MASTER_OPERATOR_H

#include <string>
#include <vector>
#include <stdio.h>
#include <queue>
#include "Plane.h"

using namespace std;

typedef priority_queue<Plane> HEAP_PLANES;

class Operator {

 private:
  string nome;
  vector <string> models;
  bool available;
  HEAP_PLANES planes_to_repair_;
  int average_repair = 2 ; //em dias
 public:

  Operator(){};
  Operator(const string nome, const vector<string> models, bool available);
  const vector<string> &getModels() const;

  void setModels(const vector<string> &models);
  void Addmodel(const string model);
  bool isAvailable() const;
  void setAvailable(bool available);
  string getName() const;
  void addPlaneToQueue(Plane p );

  bool operator<(const Operator &rhs) const;
  bool operator==(const Operator &rhs) const;

};

#endif //AEDA_PROJ_MASTER_OPERATOR_H
