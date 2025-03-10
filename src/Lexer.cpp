#include "Lexer.h"

// NOT COMMENTED BECAUSE IT IS GIVEN IN THE SUBJECT

Lexer::~Lexer()
{
   if (DEBUG)
   {
      cout << "Lexer.~Lexer()" << endl;
   }
   if (buffer)
      delete buffer;
}

Symbol *Lexer::getSymbol()
{
   if (DEBUG)
   {
      cout << "Lexer.getSymbol()" << endl;
   }
   if (!buffer)
   {

      if (head == flux.length())
         buffer = new Symbol(FIN);
      else
      {

         switch (flux[head])
         {
         case '(':
            buffer = new Symbol(OPENPAR);
            head++;
            break;
         case ')':
            buffer = new Symbol(CLOSEPAR);
            head++;
            break;
         case '*':
            buffer = new Symbol(MULT);
            head++;
            break;
         case '+':
            buffer = new Symbol(PLUS);
            head++;
            break;
         default:
            if (flux[head] <= '9' && flux[head] >= '0')
            {                                 // check if the character is a number
               int result = flux[head] - '0'; // convert the character to an integer
               int i = 1;
               while (flux[head + i] <= '9' && flux[head + i] >= '0')
               { // read 1824 as 1824
                  result = result * 10 + (flux[head + i] - '0');
                  i++;
               }
               head = head + i;
               buffer = new Integer(result); // give the total integer to the buffer
            }
            else
            {
               buffer = new Symbol(ERREUR); // if not a number or a ending character, it's an error
            }
         }
      }
   }
   return buffer;
}

void Lexer::MoveHeadForward()
{
   if (DEBUG)
   {
      cout << "Lexer.MoveHeadForward()" << endl;
   }
   buffer = nullptr;
}
