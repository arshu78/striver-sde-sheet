//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int j=0,i=0;
    int ans=INT_MIN;
    
    map<char,int> mp;
    int cur=0;
    while(j<s.length())
    {
        mp[s[j]]++;
        cur++;
        if(mp[s[j]]==1)
        {
            ans=max(ans,cur);
            j++;
        }
        else if(mp[s[j]]>1)
        {
            while(mp[s[j]]>1)
            {
                cur--;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
    }
    
    return ans;
}