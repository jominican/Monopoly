#include <iostream>

using namespace std;
 /****************************************************************************
 **
 ** Copyright (C) 2004-2008 Trolltech ASA. All rights reserved.
 **
 ** This file is part of the documentation of the Qt Toolkit.
 **
 ** This file may be used under the terms of the GNU General Public
** License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file.  Alternatively you may (at
** your option) use any later version of the GNU General Public
** License if such license has been publicly approved by Trolltech ASA
** (or its successors, if any) and the KDE Free Qt Foundation. In
** addition, as a special exception, Trolltech gives you certain
** additional rights. These rights are described in the Trolltech GPL
** Exception version 1.2, which can be found at
** http://www.trolltech.com/products/qt/gplexception/ and in the file
** GPL_EXCEPTION.txt in this package.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/. If
** you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** In addition, as a special exception, Trolltech, as the sole
** copyright holder for Qt Designer, grants users of the Qt/Eclipse
** Integration plug-in the right for the Qt/Eclipse Integration to
** link to functionality provided by Qt Designer and its related
** libraries.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not expressly
** granted herein.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/

 #include <QtGui>

 #include "mainwindow1.h"

 MainWindow1::MainWindow1()
 {
     textEdit = new QTextEdit;
     setCentralWidget(textEdit);

     createActions();
     createMenus();
     createToolBars();
     createStatusBar();

     readSettings();

     connect(textEdit->document(), SIGNAL(contentsChanged()),
             this, SLOT(documentWasModified()));

     setCurrentFile("");
		mainwindow = new MainWindow();
 }

 void MainWindow1::closeEvent(QCloseEvent *event)
 {
     if (maybeSave()) {
         writeSettings();
         event->accept();
     } else {
         event->ignore();
     }
 }

 void MainWindow1::newFile()
 {
     if (maybeSave()) {
         textEdit->clear();
         setCurrentFile("");
     }
 }

 void MainWindow1::open()
 {
     if (maybeSave()) {
         QString fileName = QFileDialog::getOpenFileName(this);
         if (!fileName.isEmpty())
             loadFile(fileName);
     }
 }

 bool MainWindow1::save()
 {
     if (curFile.isEmpty()) {
         return saveAs();
     } else {
         return saveFile(curFile);
     }
 }

 bool MainWindow1::saveAs()
 {
     QString fileName = QFileDialog::getSaveFileName(this);
     if (fileName.isEmpty())
         return false;

     return saveFile(fileName);
 }

 void MainWindow1::about()
 {
    QMessageBox::about(this, tr("About the Game"),
             tr("Rules:: This game is similar to an actual Monopoly game where players will go around the board buying properties, upgrading properties, drawing cards, and landing on spaces that teleports you random places. One thing to note that this is speed Monopoly where all the properties are on the top and bottom row and the rent increases by a lot when a house is bought/upgraded. The money gain/loss will be updated when a card is drawn, a space is landed, or after every turn. Once a player's money drops below $0, the game will end. The game will end when a player resign as well. As soon as one player resigns or loses due to negative money, whoever has the most money at that time will be declared the winner. In this game, there are no rules for every player to take turns. In effect, any player can go at any time to simulate a real-life monopoly game where people can keep rolling if they wish or they can skip a player's turn as punishment. Also, a player is forced to buy/upgrade a property every time. If after a player buy/upgrade a property has no money left, he will automatically lose. Gameplay:: Everyone will choose a player by gamepiece. You first click on the player you want to be: p1, p2, p3 ,p4. Then click on the piece you want to be. Each player has their own player dice, so the player can only move by rolling their respective die. The dices will not be enabled until at least two players join the game. Any additional player can join the game at any time by clicking on the leftover player slot and pieces. The first player to reach a community chest/chance space will not be able to draw a card, all subsequent landing on that space wil be able to draw a card."));
 }

 void MainWindow1::documentWasModified()
 {
     setWindowModified(textEdit->document()->isModified());
 }

 void MainWindow1::createActions()
 {
     newAct = new QAction(tr("&New"), this);
     newAct->setShortcut(tr("Ctrl+N"));
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(openNewWindow()));

     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcut(tr("Ctrl+O"));
     openAct->setStatusTip(tr("Open an existing file"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     saveAct = new QAction(tr("&Save"), this);
     saveAct->setShortcut(tr("Ctrl+S"));
     saveAct->setStatusTip(tr("Save the document to disk"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     saveAsAct = new QAction(tr("Save &As..."), this);
     saveAsAct->setStatusTip(tr("Save the document under a new name"));
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcut(tr("Ctrl+Q"));
     exitAct->setStatusTip(tr("Exit the application"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     cutAct = new QAction(tr("Cu&t"), this);
     cutAct->setShortcut(tr("Ctrl+X"));
     cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                             "clipboard"));
     connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

     copyAct = new QAction(tr("&Copy"), this);
     copyAct->setShortcut(tr("Ctrl+C"));
     copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                              "clipboard"));
     connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

     pasteAct = new QAction(tr("&Paste"), this);
     pasteAct->setShortcut(tr("Ctrl+V"));
     pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                               "selection"));
     connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

     cutAct->setEnabled(false);
     copyAct->setEnabled(false);
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             cutAct, SLOT(setEnabled(bool)));
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             copyAct, SLOT(setEnabled(bool)));
 }

 void MainWindow1::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(newAct);
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAct);
     fileMenu->addAction(saveAsAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     editMenu = menuBar()->addMenu(tr("&Edit"));
     editMenu->addAction(cutAct);
     editMenu->addAction(copyAct);
     editMenu->addAction(pasteAct);

     menuBar()->addSeparator();

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);

		QMenu *mymenu = menuBar()->addMenu( tr("&New Game") );

     QAction* myAct = new QAction(tr("&Open A Game"), this);
     myAct->setShortcut(tr("Ctrl+M"));
     myAct->setStatusTip(tr("Do my action"));
     connect(myAct, SIGNAL(triggered()), this, SLOT(openNewWindow()));
			mymenu->addAction(myAct);

		/*QMenu *mymenu2 = menuBar()->addMenu( tr("&Choose Number of Players") );

		  QAction* myAct1 = new QAction(tr("&2"), this);
     myAct1->setShortcut(tr("Ctrl+2"));
     myAct1->setStatusTip(tr("Do my action"));
     connect(myAct1, SIGNAL(triggered()), this, SLOT(myFunction()));
			mymenu2->addAction(myAct1);

		  QAction* myAct2 = new QAction(tr("&3"), this);
     myAct2->setShortcut(tr("Ctrl+3"));
     myAct2->setStatusTip(tr("Do my action"));
     connect(myAct2, SIGNAL(triggered()), this, SLOT(myFunction()));
			mymenu2->addAction(myAct2);

		  QAction* myAct3 = new QAction(tr("&4"), this);
     myAct3->setShortcut(tr("Ctrl+4"));
     myAct3->setStatusTip(tr("Do my action"));
     connect(myAct3, SIGNAL(triggered()), this, SLOT(myFunction()));
			mymenu2->addAction(myAct3);*/


 }

void MainWindow1::myFunction()
{
	//mainwindow->choosePlayer2();
}

void MainWindow1::openNewWindow()
{
	mainwindow->show();
}

 void MainWindow1::createToolBars()
 {
     fileToolBar = addToolBar(tr("File"));
     fileToolBar->addAction(newAct);
     fileToolBar->addAction(openAct);
     fileToolBar->addAction(saveAct);

     editToolBar = addToolBar(tr("Edit"));
     editToolBar->addAction(cutAct);
     editToolBar->addAction(copyAct);
     editToolBar->addAction(pasteAct);
 }

 void MainWindow1::createStatusBar()
 {
     statusBar()->showMessage(tr("Ready"));
 }

 void MainWindow1::readSettings()
 {
     QSettings settings("Trolltech", "Application Example");
     QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
     QSize size = settings.value("size", QSize(400, 400)).toSize();
     resize(size);
     move(pos);
 }

 void MainWindow1::writeSettings()
 {
     QSettings settings("Trolltech", "Application Example");
     settings.setValue("pos", pos());
     settings.setValue("size", size());
 }

 bool MainWindow1::maybeSave()
 {
     if (textEdit->document()->isModified()) {
         QMessageBox::StandardButton ret;
         ret = QMessageBox::warning(this, tr("Application"),
                      tr("The document has been modified.\n"
                         "Do you want to save your changes?"),
                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         if (ret == QMessageBox::Save)
             return save();
         else if (ret == QMessageBox::Cancel)
             return false;
     }
     return true;
 }

 void MainWindow1::loadFile(const QString &fileName)
 {
     QFile file(fileName);
     if (!file.open(QFile::ReadOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Application"),
                              tr("Cannot read file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     QTextStream in(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     textEdit->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();

     setCurrentFile(fileName);
     statusBar()->showMessage(tr("File loaded"), 2000);
 }

 bool MainWindow1::saveFile(const QString &fileName)
 {
     QFile file(fileName);
     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Application"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return false;
     }

     QTextStream out(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     out << textEdit->toPlainText();
     QApplication::restoreOverrideCursor();

     setCurrentFile(fileName);
     statusBar()->showMessage(tr("File saved"), 2000);
     return true;
 }

 void MainWindow1::setCurrentFile(const QString &fileName)
 {
     curFile = fileName;
     textEdit->document()->setModified(false);
     setWindowModified(false);

     QString shownName;
     if (curFile.isEmpty())
         shownName = "untitled.txt";
     else
         shownName = strippedName(curFile);

     setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Application")));
 }

 QString MainWindow1::strippedName(const QString &fullFileName)
 {
     return QFileInfo(fullFileName).fileName();
 }
