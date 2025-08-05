//4.11 Lab Sort a vector
//Define a function named SortVector that takes a vector of integers as a parameter. 
//Function SortVector() modifies the vector parameter by sorting the elements in descending order 
//(highest to lowest). 
//Then write a main program that reads a list of integers from input, stores the integers in a vector, 
//calls SortVector(), and outputs the sorted vector. 
//The first input integer indicates how many numbers are in the list.

//Ex: If the input is:
//5 10 4 39 12 2
//the output is:
//39,12,10,4,2,
//For coding simplicity, follow every output value by a comma, including the last one.
//Your program must define and call the following function:
//void SortVector(vector<int>& myVec)

#include <iostream>
#include <vector>
using namespace std;

//Function- SortVector, Parameters- vectors of integers
//returns- void
//This will modify the vector by sorting the elements highest to lowest
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

//Function will sort a vector of integers 
void SortVector(vector<int>& myVec) { //required line
   int i, j;
   //The loop will compare the elements to each other
   for (i = 0; i < myVec.size()-1; i++)
   for (j = 0; j < myVec.size()-i-1; j++)
   //If the element is larger swap them
   if (myVec[j] < myVec[j+1])
   swap(&myVec[j], &myVec[j+1]);
}

int main() {
   //get the number of elements
   int n;
   cin >> n;
   //create a vector of integers 
   vector<int>myVec;
   for(int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      myVec.push_back(temp);
   }
   //sort the vector
   SortVector(myVec);
   
   //print the vector
   for(int i = 0; i < n; i++) {
      cout << myVec[i] << ",";
   }
   
   cout << endl;
   return 0;
}
