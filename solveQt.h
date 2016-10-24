#ifndef solveQt_h
#define solveQt_h

#include <QtGui/QWidget>
#include <QtGui/QBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QApplication>
#include<QtGui/QDesktopWidget>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include "Moteur.h"
using namespace std;

class solveQt : public QWidget {
  Q_OBJECT
public:
  solveQt(vector<Predicat*>* mpred,vector<Regle*>* mregles, vector< pair<Predicat*,vector<Variable*>> >* mconcl);
  virtual ~solveQt();
private:
  QHBoxLayout* lay_buts;
  QVBoxLayout* layout;
  QLabel* lab_res;
  QTextEdit* text_result;
  QPushButton* but_forward;
  QPushButton* but_backward;
  
  vector<Predicat*>* preds;
  vector<Regle*>* regles;
  vector< pair<Predicat*,vector<Variable*>> >* concl;
  
public slots:
  void chainageAvant();
  void chainageArriere();
  
};

#endif
