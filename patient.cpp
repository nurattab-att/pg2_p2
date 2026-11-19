#include "patient.h"

Patient::Patient(long pID, string bDate, string fName,
                 string lName, string insurance, Gender g)
{
    patientID = pID;
    birthDate = bDate;
    firstName = fName;
    lastName = lName;
    insuranceNumber = insurance;
    gender = g;
}
void Patient::addStay(Stay stay)
{
    stays.push_back(stay);
}
string Patient::getInsuranceNumber()
{
    return insuranceNumber;
}
string Patient::checkInsuranceNumber()
{
    if (insuranceNumber.length() != 20)
        return "Versicherungsnummer hat falsche Laenge.";
    if (insuranceNumber[0] < 'A' || insuranceNumber[0] > 'Z')
        return "Ungueltiger Anfangsbuchstabe.";

    for (int i = 1; i < 20; i++)
    {
        if (insuranceNumber[i] < '0' || insuranceNumber[i] > '9')
            return "Versicherungsnummer enthaelt ungueltige Zeichen.";
    }

    int letterValue = insuranceNumber[0] - 'A' + 1;

    string letterCode =
        (letterValue < 10 ? "0" : "") + to_string(letterValue);

    auto calculateCheckDigit = [](string number)
    {
        int sum = 0;

        for (int i = 0; i < number.length(); i++)
        {
            int digit = number[i] - '0';

            int product = digit * ((i % 2 == 0) ? 1 : 2);

            sum += product / 10 + product % 10;
        }

        return sum % 10;
    };

    string firstPart = letterCode + insuranceNumber.substr(1, 8);

    string secondPart = letterCode + insuranceNumber.substr(1, 18);

    int checkDigit1 = calculateCheckDigit(firstPart);
    int checkDigit2 = calculateCheckDigit(secondPart);

    string result = "";

    if (checkDigit1 != insuranceNumber[9] - '0')
    {
        result += "Pruefziffer 10 falsch. Richtig waere: "
                  + to_string(checkDigit1) + "\n";

    }



    else if (checkDigit2 != insuranceNumber[19] - '0')
    {
        result += "Pruefziffer 20 falsch. Richtig waere: "
                  + to_string(checkDigit2) + "\n";
    }

    if (result.empty())
        result = "Versicherungsnummer ist gueltig.";

    return result;
}

long Patient::getPatientID()
{
    return patientID;
}
string Patient::showOverview()
{
    string result;
    result += "--------------------------------------\n";
    result += "Patient*in " + to_string(patientID) + ": ";
    result += firstName + " " + lastName + "\n";

    result += "Versicherungsnummer: ";
    result += insuranceNumber + "\n";

    result += "Geschlecht: ";

    if (gender == male)
        result += "maennlich";
    else if (gender == female)
        result += "weiblich";
    else
        result += "nicht binaer";

    result += ", Geburtsdatum: " + birthDate + "\n";
    result += "Aufenthalte:\n";

    for (Stay stay : stays)
    {
        result += stay.showDetails();
    }

    return result;
}
