//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool f(int i,int j,string &A,string &B)
    {
        if(j==A.length()-1) return true;
        if(i==B.length()-1)
        {
            return false;
        }
        if(A[j]==B[i]) return f(i+1,j+1,A,B);
        else
        return f(i+1,j,A,B);
    }
    bool isSubSequence(string A, string B) 
    {
        return f(0,0,A,B);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends