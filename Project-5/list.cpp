/*list.h*/

//
// Declarations of structs, and core functions, for two-way linked-lists.
// Author: Neel Parikh UIC Fall 2020
// Initially by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 05
// This File in project 5 will work as a low level programming file which will work with pointer 
// and that helps the oper.cpp and main.cpp file to function.
//



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
// This init function will set head and tail of the list to null pointer and initialize for programme to work.


void init(List& L)
{
    
    L.Head = nullptr; // intializing head and tail to null pointer.
    L.Tail = nullptr;
    
}

//
// free
//
// Frees the memory associated with the nodes in the list, 
// and then sets the list to empty.
//
// pre-condition: a properly initialized list.
// post-condition: L is properly set to denote empty.
//
// This free function will remove nodes and set head and tail to null for other to use that list.This

void free(List& L)
{
    Node* cur = L.Head; // creates new node of cur than can go through the list
    
    while(cur != nullptr) // while loop will run until cur is null and delete node one by one
    {
        
        Node* cur2 = cur;
        cur = cur->Next;
        delete cur2;
        
    }
    
    L.Head = nullptr; //finally head and tail is set yo null
    L.Tail = nullptr;
    
}

//
// empty
//
// Returns true if the list is empty, false if not.
//
// pre-condition: a properly initialized list.
// post-condition: L is unchanged.
//

bool empty(List L)
{
    if (L.Head == nullptr && L.Tail == nullptr) //it will return true if head and tail are null otherwise false
    {
        return true;
    }
    else
    {
        return false;
    }
}

//
// size
//
// Returns the number of nodes in the list.
//
// pre-condition: a properly initialized list.
// post-condition: L is unchanged.
//

int  size(List L)
{
    
   Node* temp = L.Head; // creates new node of temp than can go through the list
    
   int i=0; // intializing i to zero to count the size of list
    
   while (temp != nullptr) // while loop will run until temp is null and it has counted every nodes in the list
   {
       
      i++;
      temp = temp->Next;
       
   }
    
   return i; // finally returns the size of the list
}

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
// This function will return the ith positon in the list if it's possible otherwise it will throw an error.

int ith(List L, int position)
{
    
   Node* temp1 = L.Head; // creates new node of temp than can go through the list
    
   int value = 0; // intializing i to zero to obtain the value of ith position
    
   if (position < 0) // it will throw an argument if position is negative
   {
      throw invalid_argument("ith: invalid position");
   }
    
   else // this else statement will run to find the ith element
   {
      int j=0; // intializing j to zero to see if postion and j are equal to return the value at that point
      while (temp1 != nullptr) // while loop will run until temp1 is null
      {
          if  (position != j) // this loop will run until j = position otherwie temp is assign temp next
          {
             j++;
             temp1 = temp1->Next;
          }
          else // if j == position than it will outpout  value of that position
          {
              value = temp1->Value;
              return value;
              break;
          }
      }
      
      throw invalid_argument("ith: invalid position"); // it will throw an argument if position is bigger than size of list
   }
}




//
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
// The purpose of search function is to search if value is in the list or not. 

int search(List L, int value)
{
    
   Node* temp1 = L.Head; // creates new node of temp1 than can go through the list
    
   int position = -1; // intializing position to negative one and value is not found than it return that value.
    
   int i=0; // intializing i to zero and run in while loop until value is not it will increment itself
    
   while (temp1 != nullptr) // while loop will run until temp1 is null
   {
       
      if(temp1->Value == value) // if given value is found than i is given to position and break
      {
         position = i; 
         break;
      }
       
      i++;
      temp1 = temp1->Next;
   }
    
   return position; // finally returns the value
}

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
void insert(List& L, int position, int value)
{
    
    Node* temp1 = new Node();
    temp1->Value = value;
    temp1->Next = nullptr;
    temp1->Prev = nullptr;
    Node* temp2 = L.Head;
    Node* temp3 = nullptr;
    
    while(temp2 != nullptr)
    {
        if (position == 0)
        {
            break;
        }
        
         position--;
         temp3 = temp2;
         temp2 = temp2->Next;
    }
    
    if (position != 0)
    {
        delete temp1;
        throw invalid_argument("insert: invalid position");
    }
    
   else
   {
       if(temp3 == nullptr)
       {
           if (temp2 == nullptr)
           {
               L.Head = temp1;
               L.Tail = temp1;
           }
           
           else
           {
               temp2->Prev = temp1;
               temp1->Next = temp2;
               L.Head = temp1;
           }
       }
       else
       {
           if (temp2 == nullptr)
           {
               L.Tail->Next = temp1;
               temp1->Prev = L.Tail;
               L.Tail = temp1;
           }
           else
           {
               
               temp3->Next = temp1;
               temp2->Prev = temp1;
               temp1->Next = temp2;
               temp1->Prev = temp3;

           }
       }
   }
}

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
int  remove(List& L, int position)
{
    Node* cur = L.Head;
    Node* prev = nullptr;
    
    while(cur != nullptr)
    {
        if (position == 0)
        {
            break;
        }
        
        position--;
        
        prev = cur;
        cur = cur->Next;
    }
    
    if (position != 0 || cur == nullptr)
    {
        throw invalid_argument("remove: invalid position");
    }
    
    int value = cur->Value;
    
    if (prev == nullptr)
    {
        
        if (cur->Next == nullptr)
        {
            
            L.Head = nullptr;
            L.Tail = nullptr;
        }
        
        else 
        {
            L.Head = cur->Next;
            cur->Next->Prev = nullptr;
        }
    }
    
    else 
    {
        prev->Next = cur->Next;
        
        if(cur->Next == nullptr)
        {
            L.Tail = cur->Prev;
        }
        else
        {
            cur->Next->Prev = cur->Prev;
        }
        
    }
   
    delete cur;
    
    return value;
}


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
int  pop_front(List& L)
{
    if (L.Head == nullptr) // this will throw an error massage because it's empty list
    {
        throw runtime_error("pop_front on empty list");
    }
    
    Node* newVar = L.Head; // creates new node is asignsed to head of list
    int value = L.Head->Value; // value is assign the first value of the list
    
    if (L.Head->Next == nullptr) // if head next is null than list is assignsed the to null
    {
        L.Head = nullptr;
        L.Tail = nullptr;
    }
    else // otherwise it will with rest of list
    {
        L.Head = L.Head->Next;
        L.Head->Prev = nullptr;
    }
    
    delete newVar; // node is newvar is deleted
    return value; // finally value is returned
}

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
int  pop_back(List& L)
{
    if (L.Head == nullptr) // this will throw an error massage because it's empty list
    {
        throw runtime_error("pop_back on empty list");
    }
    
    Node* newVar = L.Tail; // creates new node is asignsed to head of list
    int value = L.Tail->Value; // value is assign the last value of the list
    
    if (L.Tail->Prev == nullptr) // if tail prev is null than list is assignsed the to null
    {
        L.Head = nullptr;
        L.Tail = nullptr;
    }
    else // otherwise it will with rest of list
    {
        L.Tail = L.Tail->Prev;
        L.Tail->Next = nullptr;
    }
    
    delete newVar; // node is newvar is deleted
    return value; // and value is returned
}

//
// push_front
//
// Inserts the given value at the head of the list.
//
// pre-condition: a properly initialized list.
// post-condition: L with value inserted at head.
//
void push_front(List& L1, int value)
{
   Node* temp1 = new Node(); // creates new node of temp1 than can go through the list
    
   temp1->Value = value; // given value is assigned to the temp
    
   temp1->Next = temp1->Prev = nullptr; // temp next and prev are assignsed to null pointer
   
   if(L1.Head != nullptr) // this if statement will run if head is not null pointer and value is pushed front.
   {
      L1.Head->Prev = temp1;
      temp1->Next = L1.Head;
      L1.Head = temp1;
   }
    
   else // otherwise that node will be assignsed head and tail of that list
   {
      L1.Head = L1.Tail = temp1;
   }
}

//
// push_back
//
// Inserts the given value at the tail of the list.
//
// pre-condition: a properly initialized list.
// post-condition: L with value inserted at tail.
//
void push_back(List& L1, int num)
{
   Node* temp1 = new Node(); // creates new node of temp1 than can go through the list
    
   temp1->Value = num; // given value is assigned to the temp
    
   temp1->Next = temp1->Prev = nullptr; // temp next and prev are assignsed to null pointer
   
   if(L1.Head != nullptr) // this if statement will run if head is not null pointer and value is pushed back.
   {
      L1.Tail->Next = temp1;
      temp1->Prev = L1.Tail;
      L1.Tail = temp1;
   }
    
   else // otherwise that node will be assignsed head and tail of that list
   {
      L1.Head = L1.Tail = temp1;
   }
}