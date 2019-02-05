// Filename:     prog03.cpp
// Author:       Mathew Walker, CS116, Winter 2015
// Description:  This program processes data from an input file (using a loop) and creates a chart in an output file 
//               displaying the patient's name, identification number, exam scores, average, and risk level. It then 
//               prints a summary including a histogram of risk levels, percentages of male and female, valid and invalid, 
//               and reports the maximum and minumum.
//DESIGN
    //1. Preprocessor directives
    //2. Function declarations(prototypes)
    //3. OPENS main function
    //4. DECLARES variables
    //5. Function declaration for PRINTING column headers
    //6. Function declaration for reading input file, PREPARING loop
    //7. LOOPS through the input file until the end
        //7a. RESETS valid and avererage for every loop
        //7b. COUNTS the number of male and female patients
        //7c. CHECKS validity of the exam scores
        //7d. If the exam scores are valid this sets up the histograms, counts the valid scores, sets the minimum and 
        //    maximum scores, and sets colors to risk levels
        //7e. Keeps track of invalid scores and sets up the histograms for invalid scores
        //7f. function declaration for printing chart to output file
        //7g. SETS variables up with data for the next loop
    //8. Function declarations for printing the summary including a histogram, percentages, and min max
    //9. Function definitions


//1. Preprocessor directives
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

//2. Function declarations(prototypes)
void printHeader (ofstream& outData);
void readrecord(ifstream& inData, string& patientName, int& patientID, string& gender, float& exam1, float& exam2, float& exam3);
float computeAverage(float& avg, float& exam1, float& exam2, float& exam3);
void printRecord(ofstream& outData, bool& valid, string& patientName, int& patientID, string& gender, float& exam1, float& exam2, float& exam3, float& avg, string& risk, string& invalid);
void printHistogram(ofstream& outData, string& red, string& orange, string& yellow, string& blue, string& green, string& lowExam, string& midExam, string& highExam, string& invExam, string& invReport);
void printPercentages(ofstream& outData, int& male, int& female, float& validCount, float& invalidCount);
void printMinMax(ofstream& outData, float& max, float& min, int& maxID, int& minID);

//3. OPENS main function
int main()
{
    //4. DECLARES variables
    ifstream inData;
    ofstream outData;
    inData.open("in.data");
    outData.open("out.data");
    string patientName, risk, gender, star, red, orange, yellow, blue, green, invalid = "~~Invalid Data~~", lowExam = "", midExam = "", highExam = "", invExam = "", invReport = "";
    int patientID, male, female, maxID, minID;
    float exam1, exam2, exam3, validCount, invalidCount = 0.00, avg, max, min = 100.00;
    bool valid = true;

    
    //5. Function declaration for PRINTING column headers
    printHeader(outData);
    //6. Function declaration for reading input file, PREPARING loop
    readrecord(inData, patientName, patientID, gender, exam1, exam2, exam3);   
    
    //7. LOOPS through the input file until the end
    while (inData)
    {
        //7a. RESETS valid and avererage for every loop
        avg = 0;
        valid = true;
        

        //7b. COUNTS the number of male and female patients
        if (gender == "M") male++;
        else female++;
        
        //7c. CHECKS validity of the exam scores
        if (exam1 < 0 || exam1 > 100) valid = false;
        if (exam2 < 0 || exam2 > 100) valid = false;
        if (exam3 < 0 || exam3 > 100) valid = false;
        

        //7d. If the exam scores are valid this sets up the histograms, counts the valid scores, sets the minimum and 
        //    maximum scores, and sets colors to risk levels
        if (valid)
        {
            computeAverage(avg, exam1, exam2, exam3);
            validCount ++;
            if (exam1 <= 70) lowExam += "*";
            if (exam1 < 97 && exam1 > 70) midExam += "*";
            if (exam1 >= 97) highExam += "*";
            if (exam2 <= 70) lowExam += "*";
            if (exam2 < 97 && exam2 > 70) midExam += "*";
            if (exam2 >= 97) highExam += "*";
            if (exam3 <= 70) lowExam += "*";
            if (exam3 < 97 && exam3 > 70) midExam += "*";
            if (exam3 >= 97) highExam += "*";
            
            if (avg > 97.00) 
            {
                risk = "RED";
                red = red + "*";
                if (avg > max)
                    max = avg;
                    maxID = patientID;
            }
                if (avg <= 97.00 and avg > 88.00) 
                {
                    risk = "ORANGE";
                    orange = orange + "*";
                }
                    if (avg <= 88.00 and avg > 78.00)  
                    {
                        risk = "YELLOW";
                        yellow = yellow + "*";
                    }
                        if (avg <= 78 and avg > 70)  
                        {
                            risk = "BLUE"; 
                            blue = blue + "*";
                        }
                            if (avg <= 70) 
                            {
                                risk = "GREEN"; 
                                green = green + "*";
                                if (avg < min)
                                min = avg;
                                minID = patientID;
                            }
        }
        //7e. Keeps track of invalid scores and sets up the histograms for invalid scores
        else {
            invalidCount ++;
            invExam += "***";
            invReport += "*";
        }
        //7f. function declaration for printing chart to output file
        printRecord(outData, valid, patientName, patientID, gender, exam1, exam2, exam3, avg, risk, invalid);


        //7g. SETS variables up with data for the next loop
        readrecord(inData, patientName, patientID, gender, exam1, exam2, exam3);
    }

//8. Function declarations for printing the summary including a histogram, percentages, and min max
printHistogram(outData, red, orange, yellow, blue, green, lowExam, midExam, highExam, invExam, invReport);
printPercentages(outData, male, female, validCount, invalidCount);
printMinMax(outData, max, min, maxID, minID);

return 0;
}

//9. Function definitions 
void printHeader(ofstream& outData)
{
    //Pre: Outdata must be declared
    //Post: Column headers have been printed to output file
    outData << "*~~<Patient Exam Report>~~*" << endl;
    outData << setfill(' ') << setw(15) << left << "Name";
    outData << setw(5) << left << "Pat.";
    outData << setw(5) << left << "M/F";
    outData << setw(7) << left << "Exam1";
    outData << setw(7) << left << "Exam2";
    outData << setw(7) << left << "Exam3";
    outData << setw(10) << left << "AVG";
    outData << setw(10) << left << "Risk Level";
    outData << endl;
    
    outData << setfill(' ') << setw(15) << left << "----";
    outData << setw(5) << left << "----";
    outData << setw(5) << left << "---";
    outData << setw(7) << left << "-----";
    outData << setw(7) << left << "-----";
    outData << setw(7) << left << "-----";
    outData << setw(10) << left << "-----";
    outData << setw(10) << left << "----------";
    outData << endl;

}

void readrecord(ifstream& inData, string& patientName, int& patientID, string& gender, float& exam1, float& exam2, float& exam3)
{
    inData >> patientName >> patientID >> gender >> exam1 >> exam2 >> exam3;

    // Pre: record has not been read
    // Post: record has been read into variables
}

float computeAverage(float& avg, float& exam1, float& exam2, float& exam3)
{
    avg = (exam1 + exam2 + exam3) / 3;
    return avg;
    // Pre: average has not been calculated
    // Post: average has been calculated
}

void printRecord(ofstream& outData, bool& valid, string& patientName, int& patientID, string& gender, float& exam1, float& exam2, float& exam3, float& avg, string& risk, string& invalid)
{
        //Pre: all variables must have been declared and processed
        //Post: all variables have been printed to diagram
        if (valid)
        {
            outData << setfill(' ') << setprecision(2) << fixed << setw(15) << left << patientName;
            outData << setw(5) << left << patientID;
            outData << setw(5) << left << gender;
            outData << setw(7) << left << exam1;
            outData << setw(7) << left << exam2;
            outData << setw(7) << left << exam3;
            outData << setw(10) << left << avg;
            outData << setw(10) << left << risk;
            outData << endl;
        }
        
        else
        {
            outData << setfill(' ') << setw(15) << left << patientName;
            outData << setw(5) << left << patientID;
            outData << setw(5) << left << gender;
            outData << setw(7) << left << exam1;
            outData << setw(7) << left << exam2;
            outData << setw(7) << left << exam3;
            outData << setw(20) << left << invalid;
            outData << endl;  
        
        }
}

void printHistogram(ofstream& outData, string& red, string& orange, string& yellow, string& blue, string& green, string& lowExam, string& midExam, string& highExam, string& invExam, string& invReport)
{   
   //Pre: variables must have been declared and processed
   //Post: Histograms have been printed to the summary of the output file
    outData << " " << endl;
    outData << "Exam Summary (If record invalid, all exam scores counted invalid)" << endl;
    outData << "------------" << endl;
    outData << setw(8) << left << "<=70";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << lowExam << endl;
    outData << setw(8) << left << ">70, <97";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << midExam << endl;
    outData << setw(8) << left << ">=97";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << highExam << endl;
    outData << setw(8) << left << "Invalid";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << invExam << endl;
    outData << " " << endl;
    outData << "Patient Summary" << endl;
    outData << "---------------" << endl;
    outData << " " << endl;
    outData << setw(8) << left << "RED";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << red << endl;
    outData << setw(8) << left << "ORANGE";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << orange << endl;
    outData << setw(8) << left << "YELLOW";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << yellow << endl;
    outData << setw(8) << left << "BLUE";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << blue << endl;
    outData << setw(8) << left << "GREEN";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << green << endl;
    outData << setw(8) << left << "Invalid";
    outData << setw(1) << left << ":";
    outData << setw(5) << left << invReport << endl;
    outData << " " << endl;
   
}

void printPercentages(ofstream& outData, int& male, int& female, float& validCount, float& invalidCount)
{
    //Pre: variables must have been declared and processed
    //Post: Percentages have been printed to the summary of the output file
    outData << setw(8) << left << "Male";
    outData << setw(1) << left << ":";
    outData << left << male * 10 << "% " << "(" << male << " valid records)" << endl;
    outData << setw(8) << left << "Female";
    outData << setw(1) << left << ":";
    outData << left << female * 10 << "% " << "(" << female << " valid records)" << endl;
    outData << " " << endl;
    outData << setw(8) << left << "Valid";
    outData << setw(1) << left << ":";
    outData << left << validCount * 10 << "% " << "(" << validCount << " records)" << endl;
    outData << setw(8) << left << "Invalid";
    outData << setw(1) << left << ":";
    outData << left << invalidCount * 10 << "% "<< "(" << invalidCount << " records)" << endl;
    outData << " " << endl;
    
}

void printMinMax(ofstream& outData, float& max, float& min, int& maxID, int& minID)
{
    //Pre: Variables must have been declared and processed
    //Post: Minimum and maximum have been printed to the summary of the output file
    outData << setw(8) << left << "Max";
    outData << setw(1) << left << ":";
    outData << left << max << " (Patient ID: " << maxID << ")" << endl;
    outData << setw(8) << left << "Min";
    outData << setw(1) << left << ":";
    outData << left << min << " (Patient ID: " << minID << ")" << endl;
    outData << " " << endl;
    outData << "*< End of Report >*" << endl;
    
}