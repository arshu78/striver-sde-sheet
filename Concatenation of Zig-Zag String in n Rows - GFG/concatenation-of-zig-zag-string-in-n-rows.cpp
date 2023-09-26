//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        vector<string> ans(n);
        int i=0,f=1;
        if(n==1) return s;
        for(auto it:s)
        {
            ans[i]+=it;
            if(i==0 || i==n-1) f=!f;
            
            if(f==0) i++;
            else i--;
        }
        string res="";
        for(auto it:ans) res+=it;
        
        return res;
        
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends