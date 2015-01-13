#############################################################################
# Makefile for building: Monopoly
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Jan 13 10:58:16 2015
# Project:  Monopoly.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile Monopoly.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = bank.cpp \
		gameBoard.cpp \
		guiplayer.cpp \
		guiplayerhorizontal.cpp \
		guiplayervertical.cpp \
		house.cpp \
		mainwindow.cpp \
		mainwindow1.cpp \
		PA4.cpp \
		players.cpp \
		space.cpp moc_gameBoard.cpp \
		moc_guiplayer.cpp \
		moc_guiplayerhorizontal.cpp \
		moc_guiplayervertical.cpp \
		moc_mainwindow.cpp \
		moc_mainwindow1.cpp \
		moc_players.cpp
OBJECTS       = bank.o \
		gameBoard.o \
		guiplayer.o \
		guiplayerhorizontal.o \
		guiplayervertical.o \
		house.o \
		mainwindow.o \
		mainwindow1.o \
		PA4.o \
		players.o \
		space.o \
		moc_gameBoard.o \
		moc_guiplayer.o \
		moc_guiplayerhorizontal.o \
		moc_guiplayervertical.o \
		moc_mainwindow.o \
		moc_mainwindow1.o \
		moc_players.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Monopoly.pro
QMAKE_TARGET  = Monopoly
DESTDIR       = 
TARGET        = Monopoly

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Monopoly.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile Monopoly.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Monopoly.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Monopoly1.0.0 || $(MKDIR) .tmp/Monopoly1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Monopoly1.0.0/ && $(COPY_FILE) --parents bank.h gameBoard.h guiplayer.h guiplayerhorizontal.h guiplayervertical.h house.h mainwindow.h mainwindow1.h players.h space.h .tmp/Monopoly1.0.0/ && $(COPY_FILE) --parents bank.cpp gameBoard.cpp guiplayer.cpp guiplayerhorizontal.cpp guiplayervertical.cpp house.cpp mainwindow.cpp mainwindow1.cpp PA4.cpp players.cpp space.cpp .tmp/Monopoly1.0.0/ && (cd `dirname .tmp/Monopoly1.0.0` && $(TAR) Monopoly1.0.0.tar Monopoly1.0.0 && $(COMPRESS) Monopoly1.0.0.tar) && $(MOVE) `dirname .tmp/Monopoly1.0.0`/Monopoly1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Monopoly1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_gameBoard.cpp moc_guiplayer.cpp moc_guiplayerhorizontal.cpp moc_guiplayervertical.cpp moc_mainwindow.cpp moc_mainwindow1.cpp moc_players.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_gameBoard.cpp moc_guiplayer.cpp moc_guiplayerhorizontal.cpp moc_guiplayervertical.cpp moc_mainwindow.cpp moc_mainwindow1.cpp moc_players.cpp
moc_gameBoard.cpp: players.h \
		gameBoard.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gameBoard.h -o moc_gameBoard.cpp

moc_guiplayer.cpp: players.h \
		guiplayer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) guiplayer.h -o moc_guiplayer.cpp

moc_guiplayerhorizontal.cpp: players.h \
		guiplayer.h \
		guiplayerhorizontal.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) guiplayerhorizontal.h -o moc_guiplayerhorizontal.cpp

moc_guiplayervertical.cpp: players.h \
		guiplayer.h \
		guiplayervertical.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) guiplayervertical.h -o moc_guiplayervertical.cpp

moc_mainwindow.cpp: guiplayerhorizontal.h \
		players.h \
		guiplayer.h \
		guiplayervertical.h \
		gameBoard.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_mainwindow1.cpp: mainwindow.h \
		guiplayerhorizontal.h \
		players.h \
		guiplayer.h \
		guiplayervertical.h \
		gameBoard.h \
		mainwindow1.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow1.h -o moc_mainwindow1.cpp

moc_players.cpp: players.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) players.h -o moc_players.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

bank.o: bank.cpp bank.h \
		players.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bank.o bank.cpp

gameBoard.o: gameBoard.cpp gameBoard.h \
		players.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameBoard.o gameBoard.cpp

guiplayer.o: guiplayer.cpp guiplayer.h \
		players.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o guiplayer.o guiplayer.cpp

guiplayerhorizontal.o: guiplayerhorizontal.cpp guiplayerhorizontal.h \
		players.h \
		guiplayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o guiplayerhorizontal.o guiplayerhorizontal.cpp

guiplayervertical.o: guiplayervertical.cpp guiplayervertical.h \
		players.h \
		guiplayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o guiplayervertical.o guiplayervertical.cpp

house.o: house.cpp house.h \
		players.h \
		bank.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o house.o house.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		guiplayerhorizontal.h \
		players.h \
		guiplayer.h \
		guiplayervertical.h \
		gameBoard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

mainwindow1.o: mainwindow1.cpp mainwindow1.h \
		mainwindow.h \
		guiplayerhorizontal.h \
		players.h \
		guiplayer.h \
		guiplayervertical.h \
		gameBoard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow1.o mainwindow1.cpp

PA4.o: PA4.cpp mainwindow.h \
		guiplayerhorizontal.h \
		players.h \
		guiplayer.h \
		guiplayervertical.h \
		gameBoard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PA4.o PA4.cpp

players.o: players.cpp players.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o players.o players.cpp

space.o: space.cpp space.h \
		house.h \
		players.h \
		bank.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o space.o space.cpp

moc_gameBoard.o: moc_gameBoard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameBoard.o moc_gameBoard.cpp

moc_guiplayer.o: moc_guiplayer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_guiplayer.o moc_guiplayer.cpp

moc_guiplayerhorizontal.o: moc_guiplayerhorizontal.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_guiplayerhorizontal.o moc_guiplayerhorizontal.cpp

moc_guiplayervertical.o: moc_guiplayervertical.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_guiplayervertical.o moc_guiplayervertical.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_mainwindow1.o: moc_mainwindow1.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow1.o moc_mainwindow1.cpp

moc_players.o: moc_players.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_players.o moc_players.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

