//JoAnn Olney
//Project 2

#include <iostream>
#include <iomanip>
#include <string>
#include "InvestmentCalculator.h"

using namespace std;

// Constructor initializes all values to 0
InvestmentCalculator::InvestmentCalculator() {
    initialInvestment = 0.0;
    monthlyDeposit = 0.0;
    annualInterestRate = 0.0;
    numberOfYears = 0;
}

// Prompt the user for investment details
void InvestmentCalculator::setUserData() {
    cout << "**********************************" << endl;
    cout << "********* Data Input *************" << endl;

    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest Rate (in %): ";
    cin >> annualInterestRate;

    cout << "Number of Years: ";
    cin >> numberOfYears;

    cout << endl;
}

// Display header for both reports
void InvestmentCalculator::printReportHeader(const string& title) {
    cout << "**********************************" << endl;
    cout << title << endl;
    cout << "Year\tYear End Balance\tEarned Interest" << endl;
    cout << "----------------------------------" << endl;
}

// Report without monthly deposits
void InvestmentCalculator::printReportWithoutMonthlyDeposits() {
    double yearEndBalance = initialInvestment;
    double interestEarned;

    printReportHeader("Balance and Interest Without Additional Monthly Deposits");

    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarned = yearEndBalance * (annualInterestRate / 100);
        yearEndBalance += interestEarned;

        cout << year << "\t$" << fixed << setprecision(2) << setw(18) << yearEndBalance
             << "\t$" << setw(16) << interestEarned << endl;
    }
    cout << endl;
}

// Report with monthly deposits
void InvestmentCalculator::printReportWithMonthlyDeposits() {
    double yearEndBalance = initialInvestment;
    double interestEarned;
    double monthlyInterestRate = annualInterestRate / 100 / 12;

    printReportHeader("Balance and Interest With Additional Monthly Deposits");

    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarned = 0.0;
        for (int month = 1; month <= 12; ++month) {
            yearEndBalance += monthlyDeposit;
            double interest = yearEndBalance * monthlyInterestRate;
            yearEndBalance += interest;
            interestEarned += interest;
        }

        cout << year << "\t$" << fixed << setprecision(2) << setw(18) << yearEndBalance
             << "\t$" << setw(16) << interestEarned << endl;
    }
    cout << endl;
}