#ifndef ajoutQt_h
#define ajoutQt_h

#include <QtGui/QWidget>
#include <QtGui/QListWidget>
#include <QtGui/QGroupBox>
#include <QtGui/QRadioButton>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QBoxLayout>
#include <QtCore/QString>
#include<QtDebug>


#include "Predicat.h"
#include "variableQt.h"
using namespace std;
class ajoutQt : public QWidget
{
    Q_OBJECT

public:
    ajoutQt(vector<Predicat*>* preds,vector< pair<Predicat*,vector<Variable*>> >* mconcl);
    virtual ~ajoutQt();
    
    bool fait();
    Predicat* pred();
    
private:
  QLabel* lab_pred;
  QListWidget* list_pred;
  QGroupBox* type_pred;
  QRadioButton* radio_fact;
  QRadioButton* radio_goal;
  QPushButton* but_validate;
  QVBoxLayout* layout;
  QHBoxLayout* lay_radio;
  
  bool fact;
 
  variableQt* vrqt;
  vector<Predicat*>* preds;
  Predicat* currPred;
  vector<Variable*>* vars;
  vector< pair<Predicat*,vector<Variable*>> >* concl;
public slots:
  void validate();
  void validate(QListWidgetItem* item);
  
signals:
  void closed();
public slots:
  void onClose();
};

#endif // displayQt_H
