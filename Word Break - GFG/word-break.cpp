//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool f(int ind,int n,string& a,set<string>& st,vector<int>& dp)
    {
        if(ind==n) return true;
        if(dp[ind]!=-1) return dp[ind];
        string temp="";
        for(int i=ind;i<a.length();i++)
        {
            temp+=a[i];
            
            if(st.find(temp)!=st.end())
            {
                if(f(i+1,n,a,st,dp)) return true;
            }
        }
        return dp[ind]= false;
    }
    int wordBreak(string A, vector<string> &B) {
        set<string> st;
        vector<int> dp(A.size()+1,-1);
        for(auto it:B) st.insert(it);
        return f(0,A.size(),A,st,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends