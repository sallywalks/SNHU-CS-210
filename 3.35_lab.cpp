//3.35 Lab Mad lib loops
//Mad Libs are activities that have a person provide various words, which are then used to complete a short story 
//in unexpected (and hopefully funny) ways.

//Write a program that takes a string and an integer as input, and outputs a sentence using the input values 
//as shown in the example below. 
//The program repeats until the input string is quit and disregards the integer input that follows.

//Ex: If the input is:

//apples 5
//shoes 2
//quit 0
//the output is:

//Eating 5 apples a day keeps you happy and healthy.
//Eating 2 shoes a day keeps you happy and healthy.

#include <iostream>
#include <string>
using namespace std;

int main() {

   string noun;
   int number;
   
   while (true) { //main loop for unknown # of lines of text 
      cin >> noun; //gets user input
      cin >> number;
      
      if (noun == "quit") { //stops the loop when quit is entered 
         break; 
      }
      
      cout << "Eating " << number << " " << noun << " a day keeps you happy and healthy." << endl;
   }
   return 0;
}
