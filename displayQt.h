#ifndef displayQt_H
#define displayQt_H

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QListWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QBoxLayout>
#include <QtCore/QString>
#include <QtGui/QWidget>
#include <QtGui/QMainWindow>


#include "ajoutQt.h"
#include "solveQt.h"
#include "rulesQt.h"

#include "Regle.h"

using namespace std;
class displayQt : public QMainWindow
{
    Q_OBJECT
private :
  QPushButton* But_Aj;
  QPushButton* But_Del;
  QPushButton* But_Solve;
  QLabel* lab_faits;
  QLabel* lab_buts;
  QListWidget* List_Facts;
  QListWidget* List_Goals;
  QVBoxLayout* center_Layout;
  QHBoxLayout* lay_buttons;
  QAction* rulesAc;
  QMenu* menuHelp;
  
  ajoutQt* ajq;
  solveQt* svq;
  rulesQt* rlq;
  
  vector<Predicat*>* preds;
  vector<Regle*>* regles;
  vector< pair<Predicat*,vector<Variable*>> >* concl;
public:
    displayQt(vector<Predicat*>* mpreds, vector<Regle*>* mregles, vector< pair<Predicat*,vector<Variable*>> >* mconcl);
    virtual ~displayQt();

public slots:
  void ajout();
  void resolution();
  void deleteEle();
  void onCloseAj();
  void help();
};

#endif // displayQt_H
