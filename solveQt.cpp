#include "solveQt.h"

solveQt::solveQt(vector<Predicat*>* mpred,vector<Regle*>* mregles, vector< pair<Predicat*,vector<Variable*>> >* mconcl)
: QWidget(), preds(mpred), regles(mregles),concl(mconcl), m(*preds,*regles,*concl)

{
  resize(QApplication::desktop()->width()/2, QApplication::desktop()->height()/2);
  move(QApplication::desktop()->screen()->rect().center() - rect().center());
  lay_buts = new QHBoxLayout();
  but_backward = new QPushButton("Chainage arriere");
  but_forward = new QPushButton("Chainage avant");
  lay_buts->addWidget(but_forward);
  lay_buts->addWidget(but_backward);
  lab_res = new QLabel("Resultat :");
  text_result = new QTextEdit();
  text_result->setReadOnly(true);
  layout = new QVBoxLayout(this);
  layout->addLayout(lay_buts);
  layout->addWidget(lab_res);
  layout->addWidget(text_result);
  QObject::connect(but_forward, SIGNAL(clicked()), this, SLOT(chainageAvant()));
  QObject::connect(but_backward, SIGNAL(clicked()), this, SLOT(chainageArriere()));
}

solveQt::~solveQt()
{

}

void solveQt::chainageAvant()
{
  text_result->clear();
  QString text = QString::fromUtf8(m.print_predsS().c_str());
  text += QString::fromUtf8(m.print_reglesS().c_str());
  text_result->setText(text);
}

void solveQt::chainageArriere(){
}


#include "solveQt.moc"