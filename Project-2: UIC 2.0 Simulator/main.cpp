//
// Simulator for UIC 1.0, a very simple computer language.
// UIC 1.0 has 10 memory locations, an accumulator, and only
// supports integers, basic I/O, and arithmetic operations.
//
// Initial version written by
//  Author: Neel Parikh, UIC Fall 2020
//   
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // isspace

using namespace std;

string nextToken(istream& infile);  // defined in "token.cpp"


//
// readMemory
//
// Given an operand such as "M0", returns the contents of that
// memory location.  If the operand is not a memory location, 
// it is assumed to be an integer literal in which case that 
// 
// value is converted to an integer and returned.
//
int readMemory(string operand, int* A, int PC)
{
    if (operand.at(0) == 'M')
    {
        return A[stoi(operand.substr(1))];
    }
    else{
        return stoi(operand);
    }
}

//
// writeMemory
//
//
// Given an operand such as "M0" and a new value, stores that value 
// into the appropriate memory location (overwriting the current value).
//
void writeMemory(string operand, int value, int* A)
{
    int j = stoi(operand.substr(1));
    A[j] = value;
}



//
// main:
//
int main()
{
   string config, filename;
   cout << "Config file> ";
   cin >> config;
    
   ifstream inconfigfile(config);

   if (!inconfigfile.good())
   {
      cout << "**Error: unable to open input file '" << config << "'." << endl;
      return 0;
   }
    
    
   cout << "Program File> ";
   cin >> filename;

   //
   // open the program file:
   //
   ifstream infile(filename);

   if (!infile.good())
   {
      cout << "**Error: unable to open input file '" << filename << "'." << endl;
      return 0;
   }
   
   string wordFirst, wordSecond, wordThird;
   int memorysize, codesize, track;
   inconfigfile >> wordFirst;
   inconfigfile >> memorysize;
   inconfigfile >> wordSecond;
   inconfigfile >> codesize;
   inconfigfile >> wordThird;
   inconfigfile >> track;
   
   cout << "**Memory area: " << memorysize << endl;
   cout << "**Code area: " << codesize << endl;
   cout << "**Tracing: " << track << endl;
    
   int* A;
   A = new int [memorysize];
   
   string* instructions;
   string* operands;
   instructions = new string[codesize];
   operands = new string[codesize];
   
   string token;
   token = nextToken(infile);
   int i =0;
   while (token != "")
   {
       instructions[i] = token;
       if (token == "in_i" || token == "out_i" || token == "loadind_i" || token == "storeind_i" || token == "clear" || token == "end")
       {
           operands[i] = "";
       }
       else 
       {
           operands[i] = nextToken(infile);
       }
       i++;
       token = nextToken(infile);
   }
    
   cout << "**program size: " << i << endl;
   
   cout << "**Executing..." << endl;
   
   
   
   // read the contents of the file and execute each instruction 
   // one by one:
   //string instruction;

   int ACC;  // our memory:
   ACC = 0; 
   int AR = 0;
   int PC = 0;
   int CF = 0;
   
   //instruction = instructions[PC];
   //operand = operands[PC];

   while (instructions[PC] != "")
   {
      if (track == 1){
          cout << "**Trace: PC=" << PC << ",ACC=" << ACC << ",AR=" << AR << ",CF=" << CF << "," << instructions[PC] << " " << operands[PC] << endl;
      }
      if (instructions[PC] == "in_i")
      {
         cin >> ACC;
      }
      else if (instructions[PC] == "out_i")
      {
         cout << ACC;
      }
      else if (instructions[PC] == "out_s")
      {
         
         cout << operands[PC];
      }
      else if (instructions[PC] == "add_i")
      {
         
         ACC = ACC + readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "sub_i")
      {
         
         ACC = ACC - readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "mult_i")
      {
         
         ACC = ACC * readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "div_i")
      {
         
         ACC = ACC / readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "mod_i")
      {
         
         ACC = ACC % readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "load_i")
      {
         
         ACC = readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "store_i")
      {
        
         writeMemory(operands[PC], ACC, A);
      }
      else if (instructions[PC] == "clear")   // clear memory to 0:
      {
         for (int n=0;  n<memorysize; n++){
             A[n] = 0;
         }  
      }
      else if (instructions[PC] == "end")
      {
         break;
      }
      else if (instructions[PC] == "loada_i")
      {
        
         AR = readMemory(operands[PC], A, PC);
      }
      else if (instructions[PC] == "loadind_i")
      {
         ACC = A[AR];
      }
      else if (instructions[PC] == "storeind_i")
      {
         A[AR] = ACC;
      }
      else if (instructions[PC] == "jump")
      {
         
         PC = PC + stoi(operands[PC])-1;     
      } 
       else if (instructions[PC] == "cmp_i")
      {
         
         CF = ACC - readMemory(operands[PC], A, PC);
      } 
      else if (instructions[PC] == "jeq")
      {
          
          if (CF == 0)
          {
             PC = PC + stoi(operands[PC])-1; 
          }   
      } 
      else if (instructions[PC] == "jne")
      {
          
          if (CF != 0)
          {
             PC = PC + stoi(operands[PC])-1; 
          }  
      }  
      else if (instructions[PC] == "jlt")
      {
          
          if (CF < 0)
          {
             PC = PC + stoi(operands[PC])-1; 
          }  
      } 
      else if (instructions[PC] == "jle")
      {
          
          if (CF <= 0)
          {
             PC = PC + stoi(operands[PC])-1; 
          } 
      }  
      else if (instructions[PC] == "jgt")
      {
          
          if (CF > 0)
          {
             PC = PC + stoi(operands[PC])-1; 
          }   
      }  
      else if (instructions[PC] == "jge")
      {
          
          if (CF >= 0)
          {
             PC = PC + stoi(operands[PC])-1; 
          } 
      }
      else
      {
         cout << "**Error: unknown instruction '" << token << "'." << endl;
      }
      
      
      PC++;
   }
   delete [] instructions;
   delete [] operands;
   delete [] A;

   //
   // done
   //
   return 0;
}


//
// nextToken
//
// Returns the next token in the input stream; returns the empty
// string "" if there is no more input (i.e. end of stream).
// Comments (i.e. REM ...) are discarded by this function, and 
// never returned.
//
string nextToken(istream& stream)
{
   char  c;
   string token = "";

   while (token == "")
   {
      // skip initial whitespace:
      stream.get(c);
      while (!stream.eof() && isspace(c))
      {
         stream.get(c);
      }

      // did we reach end of file?  If so, there's no token:
      if (stream.eof())
      {
         return "";
      }

      if (c == '"')  // a string literal, loop until end of string:
      {
         stream.get(c);
         while (!stream.eof() && c != '"')
         {
            if (c == '\\')  // escape char?  Then read next done
            {
               stream.get(c);

               if (c == 'n')
                  c = '\n';
               else if (c == 't')
                  c = '\t';
               else if (c == 'f')
                  c = '\f';
               else if (c == 'r')
                  c = '\r';
               else
                  token += '\\';  // not sure what it is, so leave alone:
            }

            token += c;
            stream.get(c);
         }
      }
      else  // we have a word or numeric literal:
      {
         token += c;  // append that first char

         // now append remaining chars up until next whitespace:
         stream.get(c);
         while (!stream.eof() && !isspace(c))
         {
            token += c;
            stream.get(c);
         }
      }

      //
      // was the token REM?  If so, this denotes a comment, so discard 
      // rest of line and try again:
      //
      if (token == "REM")
      {
         //
         // we want to discard the rest of the line, except when
         // REM already comes at the end of the line (in which case
         // we do nothing):
         //
         if (c == '\n' || c == '\r')  // REM @ end of line, do nothing
         {
            // nothing
         }
         else
         {
            getline(stream, token);  // discard rest of line:
         }

         token = "";  // try again:
      }
   }//while

   //
   // done, we have a token to return:
   //
   return token;
}