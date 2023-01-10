//
// Simulator for UIC 1.0, a very simple computer language.
//
// Author: Neel Parikh, University of Illinois Chicago, Fall 2020
// Author: Prof. Hummel, U. of Illinois Chicago, Fall 2020
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string nextToken(istream& infile);  // defined in "token.cpp"

//
// main:
//
int main()
{
    string filename;
    cout << "Filename> ";
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
    
    
    //
    // read the contents of the file and echo to the console:
    //
    string token, operand, second;
    
    int ACC, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9;
    
    token = nextToken(infile);
    while (token != "")
    {
        
        if (token == "out_s"){                     // out_s function sends out the operand.
            operand = nextToken(infile);           
            cout << operand;
        }
        
        if (token == "out_i"){                    // out_i function sends out the value from ACC.
            cout << ACC;
        }
        
        if (token == "in_i"){                    // in_i function sends in the value to ACC from programmer.  
            cin >> ACC;
        }
        
        if (token == "store_i"){               // if loop will check if token is equal to string store_i
            operand = nextToken(infile);       // then it will store value in M0 to until M9 which ever
            if(operand == "M0"){               // is next and empty.
                M0 = ACC;
            }
            else if(operand == "M1"){
                M1 = ACC;
            }
            else if(operand == "M2"){
                M2 = ACC;
            }
            else if(operand == "M3"){
                M3 = ACC;
            }
            else if(operand == "M4"){
                M4 = ACC;
            }
            else if(operand == "M5"){
                M5 = ACC;
            }
            else if(operand == "M6"){
                M6 = ACC;
            }
            else if(operand == "M7"){
                M7 = ACC;
            }
            else if(operand == "M8"){
                M8 = ACC;
            }
            else if(operand == "M9"){
                M9 = ACC;
            }
        }
        
        if (token == "load_i"){                 // load_i function will call the value from 
            operand = nextToken(infile);        // M0 or other funtion until M9 and will place it 
            if (operand == "M0"){              // in the ACC funtion.
                ACC = M0;
            }
            else if (operand == "M1"){
                ACC = M1;
            }
            else if (operand == "M2"){
                ACC = M2;
            }
            else if (operand == "M3"){
                ACC = M3;
            }
            else if (operand == "M4"){
                ACC = M4;
            }
            else if (operand == "M5"){
                ACC = M5;
            }
            else if (operand == "M6"){
                ACC = M6;
            }
            else if (operand == "M7"){
                ACC = M7;
            }
            else if (operand == "M8"){
                ACC = M8;
            }
            else if (operand == "M9"){
                ACC = M9;
            }
            else{                          // this else loop will funtion when programmer assign's
                ACC = stoi(operand);       // the direct value to funtion.
            }
        }
        
        if (token == "add_i"){             // add_i function will add the value to ACC from the
            operand = nextToken(infile);   // current value.
            if (operand == "M0"){
                ACC = ACC+M0;
            }
            else if (operand == "M1"){
                ACC = ACC+M1;
            }
            else if (operand == "M2"){
                ACC = ACC+M2;
            }
            else if (operand == "M3"){
                ACC = ACC+M3;
            }
            else if (operand == "M4"){
                ACC = ACC+M4;
            }
            else if (operand == "M5"){
                ACC = ACC+M5;
            }
            else if (operand == "M6"){
                ACC = ACC+M6;
            }
            else if (operand == "M7"){
                ACC = ACC+M7;
            }
            else if (operand == "M8"){
                ACC = ACC+M8;
            }
            else if (operand == "M9"){
                ACC = ACC+M9;
            }
            else{                             // this else loop will funtion when programmer assign's
                ACC = ACC + stoi(operand);   // the direct value to funtion.
            }
        }
        
        if (token == "div_i"){             // div_i function will divide the ACC from the M0 to M9 
            operand = nextToken(infile);   // and replace it back to ACC.
            if (operand == "M0"){
                ACC = ACC/M0;
            }
            else if (operand == "M1"){
                ACC = ACC/M1;
            }
            else if (operand == "M2"){
                ACC = ACC/M2;
            }
            else if (operand == "M3"){
                ACC = ACC/M3;
            }
            else if (operand == "M4"){
                ACC = ACC/M4;
            }
            else if (operand == "M5"){
                ACC = ACC/M5;
            }
            else if (operand == "M6"){
                ACC = ACC/M6;
            }
            else if (operand == "M7"){
                ACC = ACC/M7;
            }
            else if (operand == "M8"){
                ACC = ACC/M8;
            }
            else if (operand == "M9"){
                ACC = ACC/M9;
            } 
            else {                           // this else loop will funtion when programmer assign's
                ACC = ACC/stoi(operand);     // the direct value to funtion.
            }
        }
        
        if (token == "sub_i"){               // sub_i function will subtract the value from ACC's
            operand = nextToken(infile);    //  current value and replace it back to ACC with new value.
            if (operand == "M0"){
                ACC = ACC-M0;
            }
            else if (operand == "M1"){
                ACC = ACC-M1;
            }
            else if (operand == "M2"){
                ACC = ACC-M2;
            }
            else if (operand == "M3"){
                ACC = ACC-M3;
            }
            else if (operand == "M4"){
                ACC = ACC-M4;
            }
            else if (operand == "M5"){
                ACC = ACC-M5;
            }
            else if (operand == "M6"){
                ACC = ACC-M6;
            }
            else if (operand == "M7"){
                ACC = ACC-M7;
            }
            else if (operand == "M8"){
                ACC = ACC-M8;
            }
            else if (operand == "M9"){
                ACC = ACC-M9;
            }
            else {                         // this else loop will funtion when programmer assign's
                ACC = ACC-stoi(operand);   // the direct value to funtion.
            }
        }
        
        if (token == "mult_i"){            // mult_i function will multiply the value from ACC's
            operand = nextToken(infile);   //  current value and replace it back to ACC with new value.
            if (operand == "M0"){
                ACC = ACC*M0;
            }
            else if (operand == "M1"){
                ACC = ACC*M1;
            }
            else if (operand == "M2"){
                ACC = ACC*M2;
            }
            else if (operand == "M3"){
                ACC = ACC*M3;
            }
            else if (operand == "M4"){
                ACC = ACC*M4;
            }
            else if (operand == "M5"){
                ACC = ACC*M5;
            }
            else if (operand == "M6"){
                ACC = ACC*M6;
            }
            else if (operand == "M7"){
                ACC = ACC*M7;
            }
            else if (operand == "M8"){
                ACC = ACC*M8;
            }
            else if (operand == "M9"){
                ACC = ACC*M9;
            }
            else {                         // this else loop will funtion when programmer assign's
                ACC = ACC*stoi(operand);   // the direct value to funtion.
            }
        }
        
        if (token == "mod_i"){            // mod_i function will divide the value from ACC's
            operand = nextToken(infile);  //  current value and replace it back to ACC with
            if (operand == "M0"){         // reminder of that division.
                ACC = ACC%M0;
            }
            else if (operand == "M1"){
                ACC = ACC%M1;
            }
            else if (operand == "M2"){
                ACC = ACC%M2;
            }
            else if (operand == "M3"){
                ACC = ACC%M3;
            }
            else if (operand == "M4"){
                ACC = ACC%M4;
            }
            else if (operand == "M5"){
                ACC = ACC%M5;
            }
            else if (operand == "M6"){
                ACC = ACC%M6;
            }
            else if (operand == "M7"){
                ACC = ACC%M7;
            }
            else if (operand == "M8"){
                ACC = ACC%M8;
            }
            else if (operand == "M9"){
                ACC = ACC%M9;
            }
            else {                            // this else loop will funtion when programmer assign's
                ACC = ACC%stoi(operand);      // the direct value to funtion.
            }
        }
        
        if (token == "clear"){              // if token is equal t0 string clear then it 
            M0 = 0;                         // will split out the value zero for for every
            M1 = 0;                         // M0 to until M9.
            M2 = 0;
            M3 = 0;
            M4 = 0;
            M5 = 0;
            M6 = 0;
            M7 = 0;
            M8 = 0;
            M9 = 0;
        }
        
        if (token == "end"){               // if token is equal to string end then it will break the 
            break;                         // program and end it over there.
        }
        
        token = nextToken(infile);        // token equal next token will move token to next token in file.
    }
    
    //
    // done:
    //
    return 0;
}
