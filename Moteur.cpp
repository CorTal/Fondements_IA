#include "Moteur.h"

using namespace std;

Moteur::Moteur()
{}

void Moteur::print_preds()
{
    cout << endl << "---------------Prédicats---------------" << endl;
    for(unsigned int i=0; i<preds.size(); ++i)
    {
      cout << i << " : " << *preds[i] << endl;
    }
}

void Moteur::print_regles()
{
    cout << endl << endl << "---------------Règles---------------" << endl;
    for(unsigned int i=0; i<regles.size(); ++i)
    {
      cout << "Règle n°" << i << endl;
      cout << *regles[i] << endl << endl;
    }
}

Moteur::Moteur(vector< Predicat* > _preds, vector< Regle* > _regles, std::vector< std::pair<Predicat*,std::vector<Variable*>> > _concl)
:preds(_preds), regles(_regles), concl(_concl)
{}

void Moteur::ChainageAvant()
{
  vector<Predicat*> build;
  Predicat* p;
  map<unsigned int, Variable*> m;
  bool built = true;
  int j=0;
  while(built && concl.size()>0)
  {
    built = true;
    j=0;
    for (unsigned int i=0; i<regles.size(); ++i)
    {
      build.clear();
      p = regles[i]->get_conditions()[0];
      m.clear();
      regles[i]->verifyCA(m, 0, p, build);
      if (build.size() == 0)
	++j;
      else
      {
	for (unsigned int k=(build[0]->get_variables().size()-build.size()); k<build[0]->get_variables().size(); ++k)
	{
	  build[0]->print_var(k);
	  exist(build[0]);
	}
      }
    }
    if (j == regles.size())
      built = false;
  }
}

void Moteur::exist(Predicat* p)
{
  for (unsigned int i=0; i<concl.size(); ++i)
  {
    if (concl[i].first == p)
    {
      if (p->verify(concl[i].second))
	concl.erase(concl.begin()+i);
    }
  }
}

void Moteur::ChainageArriere()
{
  bool et = true;
  bool id;
  for (unsigned int i = 0; i<concl.size(); ++i)
  {
    id = CArecurs(concl[i].first ,concl[i].second);
    et = et && id;
  }
  if (et == true)
    cout << "Chaînage Arrière réussi" << endl;
  else
    cout << "Chaînage Arrière raté" << endl;
}

bool Moteur::CArecurs(Predicat* p, std::vector< Variable* > var)
{
  cout << endl << endl;
  cout << "in CArecurs :" << *p;
  if (p->verify(var) == true)
    return true;
  vector<Regle*> reg;
  for (unsigned int i=0; i<regles.size(); ++i)
  {
    if (regles[i]->exist_concl(p) == true)
      reg.push_back(regles[i]);
  }
  if (reg.size() == 0)
    return false; // On a déjà testé en premier si le prédicat possédait les variables var nécessaires
  vector<unsigned int> cond, concl;
  map<unsigned int, Variable*> concls;
  bool ou = false;
  for (unsigned int i=0; i<reg.size(); ++i)
  {
    bool et = true;
    concl = reg[i]->get_var_concl()[0];
    for (unsigned int j=0; j<reg[i]->get_conditions().size(); ++j)
    {
      bool id;
      cond = reg[i]->get_var_cond()[j];
      vector<Variable*> var_next;
      for (unsigned int k=0; k<concl.size(); ++k)
	concls[concl[k]]=var[k];
      for (unsigned int k=0; k<cond.size(); ++k)
      {
	if (concls[cond[k]] == nullptr)
	  var_next.push_back(nullptr);
	else
	  var_next.push_back(concls[cond[k]]);
      }
      id = CArecurs(reg[i]->get_conditions()[j],var_next);
      et = et && id;
      cout << "et : " << et << endl;
    }
    ou = ou || et;
    if (ou == true)
    {
      return true;
    }
  }
  return ou;
}


bool present(pair< Predicat*, vector< Variable* > > p, vector< pair< Predicat*, vector< Variable* > > > v)
{
  bool pres;
  for (unsigned int i=0; i<v.size(); ++i)
  {
    if ((p.first)==(v[i].first))
    {
      pres = true;
      for (unsigned int j=0; j< v[i].second.size(); ++j)
      {
	if (p.second[j] != (v[i].second[j]))
	  pres = false;
      }
      if (pres == true)
	return true;
    }
  }
  return false;
}

