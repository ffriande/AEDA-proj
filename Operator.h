//
// Created by vordep on 27-12-2017.
//

#ifndef AEDA_PROJ_MASTER_OPERATOR_H
#define AEDA_PROJ_MASTER_OPERATOR_H

#include <string>
#include <vector>
using namespace std;

class Operator {
 private:
  string nome;
  vector <string> models;
  bool available;
 public:

  Operator(const string &nome, const vector<string> &models, bool available);
  const vector<string> &getModels() const;

  void setModels(const vector<string> &models);
  void Addmodel(const string model);
  bool isAvailable() const;
  void setAvailable(bool available);


};

#endif //AEDA_PROJ_MASTER_OPERATOR_H
