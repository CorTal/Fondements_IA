#ifndef PREDICAT_H
#define PREDICAT_H

#include "Variable.h"
#include <iostream>
#include <vector>

class Predicat{
private:
  const std::vector<std::string> var = {"X","Y","Z","T","K","M","N","P","R","W","C","B","V","A","E","U","I","O","Q","S","D","F","G","H","J","L"};
  
  int arite;
  std::vector< std::vector<Variable*> > variables;
  std::vector<std::string> name;
  std::vector<unsigned int> num_var;
  Predicat* contr;
public:
  Predicat();
  Predicat(int _arite, std::vector<std::string> _name);
  Predicat(int _arite, std::vector<std::string> _name, Predicat* _contr);
  void set_contr(Predicat* _contr);
  int get_arite();
  std::vector< std::vector<Variable*> > get_variables();
  void add_variables(std::vector<Variable*>& _var);
  void add_var(std::vector<unsigned int> _num_var);
  void p_var();
  bool verify(std::vector< Variable* >& _variables);
  void print_var(int n);
  void print(std::ostream& out);
  friend std::ostream& operator<<(std::ostream& _out, Predicat& _p){
    _p.print(_out);
    return _out;
  };
};

#endif