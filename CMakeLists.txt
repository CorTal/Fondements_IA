cmake_minimum_required(VERSION 2.6)
project(qt_systeme_expert)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(qt_systeme_expert_SRCS rulesQt.cpp Moteur.cpp variableQt.cpp solveQt.cpp ajoutQt.cpp displayQt.cpp Predicat.cpp Regle.cpp Variable.cpp main.cpp)

qt4_automoc(${qt_systeme_expert_SRCS})
add_executable(qt_systeme_expert ${qt_systeme_expert_SRCS})
add_definitions(-std=c++11)
target_link_libraries(qt_systeme_expert ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS qt_systeme_expert RUNTIME DESTINATION bin)
