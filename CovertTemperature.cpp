//JoAnn Olney
//7-30-25
//CS-210

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    //Used to open input files
    ifstream inputFile("FahrenheitTemperature.txt");
    //Used to open the output files
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if input file opened correctly 
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Check if output file opened correctly 
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    //The conversion from fahrenheint to celsius
    const double FahrenheitToCelsius = 5.0 / 9.0;
    string city;
    int fahrenheit;

    //Format the output to have 2 decimal places 
    outputFile << fixed << setprecision(2); 

    while (inputFile >> city >> fahrenheit) {
        //Converts farhenheit to celsius using the given formula
        double celsius = (fahrenheit - 32) * FahrenheitToCelsius;
        outputFile << city << " " << celsius << endl;
    }

    //Will close both the input and output files 
    inputFile.close();
    outputFile.close();

    //Complete, data to be added to CelsiusTemperature.txt
    cout << "Conversion complete. Data added to CelsiusTemperature.txt." << endl;
    return 0;
}