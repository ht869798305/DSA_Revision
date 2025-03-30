#include<iostream>
#include<cmath> // Ensure cmath is included
using namespace std;

// Brute Force:
// Implementation:
// Initialize an answer variable with zero to store the answer.
// Run a loop from 1 to N.
// For every ith index run another loop from 1 to i and check how many divisors are present for i.
// If the number of divisors of i is 3 then increase the answer by 1.
// Return the answer.Implementation:
// Initialize an answer variable with zero to store the answer.
// Run a loop from 1 to N.
// For every ith index run another loop from 1 to i and check how many divisors are present for i.
// If the number of divisors of i is 3 then increase the answer by 1.
// Return the answer.

// Time Complexity: O(N2) as we are running two nested for loops from 1 to N.
// Space Complexity: O(1) as we are only using variables of type int.




class Solution {
    public:
        bool hasThreeDivisors(int n)
        {
            int numberofFactors = 0;
            for (int i = 1; i <= n; i++) {
                if (n % i == 0)
                    numberofFactors++;
            }
            return numberofFactors == 3;
        }
        int exactly3Divisors(int N)
        {
            int ans = 0;
            for (int i = 1; i <= N; i++) {
                if (hasThreeDivisors(i))
                    ans++;
            }
            return ans;
            // Your code here
        }
    };


// Optimized Brute Force Approach:-
// // Implementation:
// Initialize an answer variable with zero to store the answer.
// Run a loop from 1 to N.
// For every ith index run another loop from 2 to sqrt(i) and check how many divisors are present for i.
// If the number of divisors of i is 3 then increase the answer by 1.
// Return the answer.

// Complexity:
// Time Complexity: O(N3/2) as we are running two nested for loops one from 1 to N and the other from 2 to sqrt(N).
// Space Complexity: O(1) as we are only using variables of type int.

class Solution {
    public:
       bool hasThreeDivisors(int n)
       {
           int numberofFactors = 2;
           for (int i = 2; i * i <= n; i++) {
               if (n % i == 0) {
                   numberofFactors++;
                   if (i * i != n)
                       numberofFactors++;
               }
           }
           return numberofFactors == 3;
       }
       int exactly3Divisors(int N)
       {
           int ans = 0;
           for (int i = 1; i <= N; i++) {
               if (hasThreeDivisors(i))
                   ans++;
           }
           return ans;
           // Your code here
       }
    };


// Expected Approach:
// Run a for loop from 1 to sqrt(N).
// For each i determine if i is prime or not if i is prime then increment the answer.
// To find if i is prime or not use the sqrt(N) approach as discussed here.
// Return the answer.
// Complexity:
// Time Complexity: O(N1/2 * N1/4) as we are running two nested for loops one from 1 to sqrt(N) and the other from 1 to sqrt(sqrt(N)).
// Space Complexity: O(1) as we are only using a variable of type int in the for loop.

//Back-end complete function Template for C++

class Solution{
    public:
    // function to check if n is prime
    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        
        return true ;
    }
    
    // function to check the numbers which has exactly 3 divisors
    int exactly3Divisors(int N)
    {
        //Initializing counter to zero
        int counter=0; 
        N = sqrt(N); 
        //running a loop from 1 to sqrt(N)     
        for(int i=1;i<=N;i++) 
        {
            // A number N only has 3 divisors if it is a  
            // perfect square and its square  root is a prime number, 
            // and we know the number of perfect squares less than N which 
            // is sqrt(N), so just checking if i is prime or not
            if(isPrime(i)) 
                counter++;
        }
        return counter;
    }

};

int main()
{
    int N;
    cin >> N;
    Solution obj;
    cout << obj.exactly3Divisors(N) << endl;
    
    return 0;


}