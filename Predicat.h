#ifndef PREDICAT_H
#define PREDICAT_H

#include "Variable.h"
#include <iostream>
#include <sstream>


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
  int get_arite();
  std::vector< std::vector<Variable*> > get_variables();
  void set_contr(Predicat* _contr);
  
  void add_variables(std::vector<Variable*>& _var);
std::string add_variablesS(std::vector<Variable*>& _var);
  void add_var(std::vector<unsigned int> _num_var);
  void p_var();
  bool verify(std::vector< Variable* >& _variables);
  void print_var(int n);
  void print(std::ostream& out);
  const std::vector<std::string>& get_var() const;
  const std::vector<unsigned int>& get_numvar() const;
  unsigned int get_numvariables() const;
  std::string print_varS(int n);
  std::string print_with_vars(std::vector<Variable*> vec);
  std::string printLastVar();
  std::string print();
  void printVariables();
  friend std::ostream& operator<<(std::ostream& _out, Predicat& _p){
    _p.print(_out);
    return _out;
  };
};


#endif
