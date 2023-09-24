//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        string ans="";
        int cnt=0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto it:mp)
        {
            int tot=it.second;
            if(tot > cnt)
            {
                cnt=it.second;
                ans=it.first;
            }
            else if(it.second==cnt)
            {
                ans=it.first<ans?it.first:ans;
            }
        }
        string c=to_string(cnt);
        return {ans,c};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends