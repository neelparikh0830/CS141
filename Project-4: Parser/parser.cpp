/*parser.cpp*/

//
// Recursive-descent parsing functions for SimpleC programming language
// Parser cpp will check if the program is in correct order.
// it will check program semantically and any error it will point out to programmer.
//
// Author: Neel Parikh UIC fall 2020 10/31/2020
//
// Originally written by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 04
//

#include <iostream>
#include <istream>
#include <string>
#include <list>

#include "token.h"
#include "parser.h"

using namespace std;


//
// recursive-descent functions:
//

//This statement will print out syntax error wherever it has been called and return false.
//
bool syntaxerror(list<Token>& tokens, string error)
{
    cout << "Syntax error: expecting '"
         << error << "', found '" 
         << tokens.front().Value << "' @ (" 
         << tokens.front().Line << ", " 
         << tokens.front().Col << ")" << endl;
    return false;
}

//
// <simplec> ::= void main ( ) <block> $
//
//This bool statement will check the order of program described in simplec or it will output error massage if it's false.
bool simplec(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<simplec>" << endl;
   }
   if (tokens.front().ID != VOID_KEYW)
   {
       return syntaxerror(tokens, "void");
   }
   tokens.pop_front();
   if (tokens.front().ID != MAIN_KEYW)
   {
       return syntaxerror(tokens, "main");
   }
   tokens.pop_front();
   if (tokens.front().ID != LEFT_PAREN)
   {
       return syntaxerror(tokens, "(");
   }
   tokens.pop_front();
   if (tokens.front().ID != RIGHT_PAREN)
   {
       return syntaxerror(tokens, ")");
   }
   tokens.pop_front();
   if ( !block(tokens, trace))
   {
       return false;
   }
   if (tokens.front().ID != EOS)
   {
       return syntaxerror(tokens, "EOS");
   }
   tokens.pop_front();
   return true;
}

//
// <stmts> ::= <stmt> <stmts>
//          | EMPTY
//This boolean statement will check call the stmt function and will check given in block is correct or not. 
//it will go through each case and nothing is found then return true because of empty stmts
bool stmts(list<Token>& tokens, bool trace)
{
    if (trace)
   {
      cout << "<stmts>" << endl;
   }
   if(tokens.front().ID == SEMICOLON || tokens.front().ID == INT_KEYW || tokens.front().ID == CIN_KEYW
     || tokens.front().ID == COUT_KEYW || tokens.front().ID == IDENTIFIER || tokens.front().ID == LEFT_BRACE
     || tokens.front().ID == WHILE_KEYW || tokens.front().ID == IF_KEYW)
   {
       if (!stmt(tokens, trace))
       {
           return false;
       }
       if (!stmts(tokens, trace))
       {
           return false;
       }
       return true;
   }
   else
   {
       return true;
   }
}

//
// <stmt> ::= ...
//
//This boolean statement will check the stmt given in block is correct or not. 
//it will go through each case and nothing is found then output error massage if it's false
bool stmt(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<stmt>" << endl;
   }
   if (tokens.front().ID == SEMICOLON)
   {
       if (missing(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == INT_KEYW)
   {
       if (vardecl(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == CIN_KEYW)
   {
       if (input(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == COUT_KEYW)
   {
       if (output(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == IDENTIFIER)
   {
       if (assignment(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == LEFT_BRACE)
   {
       if (block(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == WHILE_KEYW)
   {
       if (whileloop(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else if (tokens.front().ID == IF_KEYW)
   {
       if (ifthenelse(tokens, trace))
       {
           return true;
       }
       return false;
   }
   else
   {
       return syntaxerror(tokens, "stmt");
   }
}


//
// <missing> ::= ;
//
//This bool statement will check the missing semicolon in program or it will output error massage if it's false
bool missing(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<missing>" << endl;
   }
   if (tokens.front().ID != SEMICOLON)
   {
       return syntaxerror(tokens, ";");
   }
   tokens.pop_front();
   return true;
}


//
// <vardecl> ::= int IDENTIFIER ;
//
//This bool statement will check the order of variable declaration in program
// or it will output error massage if it's false
bool vardecl(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<vardecl>" << endl;
   }
   if (tokens.front().ID != INT_KEYW)
   {
       return syntaxerror(tokens, "int");
   }
   tokens.pop_front();
   if (tokens.front().ID != IDENTIFIER)
   {
       return syntaxerror(tokens, "identifier");
   }
   tokens.pop_front();
   if (tokens.front().ID != SEMICOLON)
   {
       return syntaxerror(tokens, ";");
   }
   tokens.pop_front();
   return true;
}


//
// <input> ::= cin >> IDENTIFIER ;
//
//This bool statement will check the order of input in program or
//if anything is missing than it will output error massage
bool input(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<input>" << endl;
   }
   if (tokens.front().ID != CIN_KEYW)
   {
       return syntaxerror(tokens, "cin");
   }
   tokens.pop_front();
   if (tokens.front().ID != INPUT)
   {
       return syntaxerror(tokens, ">>");
   }
   tokens.pop_front();
   if (tokens.front().ID != IDENTIFIER)
   {
       return syntaxerror(tokens, "identifier");
   }
   tokens.pop_front();
   if (tokens.front().ID != SEMICOLON)
   {
       return syntaxerror(tokens, ";");
   }
   tokens.pop_front();
   return true;
}


//
// <output> ::= cout << <output_elem> <more_elems>;
//
//This bool statement will check the order of output in program by calling the output element and more element.
// it will output error massage if it's false or missing somethings.
bool output(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<output>" << endl;
   }
   if (tokens.front().ID != COUT_KEYW)
   {
       return syntaxerror(tokens, "cout");
   }
   tokens.pop_front();
   if ( !output_elem(tokens, trace))
   {
       return false;
   }
   if ( !more_elems(tokens, trace))
   {
           return false;
   }
   if (tokens.front().ID != SEMICOLON)
   {
       return syntaxerror(tokens, ";");
   }
   tokens.pop_front();
   return true;
}


//
// <output_elem> ::= << <expr>
//                 | << endl
//
//This bool statement will check the order of outputting an element in program 
//or saying go to the next line or expr is not found than it will output error massage and retun false.
bool output_elem(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<output_elem>" << endl;
   }
   if (tokens.front().ID != OUTPUT)
   {
       return syntaxerror(tokens, "<<");
   }
   tokens.pop_front();
   if (tokens.front().ID != ENDL_KEYW)
   {
       if (!expr(tokens, trace))
       {
           return false;
       }
       return true;
   }
   else
   {
       tokens.pop_front();
       return true;
   }
}

//
// <more_elems> ::= <output_elem> <more_elems>
//               | EMPTY
//
// This function will check if there are more element in cout statement if it is than it will loop by
// itself untill nothing further is found and return true if correct of false and error massage.
bool more_elems(list<Token>& tokens, bool trace)
{
    if (trace)
   {
      cout << "<more_elems>" << endl;
   }
   if (tokens.front().ID == OUTPUT)
   {
       if ( !output_elem(tokens, trace))
       {
           return false;
       }
       if ( !more_elems(tokens, trace))
       {
           return false;
       }
       return true;
   }
   else
   {
       return true;
   }
}


//
// <assignment> ::= IDENTIFIER = <expr> ;
//
//This bool statement will check if identifier is assigned to any expression in program
// expr is not found than it will output error massage and retun false.
bool assignment(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<assignment>" << endl;
   }
   if (tokens.front().ID != IDENTIFIER)
   {
       return syntaxerror(tokens, "identifier");
   }
   tokens.pop_front();
   if (tokens.front().ID != EQUAL)
   {
       return syntaxerror(tokens, "=");
   }
   tokens.pop_front();
   if (!expr(tokens, trace))
   {
       return false;
   }
   if (tokens.front().ID != SEMICOLON)
   {
       return syntaxerror(tokens, ";");
   }
   tokens.pop_front();
   return true;
}


//
// <block> ::= { <stmts> }
//
//This block statement will check the order of program correct by looking at first bracket and last and in middle
//calling stmts and other function in stmt, if it doesn't work than it will output error massage and retun false.
bool block(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<block>" << endl;
   }
   if (tokens.front().ID != LEFT_BRACE)
   {
       return syntaxerror(tokens, "{");
   }
   tokens.pop_front();
   if (!stmts(tokens, trace))
   {
       return false;
   }
   if (tokens.front().ID != RIGHT_BRACE)
   {
       return syntaxerror(tokens, "}");
   }
   tokens.pop_front();
   return true;
}


//
// <whileloop> ::= while ( <expr> ) <block>
//
//This bool statement will check the order of while loop in program by calling other functions
//or expr is not found than it will output error massage and retun false.
bool whileloop(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<whileloop>" << endl;
   }
   if (tokens.front().ID != WHILE_KEYW)
   {
       return syntaxerror(tokens, "while");
   }
   tokens.pop_front();
   if (tokens.front().ID != LEFT_PAREN)
   {
       return syntaxerror(tokens, "(");
   }
   tokens.pop_front();
   if (!expr(tokens, trace))
   {
       return false;
   }
   if (tokens.front().ID != RIGHT_PAREN)
   {
       return syntaxerror(tokens, ")");
   }
   tokens.pop_front();
   if (!block(tokens, trace))
   {
       return false;
   }
   return true;
}


//
// <ifthenelse> ::= if ( <expr> ) <block> <elseblock>
//
//This bool statement will check the order of if than else stament in program is correct or not 
//or if anything goes wrong in calling function than it will output error massage and retun false.
bool ifthenelse(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<ifthenelse>" << endl;
   }
   if (tokens.front().ID != IF_KEYW)
   {
       return syntaxerror(tokens, "if");
   }
   tokens.pop_front();
   if (tokens.front().ID != LEFT_PAREN)
   {
       return syntaxerror(tokens, "(");
   }
   tokens.pop_front();
   if (!expr(tokens, trace))
   {
       return false;
   }
   if (tokens.front().ID != RIGHT_PAREN)
   {
       return syntaxerror(tokens, ")");
   }
   tokens.pop_front();
   if (!block(tokens, trace))
   {
       return false;
   }
   if (!elseblock(tokens, trace))
   {
       return false;
   }
   return true;
}


//
// <elseblock> ::= else <block>
//               | EMPTY
//
//This bool statement will check the order of else statement it has one in program if not than return true, 
//if it has one than calling block function and checking it, if nothing is found than it will output error massage and retun false.
bool elseblock(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<elseblock>" << endl;
   }
   if (tokens.front().ID == ELSE_KEYW)
   {
       if (tokens.front().ID != ELSE_KEYW)
       {
           return syntaxerror(tokens, "else");
       }
       tokens.pop_front();
       if (!block(tokens, trace))
       {
           return false;
       }
       return true;
   }
   else
   {
       return true;
   }
}


//
// <expr> ::= <term> <oper> <expr>
//          | <term>
//
//This bool statement will check if expression contains term, operation of anykind and it is than repeat itself
//untill their is only term left. if it is not found than it will retun false.

bool expr(list<Token>& tokens, bool trace)
{
    if (trace)
    {
        cout << "<expr>" << endl;
    }
    if (!term(tokens, trace))
    {
        return false;
    }
    if (tokens.front().ID == PLUS || tokens.front().ID == MINUS || tokens.front().ID == MULT || tokens.front().ID == DIV
        || tokens.front().ID == MOD || tokens.front().ID == LT || tokens.front().ID == LTE || tokens.front().ID == GT
        || tokens.front().ID == GTE || tokens.front().ID == EQUAL_EQUAL || tokens.front().ID == NOT_EQUAL)
    {
       if (!oper(tokens, trace))
       {
           return false;
       }
       if (!expr(tokens, trace))
       {
           return false;
       }
       return true;
    }
    return true;
}



//
// <term> ::= ( <expr> )
//          | IDENTIFIER
//          | INT_LITERAL
//          | STR_LITERAL
//
//This bool statement will check if term contains identifier, int literal or str literal or expression in parenthess.
//if it is not found than it will output error massage and retun false.
bool term(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<term>" << endl;
   }
   if (tokens.front().ID == LEFT_PAREN)
   {
       if (tokens.front().ID != LEFT_PAREN)
       {
           return syntaxerror(tokens, "(");
       }
       tokens.pop_front();
       if (!expr(tokens, trace))
       {
           return false;
       }
       if (tokens.front().ID != RIGHT_PAREN)
       {
           return syntaxerror(tokens, ")");
       }
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == IDENTIFIER)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == INT_LITERAL)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == STR_LITERAL)
   {
       tokens.pop_front();
       return true;
   }
   else
   {
       return syntaxerror(tokens, "term");
   }
}



// <oper> ::= +
//        | -
//        | *
//        | /
//        | %
//        | <
//        | <=
//        | >
//        | >=
//        | ==
//        | !
// 
// This function will check if their is any mathematical function in the programmers code or if not than
// it will output error saying that one of this function are necessary and return false.
bool oper(list<Token>& tokens, bool trace)
{
   if (trace)
   {
      cout << "<oper>" << endl;
   }
   if (tokens.front().ID == PLUS)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == MINUS)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == MULT)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == DIV)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == MOD)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == LT)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == LTE)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == GT)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == GTE)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == EQUAL_EQUAL)
   {
       tokens.pop_front();
       return true;
   }
   else if (tokens.front().ID == NOT_EQUAL)
   {
       tokens.pop_front();
       return true;
   }
   else
   {
       return syntaxerror(tokens, "oper");
   }
}
