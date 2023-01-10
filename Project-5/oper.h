/*oper.h*/

//
// Declarations of command functions manipulating linked-lists.
//
// Initially by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 05
//

#pragma once

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
void doPrint(List L);


//
// doSearch
//
// Searches the list for the given value.  If found, a message with
// the value and list position is output on the console.  If not 
// found, a "not found" message is output.
//
void doSearch(List L, int value);

//
// doInsert
//
// Attempts to insert the value in the List at the specified
// position.  If successful, a message is output on the console
// containing the value and position.  If unsuccessful, the 
// exception is caught and the error msg is output to the 
// console.  Either way, the list is printed afterwards.
//
void doInsert(List& L, int position, int value);

//
// doRemove
//
// Attempts to remove the node at the specified position from
// the list.  If successful, a message containing the node's 
// value and position is output on the console.  If unsuccessful,
// the exception is caught and the error msg is output to the 
// console.  Either way, the list is printed afterwards.
//
void doRemove(List& L, int position);

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
void doRotateLeft(List& L);

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
void doRotateRight(List& L);

//
// doFree
//
// Frees the nodes in the given list, resetting the list to empty.
// A success message is output to the console, followed by the 
// contents of the list to confirm it's empty.
//
void doFree(List& L);

//
// doAppend
//
// Appends the "Other" list to the end of "L".  Afterwards, the
// "Other" list will be empty.  The lists are printed before and 
// after the operation, with a success message in-between.
//
void doAppend(List& L, List& Other); 

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
void doMerge(List& L, List& Other); 

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
void doCopy(List& Dest, List Src);

//
// doClean
//
// Removes duplicates from L, while preserving the original order.
// The list is printed before and after, along with the # of 
// duplicate values that were removed.
//
void doClean(List& L);
