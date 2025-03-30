#include <iostream>
#include <cmath> // Ensure cmath is included
using namespace std;


// Brute Force Approach:
// Intuition
// The idea is to simply calculate factorial(N) and then find the number of digits in it.

// Implementation:-
// Implement a function to return factorial of N.
// In function digitsInFactorial(N):
// Calculate factorial(N) and store it in variable 'fact'.
// Count number of digits present in 'fact'.
// Initialize variable 'd' with 0, to store number of digits in 'fact'.
// while 'fact' is not equal to 0, increase 'd' by 1 and divide 'fact' by 10.
// Return 'd' as answer.

// Time Complexity: O(N), as function factorial(N) is having linear complexity.
// Auxiliary Space: O(1), as we are not using any extra space.

// Note: This approach will NOT work for higher values of N because of integer overflow as factorial(N) will be a very large value.

// Brute Force Approach:-
class BruteSolution{
    public:
    
    int factorial(int n){
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }
    
    int digitsInFactorial(int N){
        // finding factorial of a number
        int fact = factorial(N);
        
        // counting the number of digits present
        // in the factorial of number N
        int d = 0;
        while (fact != 0) {
            fact /= 10;
            d += 1;
        }        
        return d;
    }
};

// Expected Approach:
// Intuition
// The idea is to make use of these properties of log:
// Property1) For a number X, number of digits in X will be (floor(log(X)) + 1). 

// Proof:
// Let x be a positive integer with k digits. This means that:
// 10^(k-1) <= x < 10^k
// Taking logarithms base 10 of both sides, we get:
// k-1 <= log(x) < k
// Adding 1 to both sides, we get:
// k <= log(x) + 1 < k+1
// Taking the floor of both sides, we get:
// k = floor(log(x) + 1)
// Therefore, the number of digits in x is equal to floor(log(x) + 1).

// Property2) log(X * Y) = log(X) + log(Y). 
// So number of digits in N! will be:
// =>  floor(log(N!)) + 1
// => floor(log(1*2*3...*N)) + 1
// => floor(log(1)+log(2)+log(3)...+log(N)) + 1.
// Note: log used here is having base of 10.

// Implementation
// Initialize a variable 'sum' of type double with 0.
// Run a loop for j from 1 to N:
// Add log10(j) to the sum.
// Return (1+ floor(sum)) as answer.
// Let us understand it better with the help of an example:
// Input: N = 5
// log1 = 0
// log2 = 0.30103
// log3 = 0.477121
// log4 = 0.60206
// log5 = 0.69897
// log(5!) = (log1+log2+log3+log4+log5) = 2.07918
// So the number of digits in 5! is (1 + floor(2.07918)) which is 3.

// Complexity
// Time Complexity: O(N), as we are running a loop having N iterations.
// Auxiliary Space: O(1), as we are not using any extra space.

// Note: This approach will work for higher values of N as well.

// Expected Approach:-


class ExpectedSolution{
    public:
        
    int digitsInFactorial(int N)
    {
        double sum=0.0; 
        for(int j=1;j<=N;j++)
        {
            //sum stores log(j) + log(j+1) + ... + log(N) 
            sum+=std::log10(j); 
        }
        return(1+std::floor(sum));
    }
};

// { Driver Code Starts

int main() {
    // Test case for Expected Approach
    int N1;
    cin >> N1;
    ExpectedSolution ob1;
    cout << ob1.digitsInFactorial(N1) << endl;

    cout<<endl;

    // Test case for Brute Force Approach
    int N2;
    cin >> N2;
    BruteSolution ob2;
    cout << ob2.digitsInFactorial(N2) << endl;
    return 0;
}