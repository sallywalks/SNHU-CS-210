//JoAnn Olney
//Project 2

#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

class InvestmentCalculator {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int numberOfYears;

public:
    // Constructor
    InvestmentCalculator();

    // Setters
    void setUserData();

    // Display Reports
    void printReportWithoutMonthlyDeposits();
    void printReportWithMonthlyDeposits();

private:
    // Helper for formatting
    void printReportHeader(const std::string& title);
};

#endif
