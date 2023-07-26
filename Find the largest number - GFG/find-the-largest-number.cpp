//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    bool possible(int n)
    {
        string s=to_string(n);
        
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1]>s[i]) return false;
        }
        return true;
    }
    
    int find(int n){
        if(possible(n))
        {
            return n;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(possible(i)) return i;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends