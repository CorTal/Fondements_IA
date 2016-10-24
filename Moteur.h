#ifndef MOTEUR_H
#define MOTEUR_H
#include "Regle.h"

#include <algorithm>

class Moteur{
private:
  std::vector<Predicat*> preds;
  std::vector<Regle*> regles;
  std::vector< std::pair<Predicat*,std::vector<Variable*>> > concl;
public:
  Moteur();
  Moteur(std::vector<Predicat*> _preds, std::vector<Regle*> _regles, std::vector< std::pair<Predicat*,std::vector<Variable*>> > _concl);
  void tri_nb_preds();
  void tri_complex();
  void print_preds();
  void print_regles();
  void ChainageAvant();
  void ChainageArriere();
  void CAregle(Regle* r, std::vector<std::pair<unsigned int, Variable*>> var);
  void CApred(Predicat* p, std::vector< std::pair< unsigned int, Variable* > > var);
  void exist(Predicat* p);
  bool existCA(Predicat* p);
};

bool present(std::pair<Predicat*,std::vector<Variable*>> p, std::vector<std::pair<Predicat*,std::vector<Variable*>>> v);
void commun(std::vector<unsigned int> var_cond, std::vector<std::pair<unsigned int, Variable*>>& var);

#endif