// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "intbst.h"

#include <iostream>
using namespace std;

int getTest();

// similar to the given test function, just automatically tests them.
int main() {
  IntBST this1;
  this1.insert(133);
  this1.insert(260);
  this1.insert(21);
  this1.insert(1027);
  this1.insert(517);
  this1.insert(69);
  this1.insert(38);
  this1.insert(15);

  cout << "Running all tests" <<endl;
  cout << "  in-order function: ";
  this1.printInOrder();
  cout << endl;
  cout << "  post-order function: ";
  this1.printPostOrder();
  cout << endl;
  cout << "  sum function: " << this1.sum() << endl;
  cout << "  count function: " << this1.count() << endl;
  cout << "  contain-true function? " <<
            (this1.contains(69) ? "Y" : "N") << endl;
  cout << "  contain-false function? " << (this1.contains(33) ? "Y" : "N") << endl;
  cout << "  predecessor function (69): " << this1.getPredecessor(69) << endl;
  cout << "  successor  function (69): " << this1.getSuccessor(69) << endl;
  cout << "  remove function (69): " << endl;
  this1.remove(69);
  cout << "  contains 133? " << (this1.contains(133) ? "Y" : "N") << endl;
  cout << "  contains 260? " << (this1.contains(260) ? "Y" : "N") << endl;
  cout << "  contains 21? " << (this1.contains(21) ? "Y" : "N") << endl;
  cout << "  contains 1027? " << (this1.contains(1027) ? "Y" : "N") << endl;
  cout << "  contains 517? " << (this1.contains(517) ? "Y" : "N") << endl;
  cout << "  contains 69? " << (this1.contains(69) ? "Y" : "N") << endl;
  cout << "  contains 38? " << (this1.contains(38) ? "Y" : "N") << endl;
  cout << "  contains 15? " << (this1.contains(15) ? "Y" : "N") << endl;