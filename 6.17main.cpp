//Lab 6.17 pt 1 main.cpp file 

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
ItemToPurchase item1, item2;
  string name;
  int price, quantity;

  // Input for Item 1
  cout << "Item 1" << endl;
  cout << "Enter the item name:" << endl;
  getline(cin, name);
  item1.SetName(name);
  cout << "Enter the item price:" << endl;
  cin >> price;
  item1.SetPrice(price);
  cout << "Enter the item quantity:" << endl;
  cin >> quantity;
  item1.SetQuantity(quantity);

  cin.ignore(); // To clear the input buffer
  
  cout << endl; // <- add blanlk line before item 2

  // Input for Item 2
  cout << "Item 2" << endl;
  cout << "Enter the item name:" << endl;
  getline(cin, name);
  item2.SetName(name);
  cout << "Enter the item price:" << endl;
  cin >> price;
  item2.SetPrice(price);
  cout << "Enter the item quantity:" << endl;
  cin >> quantity;
  item2.SetQuantity(quantity);
  
  cout << endl; // <- add blank line before total cost

  // Calculate and output total cost
  int totalCost = (item1.GetPrice() * item1.GetQuantity()) + (item2.GetPrice() * item2.GetQuantity());
  cout << "TOTAL COST" << endl;
  cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetPrice() * item1.GetQuantity() << endl;
  cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetPrice() * item2.GetQuantity() << endl;
  cout << endl; // <- add blank line before total $
  cout << "Total: $" << totalCost << endl;


   return 0;
}
