//2.25 Lab Driving Costs 
//Driving is expensive. Write a program with a car's gas milage (miles/gallon) and the cost of gas (dollars/gallon) as floating-point input, 
//and output the gas cost for 20 miles, 75 miles, and 500 miles.

//Output each floating-point value with two digits after the decimal point, which can be achieved by executing
//cout << fixed << setprecision(2); once before all other cout statements. Note: End with a newline.

//Ex: If the input is:

//20.0 3.1599
//where the gas mileage is 20.0 miles/gallon and the cost of gas is $3.1599/gallon, the output is:

//3.16 11.85 79.00
//Note: Real per-mile cost would also include maintenance and depreciation.

#include <iostream>
#include <iomanip>               //For setprecision
using namespace std;

int main() {
   //dbl miles & dollars, initalizes them 
   double miles = 0;
   double dollars = 0;
   
   //get input
   cin >> miles >> dollars;
   
   //use to get only 2 decimal places 
   cout << fixed << setprecision(2);
   
   //driving costs for the mileages
   cout << (20 * dollars) / miles << " "; //20 miles
   cout << (75 * dollars) / miles << " "; //75 miles
   cout << (500 * dollars) / miles << endl; //500 miles 

   return 0;
}
