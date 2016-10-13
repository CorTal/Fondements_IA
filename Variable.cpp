#include "Variable.h"

using namespace std;

Variable::Variable()
{}

Variable::Variable(string _name)
:name(_name)
{}

Variable::Variable(const Variable& _V)
:name(_V.name)
{}

string Variable::get_name()
{
  return name;
}

void Variable::set_name(const string _name)
{
  name = _name;
}

void Variable::print(ostream& out) const
{
  out << name;
}
