#ifndef STAY_H
#define STAY_H

#include <string>

//aufenthalte mit diagnose verwalten

using namespace std;
class Stay
{
private:
    long patientID;
    long stayID;
    string admissionDate;
    string dischargeDate;
    string mainDiagnosisCode;
    string mainDiagnosisText;
public:
    Stay(long pID, long sID, string aDate, string dDate,
         string diagnosisCode, string diagnosisText);
    string showDetails();
};
#endif
