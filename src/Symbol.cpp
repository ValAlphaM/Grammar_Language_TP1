#include "Symbol.h"
#include <iostream>

// print the symbol given
void Symbol::print() {
   cout<<labels[index];
}

// print the INT symbol
void Integer::print() {
   Symbol::print();
   cout<<"("<<value<<")";
}

// print the EXPR symbol (same as INT)
void Expr::print() {
   Symbol::print();
   cout<<"("<<value<<")";
}

