#include "mainwindow.h"
#include "hospital.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Hospital*hospital = new Hospital("Klinikum");

    MainWindow*mainwindow = new MainWindow (hospital);
    mainwindow->show();

    return a.exec();
}
