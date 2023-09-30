//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int i=0;
        
        while(i<str.size() && str[i]==' ') i++;
        str.substr(i);
        
        int sign=1;
        long ans=0;
        if(str[i]=='-') 
        {
            sign*=-1;
            i=1;
        }
        if(str[i]=='+')
        {
            i=1;
        }
        
        while(i<str.size())
        {
            if(str[i]==' ' || !isdigit(str[i])) return -1;
            
            ans=ans * 10 + (str[i] - '0');
            
            i++;
            
        }
        return (int) sign*  ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends