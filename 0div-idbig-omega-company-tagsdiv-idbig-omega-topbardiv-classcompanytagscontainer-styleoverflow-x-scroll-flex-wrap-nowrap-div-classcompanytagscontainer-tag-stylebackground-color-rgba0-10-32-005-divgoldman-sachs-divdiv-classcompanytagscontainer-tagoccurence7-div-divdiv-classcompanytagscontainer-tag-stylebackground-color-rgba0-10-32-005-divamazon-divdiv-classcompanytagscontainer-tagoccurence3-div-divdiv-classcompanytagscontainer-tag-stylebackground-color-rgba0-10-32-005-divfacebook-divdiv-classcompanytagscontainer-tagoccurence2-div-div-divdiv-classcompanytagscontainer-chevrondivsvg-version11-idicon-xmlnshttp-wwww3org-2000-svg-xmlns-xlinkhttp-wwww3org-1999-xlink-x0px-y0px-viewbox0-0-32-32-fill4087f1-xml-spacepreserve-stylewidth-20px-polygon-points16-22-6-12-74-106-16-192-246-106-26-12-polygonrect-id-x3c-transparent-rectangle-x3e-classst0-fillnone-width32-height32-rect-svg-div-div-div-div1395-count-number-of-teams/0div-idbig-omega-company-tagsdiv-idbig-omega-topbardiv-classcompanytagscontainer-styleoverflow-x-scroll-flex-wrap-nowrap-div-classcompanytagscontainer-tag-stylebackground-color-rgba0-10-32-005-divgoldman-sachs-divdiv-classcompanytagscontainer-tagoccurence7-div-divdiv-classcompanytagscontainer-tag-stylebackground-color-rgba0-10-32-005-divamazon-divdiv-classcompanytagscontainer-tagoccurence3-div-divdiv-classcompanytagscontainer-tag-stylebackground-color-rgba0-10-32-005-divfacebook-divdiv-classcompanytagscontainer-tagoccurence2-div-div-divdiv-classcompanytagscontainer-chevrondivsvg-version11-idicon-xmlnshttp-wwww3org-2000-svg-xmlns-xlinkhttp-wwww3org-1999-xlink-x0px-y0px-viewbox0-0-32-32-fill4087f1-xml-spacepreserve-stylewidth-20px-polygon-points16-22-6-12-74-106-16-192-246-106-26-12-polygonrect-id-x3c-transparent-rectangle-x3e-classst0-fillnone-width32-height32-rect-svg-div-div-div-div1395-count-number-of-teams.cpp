class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=0;i<rating.size();i++)
        {
            int ls=0,ll=0,rs=0,rl=0;
            for(int j=0;j<i;j++)
            {
               if(rating[i]<rating[j]) ls++;
                else ll++;
            }
            for(int j=i+1;j<rating.size();j++)
            {
                if(rating[i]<rating[j]) rs++;
                else rl++;
            }
            
            ans+=ls*rl + rs*ll;
        }
        return ans;
    }
};