#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "stay.h"

// versicherungsnr und prüfziffer
using namespace std;
enum Gender
{
    male,
    female,
    nonBinary
};
class Patient
{
private:
    long patientID;
    string birthDate;
    string firstName;
    string lastName;
    string insuranceNumber;
    Gender gender;
    vector<Stay> stays;
public:
    Patient(long pID, string bDate, string fName,
            string lName, string insurance, Gender g);
    void addStay(Stay stay);

    string getInsuranceNumber();
    string checkInsuranceNumber(); //aufgabe 3

    long getPatientID();

    string showOverview();
};
#endif
