#include "rulesQt.h"

rulesQt::rulesQt(std::vector< Regle* >* regles): QWidget()
{
  resize(QApplication::desktop()->width()/2, QApplication::desktop()->height()/2);
  move(QApplication::desktop()->screen()->rect().center() - rect().center());
  secondlayout = new QHBoxLayout(this);
  text_regles = new QTextEdit();
  text_regles->setReadOnly(true);
  std::ostringstream oss;
  oss << "Règles :" << std::endl << std::endl;
  for(int i = 0; i < regles->size(); ++i){
    oss << *(regles->at(i)) << std::endl << std::endl;
  }
  text_regles->setText(QString::fromUtf8(oss.str().c_str()));
  secondlayout->addWidget(text_regles);
}

rulesQt::~rulesQt()
{

}

#include "rulesQt.moc"