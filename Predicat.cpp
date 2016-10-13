#include "Predicat.h"

using namespace std;

Predicat::Predicat()
{}

Predicat::Predicat(int _arite, vector< string > _name)
:arite(_arite), name(_name)
{}

int Predicat::get_arite()
{
  return arite;
}

vector< vector< Variable > > Predicat::get_variables()
{
  return variables;
}

void Predicat::add_variables(vector<Variable> _var)
{
  if (_var.size() != arite)
    cout << "Mauvais nombre de variable" << endl;
  variables.push_back(_var);
}

void Predicat::add_var(std::vector< unsigned int > _num_var)
{
  if (_num_var.size()==(name.size()+1))
    num_var=_num_var;
  else
    cout << "Mauvais nombre de variable" << endl;
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
