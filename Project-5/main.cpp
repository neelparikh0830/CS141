//
//Author: Neel Parikh UIC Fall 2020
//linked list project 5
//



#include "list.h"
#include "oper.h"
#include <string>
#include <fstream>

using namespace std;

// 
// This print function calls the all the list which are in file and also which list they want to print.
// after that it check the which list it was printing and 
//

void print(int listnum, List L1, List L2, List L3)
{
    switch(listnum)
    {
        case 1: doPrint(L1); break;
        case 2: doPrint(L2); break;
        case 3: doPrint(L3); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void search(int listnum, int num, List L1, List L2, List L3)
{
    switch(listnum)
    {
        case 1: doSearch(L1,num); break;
        case 2: doSearch(L2,num); break;
        case 3: doSearch(L3,num); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void insert(int listnum, int position, int num, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1: doInsert(L1,position,num); break;
        case 2: doInsert(L2,position,num); break;
        case 3: doInsert(L3,position,num); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void remove(int listnum, int position, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1: doRemove(L1,position); break;
        case 2: doRemove(L2,position); break;
        case 3: doRemove(L3,position); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void rotateleft(int listnum, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1: doRotateLeft(L1); break;
        case 2: doRotateLeft(L2); break;
        case 3: doRotateLeft(L3); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void rotateright(int listnum, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1: doRotateRight(L1); break;
        case 2: doRotateRight(L2); break;
        case 3: doRotateRight(L3); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void free(int listnum, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1: doFree(L1); break;
        case 2: doFree(L2); break;
        case 3: doFree(L3); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void append(int listnum, int listnum2, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1:
            {
                switch(listnum2)
                {
                    case 1: cout << "Error, you cannot append a list to itself, try again..." << endl << endl; break;
                    case 2: doAppend(L1, L2); break;
                    case 3: doAppend(L1, L3); break;
                    default: cout << "Invalid list, try again..." << endl; break;
                }
            }
            break;
        case 2:
            {
                switch(listnum2)
                {
                    case 1: doAppend(L2, L1); break;
                    case 2: cout << "Error, you cannot append a list to itself, try again..." << endl << endl; break;
                    case 3: doAppend(L2, L3); break;
                    default: cout << "Invalid list, try again..." << endl; break;
                }
            }
            break;
        case 3:
            {
               switch(listnum2)
                {
                    case 1: doAppend(L3, L1); break;
                    case 2: doAppend(L3, L2); break;
                    case 3: cout << "Error, you cannot append a list to itself, try again..." << endl << endl; break;
                    default: cout << "Invalid list, try again..." << endl; break;
                } 
            }
            break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void merge(int listnum, int listnum2, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1:
            {
                switch(listnum2)
                {
                    case 1: cout << "Error, you cannot merge a list with itself, try again..." << endl << endl; break;
                    case 2: doMerge(L1, L2); break;
                    case 3: doMerge(L1, L3); break;
                    default: cout << "Invalid list, try again..." << endl; break;
                }
            }
            break;
        case 2:
            {
                switch(listnum2)
                {
                    case 1: doMerge(L2, L1); break;
                    case 2: cout << "Error, you cannot merge a list with itself, try again..." << endl << endl; break;
                    case 3: doMerge(L2, L3); break;
                    default: cout << "Invalid list, try again..." << endl; break;
                }
            }
            break;
        case 3:
            {
               switch(listnum2)
                {
                    case 1: doMerge(L3, L1); break;
                    case 2: doMerge(L3, L2); break;
                    case 3: cout << "Error, you cannot merge a list with itself, try again..." << endl << endl; break;
                    default: cout << "Invalid list, try again..." << endl; break;
                } 
            }
            break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void copy(int listnum, int listnum2, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1:
            {
                switch(listnum2)
                {
                    case 1: cout << "Error, you cannot copy a list onto itself, try again..." << endl << endl; break;
                    case 2: doCopy(L1, L2); break;
                    case 3: doCopy(L1, L3); break;
                    default: cout << "Invalid list, try again..." << endl; break;
                }
            }
            break;
        case 2:
            {
                switch(listnum2)
                {
                    case 1: doCopy(L2, L1); break;
                    case 2: cout << "Error, you cannot copy a list onto itself, try again..." << endl << endl; break;
                    case 3: doCopy(L2, L3); break;
                    default: cout << "Invalid list, try again..." << endl; break;
                }
            }
            break;
        case 3:
            {
               switch(listnum2)
                {
                    case 1: doCopy(L3, L1); break;
                    case 2: doCopy(L3, L2); break;
                    case 3: cout << "Error, you cannot copy a list onto itself, try again..." << endl << endl; break;
                    default: cout << "Invalid list, try again..." << endl; break;
                } 
            }
            break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void clean(int listnum, List& L1, List& L2, List& L3)
{
    switch(listnum)
    {
        case 1: doClean(L1); break;
        case 2: doClean(L2); break;
        case 3: doClean(L3); break;
        default: cout << "Invalid list, try again..." << endl; break;
    }
}

void load(string filename, List& L1, List& L2, List& L3)
{
    string command;
    int list;
    int position;
    int value;
    int list2;
    string filename1;
    
    ifstream incommandfile(filename); // open the file if it's given.
    
    if (!incommandfile.good()) // if not then this statement output's the error massage.
    {
        cout << "File does not exist, try again..." << endl;
        return;
    }
    cout << "Load: loading '" << filename << "'" << endl;
    incommandfile >> command;
    while (command != "x")
    {
        if (command == "l")
        {
            incommandfile >> filename1;
            
            load(filename1, L1, L2, L3);
            
        }
        else if (command == "p")
        {

            incommandfile >> list;

            print(list, L1, L2, L3);

        }
        else if (command == "i")
        {
            incommandfile >> list;
            incommandfile >> position;
            incommandfile >> value;

            insert(list, position, value, L1, L2, L3);
        }
        else if (command == "s")
        {
            
            incommandfile >> list;
            incommandfile >> value;
            
            search(list, value, L1, L2, L3);
            
        }
        else if (command == "r")
        {
       
            incommandfile >> list;
            incommandfile >> position;
            
            remove(list, position, L1, L2, L3);
            
        }
        else if (command == "rl")
        {
            
            incommandfile >> list;
            
            rotateleft(list, L1, L2, L3);
            
        }
        else if (command == "rr")
        {
            
            incommandfile >> list;
            
            rotateright(list, L1, L2, L3);
            
        }
        else if (command == "f")
        {
            
            incommandfile >> list;
            
            free(list, L1, L2, L3);
            
        }
        else if(command == "a")
        {
            
            incommandfile >> list;
            incommandfile >> list2;
            
            append(list, list2, L1, L2, L3);
            
        }
        else if(command == "m")
        {
            
            incommandfile >> list;
            incommandfile >> list2;
            
            merge(list, list2, L1, L2, L3);
            
        }
        else if(command == "cp")
        {
            
            incommandfile >> list;
            incommandfile >> list2;
            
            copy(list, list2, L1, L2, L3);
            
        }
        else if(command == "cl")
        {
            
            incommandfile >> list;
            
            clean(list, L1, L2, L3);
            
        }
        else
        {
            cout << "Invalid command, try again..." << endl;
        }
        
        incommandfile >> command;
    }
    
    cout << "Load: done '" << filename << "'" << endl;
}

int main()
{
    List L1;
    List L2;
    List L3;
    
    init(L1);
    init(L2);
    init(L3);
    
    string command;
    string filename;
    int list;
    int position;
    int value;
    int list2;
    int p = 1;
    
    cout << "** Program for working with linked-lists **" << endl << endl;
    
    while (p>0)
    {
        cout << "Enter a command (l,p,s,i,r,rl,rr,f,a,m,cp,cl,x): ";
        cin >> command;
        
        if (command == "x")
        {
            p = -2;
            cout << endl << "** Done **" << endl;
        }
        else if (command == "l")
        {
            cin >> filename;
            
            load(filename, L1, L2, L3);
            
        }
        else if (command == "p")
        {
            
            cin >> list;
            
            print(list, L1, L2, L3);
        
        }
        else if (command == "s")
        {
            
            cin >> list;
            cin >> value;
            
            search(list, value, L1, L2, L3);
            
        }
        else if (command == "i")
        {
            
            cin >> list;
            cin >> position;
            cin >> value;
            
            insert(list, position, value, L1, L2, L3);
            
        }
        else if (command == "r")
        {
       
            cin >> list;
            cin >> position;
            
            remove(list, position, L1, L2, L3);
            
        }
        else if (command == "rl")
        {
            
            cin >> list;
            
            rotateleft(list, L1, L2, L3);
            
        }
        else if (command == "rr")
        {
            
            cin >> list;
            
            rotateright(list, L1, L2, L3);
            
        }
        else if (command == "f")
        {
            
            cin >> list;
            
            free(list, L1, L2, L3);
            
        }
        else if(command == "a")
        {
            
            cin >> list;
            cin >> list2;
            
            append(list, list2, L1, L2, L3);
            
        }
        else if(command == "m")
        {
            
            cin >> list;
            cin >> list2;
            
            merge(list, list2, L1, L2, L3);
            
        }
        else if(command == "cp")
        {
            
            cin >> list;
            cin >> list2;
            
            copy(list, list2, L1, L2, L3);
            
        }
        else if(command == "cl")
        {
            
            cin >> list;
            
            clean(list, L1, L2, L3);
            
        }
        else
        {
            cout << "Invalid command, try again..." << endl;
        }
        
        cout << endl;
    }
    
    free(L1);
    free(L2);
    free(L3);
    
    return 0;
}