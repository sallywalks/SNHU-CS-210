//JoAnn Olney
//Project 2

#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
    InvestmentCalculator app;

    // Get user data
    app.setUserData();

    // Pause before showing reports
    cout << "Press Enter to display reports..." << endl;
    cin.ignore();
    cin.get();

    // Display investment reports
    app.printReportWithoutMonthlyDeposits();
    app.printReportWithMonthlyDeposits();

    cout << "Thank you for using the Airgead Banking Investment Calculator!" << endl;

    return 0;
}