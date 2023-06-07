class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(auto it:cardPoints)
        {
            sum+=it;
        }
        int maxi=INT_MAX;
        if(cardPoints.size()==k) return sum;
        int i=0,j=0;
        int sz=cardPoints.size()-k;
        int cur=0;
        while(j<cardPoints.size())
        {
          
                cur+=cardPoints[j];
         
            if(j-i+1==sz)
            {
                maxi=min(maxi,cur);
                cur-=cardPoints[i];
                i++;
               
            }
            j++;
        }
        
        return sum - maxi;
    }
};