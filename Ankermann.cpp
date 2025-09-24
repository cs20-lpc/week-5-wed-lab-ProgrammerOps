/****************************************************
 * Ackermann.cpp  —  Recursin Pratice
 *
 * Big idea :
 * -   We’re writing a function called "ackermann" that
 *   calls itself   (this is called recursion).
 * -  Think of recursion like a stack of pancakes:
 *   each time we call the function,  we add a pancake
 *    to the stack; when we "return", we  remove one.

 * Notes:
 * - Ackermann grows FAST. Even tiny inputs  can explode.
 * -  We'll use small inputs (like m <= 3) to avoid stack overflow.
 * - We use a   BIG integer type  for the result (unsigned long long)
 *    so we have more "room" for larger numbers.

* Analogy:
 *   -  Imagine a building with  floors labeld by m.
 *   - n is like the number of "steps" we still have.
 *   - Base flor (m == 0): just take one step    forwrd (n + 1) and youre done.
 *   - If you're above the base floor but out of steps (n == 0):
 *       go down a floor (m-1) and reset steps to 1.
 ******************************************** *************************************/




#include <iostream>
using namespace std;

// Ackermann function definition
unsigned long long ackermann(unsigned int m, unsigned int n) {
 // TODO: Complete the code.


// Base case #1: When we are on floor 0, the rule says A(0, n) = n + 1.


if (m == 0) {
        return static_cast<unsigned long long>(n) + 1ULL;

}

 // Base case #2: If m > 0 but n == 0, rule says A(m, 0) = A(m-1, 1).

if (n == 0) {
        return ackermann(m - 1, 1);

}

//Ackermann grows super fast. For small m,n this is okay,
    // but bigger values can cause very deep recursion (stack overflow).


 return ackermann(m - 1, static_cast<unsigned int>(ackermann(m, n - 1)));
}



int main() {
    unsigned int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    cout << "Ackermann(" << m << ", " << n << ") = " 
         << ackermann(m, n) << endl;

    return 0;
}