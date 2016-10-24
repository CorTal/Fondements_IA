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

string Predicat::add_variablesS(std::vector< Variable* >& _var)
{
  ostringstream oss;
  if (contr != nullptr)
  {
    if (contr->verify(_var))
    {
      oss << "contradiction trouvé : " << endl << "La variable : " << *_var[0] << endl << "est déjà vrai pour le prédicat : " << *contr  << endl << "et on essaie de le validé au prédicat contradictoire : " << name[0] << endl <<endl;;
    }
  }
  if (arite == _var.size())
    variables.push_back(_var);
  else
    oss << "Mauvais nombre de variable" << endl;
  return oss.str();
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


void Predicat::printVariables()
{
     int j=0;
  string esp = " ";
  if(!variables.empty())
  {
    for(unsigned int i = 0; i < variables.size(); ++i){
      for(unsigned int j = 0; j < name.size(); ++j){
	cout << variables[i].at(j) << esp << name[j] <<esp;
      }
    }
    if (j<arite)
      cout << variables[variables.size()-1].at(j);
    num_var.clear();
  }
}

string Predicat::print()
{
  std::stringstream ss;
 int j=0;
  string esp = " ";
  string ret = "";
  if(!num_var.empty())
  {
    for (unsigned int i=0; i<name.size(); ++i)
    {
      ret += var[num_var[j]] + esp + name[i] + esp;
      ++j;
    }
    if (j<arite)
      ret += var[num_var[j]];
    num_var.clear();
  }
  else
  {
    for (unsigned int i=0; i<name.size(); ++i)
    {
      ret += var[j] + esp + name[i] + esp;
      ++j;
    }
    if (j<arite)
      ret += var[j];
  }

  return ret;
}

string Predicat::printLastVar()
{
  unsigned int j = 0;
  string esp = " ";
  string ret = "";
  if(!variables.empty())
  {
    for(j; j < name.size(); ++j){
      ret += variables[variables.size()-1].at(j)->get_name() + esp + name[j] + esp;
    }
    if (j<arite)
	ret += variables[variables.size()-1].at(j)->get_name();
    num_var.clear();
  }
  return ret;
}

string Predicat::print_with_vars(vector< Variable* > vec)
{
   unsigned int j=0;
  string esp = " ";
  string ret = "";
  if(!vec.empty())
  {
    for(j; j < name.size(); ++j){
      ret += vec[j]->get_name() + esp + name[j] + esp;
    }
    if (j<arite)
	ret += vec[j]->get_name();
    num_var.clear();
  }
  return ret;
}


const vector< string >& Predicat::get_var() const
{
  return var;
}

const std::vector< unsigned int >& Predicat::get_numvar() const
{
  return num_var;
}

unsigned int Predicat::get_numvariables() const
{
  return variables.size();
}

string Predicat::print_varS(int n)
{
  ostringstream oss;
  int j=0;
  for (unsigned int i=0; i<name.size(); ++i)
  {
    oss << (*variables[n][j]) << " " << name[i] << " ";
    ++j;
  }
  if (j<arite)
    oss << (*variables[n][j]);
  oss << endl;
  return oss.str();
}



