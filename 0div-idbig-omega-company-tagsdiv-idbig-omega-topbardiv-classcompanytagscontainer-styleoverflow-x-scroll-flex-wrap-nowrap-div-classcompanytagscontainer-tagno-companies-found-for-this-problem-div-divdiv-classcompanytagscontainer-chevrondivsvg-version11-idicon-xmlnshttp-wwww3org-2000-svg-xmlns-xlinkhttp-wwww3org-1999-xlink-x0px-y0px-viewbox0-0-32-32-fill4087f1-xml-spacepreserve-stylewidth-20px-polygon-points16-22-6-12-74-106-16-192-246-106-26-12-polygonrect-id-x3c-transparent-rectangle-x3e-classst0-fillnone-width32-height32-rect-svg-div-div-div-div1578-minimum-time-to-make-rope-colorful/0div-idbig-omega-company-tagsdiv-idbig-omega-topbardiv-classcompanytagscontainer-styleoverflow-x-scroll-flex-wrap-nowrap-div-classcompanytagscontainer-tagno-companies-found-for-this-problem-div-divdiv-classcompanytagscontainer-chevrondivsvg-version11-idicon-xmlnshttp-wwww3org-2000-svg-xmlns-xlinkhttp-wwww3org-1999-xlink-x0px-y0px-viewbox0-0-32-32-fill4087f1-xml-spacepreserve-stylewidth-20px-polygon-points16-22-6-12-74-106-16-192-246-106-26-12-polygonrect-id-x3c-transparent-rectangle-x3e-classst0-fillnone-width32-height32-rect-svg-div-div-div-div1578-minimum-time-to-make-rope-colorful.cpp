class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans=0;
        for(int i=0;i<neededTime.size();)
        {
            int ind=i+1;
            int sum=neededTime[i],maxi=neededTime[i];
            while(ind<colors.size() && colors[ind]==colors[i])
            {
                sum+=neededTime[ind];
                maxi=max(maxi,neededTime[ind]);
                ind++;
            }
            sum-=maxi;
           
            ans+=sum;
            i=ind;
        }
        return ans;
    }
};