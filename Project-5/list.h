/*list.h*/

//
// Declarations of structs, and core functions, for two-way linked-lists.
//
// Initially by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 05
//

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

//
// One node in a two-way linked-list:
//
struct Node
{
   int   Value;
   Node* Next;
   Node* Prev;
};

//
// A two-way linked-list with Head and Tail pointers:
//
struct List
{
   Node* Head;
   Node* Tail;
};

//
// Core linked-list functions:
//

//
// init
//
// Initializes the list to empty.
//
// pre-condition: L is uninitialized and has not been used.
// post-condition: L is properly initialized to denote empty.
//
void init(List& L);

//
// free
//
// Frees the memory associated with the nodes in the list, 
// and then sets the list to empty.
//
// pre-condition: a properly initialized list.
// post-condition: L is properly set to denote empty.
//
void free(List& L);

//
// empty
//
// Returns true if the list is empty, false if not.
//
// pre-condition: a properly initialized list.
// post-condition: L is unchanged.
//
bool empty(List L);

//
// size
//
// Returns the number of nodes in the list.
//
// pre-condition: a properly initialized list.
// post-condition: L is unchanged.
//
int  size(List L);

//
// ith
//
// Returns the value in the node at the given position.
// Positions are 0-based, which means a position of 0 
// denotes the head of the list, and a position of N-1
// denotes the tail of the list (where N=size(L)).  
//
// Example: if L=[10,20,30] then 
//    ith(L,2) => 30
//
// pre-condition: a properly initialized list.
// post-condition: L is unchanged.
// exception: throws invalid_argument if position invalid.
//
int  ith(List L, int position);

//
// search
//
// Searches the list for the first occurence of value.
// If found, the position of this value is returned.
// If not found, -1 is returned.
//
// Positions are 0-based, which means a position of 0 
// denotes the head of the list, and a position of N-1
// denotes the tail of the list (where N=size(L)).  
//
// Example: if L=[10,20,30,20] then 
//    search(L,20) => 1
//
// pre-condition: a properly initialized list.
// post-condition: L is unchanged.
//
int  search(List L, int value);

//
// insert
//
// Inserts the given value in the list such that after
// the insertion, the value is now at the given
// position.
//
// Positions are 0-based, which means a position of 0 
// denotes the value will end up at the head of the list,
// and a position of N denotes the value will end up at
// the tail of the list.  N=size(L) before insertion.
//
// Examples: if L=[10,20] then 
//    insert(L,0,30) => [30,10,20]
//    insert(L,1,30) => [10,30,20]
//    insert(L,2,30) => [10,20,30]
//
// pre-condition: a properly initialized list.
// post-condition: L contains value at given position.
// exception: throws invalid_argument if position invalid.
//
void insert(List& L, int position, int value);

//
// remove
//
// Removes the node at the given position from the list,
// and returns the value stored in this node.
//
// Positions are 0-based, which means a position of 0 
// denotes the head of the list, and a position of N-1
// denotes the tail of the list.  N=size(L) before removal.
//
// Examples: if L=[10,20,30] then 
//    remove(L,1) => returns 20 with L=[10,30]
//
// pre-condition: a properly initialized list.
// post-condition: L with node at given position removed.
// exception: throws invalid_argument if position invalid.
//
int  remove(List& L, int position);

//
// pop_front
//
// Removes the node at the head of the list and returns
// the value from this node.
//
// pre-condition: a properly initialized list.
// post-condition: L with head node removed.
// exception: throws runtime_error if list empty.
//
int  pop_front(List& L);

//
// pop_back
//
// Removes the node at the tail of the list and returns
// the value from this node.
//
// pre-condition: a properly initialized list.
// post-condition: L with tail node removed.
// exception: throws runtime_error if list empty.
//
int  pop_back(List& L);

//
// push_front
//
// Inserts the given value at the head of the list.
//
// pre-condition: a properly initialized list.
// post-condition: L with value inserted at head.
//
void push_front(List& L, int value);

//
// push_back
//
// Inserts the given value at the tail of the list.
//
// pre-condition: a properly initialized list.
// post-condition: L with value inserted at tail.
//
void push_back(List& L, int value);
