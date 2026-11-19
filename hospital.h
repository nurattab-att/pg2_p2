#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include <map>
#include "patient.h"
using namespace std;
class Hospital
{
private:
    string name;
    vector<Patient> patients;
    map<string, string> icdCodes;
    bool icdLoaded = false;
public:
    Hospital(string hospitalName);
    void readICDData(string filename);

    void readCaseFile(string filename);

    string printPatientList();
    vector<Patient> getPatients(); //aufgabe 3
};
#endif
