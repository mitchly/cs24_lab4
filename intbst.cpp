// intbst.cpp
// Implements class IntBST
// Joshua Thomas: 3937661. Michelle Ly: 3774189

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(n == nullptr) {
      return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
  if(n == nullptr) {
    return;
  }

  printPostOrder(n->left);
  printPostOrder(n->right);
  cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
  if(n == nullptr) {
    return 0;
  }
  return(n->info+sum(n->left)+sum(n->right));
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
  if(n == NULL){
      return 0;
  }
  int counter = 1;
  counter += count(n->left);
  counter += count(n->right);
  return counter;
}


// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
  while(n != NULL){
      if(n->info == value){
          return n;
      }
      else if(value < n->info){
          n = n->left;
      }
      else{
          n = n->right;
      }
  }
  return NULL;
}


// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    Node* newNode = getNodeFor(value, root);
    if(newNode == NULL){
        return false;
    }
    return true;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
  Node* obj = getNodeFor(value, root);
  if(obj==nullptr) {
    return nullptr;
  }
  if(obj->left) {
    Node* current = obj->left;
    while (current->right) {
      current = current->right;
    }
    return current;
  }

  Node* p = obj->parent;  
  while(p != nullptr && obj == p->left){
    obj=p;
    p=p->parent;
  }
  return p;
}




// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
  if(getPredecessorNode(value) != nullptr) {
    return getPredecessorNode(value)->info;
  }
  else {
    return 0;
  }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
  Node* obj = getNodeFor(value, root);
  if(obj==nullptr) {
    return nullptr;
  }
  if(obj->right != nullptr) {
    Node* current = obj->right;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }
  Node* p = obj->parent;
  while(p != nullptr && obj == p->right) {
    obj=p;
    p=p->parent;
  }
  return p;
}


// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
  if(getSuccessorNode(value) != nullptr) {
    return getSuccessorNode(value)->info;
  }
  else {
    return 0;
  }
}


// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
   Node* delthis = getNodeFor(value, root);
    if(delthis == nullptr){
      return false;
    }
    if(delthis->left == delthis->right == NULL) {
      delthis=NULL;
      return true;
    }
    else if (delthis->left != NULL && delthis->right == NULL){
      delthis->left->parent = delthis->parent;
      delthis = delthis->left;
      return true;
    }
    else if (delthis->right != NULL && delthis->left == NULL){
      delthis->left->parent = delthis->parent;
      delthis = delthis->right;
      return true;
    }
    else{
      int suckey = getSuccessor(value);
      delthis->info = suckey;
      delthis->right.info = remove(suckey);
      return true;
    }

    return false;
}