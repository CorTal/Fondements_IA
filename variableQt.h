#ifndef variableQt_h
#define variableQt_h

#include <QtGui/QWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QListWidget>
#include <QtGui/QLabel>
#include <QtGui/QBoxLayout>
#include <QtGui/QMessageBox>
#include <QtCore/QString>
#include<QtDebug>
#include<QtGui/QKeyEvent>
#include <QtGui/QApplication>
#include<QtGui/QDesktopWidget>
#include <set>

#include "Predicat.h"
class variableQt : public QWidget
{
    Q_OBJECT

public:
    variableQt(std::vector<Variable*>* mvars, QString predicat);
    virtual ~variableQt();
    
  int numVars;
  std::vector<Variable*>* vars;
  static std::set<std::string> sumvars;
private:
  QLabel* lab_pred;
  QLabel* lab_var;
  QLineEdit* line_var;
  QListWidget* list_var;
  QPushButton* but_ok_list;
  QPushButton* but_ok;
  QVBoxLayout* layout;
  QHBoxLayout* secondlayout;
  QVBoxLayout* mainlayout;
  QVBoxLayout* layout2;
  
  void keyPressEvent(QKeyEvent* e);
signals:
  void closed();

public slots:
  void ok();
  void ok_list();
  void ok_list(QListWidgetItem*);
};

#endif // displayQt_H
