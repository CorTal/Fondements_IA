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
  ostringstream oss;
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
      oss << regles[i]->verifyCAS(m, 0, p, build, v);
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
  return oss.str();;
}

void Moteur::ChainageArriere()
{
  for (unsigned int i=0; i<concl.size(); ++i)
  {
    vector<Regle*> reg;
    for (unsigned int j=0; j<regles.size(); ++j)
    {
      if (regles[j]->exist_concl(concl[i].first) == true)
      {
	reg.push_back(regles[j]);
      }
    }
    for (unsigned int j=0; j<reg.size(); ++j)
    {
      vector<pair<unsigned int, Variable*>> var;
      vector<unsigned int> var_concl = reg[j]->get_var_concl()[0];
      for (unsigned int k=0; k<var_concl.size(); ++k)
	var.push_back(make_pair(var_concl[k], concl[i].second[k]));
      CAregle(reg[j],var);
    }
    if (!existCA(concl[i].first))
    {
      cout << "la conclusion numéro : " << i << " basé sur le prédicat : " << endl << *concl[i].first << endl << "n'a pas été créée, conditions initiales insuffisante." << endl;
    }
  }
}



string Moteur::ChainageArriereS()
{
  ostringstream oss;
  for (unsigned int i=0; i<concl.size(); ++i)
  {
    vector<Regle*> reg;
    for (unsigned int j=0; j<regles.size(); ++j)
    {
      if (regles[j]->exist_concl(concl[i].first) == true)
      {
	reg.push_back(regles[j]);
      }
    }
    for (unsigned int j=0; j<reg.size(); ++j)
    {
      vector<pair<unsigned int, Variable*>> var;
      vector<unsigned int> var_concl = reg[j]->get_var_concl()[0];
      for (unsigned int k=0; k<var_concl.size(); ++k)
	var.push_back(make_pair(var_concl[k], concl[i].second[k]));
      oss << CAregleS(reg[j],var);
    }
    if (!existCA(concl[i].first))
    {
      oss << "la conclusion numéro : " << i << " basé sur le prédicat : " << endl << *concl[i].first << endl << "n'a pas été créée, conditions initiales insuffisante." << endl;
    }
  }
  return oss.str();
}

void Moteur::CAregle(Regle* r, vector< pair< unsigned int, Variable* > > var)
{
  vector<unsigned int> var_cond;
  vector<pair<unsigned int, Variable*>> var_next;
  for(unsigned int i=0; i<r->get_conditions().size(); ++i)
  {
    var_cond = r->get_var_cond()[i];
    commun(var_cond, var);
    CApred(r->get_conditions()[i],var);
  }
  map<unsigned int, Variable*> m;
  for (unsigned int i=0; i<var.size(); ++i)
    m[var[i].first] = var[i].second;
  Predicat* p = r->get_conditions()[0];
  vector<Predicat*> preds;
  vector<pair<unsigned int, Predicat*>> v;
  r->verifyCA(m,0,p,preds,v);
}
string Moteur::CAregleS(Regle* r, vector< pair< unsigned int, Variable* > > var)
{
  string ret = "";
  vector<unsigned int> var_cond;
  vector<pair<unsigned int, Variable*>> var_next;
  for(unsigned int i=0; i<r->get_conditions().size(); ++i)
  {
    var_cond = r->get_var_cond()[i];
    commun(var_cond, var);
    ret += CApredS(r->get_conditions()[i],var);
  }
  map<unsigned int, Variable*> m;
  for (unsigned int i=0; i<var.size(); ++i)
    m[var[i].first] = var[i].second;
  Predicat* p = r->get_conditions()[0];
  vector<Predicat*> preds;
  vector<pair<unsigned int, Predicat*>> v;
  ret += r->verifyCAS(m,0,p,preds,v);
return ret;
}

void Moteur::CApred(Predicat* p, vector< std::pair< unsigned int, Variable* > > var)
{
  vector<Regle*> reg;
  for (unsigned int i=0; i<regles.size(); ++i)
    if (regles[i]->exist_concl(p) == true)
      reg.push_back(regles[i]);
  if (reg.size() > 0)
  {
    for (unsigned int i=0; i<reg.size(); ++i)
      CAregle(reg[i],var);
  }
}

string Moteur::CApredS(Predicat* p, vector< std::pair< unsigned int, Variable* > > var)
{
  string ret = "";
  vector<Regle*> reg;
  for (unsigned int i=0; i<regles.size(); ++i)
    if (regles[i]->exist_concl(p) == true)
      reg.push_back(regles[i]);
  if (reg.size() > 0)
  {
    for (unsigned int i=0; i<reg.size(); ++i)
      	ret += CAregleS(reg[i],var);
  }
  return ret;
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

bool Moteur::existCA(Predicat* p)
{
  for (unsigned int i=0; i<concl.size(); ++i)
  {
    if (concl[i].first == p)
    {
      if (p->verify(concl[i].second))
	return true;
    }
  }
  return false;
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

void commun(std::vector< unsigned int > var_cond, vector< std::pair< unsigned int, Variable* > >& var)
{
  bool present = false;
  for (unsigned int i=0; i<var.size(); ++i)
  {
    present = false;
    for (unsigned int j=0; j<var_cond.size(); ++j)
    {
      if (var_cond[j] == var[i].first)
	present = true;
      if (present = false)
	var.erase(var.begin()+i);
    }
  }
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
