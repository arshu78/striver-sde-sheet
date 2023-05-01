class Solution {
public:
    double average(vector<int>& salary) {
       int min= *min_element(salary.begin(),salary.end());
        int max= *max_element(salary.begin(),salary.end());
        double sum=0.0;
        int cnt=0;
        if(salary.size()<=2) return 0;
        for(auto it:salary)
        {
            if(it!=min && it!=max)
            sum+=it;
            
        }
        return sum/(salary.size()-2);
    }
};