#ifndef MOTEUR_H
#define MOTEUR_H
#include "Regle.h"

class Moteur{
private:
  std::vector<Predicat*> preds;
  std::vector<Regle*> regles;
  std::vector< std::pair<Predicat*,std::vector<Variable*>> > concl;
public:
  Moteur();
  Moteur(std::vector<Predicat*> _preds, std::vector<Regle*> _regles, std::vector< std::pair<Predicat*,std::vector<Variable*>> > _concl);
  void print_preds();
  void print_regles();
  void ChainageAvant();
  void ChainageArriere();
  bool CArecurs(Predicat* p, std::vector< Variable* > var);
  void exist(Predicat* p);
};

bool present(std::pair<Predicat*,std::vector<Variable*>> p, std::vector<std::pair<Predicat*,std::vector<Variable*>>> v);

#endif