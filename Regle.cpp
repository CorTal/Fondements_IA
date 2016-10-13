#include "Regle.h"

using namespace std;

Regle::Regle()
{}

Regle::Regle(std::vector< Predicat* > _conditions, vector< std::vector< unsigned int > > _var_cond, vector< std::vector< unsigned int > > _var_concl, std::vector< Predicat* > _conclusions)
:conditions(_conditions), var_cond(_var_cond), var_concl(_var_concl), conclusions(_conclusions)
{}

void Regle::print(std::ostream& out)
{
  for (unsigned int i=0; i<conditions.size(); ++i)
    conditions[i]->add_var(var_cond[i]);
  for (unsigned int i=0; i<conclusions.size(); ++i)
    conclusions[i]->add_var(var_concl[i]);
  string rc="\n";
  string si="Si ";
  string et="et si ";
  string donc="alors ";
  string etd="et alors ";
  out << si << *conditions[0] << rc;
  for (unsigned int i=1; i<conditions.size(); ++i)
    out << et << *conditions[i] << rc;
  out << donc << *conclusions[0] << rc;
  for (unsigned int i=1; i<conclusions.size(); ++i)
    out << etd << *conditions[i] << rc;
}

Regle* Regle::fabriqueRegle(std::vector< Predicat* > _conditions, vector< std::vector< unsigned int > > _var_cond, vector< std::vector< unsigned int > > _var_concl, std::vector< Predicat* > _conclusions)
{
  if((_var_cond.size() != _conditions.size()) || (_var_concl.size() != _conclusions.size()))
  {
      cout << "Mauvaise instanciation de règle : les vecteurs conditions et var_cond ou les vecteurs conclusions et var_concl n'ont pas la même taille entre eux" << endl;
      return nullptr;
  }
  else{
    for (unsigned int i=0; i<_conditions.size(); ++i)
      if (_conditions[i]->get_arite() != _var_cond[i].size())
      {
	cout << "Mauvaise taille de var_cond pour l'arité du prédicat à la posisiton " << i << endl;
	return nullptr;
      }
    for (unsigned int i=0; i<_conclusions.size(); ++i)
      if (_conclusions[i]->get_arite() != _var_concl[i].size())
      {
	cout << "Mauvaise taille de var_cond pour l'arité du prédicat à la posisiton " << i << endl;
	return nullptr;
      }
  }
  return new Regle(_conditions, _var_cond, _var_concl, _conclusions);
}
