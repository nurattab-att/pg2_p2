#include "hospital.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <iostream>
#include <fstream>
#include <sstream>

//jsondatei einlesen, icd codes speicher, patienten verwalten, neue map icdcodes diagnosis




Hospital::Hospital(string hospitalName)
{
    name = hospitalName;
}
// ICD-DATEI EINLESEN
void Hospital::readICDData(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string column;
        vector<string> columns;

        while (getline(ss, column, ';'))
        {
            columns.push_back(column);
        }

        if (columns.size() >= 9)
        {
            string code = columns[5];
            string diagnosis = columns[8];

            icdCodes[code] = diagnosis;
        }
    }

    file.close();

    icdLoaded = true;
}
// JSON-DATEI EINLESEN
void Hospital::readCaseFile(string filename)
{

    QFile file(QString::fromStdString(filename));

    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QJsonParseError error;

    QJsonDocument document =
        QJsonDocument::fromJson(file.readAll(), &error);

    file.close();

    if (error.error != QJsonParseError::NoError)
        return;

    if (!document.isArray())
        return;

    QJsonArray array = document.array();

    patients.clear();

    long stayID = 1;

    for (const QJsonValue &value : array)
    {
        QJsonObject object = value.toObject();

        string admissionDate =
            object["admissionDate"].toString().toStdString();

        string dischargeDate =
            object["dischargeDate"].toString().toStdString();

        string diagnosisCode =
            object["mainDiagnosis"].toString().toStdString();

        string firstName =
            object["firstName"].toString().toStdString();

        string lastName =
            object["lastName"].toString().toStdString();

        string birthDate =
            object["birthDate"].toString().toStdString();

        string insuranceNumber =
            object["insuranceNumber"].toString().toStdString();

        string genderString =
            object["gender"].toString().toStdString();


        // GESCHLECHT BESTIMMEN

        Gender gender;

        if (genderString == "M")
            gender = male;
        else if (genderString == "W")
            gender = female;
        else
            gender = nonBinary;


        // DIAGNOSE SUCHEN

        string diagnosisText = "Diagnose nicht gefunden";

        if (icdCodes.find(diagnosisCode) != icdCodes.end())
        {
            diagnosisText = icdCodes[diagnosisCode];
        }


        // PATIENT SUCHEN

        int patientIndex = -1;

        for (int i = 0; i < patients.size(); i++)
        {
            if (patients[i].getInsuranceNumber() == insuranceNumber)
            {
                patientIndex = i;
                break;
            }
        }


        // NEUEN PATIENTEN ERSTELLEN

        if (patientIndex == -1)
        {
            long patientID = patients.size() + 1;

            Patient newPatient(
                patientID,
                birthDate,
                firstName,
                lastName,
                insuranceNumber,
                gender
                );

            patients.push_back(newPatient);

            patientIndex = patients.size() - 1;
        }


        // AUFENTHALT ERSTELLEN

        long patientID = patients[patientIndex].getPatientID();

        Stay newStay(
            patientID,
            stayID,
            admissionDate,
            dischargeDate,
            diagnosisCode,
            diagnosisText
            );

        patients[patientIndex].addStay(newStay);

        stayID++;
    }
}
// PATIENTENLISTE
string Hospital::printPatientList() //für grafische darstellung
{
    string result;
    for (Patient patient : patients)
    {
        result += patient.showOverview();
        result += "Versicherungsnummer-Pruefung: " + patient.checkInsuranceNumber() + "\n";
        result += "\n";
    }

    return result;
}

vector<Patient> Hospital::getPatients()
{
    return patients;
}
