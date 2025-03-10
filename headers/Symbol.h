#pragma once // include only once

#include <string>
using namespace std;

#define DEBUG false

enum Identificators { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string labels[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };


class Symbol {
   public:
      Symbol(int i) : index(i) {  }
      virtual ~Symbol() { }
      operator int() const { return index; }
      virtual void print();

   protected:
      int index;
};

class Integer : public Symbol {
   public:
      Integer(int v) : Symbol(INT), value(v) { }
      ~Integer() { }
      virtual void print();
   protected:
      int value;
};

class Expr : public Symbol {
   public:
      Expr(int v) : Symbol(EXPR), value(v) { }
      ~Expr() { }
      virtual void print();
      int getValue() { return value; }

   protected:
      int value;
};