#include "Regle.h"

using namespace std;

void instanc_regle(vector<Predicat*>& preds, vector<Regle*>& regles)
{
    vector<string> str={"plus petit que","plus petit que"};
    vector<Predicat*> cond;
    vector<Predicat*> concl;
    vector< vector<unsigned int> > var_cond;
    vector< vector<unsigned int> > var_concl;
    var_cond = {{0,1,2},{2,1,0}};
    var_concl = {{0,2}};
    str = {"plus petit que","plus petit que"};
    Predicat* P = new Predicat(3,str);
    preds.push_back(P);
    str = {"plus grand que","plus grand que"};
    Predicat* P2 = new Predicat(3,str);
    preds.push_back(P2);
    str = {"plus petit que"};
    Predicat* P3 = new Predicat(2,str);
    preds.push_back(P3);
    cond.push_back(P);
    cond.push_back(P2);
    concl.push_back(P3);
    Regle *R1 = Regle::fabriqueRegle(cond,var_cond, var_concl, concl);
    regles.push_back(R1);
}

int main(int argc, char **argv) {
    
    vector<Predicat*> preds;
    vector<Regle*> regles;
    instanc_regle(preds, regles);
    cout << endl << endl << "---------------Prédicats---------------" << endl;
    for(unsigned int i=0; i<preds.size(); ++i)
    {
      cout << *preds[i] << endl;
    }
    
    cout << endl << endl << "---------------Règles---------------" << endl;
    for(unsigned int i=0; i<regles.size(); ++i)
    {
      cout << *regles[i] << endl;
    }
  
    return 0;
}
