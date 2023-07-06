//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1),hash(n);
        int last=0,maxi=0;
        
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int pre=0;pre<i;pre++)
            {
                if(arr[pre]<arr[i] && 1+ dp[pre] > dp[i])
                {
                    dp[i]=1 + dp[pre];
                    hash[i]=pre;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last]);
        while(hash[last]!=last)
        {
            last=hash[last];
            ans.push_back(arr[last]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends