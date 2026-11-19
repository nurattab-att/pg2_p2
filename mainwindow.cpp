#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QBrush>

MainWindow::MainWindow(Hospital *hospital, QWidget *parent) //fenster wird erstellt
    : QMainWindow(parent) //initialisiert basisklasse qmainwindow
    , ui(new Ui::MainWindow) //neues objekt für benutzeroberfläche
{
    ui->setupUi(this); //grafische elemente aus dem qt designer werden in unser fenster eingebaut
    this->hospital = hospital;    //übergebene hospitalzeiger werden in attribut gespeiceher
    connect(ui->patientListWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::onPatientItemDoubleClicked);
//doppelklich prrüfung aufgabe3
}
MainWindow::~MainWindow()
{
    delete ui; //gibt speicher frei
}
void MainWindow::on_actionLese_Aufenthalte_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "Aufenthaltsdatei öffnen",
        "",
        "JSON Dateien (*.json)"
        );
    if (!filename.isEmpty())
    {
        hospital->readCaseFile(filename.toStdString());
    }
}
void MainWindow::on_actionLese_ICD_Codes_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "ICD-Datei öffnen",
        "",
        "Textdateien (*.txt)"
        );
    if (!filename.isEmpty())
    {
        hospital->readICDData(filename.toStdString());
    }
}
void MainWindow::on_actionAufenthalts_berblick_triggered()
{
    ui->patientListWidget->clear();
    vector<Patient> patienten = hospital->getPatients();

    if (patienten.empty())
    {
        QMessageBox::warning(this, "Fehler", "Die Patientenliste ist leer!");
        return;
    }

    for (Patient patient : patienten)
    {
        QListWidgetItem *item = new QListWidgetItem(
            QString::fromStdString(patient.showOverview())
            );

        string pruefung = patient.checkInsuranceNumber();

        if (pruefung != "Versicherungsnummer ist gueltig.")
        {
            item->setForeground(QBrush(Qt::red));
        }

        ui->patientListWidget->addItem(item);
    }
}
void MainWindow::onPatientItemDoubleClicked(QListWidgetItem *item)
{
    string fehler = hospital->getPatients()[item->listWidget()->row(item)].checkInsuranceNumber();
    QMessageBox::information(this, "Versicherungsnummer", QString::fromStdString(fehler));
}

