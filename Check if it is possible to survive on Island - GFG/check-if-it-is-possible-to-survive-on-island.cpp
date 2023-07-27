//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sunday=S/7;
        
        int buy=S-sunday;
        
        int ans=0;
        
        if(S*M % N==0)
        {
            ans=S*M/N;
        }
        else
        {
            ans=S*M/N + 1;
        }
        
        if(ans<=buy) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends