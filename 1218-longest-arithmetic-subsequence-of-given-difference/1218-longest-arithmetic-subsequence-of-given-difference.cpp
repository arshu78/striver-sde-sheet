class Solution {
public:
    int f(int i,int prev,vector<int>& arr,int d)
    {
        if(i>=arr.size()) return 0;
        
      //  if(dp[i][prev]!=)
        int nt=0,t=0;
        
        if(prev==-10000)
        {
            nt= 0 + f(i+1,prev,arr,d);
            t= 1 + f(i+1,arr[i],arr,d);
        }
        else
        {
            nt= 0 + f(i+1,prev,arr,d);
            if(arr[i] - prev==d)
            {
                t= 1 + f(i+1,arr[i],arr,d);
            }
        }
        return max(nt,t);
    }
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp.find(arr[i]- d)!=dp.end())
            {
                dp[arr[i]]=dp[arr[i]-d] + 1;
            }
            else
            {
                dp[arr[i]]=1;
            }
            
            ans=max(ans,dp[arr[i]]);
        }
        
        return ans;
    }
};