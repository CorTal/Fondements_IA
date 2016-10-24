# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/coco/ia/qt/Fondements_IA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/coco/ia/qt/Fondements_IA

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/coco/ia/qt/Fondements_IA/CMakeFiles /home/coco/ia/qt/Fondements_IA/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/coco/ia/qt/Fondements_IA/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named qt_systeme_expert

# Build rule for target.
qt_systeme_expert: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 qt_systeme_expert
.PHONY : qt_systeme_expert

# fast build rule for target.
qt_systeme_expert/fast:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/build
.PHONY : qt_systeme_expert/fast

Moteur.o: Moteur.cpp.o

.PHONY : Moteur.o

# target to build an object file
Moteur.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Moteur.cpp.o
.PHONY : Moteur.cpp.o

Moteur.i: Moteur.cpp.i

.PHONY : Moteur.i

# target to preprocess a source file
Moteur.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Moteur.cpp.i
.PHONY : Moteur.cpp.i

Moteur.s: Moteur.cpp.s

.PHONY : Moteur.s

# target to generate assembly for a file
Moteur.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Moteur.cpp.s
.PHONY : Moteur.cpp.s

Predicat.o: Predicat.cpp.o

.PHONY : Predicat.o

# target to build an object file
Predicat.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Predicat.cpp.o
.PHONY : Predicat.cpp.o

Predicat.i: Predicat.cpp.i

.PHONY : Predicat.i

# target to preprocess a source file
Predicat.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Predicat.cpp.i
.PHONY : Predicat.cpp.i

Predicat.s: Predicat.cpp.s

.PHONY : Predicat.s

# target to generate assembly for a file
Predicat.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Predicat.cpp.s
.PHONY : Predicat.cpp.s

Regle.o: Regle.cpp.o

.PHONY : Regle.o

# target to build an object file
Regle.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Regle.cpp.o
.PHONY : Regle.cpp.o

Regle.i: Regle.cpp.i

.PHONY : Regle.i

# target to preprocess a source file
Regle.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Regle.cpp.i
.PHONY : Regle.cpp.i

Regle.s: Regle.cpp.s

.PHONY : Regle.s

# target to generate assembly for a file
Regle.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Regle.cpp.s
.PHONY : Regle.cpp.s

Variable.o: Variable.cpp.o

.PHONY : Variable.o

# target to build an object file
Variable.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Variable.cpp.o
.PHONY : Variable.cpp.o

Variable.i: Variable.cpp.i

.PHONY : Variable.i

# target to preprocess a source file
Variable.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Variable.cpp.i
.PHONY : Variable.cpp.i

Variable.s: Variable.cpp.s

.PHONY : Variable.s

# target to generate assembly for a file
Variable.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/Variable.cpp.s
.PHONY : Variable.cpp.s

ajoutQt.o: ajoutQt.cpp.o

.PHONY : ajoutQt.o

# target to build an object file
ajoutQt.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/ajoutQt.cpp.o
.PHONY : ajoutQt.cpp.o

ajoutQt.i: ajoutQt.cpp.i

.PHONY : ajoutQt.i

# target to preprocess a source file
ajoutQt.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/ajoutQt.cpp.i
.PHONY : ajoutQt.cpp.i

ajoutQt.s: ajoutQt.cpp.s

.PHONY : ajoutQt.s

# target to generate assembly for a file
ajoutQt.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/ajoutQt.cpp.s
.PHONY : ajoutQt.cpp.s

displayQt.o: displayQt.cpp.o

.PHONY : displayQt.o

# target to build an object file
displayQt.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/displayQt.cpp.o
.PHONY : displayQt.cpp.o

displayQt.i: displayQt.cpp.i

.PHONY : displayQt.i

# target to preprocess a source file
displayQt.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/displayQt.cpp.i
.PHONY : displayQt.cpp.i

displayQt.s: displayQt.cpp.s

.PHONY : displayQt.s

# target to generate assembly for a file
displayQt.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/displayQt.cpp.s
.PHONY : displayQt.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/main.cpp.s
.PHONY : main.cpp.s

rulesQt.o: rulesQt.cpp.o

.PHONY : rulesQt.o

# target to build an object file
rulesQt.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/rulesQt.cpp.o
.PHONY : rulesQt.cpp.o

rulesQt.i: rulesQt.cpp.i

.PHONY : rulesQt.i

# target to preprocess a source file
rulesQt.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/rulesQt.cpp.i
.PHONY : rulesQt.cpp.i

rulesQt.s: rulesQt.cpp.s

.PHONY : rulesQt.s

# target to generate assembly for a file
rulesQt.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/rulesQt.cpp.s
.PHONY : rulesQt.cpp.s

solveQt.o: solveQt.cpp.o

.PHONY : solveQt.o

# target to build an object file
solveQt.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/solveQt.cpp.o
.PHONY : solveQt.cpp.o

solveQt.i: solveQt.cpp.i

.PHONY : solveQt.i

# target to preprocess a source file
solveQt.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/solveQt.cpp.i
.PHONY : solveQt.cpp.i

solveQt.s: solveQt.cpp.s

.PHONY : solveQt.s

# target to generate assembly for a file
solveQt.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/solveQt.cpp.s
.PHONY : solveQt.cpp.s

variableQt.o: variableQt.cpp.o

.PHONY : variableQt.o

# target to build an object file
variableQt.cpp.o:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/variableQt.cpp.o
.PHONY : variableQt.cpp.o

variableQt.i: variableQt.cpp.i

.PHONY : variableQt.i

# target to preprocess a source file
variableQt.cpp.i:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/variableQt.cpp.i
.PHONY : variableQt.cpp.i

variableQt.s: variableQt.cpp.s

.PHONY : variableQt.s

# target to generate assembly for a file
variableQt.cpp.s:
	$(MAKE) -f CMakeFiles/qt_systeme_expert.dir/build.make CMakeFiles/qt_systeme_expert.dir/variableQt.cpp.s
.PHONY : variableQt.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install"
	@echo "... rebuild_cache"
	@echo "... list_install_components"
	@echo "... qt_systeme_expert"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... edit_cache"
	@echo "... Moteur.o"
	@echo "... Moteur.i"
	@echo "... Moteur.s"
	@echo "... Predicat.o"
	@echo "... Predicat.i"
	@echo "... Predicat.s"
	@echo "... Regle.o"
	@echo "... Regle.i"
	@echo "... Regle.s"
	@echo "... Variable.o"
	@echo "... Variable.i"
	@echo "... Variable.s"
	@echo "... ajoutQt.o"
	@echo "... ajoutQt.i"
	@echo "... ajoutQt.s"
	@echo "... displayQt.o"
	@echo "... displayQt.i"
	@echo "... displayQt.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... rulesQt.o"
	@echo "... rulesQt.i"
	@echo "... rulesQt.s"
	@echo "... solveQt.o"
	@echo "... solveQt.i"
	@echo "... solveQt.s"
	@echo "... variableQt.o"
	@echo "... variableQt.i"
	@echo "... variableQt.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

