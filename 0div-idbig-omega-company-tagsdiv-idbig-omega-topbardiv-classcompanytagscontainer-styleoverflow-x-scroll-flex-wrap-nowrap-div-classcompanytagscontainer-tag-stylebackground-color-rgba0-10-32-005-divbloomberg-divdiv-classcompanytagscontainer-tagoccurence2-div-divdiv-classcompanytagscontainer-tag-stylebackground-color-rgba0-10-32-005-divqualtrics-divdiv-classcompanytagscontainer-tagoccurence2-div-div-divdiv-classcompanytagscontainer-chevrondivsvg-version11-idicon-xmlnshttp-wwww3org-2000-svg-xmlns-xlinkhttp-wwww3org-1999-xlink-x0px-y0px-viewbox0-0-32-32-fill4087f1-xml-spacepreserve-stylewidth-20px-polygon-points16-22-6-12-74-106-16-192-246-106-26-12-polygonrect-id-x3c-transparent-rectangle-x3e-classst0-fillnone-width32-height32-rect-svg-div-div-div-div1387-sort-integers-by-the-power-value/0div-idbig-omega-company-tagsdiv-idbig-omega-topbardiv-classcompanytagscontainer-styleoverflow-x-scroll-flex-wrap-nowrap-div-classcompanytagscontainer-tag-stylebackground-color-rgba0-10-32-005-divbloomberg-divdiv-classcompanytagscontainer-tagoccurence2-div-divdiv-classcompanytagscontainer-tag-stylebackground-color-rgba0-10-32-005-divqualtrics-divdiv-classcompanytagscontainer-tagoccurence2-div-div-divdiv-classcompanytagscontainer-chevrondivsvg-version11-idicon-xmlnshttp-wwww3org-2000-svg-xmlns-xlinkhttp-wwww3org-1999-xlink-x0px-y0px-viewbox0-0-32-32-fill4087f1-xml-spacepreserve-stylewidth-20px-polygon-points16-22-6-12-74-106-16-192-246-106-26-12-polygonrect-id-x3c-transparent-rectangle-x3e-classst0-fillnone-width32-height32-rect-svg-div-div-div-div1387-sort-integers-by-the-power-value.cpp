class Solution {
public:
    long long f(int i)
    {
        if(i==1) return 0;
       // if(dp[i]!=-1) return dp[i];
        int e=0,o=0;
        if(i%2==0)
        {
            e=1 + f(i/2);
        }
        else o= 1 + f(3*i+1);
        
        return e+o;
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
     //   vector<long long> dp(1001,-1);
        for(int i=lo;i<=hi;i++)
        {
            pq.push({f(i),i});
        }
        k=k-1;
        while(k--) pq.pop();
        
        return pq.top().second;
    }
};