class Solution {
public:
    int missingNumber(vector<int>& a) {
          int sum1=0,sum2=0;
        for(int i=0;i<a.size();i++)
        {
            sum1=sum1+a[i];
        }
        for(int i=0;i<a.size()+1;i++)
        {
            sum2=sum2+i;
        }
        return(sum2-sum1);
    }
};