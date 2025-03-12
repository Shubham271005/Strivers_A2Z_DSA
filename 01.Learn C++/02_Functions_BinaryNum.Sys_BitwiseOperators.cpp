Functions

 Syntax:
    returnType funName(typeP1, typeP2, .......){ //parameter
                       //do some work
                  }

- A function is a reusable block of code that performs a specific task.\
- They take input, performs operation and return result/output
- We define a function out of the int main function
  Now whenever we want to use the function, we write the function name and it will perform the operation and give output of the function.

eg- 
    #include<iostream>
     using namespace std;
      // function definition
     void printHello(){                 // void is a returnTyype with no return value.
            cout<<"hello\n";                   
              }
       int main(){
         printHello();
        return 0;
         }
          
eg- For sum function
       int sum(int a, int b){
           int s = a+b;
           return s
             }
//in main function : cout << sum(10, 5) 

- values that can not be changed are called literals
- arguments are generally literals
------------------------------------------------------------------------------------------------------------------------------------------------------
Function in Memory
 - stack : for static allocation
 - heep : for dynamic allocation
- Functions are stored in stack memory as stack frame,
  after returning their values, that stack frame comes out of the stack memory
------------------------------------------------------------------------------------------------------------
Pass by value
   - Copy of argument is passed to function
   - Any modification to the parameters inside the function do not affect original variables
   - Original data remains unchanged.
eg- 
   int sum(int a , int b){
      a = a+10; //15
      b = b+10; //14
       return a+b; //29
       }
    int main(){
    int a=5, b=4;                     // The output will be
    cout << sum(a, b) << endl;        //  29
     cout << a << endl;               //  5
     cout << b << endl;               //  4
    return 0;                         //  It shows that value of a and b are same i.e. 5 and 4 in main function
    }

For making changes in original argument (Pass by Reference)  
  just put '&' before the variable in the argument 
      eg-  in above function 
             int sum(int &a , int &b)
 - In arrays , it is default pass by reference . Except arrays, in everything , use '&' for pass by reference
 
---------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------
Binary Number System (0/1)
_________________________
 Base 2

# Decimal to Binary 
 
  Step : Repeated division with 2 and check remainder till quotient is 0
   eg-  (42) = (101010)       
         explanation -  42/2 = 0 rem
                        21/2 = 1 rem
                        10/2 = 0 men
                        05/2 = 1 rem
                        02/2 = 0 rem
                        01/2 = 1 rem
                    write from bottom to top , binary of 42 will bw 101010

 Code ( for decimal to binary )

   int decToBin(int decNum){
   int ans = 0; //binNum
   int pow = 1; // 10^0 to 10^1 to 10^2 ....
     while(decNum > 0){
      int rem = decNum % 2;
       decNum /= 2;
      ans += (rem*pow);
      pow *= 10;
      }
      return ans; //binary form

# Binary to Decimal

 Step : "2" ke increasing powers se multiply then add ( right to left )
       eg- (101010)
           in decimal form , 0*(2^0) + 1*(2^1) + 0*(2^2) + 1*(2^3) + 0*(2^4) + 1*(2^5) = 42 

  Code ( for binary to decimal )

   int binToDecimal(int binNum){
    int ans = 0;
    int pow = 1;
   while(binNum > 0){
    int rem = binNum % 10;
    ans += rem*pow;
   binNum /= 10;
   pow *= 2;
    }
   return ans; // decimal form
    }

Two’s Complement 
 Two’s complement is a method to represent negative numbers in binary.

Steps to Find Two’s Complement
-  Write the binary form of the number.
-  Invert all bits (0 → 1, 1 → 0).
-  Add 1 to the result.
 
  Example: -5 in 4-bit

+5 in binary → 0101
Invert bits → 1010
Add 1 → 1011 (Final result for -5)
 This is how computers store negative numbers! 
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
Bitwise Operators, Scope, Operator Precedence, and Data Type Modifiers

## 1. Bitwise Operators in C++
Bitwise operators perform operations at the bit level and are useful for optimizing programs that require low-level data manipulation.

### **Bitwise Operators**
- **AND (`&`)**: Performs bitwise AND
- **OR (`|`)**: Performs bitwise OR
- **XOR (`^`)**: Performs bitwise XOR (Exclusive OR)
- **NOT (`~`)**: Performs bitwise NOT (One’s complement)
- **Left Shift (`<<`)**: Shifts bits left (Multiply by 2^n)
- **Right Shift (`>>`)**: Shifts bits right (Divide by 2^n)

### **Examples**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3;
    cout << "a & b: " << (a & b) << endl;  // AND
    cout << "a | b: " << (a | b) << endl;  // OR
    cout << "a ^ b: " << (a ^ b) << endl;  // XOR
    cout << "~a: " << (~a) << endl;        // NOT
    cout << "a << 1: " << (a << 1) << endl; // Left Shift
    cout << "a >> 1: " << (a >> 1) << endl; // Right Shift
    return 0;
}
```

---

## 2. Scope in C++
Scope defines the visibility and lifetime of variables and functions.

### **Types of Scope**
- **Local Scope**: Variables declared inside a function are accessible only within that function.
- **Global Scope**: Variables declared outside functions can be accessed anywhere in the file.
- **Block Scope**: Variables declared inside `{}` are accessible only within that block.
- **Namespace Scope**: Used for organizing code and avoiding name conflicts.

### **Example**
```cpp
#include <iostream>
using namespace std;

int globalVar = 10; // Global Scope

void func() {
    int localVar = 5; // Local Scope
    cout << "Local Variable: " << localVar << endl;
}

int main() {
    func();
    cout << "Global Variable: " << globalVar << endl;
    return 0;
}
```

---

## 3. Operator Precedence in C++
Operator precedence determines the order in which operations are performed.

### **Precedence (Highest to Lowest)**
1. `::` (Scope resolution)
2. `++`, `--`, `()` (Increment, Decrement, Function call)
3. `*`, `/`, `%` (Multiplication, Division, Modulus)
4. `+`, `-` (Addition, Subtraction)
5. `<<`, `>>` (Bitwise Shift)
6. `<`, `<=`, `>`, `>=` (Relational Operators)
7. `==`, `!=` (Equality Operators)
8. `&` (Bitwise AND)
9. `^` (Bitwise XOR)
10. `|` (Bitwise OR)
11. `&&` (Logical AND)
12. `||` (Logical OR)
13. `=`, `+=`, `-=`, `*=`, `/=`, `<<=`, `>>=` (Assignment Operators)
14. `,` (Comma Operator)

### **Example of Operator Precedence**
```cpp
#include <iostream>
using namespace std;

int main() {
    int result = 5 + 2 * 3; // Multiplication (*) has higher precedence than Addition (+)
    cout << "Result: " << result << endl; // Output: 11
    return 0;
}
```

---

## 4. Data Type Modifiers in C++
Modifiers change the size or behavior of data types.

### **Types of Modifiers**
- `signed`: Default for int and char; allows positive & negative values
- `unsigned`: Allows only positive values
- `short`: Reduces the size of int (typically 2 bytes)
- `long`: Increases the size of int (typically 4 or 8 bytes)
- `long long`: Increases the size further (typically 8 bytes)

### **Example**
```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int x = 10; // Only positive values
    short int y = 32767; // Short integer
    long int z = 1000000; // Long integer
    cout << "Unsigned: " << x << endl;
    cout << "Short: " << y << endl;
    cout << "Long: " << z << endl;
    return 0;
}
```

---

## **Summary**
✅ Bitwise operators optimize low-level computations.
✅ Scope determines variable visibility.
✅ Operator precedence affects execution order.
✅ Data type modifiers modify memory usage and value ranges.

----------------------------------------------------------------------------------------------------------------------------------------------------------------


  
