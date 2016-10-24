#include "ajoutQt.h"

ajoutQt::ajoutQt(vector<Predicat*>* m_pred,vector< pair<Predicat*,vector<Variable*>> >* mconcl) 
: preds(m_pred), concl(mconcl)
{
  resize(QApplication::desktop()->width()/2, QApplication::desktop()->height()/2);
  move(QApplication::desktop()->screen()->rect().center() - rect().center());
  lab_pred = new QLabel(QString("Predicats :"));
  list_pred = new QListWidget();
  for(unsigned int i = 0; i < preds->size(); ++i){
    list_pred->addItem(QString::fromUtf8(preds->at(i)->print().c_str()));
  }
  radio_fact = new QRadioButton(QString("Fait "));
  radio_goal = new QRadioButton(QString("But "));
  radio_fact->setChecked(true);
  lay_radio = new QHBoxLayout();
  lay_radio->addWidget(radio_fact);
  lay_radio->addWidget(radio_goal);
  type_pred = new QGroupBox(QString("Type du predicat:"));
  type_pred->setLayout(lay_radio);
  but_validate = new QPushButton(QString("OK"));
  layout = new QVBoxLayout(this);
  layout->addWidget(lab_pred);
  layout->addWidget(list_pred);
  layout->addWidget(type_pred);
  layout->addWidget(but_validate);
   QObject::connect(but_validate, SIGNAL(clicked()), this, SLOT(validate()));
  QObject::connect(list_pred,SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(validate(QListWidgetItem*)));
}
  
ajoutQt::~ajoutQt()
{}

bool ajoutQt::fait()
{
  return fact;
}

void ajoutQt::validate()
{
  if(radio_fact->isChecked()){
    fact = true;
  }else{
    fact = false;
  }
 currPred = preds->at(list_pred->currentRow());
 const vector<string>& nameVariables = currPred->get_var();
 const vector<unsigned int>& numVariables = currPred->get_numvar();
 vars = new vector<Variable*>(currPred->get_arite());
 for(unsigned int i = 0; i < currPred->get_arite(); ++i){
   if(!currPred->get_numvar().empty()){
    vars->at(i) = new Variable(nameVariables.at(numVariables.at(i)));
   }else{
     vars->at(i) = new Variable(nameVariables.at(i));
   }
 }
 vrqt = new variableQt(vars, QString::fromUtf8(currPred->print().c_str()));
  QObject::connect(vrqt, SIGNAL(closed()), this, SLOT(onClose()));
 vrqt->show();
}

void ajoutQt::validate(QListWidgetItem* item)
{
  validate();
}


void ajoutQt::onClose()
{
  if(fait()){
    currPred->add_variables(*vars);
  }else if(!fait()){
    concl->push_back(make_pair(currPred,*vars));
  }
  emit closed();
  close();
}

Predicat* ajoutQt::pred()
{
  return currPred;
}


#include "ajoutQt.moc"
