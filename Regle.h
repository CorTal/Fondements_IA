#ifndef REGLE_H
#define REGLE_H

#include "Predicat.h"
#include <map>

class Regle{
private:
  std::vector<Predicat*> conditions;
  std::vector< std::vector<unsigned int>> var_cond;
  std::vector< std::vector<unsigned int>> var_concl;
  std::vector<Predicat*> conclusions;
  Regle();
  Regle(std::vector<Predicat*> _conditions, std::vector< std::vector<unsigned int>> _var_cond, std::vector< std::vector<unsigned int>> _var_concl, std::vector<Predicat*> _conclusions);
public:
  unsigned int get_arite_tot();
  std::vector<Predicat*> get_conditions();
  std::vector< std::vector<unsigned int> > get_var_cond();
  std::vector< std::vector<unsigned int> > get_var_concl();
  void verifyCA(std::map< unsigned int, Variable* > m, unsigned int n, Predicat* p, std::vector< Predicat* >& preds, std::vector<std::pair<unsigned int, Predicat*>> v);
  bool exist_concl(Predicat* p);
  void print(std::ostream& out);
  friend std::ostream& operator<<(std::ostream& _out, Regle& _r){
    _r.print(_out);
    return _out;
  };
  static Regle* fabriqueRegle(std::vector<Predicat*> _conditions, std::vector< std::vector<unsigned int>> _var_cond, std::vector< std::vector<unsigned int>> _var_concl, std::vector<Predicat*> _conclusions);
};

#endif