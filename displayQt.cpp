#include "displayQt.h"


displayQt::displayQt(vector<Predicat*>* mpred,vector<Regle*>* mregles, vector< pair<Predicat*,vector<Variable*>> >* mconcl) 
: preds(mpred), regles(mregles),concl(mconcl)
{
  resize(QApplication::desktop()->width()/2, QApplication::desktop()->height()/2);
  move(QApplication::desktop()->screen()->rect().center() - rect().center());
    lab_faits = new QLabel( this );
    lab_faits->setText( "Faits :" );
    List_Facts = new QListWidget();
    /*for(int i = 0; i < mpred->size(); ++i){
      for(int j = 0; j < mpred->at(i)->get_numvariables(); ++j){
	List_Facts->addItem(QString::fromUtf8(mpred->at(i)->print_varS(j).c_str()));
      }
    }*/
    lab_buts = new QLabel(this);
    lab_buts->setText("Buts :");
    List_Goals = new QListWidget();
    /*for(int i = 0; i < mconcl->size(); ++i){
      List_Goals->addItem(QString::fromUtf8(mconcl->at(i).first->print_with_vars(mconcl->at(i).second).c_str()));
    }*/
    lay_buttons = new QHBoxLayout();
    But_Aj = new QPushButton(QString("Ajouter..."));
    But_Solve = new QPushButton(QString("Resoudre") );
    But_Del = new QPushButton(QString("Supprimer") );
    But_Del->setEnabled(true);
    lay_buttons->addWidget(But_Aj);
    lay_buttons->addWidget(But_Solve);
    lay_buttons->addWidget(But_Del);
    center_Layout = new QVBoxLayout();
    center_Layout->addWidget(lab_faits);
    center_Layout->addWidget(List_Facts);
    center_Layout->addWidget(lab_buts);
    center_Layout->addWidget(List_Goals);
    center_Layout->addLayout(lay_buttons);
    QWidget* window = new QWidget();
    window->setLayout(center_Layout);
    setCentralWidget(window);
    
    rulesAc = new QAction(tr("&Regles"),this);
    menuHelp = menuBar()->addMenu(tr("&Aide"));
    menuHelp->addAction(rulesAc);
    
    rlq = new rulesQt(regles);
    QObject::connect(rulesAc, SIGNAL(triggered()), this, SLOT(help()));
    QObject::connect(But_Aj, SIGNAL(clicked()), this, SLOT(ajout()));
    QObject::connect(But_Solve, SIGNAL(clicked()), this, SLOT(resolution()));
    QObject::connect(But_Del, SIGNAL(clicked()), this, SLOT(deleteEle()));
}
  
displayQt::~displayQt()
{}

void displayQt::ajout()
{
  ajq = new ajoutQt(preds,concl);
  QObject::connect(ajq, SIGNAL(closed()), this, SLOT(onCloseAj()));
  ajq->show();
}

void displayQt::resolution()
{
  svq = new solveQt(preds,regles,concl);
  svq->show();
}

void displayQt::deleteEle()
{
  if(List_Facts->currentRow() == -1){
    List_Goals->takeItem(List_Goals->currentRow());
  }else if(List_Goals->currentRow() == -1){
    List_Facts->takeItem(List_Facts->currentRow());
  }
}

void displayQt::onCloseAj()
{
  Predicat* pred = ajq->pred();
  if(ajq->fait()){
    List_Facts->addItem(QString::fromUtf8(pred->printLastVar().c_str()));
  }else{
    List_Goals->addItem(QString::fromUtf8(pred->print_with_vars(concl->back().second).c_str()));
  }
}

void displayQt::help()
{
  rlq->show();
}


#include "displayQt.moc"
