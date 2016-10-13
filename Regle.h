#ifndef REGLE_H
#define REGLE_H

#include "Predicat.h"

class Regle{
private:
  std::vector<Predicat*> conditions;
  std::vector< std::vector<unsigned int>> var_cond;
  std::vector< std::vector<unsigned int>> var_concl;
  std::vector<Predicat*> conclusions;
  Regle();
  Regle(std::vector<Predicat*> _conditions, std::vector< std::vector<unsigned int>> _var_cond, std::vector< std::vector<unsigned int>> _var_concl, std::vector<Predicat*> _conclusions);
public:
  void print(std::ostream& out);
  friend std::ostream& operator<<(std::ostream& _out, Regle& _r){
    _r.print(_out);
    return _out;
  };
  static Regle* fabriqueRegle(std::vector<Predicat*> _conditions, std::vector< std::vector<unsigned int>> _var_cond, std::vector< std::vector<unsigned int>> _var_concl, std::vector<Predicat*> _conclusions);
};

#endif