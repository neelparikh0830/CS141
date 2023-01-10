/*token.cpp*/

//
// nextToken function needed for parsing of SimpleC programming language
//
//Author: Neel Parikh UIC Fall2020
//
// Originally written by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 04
//

#include <iostream>
#include <istream>
#include <string>
#include <cctype>  // isdigit, isalpha

#include "token.h"

using namespace std;


//
// overload << for Token so we can output tokens easily for debugging:
//
ostream& operator<<(ostream& os, const Token& T)
{
   os << "Token(" << T.ID << "," << T.Value << "," << T.Line << "," << T.Col << ")";
   return os;
}

// This function checks if input is string and send the string to main function.

void strinput(int c, istream& input, string& str1)
{
    if (c == '"' ) // this if statement checks whenever their is quotation marks it will store in to str1 and finish
    {              // the recurssive statement sending it to main function by pass by reference.
        c = input.get();
        str1.push_back(c);
    }
    else // This else statement will run until it quotation marks in input and repeat itself until that quotation marks. 
    {
        c = input.get();
        str1.push_back(c);
        c = input.peek();
        return strinput(c, input, str1);
    }
        
}

// This function checks if input is integer and put it into string and that string send the string to main function.

void intinput(int c, istream& input, string& str2)
{
    if (!isdigit(c)) // this if statement checks whenever it's a digit or not it will store in to str1 and finish
    {
        ;
    }
    else // else statement will be recursive until there is digit.
    {
        c = input.get();
        str2.push_back(c);
        c = input.peek();
        return intinput(c, input, str2);
    }
}

// This function will store identifier in the str3

void alphainput(int c, istream& input, string& str3)
{
    if (!isalpha(c) && !(c == '_') && !isdigit(c)) // program will be finish when it runs this if statement.
    {
        ;
    }
    else // this else statement will run until their is alegal input given to program.
    {
        c = input.get();
        str3.push_back(c);
        c = input.peek();
        return alphainput(c, input, str3);
    }
}


//
// nextToken
//
// Summary: finds and returns the next SimpleC token as 
// defined in "token.h" and by the SimpleC programming 
// language.  If the input stream does not contain another
// token, TokenID::EOS (End-Of-Stream) is returned.  The
// longest possible token is always returned, e.g. the 
// input ">=" would be returned as TokenID::GTE instead
// of TokenID::GT followed by TokenID::EQUAL.  If the input
// stream contains a character that is not recognized as 
// part of SimpleC, TokenID::UNKNOWN is returned with 
// the token's value set to the unknown character.
//
// Pre-condition: input must be an open stream denoting
// the source of tokens, with line and col set to current 
// line and column position in this stream.
//
// Post-condition: input stream is advanced based on token 
// that is returned, with line and col advanced similarly.
//
Token nextToken(istream& input, int& line, int& col)
{
   Token T;
   int   c;
   string str1; // stores string statement from input to str1
   string str2; // stores digits input to sring into str2
   string str3; // stroes identifiers into str3
   
   c = input.peek();  // look ahead at the next char:

   if (c == EOF)  // end of stream:
   {
      T.ID = TokenID::EOS;
      
      T.Value = "$";
      T.Line  = line;
      T.Col   = col;
   }
   
   else if (c == ' ' || c == '\t' || c == '\r' || c =='\f') // this will check if input is whitespace.
   {
       c = input.get();
       col++;
       return nextToken(input, line, col); // then it will run nextToken function.
   } 
    
   else if (c == '\n') // this will check if input is going to next line.
   {
       c = input.get();
       line++;
       col = 1;
       return nextToken(input, line, col); // then it will run nextToken function.
   }
    
   else if (c == ';') // This function will check if its semicolon and return this T ID, value, line and col.
   {
      c = input.get();
      T.ID = TokenID::SEMICOLON;
      T.Value = c;
      T.Line = line;
      T.Col = col;
       
      col++; 
   }
    
   else if (c == '(' || c == ')' || c == '{' || c == '}') // This function will check which brackets is it
   {                                                      // and return that T ID, value, line and col.
      c = input.get();
      switch (c) // This switch statement will check Which T.ID to return.
       {
           case '(': T.ID = TokenID::LEFT_PAREN; break;
           case ')': T.ID = TokenID::RIGHT_PAREN; break;
           case '{': T.ID = TokenID::LEFT_BRACE; break;
           case '}': T.ID = TokenID::RIGHT_BRACE; break;
       }
      ;
      T.Value = c;
      T.Line = line;
      T.Col = col;
       
      col++; 
   }
   
   else if (c == '/') // This function will check if its / and return this T ID, value, line and col.
   {
       c = input.get();
       c = input.peek();
       if (c == '/') // if this if statement works then that line will be avoided and go to next line.
       {
           c = input.get();
           while (c != EOF && c != '\n')
           {
               c = input.get();
           }
           line++;
           col = 1;
           return nextToken(input, line, col);
       }
       else // otherwise it will return divide function.
       {
           T.ID = TokenID::DIV;
           T.Value = "/";
           T.Line = line;
           T.Col = col;
       
           col++; 
       }
       
   }
    
   else if (c == '+' || c == '-' || c == '*' || c == '%') // This function will check which operation is it
   {                                                      // and it will return that T value and other things.
       c = input.get();
       switch (c) // This switch case decided which token id to return.
       {
           case '+': T.ID = TokenID::PLUS; break;
           case '-': T.ID = TokenID::MINUS; break;
           case '*': T.ID = TokenID::MULT; break;
           case '%': T.ID = TokenID::MOD; break;
       }
       
       T.Value = c;
       T.Line = line;
       T.Col = col;
       
       col++;
       
   }
    
   else if (c == '>') // This if statement will check if its > and return this T ID, value, line and col.
   {
       c = input.get();
       c = input.peek();
       if (c == '=' || c == '>') // this will check if its cin or greater than equal to.
       {
           c = input.get();
           switch (c) // this switch statement will output correct token id and value.
           {
               case '=': T.ID = TokenID::GTE; T.Value = ">="; break;
               case '>': T.ID = TokenID::INPUT; T.Value = ">>"; break;
           }
           
           T.Line = line;
           T.Col = col;
       
           col += 2;
       }
       else // This else statement will return this T ID, value, line and col.
       {
           T.ID = TokenID::GT;
           T.Value = ">";
           T.Line = line;
           T.Col = col;
       
           col++;
       }
   }
   
   else if (c == '<') // This if statement will check if its < and return this T ID, value, line and col.
   {
       c = input.get();
       c = input.peek();
       if (c == '=' || c == '<') // this will check if its cout or smaller than equal to.
       {
           c = input.get();
           switch (c) // this switch statement will output correct token id and value.
           {
               case '=': T.ID = TokenID::LTE; T.Value = "<="; break;
               case '<': T.ID = TokenID::OUTPUT; T.Value = "<<"; break;
           }
           
           T.Line = line;
           T.Col = col;
       
           col += 2;
       }
       else // This else statement will return this T ID, value, line and col.
       {
           T.ID = TokenID::LT;
           T.Value = "<";
           T.Line = line;
           T.Col = col;
       
           col++;
       }
   }
    
   else if (c == '=') // this statement will check if value is given to something/
   {
       c = input.get();
       c = input.peek();
       if (c == '=') // this is statement will check if its == signs.
       {
           c = input.get();
           T.ID = TokenID::EQUAL_EQUAL;
           T.Value = "==";
           T.Line = line;
           T.Col = col;
       
           col += 2;
       }
       else
       {
           T.ID = TokenID::EQUAL;
           T.Value = "=";
           T.Line = line;
           T.Col = col;
       
           col++; 
       }
   }
    
   else if (c == '!') // this function will check if its != or just ! sign.
   {
       c = input.get();
       c = input.peek();
       if (c == '=')
       {
           c = input.get();
           T.ID = TokenID::NOT_EQUAL;
           T.Value = "!=";
           T.Line = line;
           T.Col = col;
       
           col += 2;
       }
       else
       {
           T.ID = TokenID::UNKNOWN;
           T.Value  = "!";
           T.Line   = line;
           T.Col    = col;

           col++;
       }
   }
   
   else if (isdigit(c)) // this function will check if all digit in the input.
   {
       c = input.get();
       str2.push_back(c);
       c = input.peek();
       intinput(c, input, str2); // this function will check the next all digit value by recursive method.
       T.ID = TokenID::INT_LITERAL;
       T.Value = str2;
       T.Line = line;
       T.Col = col;
       
       col += str2.size();
   }
    
   else if (c == '"') // this function will check if string in the input.
   {
       c = input.get();
       str1.push_back(c);
       c = input.peek();
       strinput(c, input, str1); // this function will check the next all string value by recursive method.
       T.ID = TokenID::STR_LITERAL;
       T.Value = str1;
       T.Line = line;
       T.Col = col;
       
       col += str1.size();
   }
    
   else if (isalpha(c) || c == '_') // this function will check if identifier in the input or other statement.
   {
       c = input.get();
       str3.push_back(c);
       c = input.peek();
       alphainput(c, input, str3);  // this function will check the next all identifier value by recursive method.
       if(str3 == "void") // This statement will run if string is equal to void.
       {
           T.ID = TokenID::VOID_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 4;
       }
       else if(str3 == "main") // This statement will run if string is equal to main.
       {
           T.ID = TokenID::MAIN_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 4;
       }
       else if(str3 == "int") // This statement will run if string is equal to int.
       {
           T.ID = TokenID::INT_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 3;
       }
       else if(str3 == "cin") // This statement will run if string is equal to cin.
       {
           T.ID = TokenID::CIN_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 3;
       }
       else if(str3 == "cout") // This statement will run if string is equal to cout.
       {
           T.ID = TokenID::COUT_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 4;
       }
       else if(str3 == "endl") // This statement will run if string is equal to endl.
       {
           T.ID = TokenID::ENDL_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 4;
       }
       else if(str3 == "while") // This statement will run if string is equal to while.
       {
           T.ID = TokenID::WHILE_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 5;
       }
       else if(str3 == "if") // This statement will run if string is equal to if.
       {
           T.ID = TokenID::IF_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 2;
       }
       else if(str3 == "else") // This statement will run if string is equal to else.
       {
           T.ID = TokenID::ELSE_KEYW;
           T.Value = str3;
           T.Line = line;
           T.Col = col;

           col += 4;
       }
       else // This statement will run if string is not equal to anything.
       {
          T.ID = TokenID::IDENTIFIER;
          T.Value = str3;
          T.Line = line;
          T.Col = col;
       
          col += str3.size(); 
       } 
   }
   
   else  // unknown char => UNKNOWN token:
   {
      c = input.get();  // consume char
      
      T.ID = TokenID::UNKNOWN;
      
      T.Value  = "";
      T.Value += static_cast<char>(c);
      T.Line   = line;
      T.Col    = col;
      
      col++;
   }
   
   return T;
}
