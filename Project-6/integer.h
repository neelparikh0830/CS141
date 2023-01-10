/*integer.h*/

//
// An Integer class for adding and shifting integers of unlimited
// digits.  Each integer is stored as a linked-list of individual
// digits.
// Author: Neel Parikh, UIC, Fall 2020
// Initially by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 06
//

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;


class Integer
{
private:
   class Node
   {
   public:
      int Value;
      Node* Next;
      Node* Prev;

      Node() // This is a constructor for Node that set next and prev to null
      {
         Next = nullptr;
         Prev = nullptr;
      }
   };
    
    // setting node head and tail to null and size to zero.
    
    Node* Head = nullptr;
    Node* Tail = nullptr;
    int size = 0;
    

    
    int  Size()
    {

       Node* temp = Head; // creates new node of temp than can go through the list

       int i=0; // intializing i to zero to count the size of list

       while (temp != nullptr) // while loop will run until temp is null and it has counted every nodes in the list
       {

          i++;
          temp = temp->Next;

       }

       return i; // finally returns the size of the list
    }

    void push_back(int num)
    {
       Node* cur = new Node(); // creates new node of temp1 than can go through the list

       cur->Value = num; // given value is assigned to the temp
       
       Node* temp1 = Head;
        
       if(temp1 != nullptr) // this if statement will run if head is not null pointer and value is pushed back.
       {
           Tail->Next = cur;
           cur->Prev = Tail;
           Tail = cur;
          
       }

       else // otherwise that node will be assignsed head and tail of that list
       {
          Head = Tail = cur;
       }
    }
    
    void deepCopy(const Integer& other)
    {
      Node* temp1 = other.Head;
      
      while (temp1 != nullptr)
      {
      
         push_back(temp1->Value);
         
         temp1 = temp1->Next;
         
      }
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
// This free function will remove nodes and set head and tail to null for other to use that list.
    
    void free()
    {
        Node* cur = Head; // creates new node of cur than can go through the list

        while(cur != nullptr) // while loop will run until cur is null and delete node one by one
        {

            Node* cur2 = cur;
            cur = cur->Next;
            delete cur2;

        }

        Head = nullptr; //finally head and tail is set yo null
        Tail = nullptr;

    }
    
    void  pop_back()
    {
        if (Head == nullptr) // this will throw an error massage because it's empty list
        {
            throw runtime_error("pop_back on empty list");
        }

        Node* newVar = Tail; // creates new node is asignsed to head of list

        if (Tail->Prev == nullptr) // if tail prev is null than list is assignsed the to null
        {
            Head = nullptr;
            Tail = nullptr;
        }
        else // otherwise it will with rest of list
        {
            Tail = Tail->Prev;
            Tail->Next = nullptr;
        }

        delete newVar; // node is newvar is deleted
    }
    
    void push_front(int value)
    {
       Node* temp1 = new Node(); // creates new node of temp1 than can go through the list

       temp1->Value = value; // given value is assigned to the temp

       temp1->Next = temp1->Prev = nullptr; // temp next and prev are assignsed to null pointer

       if(Head != nullptr) // this if statement will run if head is not null pointer and value is pushed front.
       {
          Head->Prev = temp1;
          temp1->Next = Head;
          Head = temp1;
       }

       else // otherwise that node will be assignsed head and tail of that list
       {
          Head = Tail = temp1;
       }
    }


public:   
   //
   // default constructor
   //
   // Constructs an integer object and initializes to the value 0.
   // This function is called automatically when an integer is 
   // constructed; do not call this function directly.
   //
   // pre-condition: an invalid integer object.
   // post-condition: a properly initialized integer set to 0.
   // exception: none.
   //
   Integer()
   {
       push_back(0);
   }

   //
   // constructor:
   //
   // Constructs this integer based on the digits from the given 
   // integer string; throws an exception if s is not an integer
   // strnig.  This function is called automatically when an integer
   // is constructed; do not call this function directly.
   //
   // Example:
   //   if s = "1234" => integer is 1234
   //   if s = "oops" => integer is 0 and throws an exception
   //
   // pre-condition: an invalid integer object.
   // post-condition: a properly initialized integer object that has
   //   the same integer value as implied by the string.
   // exception: throws invalid_argument if the string is empty or 
   //   non-numeric, with integer initialized to 0.
   //
   Integer(string s)
   {
       int k = 0;
       int j = s.length();
       
        for (int i=0; i<j; i++)
        {
            if(!isdigit(s[i]))
            {
               push_back(0);
               throw invalid_argument("Integer(string s): invalid string");
            }
        }
       
       if (j == 0)
       {
           push_back(0);
           throw invalid_argument("Integer(string s): invalid string");
       }
       
       else
       {
           while(isdigit(s[k]))
           {
               push_back(s[k]-'0');
               k++;
               size++;
           }
       }
   }

   //
   // copy constructor
   //
   // Constructs this integer via a deep-copy of the other integer.  
   // This function is called automatically when an integer is 
   // constructed; do not call this function directly.
   //
   // pre-condition: an invalid integer object.
   // post-condition: a properly initialized integer object that has
   //   the same integer value as the other integer.
   // exception: none.
   //
   Integer(const Integer& other)
   {
      Head = nullptr;
      Tail = nullptr;
      
      deepCopy(other);
      
   }

   //
   // destructor
   //
   // Frees the resources associated with this integer.  This function
   // is called automatically when an integer is being destroyed; 
   // do not call this function directly.
   //
   // pre-condition: properly initialized integer objects.
   // post-condition: an invalid integer object.
   // exception: none.
   //
   ~Integer()
   {
       free();
   }

   //
   // operator=
   //
   // Performs a proper C++ assignment of the other integer into
   // this integer.  This implies the existing integer is freed,
   // and then a deep-copy of the other integer is made.  This
   // function is called automatically as part of an assignment
   // operation involving integer objects; do not call this function
   // directly.
   //
   // pre-condition: properly initialized integer objects.
   // post-condition: this integer is a deep-copy of the other integer.
   // exception: none.
   //
   Integer& operator=(const Integer& other)
   {
      if (this == &other)  // special case: check for i = i;
      {
         return *this;     // do nothing and just return THIS object back
      }
         
      free();
      
      deepCopy(other);

      return *this;  // done, return THIS object back
   }

   //
   // toRawStr
   //
   // Converts this integer to a string, with no leading zeros.
   // The string is returned.
   //
   // Example:
   //   if i = 123456 => returns "123456"
   //   if i = 0 => return "0"
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: integer string is returned with no leading zeros.
   // exception: none.
   //
   string toRawStr()
   {
       string neel;
       int length = 0;
       Node* cur = Head;
       while (cur != nullptr)
       {
           if(cur->Value+'0' == 48 && length == 0)
           {
               cur = cur->Next;
           }
           else
           {
               neel += cur->Value+'0';
               cur = cur->Next;
               length++;
           }
       }
       
      if(length == 0)
      {
          neel = "0";
      }
      
      return neel;
   }

   //
   // toStr()
   //
   // Converts this integer to a string with USA-style commas
   // inserted at every thousandth location, with no leading 
   // zeros.  The string is returned.
   //
   // Example:
   //   if i = 123456 => returns "123,456"
   //   if i = 789 => returns "789"
   //   if i = 0 => return "0"
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: USA-style integer string is returned, with
   //   no leading zeros.
   // exception: none.
   //
   string toStr()
   {
       string meet = toRawStr();
       int x = 3;
       int y = meet.length() - x;
       
       while (y > 0)
       {
           meet.insert(y,",");
           y-=3;
           
       }
       
      return meet;
   }

   //
   // add
   //
   // Adds the other integer to this integer, in effect computing
   // this += other.  Nothing is returned, the integer is internally
   // updated.
   //
   // pre-condition: properly initialized integer objects.
   // post-condition: this integer increased by other integer.
   // exception: none.
   //
   void add(const Integer& other)
   {
       Node* temp1 = Tail;
       Node* temp2 = other.Tail;
       int sum = 0;
       int carry = 0;
   
         while (temp1 != nullptr && temp2 != nullptr) 
         {
         
           sum = temp1->Value + temp2->Value + carry; 
           
           if (sum < 10)
           {
           
             temp1-> Value = sum;
             carry = 0;

           }
           
           else
           {
           
             temp1 -> Value = sum - 10; 
             carry = 1;
             
           }
           
           temp1 = temp1-> Prev;
           temp2 = temp2-> Prev;
         }
         
         if(temp1 == nullptr && temp2 == nullptr && carry == 1) 
         {
         
             push_front(carry);
           
         }
         
         if(temp1 != nullptr && temp2 == nullptr) 
         {
           while(temp1 != nullptr)
           {
             sum = temp1->Value + carry;
             
             if (sum < 10)
             {
             
               carry = 0;
               temp1->Value = sum;
              
             }
             else
             {
             
               temp1->Value = sum - 10;
               carry = 1;
               
             }
             temp1 = temp1->Prev;
           }
           
          if(temp1 == nullptr && temp2 == nullptr && carry == 1) 
          {
          
              push_front(carry);
            
          }
       }
         
         if (temp1 == nullptr && temp2 != nullptr)
         {
           while(temp2 != nullptr)
           {
             sum = temp2-> Value + carry;
             
             if(sum < 10)
             {
               
               push_front(sum);
               carry = 0;
               
             }
             else
             {
               
               push_front(sum-10);
               carry = 1;
               
             }
             temp2 = temp2-> Prev;
           }
         if(temp1 == nullptr && temp2 == nullptr && carry == 1)
         {
         
             push_front(carry);
          
         }
       }  
   }

   //
   // shift_left
   //
   // Shifts the integer digits left by the given amount N,
   // in effect multiplying the integer by 10^N.  If the integer
   // is 0, then the result remains 0.  Nothing is returned, 
   // the integer is internally updated.
   //
   // Example: 
   //   if i = 1234 then shift_left(i, 2) => 123400
   //   if i = 0 then shift_left(i, x) => 0
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: if non-zero to start, the integer has 
   //   N lower-order 0's added.
   // exception: throws invalid_argument if N < 0.
   //
   void shift_left(int N)
   {
   
       if (N < 0)
       {
           throw invalid_argument("shift_right: invalid shift amount N");
       }
       
       else
       {
       
           while (N > 0)
           {
           
               push_back(0);
               N--;
               
           }  
       }
   }

   //
   // shift_right
   //
   // Shifts the integer digits right by the given amount N,
   // in effect dividing the integer by 10^N.  If the integer
   // contains <= N digits, then the integer is shifted right
   // until 1 digit remains.  Nothing is returned, the integer
   // is internally updated.
   //
   // Example: 
   //   if i = 1234 then shift_right(i, 2) => 12
   //   if i = 1234 then shift_right(i, 4) => 1
   //   if i = 0 then shift_right(i, x) => 0
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: if non-zero to start, the integer has 
   //   N lower-order digits removed.
   // exception: throws invalid_argument if N < 0.
   //
   void shift_right(int N)
   {
       
       
       if (N < 0)
       {
           throw invalid_argument("shift_left: invalid shift amount N");
       }
       
       else
       {
       
           while (N > 0 && size > 1)
           {
               pop_back();
               N--;
               size--;
               
           }  
       }
   }

};
