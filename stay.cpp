#include "stay.h"

Stay::Stay(long pID, long sID, string aDate, string dDate,
           string diagnosisCode, string diagnosisText)
{
    patientID = pID;
    stayID = sID;
    admissionDate = aDate;
    dischargeDate = dDate;
    mainDiagnosisCode = diagnosisCode;
    mainDiagnosisText = diagnosisText;
}
string Stay::showDetails()
{
    string result;
    result += to_string(stayID) + ": von " + admissionDate;

    if (dischargeDate == "")
        result += " bis noch nicht entlassen\n";
    else
        result += " bis " + dischargeDate + "\n";

    result += "Aufnahmediagnose: ";
    result += mainDiagnosisCode + " " + mainDiagnosisText + "\n";

    return result;
}
