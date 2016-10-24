
#authors: Corentin Talarmain, Nicolas Roux, Théo Voillemin
CPP = *.cpp

FLAGS = -O3 -I/usr/include/qt4 -l QtCore -l QtGui -Wall -std=c++11 

all: 
	moc displayQt.h -o moc_displayqt.cpp
	moc ajoutQt.h -o moc_ajoutqt.cpp 
	g++ displayQt.cpp moc_displayqt.cpp ajoutQt.cpp moc_ajoutqt.cpp main.cpp $(FLAGS) -o test.exe

clean:
	@echo "-> Clean project"
	rm -rf *.exe