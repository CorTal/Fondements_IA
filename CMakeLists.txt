cmake_minimum_required(VERSION 2.6)
project(test)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(test_SRCS rulesQt.cpp Moteur.cpp variableQt.cpp solveQt.cpp ajoutQt.cpp displayQt.cpp Predicat.cpp Regle.cpp Variable.cpp main.cpp)

qt4_automoc(${test_SRCS})
add_executable(test ${test_SRCS})
target_link_libraries(test ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS test RUNTIME DESTINATION bin)
