//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string solve(string &S)
    {
         int start=0;
        int end=0;
        int low,high;
        int n=S.length();
        for(int i=0;i<n;i++)
        {
            // even length
            low=i;
            high=i;
            
            while(low>=0 and high<n and S[low]==S[high])
            {
                if((end-start)<(high-low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
            
            // Odd length
            
            low=i;
            high=i+1;
            while(low>=0 and high<n and S[low]==S[high])
            {
                if((end-start)<(high-low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
        }
        return S.substr(start,end-start+1);
    
    }
    string longestPalin (string S) {
        string a=solve(S);
       // if(a=="") return S.substr(0,1);
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends