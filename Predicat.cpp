#include "Predicat.h"

using namespace std;

Predicat::Predicat()
{}

Predicat::Predicat(int _arite, vector< string > _name)
:arite(_arite), name(_name)
{}

Predicat::Predicat(int _arite, vector< string > _name, Predicat* _contr)
:arite(_arite), name(_name), contr(_contr)
{}

void Predicat::set_contr(Predicat* _contr)
{
  contr = _contr;
}

int Predicat::get_arite()
{
  return arite;
}

vector< vector< Variable* > > Predicat::get_variables()
{
  return variables;
}

void Predicat::add_variables(std::vector< Variable* >& _var)
{
  if (contr != nullptr)
  {
    if (contr->verify(_var))
    {
      cout << "contradiction trouvé : " << endl << "La variable : " << *_var[0] << endl << "est déjà vrai pour le prédicat : " << *contr  << endl << "et on essaie de le validé au prédicat contradictoire : " << name[0] << endl <<endl;;
    }
  }
  if (arite == _var.size())
    variables.push_back(_var);
  else
    cout << "Mauvais nombre de variable" << endl;
}

void Predicat::add_var(vector< unsigned int > _num_var)
{
  if (_num_var.size()==arite)
    num_var=_num_var;
  else
    cout << "Mauvais nombre de variable" << endl;
}

bool Predicat::verify(std::vector< Variable* >& _variables)
{
  vector<Variable*> inter;
  vector<unsigned int> interint;
  for (unsigned int i=0; i<variables.size(); ++i)
  {
    if (variables[i].size() == _variables.size())
    {
      bool id = true;
      for (unsigned int j = 0; j<_variables.size(); ++j)
      {
	if (variables[i][j] != _variables[j])
	  if (_variables[j] != nullptr)
	    id = false;
      }
      if (id == true)
      {
	return true;
      }
    }
  }
  return false;
}

void Predicat::print_var(int n)
{
  int j=0;
  for (unsigned int i=0; i<name.size(); ++i)
  {
    cout << (*variables[n][j]) << " " << name[i] << " ";
    ++j;
  }
  if (j<arite)
    cout << (*variables[n][j]);
  cout << endl;
}

void Predicat::print(std::ostream& out)
{
  int j=0;
  string esp = " ";
  if(!num_var.empty())
  {
    for (unsigned int i=0; i<name.size(); ++i)
    {
      out << var[num_var[j]] << esp << name[i] << esp;
      ++j;
    }
    if (j<arite)
      out << var[num_var[j]];
    num_var.clear();
  }
  else
  {
    for (unsigned int i=0; i<name.size(); ++i)
    {
      out << var[j] << esp << name[i] << esp;
      ++j;
    }
    if (j<arite)
      out << var[j];
  }
}

void Predicat::p_var()
{
  for (unsigned int i = 0; i<variables.size(); ++i)
  {
    cout << "vector n°" << i << endl;
    for (unsigned int j=0; j<variables[i].size(); ++j)
      cout << *variables[i][j] << " ";
    cout << endl;
  }
}

