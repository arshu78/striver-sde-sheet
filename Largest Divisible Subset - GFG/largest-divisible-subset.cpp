//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
         vector<int> dp(n,1),hash(n);
        int last=0,maxi=0;
        
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int pre=0;pre<i;pre++)
            {
                if(arr[i] % arr[pre]==0 && 1+ dp[pre] > dp[i])
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
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends