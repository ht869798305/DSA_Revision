// Problem: Absolute Value
class Solution{
    public:
        int absolute(int I) {
        
        // if value is negative, then make it positive by multiplying it with -1
        // else return number as it is
        if (I < 0)
            return -1 * I;
        else
            return I;
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
        int I;
        cin >> I;
        Solution ob;
        cout << ob.absolute(I) << endl;
    }
    return 0;
}