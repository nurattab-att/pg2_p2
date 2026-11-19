#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hospital.h"
class QListWidgetItem;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow //mainwindow erbt von qmainwindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Hospital *hospital; //zeiger auf hospital objekt;zeiger ermöglicht zugriff ohne eine zweite hospitalinstanz zu erstellen
public:
    MainWindow(Hospital *hospital, QWidget *parent = nullptr);
    ~MainWindow();

private slots: //spezielle qt funktionen die auf signale reagieren können
    void on_actionLese_Aufenthalte_triggered(); //triggerd wird bsp ausgelöst wenn jmd auf einen menüeintrag klickt
    void on_actionLese_ICD_Codes_triggered();
    void on_actionAufenthalts_berblick_triggered();
    void onPatientItemDoubleClicked(QListWidgetItem *item);
};
#endif
