#include <iostream>
#include "integer.h"

using namespace std;

int main()
{
    Integer i1; // default constructor => 0
    Integer i2("00000123"); // constructor => 123
    Integer i3("1230456789123456789"); // constructor => 456
    Integer i5("456");
    
    cout << i1.toRawStr() << endl;
    cout << i2.toRawStr() << endl;
    cout << i3.toRawStr() << endl;
    
    Integer i4(i2);
    
    cout << i4.toRawStr() << endl;
    
    i4 = i3;
    
    cout << i4.toRawStr() << endl;
    
    cout << i3.toStr() << endl;
    
    i5.shift_left(5);
    
    cout << i5.toStr() << endl;
    
    i3.add(i2);
    
    /*i1.add(i2); // i1 += i2;
    i2.add(i3); // i2 += i3;
   */
    
    return 0;
}