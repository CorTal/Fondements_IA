#include <QtGui/QApplication>
#include "displayQt.h"

void instanc_regle(vector<Predicat*>& preds, vector<Regle*>& regles, vector<Variable*>& var)
{
    vector<string> str={"a ses empreintes sur l'arme"};
    Predicat* P_ea = new Predicat(2,str);
    str = {"a ses empreintes sur l'outil"};
    Predicat* P_eo = new Predicat(2,str);
    str = {"est l'arme du crime"};
    Predicat* P_ac = new Predicat(1,str);
    str = {"a été utilisé pour le vol"};
    Predicat* P_ov = new Predicat(1,str);
    str = {"a utilisé l'arme du crime"};
    Predicat* P_uac = new Predicat(1,str);
    str = {"a utilisé l'outil pour le vol"};
    Predicat* P_uov = new Predicat(1,str);
    str = {"est la victime"};
    Predicat* P_v = new Predicat(1,str);
    str = {"est l'objet volé"};
    Predicat* P_vol = new Predicat(1,str);
    str = {"est coupable"};
    Predicat* P_c = new Predicat(1,str);
    str = {"a un passé tumultueux avec"};
    Predicat* P_pt = new Predicat(2,str);
    str = {"a un motif pour tué"};
    Predicat* P_mt = new Predicat(2,str);
    str = {"a une dette à règler"};
    Predicat* P_d = new Predicat(1,str);
    str = {"se vend cher"};
    Predicat* P_vc = new Predicat(1,str);
    str = {"a un motif pour voler"};
    Predicat* P_mv = new Predicat(2,str);
    str = {"était sur le lieu"};
    Predicat* P_l = new Predicat(2,str);
    str = {"est le lieu du crime"};
    Predicat* P_lc = new Predicat(1,str);
    str = {"n'est pas le lieu du crime"};
    Predicat* P_nlc = new Predicat(1,str);
    str = {"était présent sur le lieu du crime"};
    Predicat* P_plc = new Predicat(1,str);
    str = {"est témoin de la présence de" , "sur le lieu"};
    Predicat* P_tlc = new Predicat(3,str);
    str = {"est témoin de l'assassinat de", "par"};
    Predicat* P_tc = new Predicat(3,str);
    str = {"est témoin du vol de", "par"};
    Predicat* P_tv = new Predicat(3,str);
    str = {"témoin à l'heure du crime"};
    Predicat* P_th = new Predicat(1,str);
    str = {"a un alibi pour le crime"};
    Predicat* P_a = new Predicat(1,str);
    str = {"dit avoir un alibi pour le crime"};
    Predicat* P_da = new Predicat(1,str);
    str = {"est témoin de l'alibi de"};
    Predicat* P_ta = new Predicat(2,str);
    str = {"ne peux pas être le coupable de l'affaire"};
    Predicat* P_nc = new Predicat(1,str);
    str = {"a laissé des cheveux sur le lieu"};
    Predicat* P_cl = new Predicat(2,str);
    str = {"a été filmé sur le lieu"};
    Predicat* P_fl = new Predicat(2,str);
    
    
    preds.push_back(P_ea);
    preds.push_back(P_eo);
    preds.push_back(P_ac);
    preds.push_back(P_ov);
    preds.push_back(P_uac);
    preds.push_back(P_uov);
    preds.push_back(P_v);
    preds.push_back(P_vol);
    preds.push_back(P_c);
    preds.push_back(P_pt);
    preds.push_back(P_mt);
    preds.push_back(P_d);
    preds.push_back(P_vc);
    preds.push_back(P_mv);
    preds.push_back(P_l);
    preds.push_back(P_lc);
    preds.push_back(P_nlc);
    preds.push_back(P_plc);
    preds.push_back(P_tlc);
    preds.push_back(P_tc);
    preds.push_back(P_tv);
    preds.push_back(P_th);
    preds.push_back(P_a);
    preds.push_back(P_ta);
    preds.push_back(P_nc);
    preds.push_back(P_cl);
    preds.push_back(P_fl);
    
    
    /*Variable* p1 = new Variable("Georges");
    Variable* p2 = new Variable("Paul");
    Variable* p3 = new Variable("Anne");
    Variable* p4 = new Variable("Jean");
    Variable* o1 = new Variable("Vase");
    Variable* l1 = new Variable("Parc");
    
    
    vector<Variable*> v = {p1};
    preds[11]->add_variables(v);
    preds[11]->print_var(preds[11]->get_variables().size()-1);
    v = {o1};
    preds[12]->add_variables(v);
    preds[12]->print_var(preds[12]->get_variables().size()-1);
    preds[7]->add_variables(v);
    preds[7]->print_var(preds[7]->get_variables().size()-1);
    v = {p2, l1};
    preds[14]->add_variables(v);
    preds[14]->print_var(preds[14]->get_variables().size()-1);
    v = {p2,p1,l1};
    preds[18]->add_variables(v);
    preds[18]->print_var(preds[18]->get_variables().size()-1);
    v = {p4, l1};
    preds[14]->add_variables(v);
    preds[14]->print_var(preds[14]->get_variables().size()-1);
    v = {p4,p3,l1};
    preds[18]->add_variables(v);
    preds[18]->print_var(preds[18]->get_variables().size()-1);
    v = {l1};
    preds[15]->add_variables(v);
    preds[15]->print_var(preds[15]->get_variables().size()-1);
    var.push_back(p1);
    var.push_back(p2);
    var.push_back(p3);
    var.push_back(p4);
    var.push_back(o1);
    var.push_back(l1);*/
    
    vector<Predicat*> cond;
    vector<Predicat*> concl;
    vector< vector<unsigned int> > var_cond;
    vector< vector<unsigned int> > var_concl;
    cond = {P_ea, P_ac};
    concl = {P_uac};
    var_cond = {{0,1},{1}};
    var_concl = {{0}};
    Regle* R0 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_eo, P_ov};
    concl = {P_uov};
    Regle* R1 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_l, P_lc};
    concl = {P_plc};
    Regle* R2 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_pt, P_v};
    concl = {P_mt};
    var_concl = {{0,1}};
    Regle* R3 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_d,P_vc,P_vol};
    concl = {P_mv};
    var_cond = {{0},{1},{1}};
    Regle* R4 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_da, P_l, P_ta,P_l,P_th};
    concl = {P_a};
    var_cond = {{0},{0,2},{1,0},{1,2},{1}};
    var_concl={{0}};
    Regle* R5 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_cl};
    concl = {P_l};
    var_cond={{0,1}};
    var_concl={{0,1}};
    Regle* R6 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_fl};
    Regle* R7 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_l, P_tlc};
    concl = {P_l};
    var_cond = {{1,2},{1,0,2}};
    var_concl = {{0,2}};
    Regle* R8 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_a};
    concl = {P_nc};
    var_cond = {{0}};
    var_concl = {{0}};
    Regle* R9 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_uac,P_mt,P_v,P_plc};
    concl = {P_c};
    var_cond = {{0},{0,1},{1},{0}};
    var_concl = {{0}};
    Regle* R10 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    cond = {P_uov, P_mv, P_vol, P_plc};
    Regle* R11 = Regle::fabriqueRegle(cond, var_cond, var_concl, concl);
    
    
    regles.push_back(R0);
    regles.push_back(R1);
    regles.push_back(R2);
    regles.push_back(R3);
    regles.push_back(R4);
    regles.push_back(R5);
    regles.push_back(R6);
    regles.push_back(R7);
    regles.push_back(R8);
    regles.push_back(R9);
    regles.push_back(R10);
    regles.push_back(R11);
}

int main(int argc, char** argv)
{
  vector<Predicat*> preds;
    vector<Regle*> regles;
    vector<Variable*> var;
    vector<Variable*>v;
    instanc_regle(preds, regles, var);
    vector< pair<Predicat*,vector<Variable*>> > concl;
    pair<Predicat*,vector<Variable*>> p;
    /*v = {var[0]};
    p = make_pair(preds[17],v);
    concl.push_back(p);
    v = {var[2]};
    p = make_pair(preds[17],v);
    concl.push_back(p);*/
    //M.ChainageArriere();
    QApplication app(argc, argv);
    displayQt displayQt(&preds, &regles, &concl);
    displayQt.show();
    return app.exec();
}
