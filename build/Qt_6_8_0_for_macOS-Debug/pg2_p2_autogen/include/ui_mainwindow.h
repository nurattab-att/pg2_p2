/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAufenthalte;
    QAction *actionLese_Aufenthalte;
    QAction *actionLese_ICD_Codes;
    QAction *actionAufenthalts_berblick;
    QWidget *centralwidget;
    QListWidget *patientListWidget;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuAufenthalte;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionAufenthalte = new QAction(MainWindow);
        actionAufenthalte->setObjectName("actionAufenthalte");
        actionLese_Aufenthalte = new QAction(MainWindow);
        actionLese_Aufenthalte->setObjectName("actionLese_Aufenthalte");
        actionLese_ICD_Codes = new QAction(MainWindow);
        actionLese_ICD_Codes->setObjectName("actionLese_ICD_Codes");
        actionAufenthalts_berblick = new QAction(MainWindow);
        actionAufenthalts_berblick->setObjectName("actionAufenthalts_berblick");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        patientListWidget = new QListWidget(centralwidget);
        patientListWidget->setObjectName("patientListWidget");
        patientListWidget->setGeometry(QRect(0, 0, 801, 401));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuAufenthalte = new QMenu(menubar);
        menuAufenthalte->setObjectName("menuAufenthalte");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName("toolBar_3");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_3);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuAufenthalte->menuAction());
        menuDatei->addAction(actionAufenthalte);
        menuAufenthalte->addAction(actionLese_Aufenthalte);
        menuAufenthalte->addAction(actionLese_ICD_Codes);
        menuAufenthalte->addAction(actionAufenthalts_berblick);
        toolBar_3->addAction(actionLese_Aufenthalte);
        toolBar_3->addAction(actionLese_ICD_Codes);
        toolBar_3->addAction(actionAufenthalts_berblick);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAufenthalte->setText(QCoreApplication::translate("MainWindow", "Aufenthalte", nullptr));
        actionLese_Aufenthalte->setText(QCoreApplication::translate("MainWindow", "Lese Aufenthalte", nullptr));
        actionLese_ICD_Codes->setText(QCoreApplication::translate("MainWindow", "Lese ICD Codes", nullptr));
        actionAufenthalts_berblick->setText(QCoreApplication::translate("MainWindow", "Aufenthalts\303\274berblick", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuAufenthalte->setTitle(QCoreApplication::translate("MainWindow", "Aufenthalte", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
