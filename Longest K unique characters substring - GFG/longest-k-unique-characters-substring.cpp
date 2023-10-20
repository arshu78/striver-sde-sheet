//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0;
        int cnt=0,ans=-1;
        unordered_map<char,int> mp;
        while(j<s.size())
        {
            if(mp.find(s[j])==mp.end()) cnt++;
            
            if(cnt==k) ans=max(ans,j-i+1);
            else if(cnt>k)
            {
                while(cnt>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) 
                    {
                        mp.erase(s[i]);
                        cnt--;
                    }
                    i++;
                }
            }
            mp[s[j]]++;
            j++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends