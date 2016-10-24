#include "Moteur.h"

using namespace std;


bool tri_compl(Regle* R1, Regle* R2)
{
  return (R1->get_arite_tot() <= R2->get_arite_tot());
}

bool tri_preds(Regle*R1, Regle* R2)
{
  return (R1->get_conditions().size() <= R2->get_conditions().size());
}

Moteur::Moteur()
{}

void Moteur::tri_nb_preds()
{
  sort(regles.begin(), regles.end(), tri_preds);
}

void Moteur::tri_complex()
{
  sort(regles.begin(), regles.end(), tri_preds);
}

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
  vector<pair<unsigned int, Predicat*>> v;
  bool built = true;
  int j=0;
  bool ss_concl = false;
  if (concl.size() == 0)
    ss_concl = true;
  while((ss_concl && built ) || (built && concl.size()>0))
  {
    built = true;
    j=0;
    for (unsigned int i=0; i<regles.size(); ++i)
    {
      build.clear();
      p = regles[i]->get_conditions()[0];
      m.clear();
      regles[i]->verifyCA(m, 0, p, build, v);
      if (build.size() == 0)
	++j;
      else
      {
	for (unsigned int k=(build[0]->get_variables().size()-build.size()); k<build[0]->get_variables().size(); ++k)
	  exist(build[0]);
      }
    }
    if (j == regles.size())
      built = false;
  }
}

string Moteur::ChainageAvantS()
{

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



string Moteur::print_predsS()
{
  ostringstream ss;
  ss << endl << "---------------Prédicats---------------" << endl;
    for(unsigned int i=0; i<preds.size(); ++i)
    {
      ss << i << " : " << *preds[i] << endl;
    }
    return ss.str();
}

string Moteur::print_reglesS()
{
   ostringstream ss;
  ss << endl << endl << "---------------Règles---------------" << endl;
    for(unsigned int i=0; i<regles.size(); ++i)
    {
      ss << "Règle n°" << i << endl;
      ss << *regles[i] << endl << endl;
    }
    return ss.str();
}
