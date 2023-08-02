//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(string s)
    {
        int n=s.length();
        int low=0,high=0,start=0,end=0;
        
        for(int i=0;i<s.length();i++)
        {
            low=i;
            high=i+1;
            
            while(low>=0 && high<n && s[low]==s[high])
            {
                if((end-start) < (high - low))
                {
                    start=low;
                    end=high;
                }
                
                low--;
                high++;
            }
            
            low=i;
            high=i+2;
            
            while(low>=0 && high<n && s[low]==s[high])
            {
                if((end-start) < (high - low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
        }
        
        return s.substr(start,end-start+1);
    }
    string longestPalindrome(string S){
        return solve(S);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends