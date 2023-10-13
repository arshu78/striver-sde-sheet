class Solution {
public:
    int f(int i,vector<int>& arr)
    {
        if(i==0) 
        {
            return arr[i];
        }
        if(i==1) return arr[i];

        int ss=arr[i]+f(i-1,arr);
        int dd=INT_MAX;
        if(i>1)
        dd=arr[i] + f(i-2,arr);

        return min(ss,dd);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; ++i) cost[i] += min(cost[i - 1], cost[i - 2]);
        return min(cost[n - 1], cost[n - 2]);
    }
};