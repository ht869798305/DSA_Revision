//Back-end complete function Template for C++

class Solution{
    public:
    double cToF(int C)
    {
        //Fahrenheit to Celsius conversion formula
        double f =   ( ( C * 9.0 ) / 5.0 ) + 32 ;
        return f;
    }
};

// { Driver Code Starts
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int C;
        cin >> C;
        Solution ob;
        cout << ob.cToF(C) << endl;
    }
    return 0;
}