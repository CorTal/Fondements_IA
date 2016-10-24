#ifndef rulesQt_h
#define rulesQt_h

#include <QtGui/QWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QTextEdit>
#include <ostream>
#include <QtCore/QString>
#include<QtDebug>
#include <QtGui/QApplication>
#include<QtGui/QDesktopWidget>
#include <set>

#include "Regle.h"
class rulesQt : public QWidget
{
    Q_OBJECT

public:
    rulesQt(std::vector<Regle*>* regles);
    virtual ~rulesQt();
    
private:
  QTextEdit* text_regles;
  QHBoxLayout* secondlayout;

public slots:
};

#endif // displayQt_H
