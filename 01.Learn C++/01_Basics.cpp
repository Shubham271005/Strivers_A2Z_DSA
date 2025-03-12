# Boiler Code

  #include<iostream>
   using namespace std;
     int main () {
     cout<<"content" ;
      return 0;
      }
------------------------------------------------------------------------------
- for including all the libraries, use
     #include<bits/stdc++.h>
------------------------------------------------------------------------------
  
  Variables are containers to store data

Data Types
  - int : 4 butes
  - char : 1 byte
  - float : 4 bytes
  - bool : 1 byte
  - double : 8 bytes

 conversion | implicit - small to big  ( by computer automatic )
 casting | explicit - bg to small ( manually )
-------------------------------------------------------------------------------
Operators
 - Arithmetic : +, -, *, /, %
 - Relational : <, >, <=, >=, ==, !=  ( Bool Output )
 - Logical : or( || ) , and ( && ) , not ( ! )

Unary Operators 
 - Inreament : ++ 
     - post increament : a++ (pehle kaam then update)
     - pre increament : ++a (pehle update then kaam)
 - Decreament : --
      - post decreament : a-- (pehle kaam then update)
      - pre decreament : --a (pehle update then kaam)
----------------------------------------------------------------------------------
Conditional Statements  ( if-else )

 Syntax

        if(conditon){
            }
           else{
                   }

   for multiple conditions ( eg- grading system )

          if(){
            }
            else if(){
            }
            else if(){
            }
            else { -false } 

Ternary Statememt
 - Simple if-else statement ko ek line me execute.

     condition ? stt1 : stt2

 eg- number positive or negative
       cout << ( n>=o ? "pos" : "neg" ) ;
-------------------------------------------------------------------------------------

Loops 
 - while loop 
 - for loop (most used)
 - do-while loop


while loop 
 eg - print number from 1 to x ( x is 20 )
  int main () {
   int n = 1;
   int x = 20;
  while(n<=x){
  cout << n << endl;                  // endl is for next line
  n++
  }
  return 0;
  }

for loop 
   for( initialisation ; condition ; updation ){
             work
            }

  eg- print 1 to 20
        for ( int i=1 ; i <=20 ; i++ ){
               cout << i;
               }
  eg- sum of numbers from 1 to n
             int sum = 0;
          for ( int i=1 ; i<= n ; i++ ){
                    sum += i ;
                  }
           cout << sum;

  # break keyword
   - loop se bahar aane k liye break keyword
       eg- if ( i == 5 ){
                  break;          //below sum += i in above code
                 }
     - now even if n=20, sum will be only for 1 to 5

do while loop 
  do {
        work
     } while ( condition );
 - in do while loop , even if condition is not fulfilled
   loop will run once because pehle kaam ho rha h fir condition check.
     eg-  do{
           cout << i << " ";
            i++;
           } while ( i <= n );

Nested Loops
 - Loop inside Loop
      eg-  for () {
            if () {
              }
              }
-----------------------------------------------------------------------------
  INT_MAX means +infinity in C++
  INT_MIN means -infinity

Patterns  ( usually for loop )

    for(){
     for(){
        }
       }
- Here, outer loop is for number of lines ( i=0 to i<n means n lines )
        inner loop is for number of elements in 1 single row/line 
 
- Square Patterns

 eg-1  for n=3
       1  2  3
       1  2  3
       1  2  3

 eg-2  for n=3
       1  2  3
       4  5  6
       7  8  9

- Triangle Patterns

 eg-3 i=0   x          --1      i+1
      i=1   x x        --2      i+1
      i=2   x x x      --3      i+1
      i=3   x x x x    --4      i+1

 eg-4       1
            2 2
            3 3 3 
            4 4 4 4 

 eg-5 Reverse Triangle
           1
           2 1
           3 2 1 
           4 3 2 1 

 eg-6 Floyd's Triangle
           1
           2 3
           4 5 6
           7 8 9 10

 eg-7 Inverted Triangle 
           1 1 1 1
             2 2 2 
               3 3 
                 4

-Pyramid Pattern

 eg-8  for n-4 
                1
             1  2  1 
          1  2  3  2  1
       1  2  3  4  3  2  1  

-Hollow Diamond

 eg-9                  
         X    
        X X   
       X   X  
      X     X 
     X       X
      X     X 
       X   X  
        X X   
         X   






  






















