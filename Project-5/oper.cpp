/*oper.h*/

//
// Declarations of command functions manipulating linked-lists.
//Author: Neel Parikh UIC Fall 2020
// Initially by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 05
// This file will call the function from list.h and output and correct massage in main program.
// This file will help us to write high level programing code other than playing with pointer.



#include <iostream>
#include <string>

#include "list.h"

using namespace std;

//
// doPrint
//
// Prints each element, one after another, on a single line; 
// a space follows each element. 
//
void doPrint(List L)
{
    cout << "print: ";
    
    for (int i=0; i < size(L); i++) // this for loop will cout ith element until the end of list.
    {
        cout << ith(L,i) << " ";
    }
    
    cout << endl;
}

//
// doSearch
//
// Searches the list for the given value.  If found, a message with
// the value and list position is output on the console.  If not 
// found, a "not found" message is output.
//
void doSearch(List L, int value)
{
    cout << "Search: value " << value;
    
    int num = search(L, value); // This serach function will search value in the list ans asign it to num 
    
    if (num < 0) // This says if value is not found than it will retuen -1 and cout not found.
    {
        cout << " not found" << endl;
    }
    else // otherwise it will out put the index where it's found.
    {
        cout << " found at position " << num << endl;
    }
}

//
// doInsert
//
// Attempts to insert the value in the List at the specified
// position.  If successful, a message is output on the console
// containing the value and position.  If unsuccessful, the 
// exception is caught and the error msg is output to the 
// console.  Either way, the list is printed afterwards.
//
void doInsert(List& L, int position, int value)
{
    // This try and catch loop is assign if it's at correct position otherwise catch will output and error massage without crashing program.
    try
    {
        insert(L, position, value);
        cout << "Insert: value " << value << " successfully inserted at position " << position << endl;
    }
    catch(exception& e)
    {
        cout << "Insert: failed ('" << e.what() << "')" << endl;
    }
    
    doPrint(L); // then it will print the list
}

//
// doRemove
//
// Attempts to remove the node at the specified position from
// the list.  If successful, a message containing the node's 
// value and position is output on the console.  If unsuccessful,
// the exception is caught and the error msg is output to the 
// console.  Either way, the list is printed afterwards.
//
void doRemove(List& L, int position)
{
    // This try and catch loop is assign if coorect value is removed otherwise catch will output and error massage without crashing program.
    try
    {
        int value = remove(L, position);
        cout << "Remove: value " << value << " successfully removed from position " << position << endl;
    }
    catch(exception& e)
    {
        cout << "Remove: failed ('" << e.what() << "')" << endl;
    }
    
    doPrint(L); // then it will print the list
}

//
// doRotateLeft
//
// Rotates the given list left, meaning the head element is removed
// and then inserted at the tail. The result is that all elements move
// forward ("left") one place.  If the list is empty, nothing happens;
// an empty list is not considered an error.
//
// The list is printed before and after the rotation, with a success
// message in-between.
//
void doRotateLeft(List& L)
{
    doPrint(L); // then it will print the list
    
    cout << "Rotate left: success" << endl;
    
    if (!empty(L)) // This loop will run if lit is not empty
    {
        
        int value = pop_front(L); // it pop the value from front and assign to value and then that value is pushed back on the list
        push_back(L, value);
        
    }
    
    doPrint(L); // then it will print the list in the rotate form
}

//
// doRotateRight
//
// Rotates the given list right, meaning the tail element is removed
// and then inserted at the head. The result is that all elements move
// backward ("right") one place.  If the list is empty, nothing happens;
// an empty list is not considered an error.
//
// The list is printed before and after the rotation, with a success
// message in-between.
//
void doRotateRight(List& L)
{
    doPrint(L); // then it will print the list
    
    cout << "Rotate right: success" << endl;
    
    if(!empty(L)) // This loop will run if lit is not empty
    {
        
        int value = pop_back(L); // it pop the value from back and assign to value and then that value is pushed in front on the list
        push_front(L, value);
        
    }
    
    doPrint(L); // then it will print the list in the rotate form
}

//
// doFree
//
// Frees the nodes in the given list, resetting the list to empty.
// A success message is output to the console, followed by the 
// contents of the list to confirm it's empty.
//
void doFree(List& L)
{
    // To free the list free funtion from list.h is called and then empty list is print.
    free (L); 
    cout << "Free: success" << endl;
    doPrint(L);
}

//
// doAppend
//
// Appends the "Other" list to the end of "L".  Afterwards, the
// "Other" list will be empty.  The lists are printed before and 
// after the operation, with a success message in-between.
//
void doAppend(List& L, List& L1)
{
    doPrint(L); // then it will print the frist list
    
    doPrint(L1); // then it will print the second list
    
    while(!empty(L1)) // This loop will run until list is not empty
    {
        
        int value = pop_front(L1); // it pop the value from front and assign to value and then that value is pushed back on the list until list is empty
        push_back(L, value);
        
    }
    
    cout << "Append: success" << endl;
    
    doPrint(L); // then it will print the edited list
    
    doPrint(L1); // then it will print the empty list after append list
}

//
// doMerge
//
// Merges the "Other" list into "L".  Afterwards, the "Other" list
// will be empty.  By merge this means the elements of Other are
// alternated with those of L.  Example: suppose we start with
//    L = [10, 30, 20, 90, 80] and Other = [15, 5, 25]
// Then after doMerge(L, Other):
//    L = [10, 15, 30, 5, 20, 25, 90, 80] and Other = [ ]
// Extra elements after the merge appear at the end of L.
//
// The lists are printed before and after the operation, with a 
// success message in-between.
// 
void doMerge(List& L, List& L1)
{
    List T; // first of all doing list temptarery
    
    init(T); // intializing list to null pointer
    
    doPrint(L); // then print the firsr original list
    
    doPrint(L1); // then printing the second original list
    
    cout << "Merge: success" << endl; // than calling the cout statement of merge
    
    while (!empty(L1)) // This loop will run until second list is not empty
    {
        
        if (!empty(L)) // then it will see if first list is not empty
        {
            int value1 = pop_front(L); // then passing first list value to temp
            push_back(T,value1);
        }
        
        int value2 = pop_front(L1); // then passing the second list value to temp
        push_back(T,value2);
        
    }
    
    while (!empty(L)) // This loop is made if L1 was shoter than L then appending rest of the value behind the L1 in temp
    {
        int value3 = pop_front(L);
        push_back(T,value3);
    }
    
    L = T; // this pass all the List T value in list L
    
    doPrint(L); // Then printing the merged list and empty list
    doPrint(L1);
    
}

//
// doCopy
//
// The current contents of Dest are free, and then a "deep" copy
// of Src is stored in Dest.  A deep copy means that for each node
// in Dest, a new node is dynamically-allocated and stored in Src.
// This means that after doCopy returns, Dest is a complete and
// distinct copy of Src.
//
// The lists are printed before and after the operation, with a 
// success message in-between.
//
void doCopy(List& L, List L1)
{
    doPrint(L); // then print the first original list
    
    doPrint(L1); // then print the second original list
    
    free(L); // then freeing list L for coping
    
    for (int i=0; i<size(L1); i++) // this for loop will copy all the L1 value to L by caling ith element one by one and than pushing back
    {
        
        int value = ith(L1,i);
        push_back(L, value);
        
    }
    
    cout << "Copy: success" << endl;
    
    doPrint(L); // This will print both same list
    doPrint(L1);
}

//
// doClean
//
// Removes duplicates from L, while preserving the original order.
// The list is printed before and after, along with the # of 
// duplicate values that were removed.
//
void doClean(List& L)
{
    List T; // new temp list
    
    init(T); // intialize list temp
    
    doPrint(L); // then printing list 
    
    int count = 0;
    
    while (!empty(L)) // sending list L to new list T
    {
        int value1 = pop_front(L);
        push_back(T,value1);
    }
    
    while (!empty(T)) // then transferring back to original list after removing same element
    {
        
        int value2 = pop_front(T);
        push_back(L,value2);
        
        for (int i=0; i<size(T); i++)
        {
            
            if(value2 == ith(T,i))
            {
                
                remove(T,i);
                i--;
                count++;
                
            }
        }
    }
    
    cout << "Clean: success, with " << count << " node(s) removed" << endl;
    
    doPrint(L); // then printing new list
}
