//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void f(int i,int j,vector<string>& ans,string s)
    {
        if(i==0 && j==0) 
        {
            ans.push_back(s);
            return;
        }
        
        if(j>0) f(i,j-1,ans,s+")");
        if(i>0) f(i-1,j+1,ans,s+"(");
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
       vector<string> ans;
       f(n,0,ans,"");
       return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends