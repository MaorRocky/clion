// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator #include <bits/stdc++.h>


#include <stdio.h>
#include <stdlib.h>

// Function to divide a by b and
// return floor value it
int divide(int dividend, int divisor) {

// Calculate sign of divisor i.e.,
// sign will be negative only iff
// either one of them is negative
// otherwise it will be positive
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

// Update both divisor and
// dividend positive
    dividend = abs(dividend);
    divisor = abs(divisor);

// Initialize the quotient
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }

    return sign * quotient;
}

// Driver code
int main() {
    int a = 10, b = 3;
    printf("%d",divide(a, b));



    return 0;
}
