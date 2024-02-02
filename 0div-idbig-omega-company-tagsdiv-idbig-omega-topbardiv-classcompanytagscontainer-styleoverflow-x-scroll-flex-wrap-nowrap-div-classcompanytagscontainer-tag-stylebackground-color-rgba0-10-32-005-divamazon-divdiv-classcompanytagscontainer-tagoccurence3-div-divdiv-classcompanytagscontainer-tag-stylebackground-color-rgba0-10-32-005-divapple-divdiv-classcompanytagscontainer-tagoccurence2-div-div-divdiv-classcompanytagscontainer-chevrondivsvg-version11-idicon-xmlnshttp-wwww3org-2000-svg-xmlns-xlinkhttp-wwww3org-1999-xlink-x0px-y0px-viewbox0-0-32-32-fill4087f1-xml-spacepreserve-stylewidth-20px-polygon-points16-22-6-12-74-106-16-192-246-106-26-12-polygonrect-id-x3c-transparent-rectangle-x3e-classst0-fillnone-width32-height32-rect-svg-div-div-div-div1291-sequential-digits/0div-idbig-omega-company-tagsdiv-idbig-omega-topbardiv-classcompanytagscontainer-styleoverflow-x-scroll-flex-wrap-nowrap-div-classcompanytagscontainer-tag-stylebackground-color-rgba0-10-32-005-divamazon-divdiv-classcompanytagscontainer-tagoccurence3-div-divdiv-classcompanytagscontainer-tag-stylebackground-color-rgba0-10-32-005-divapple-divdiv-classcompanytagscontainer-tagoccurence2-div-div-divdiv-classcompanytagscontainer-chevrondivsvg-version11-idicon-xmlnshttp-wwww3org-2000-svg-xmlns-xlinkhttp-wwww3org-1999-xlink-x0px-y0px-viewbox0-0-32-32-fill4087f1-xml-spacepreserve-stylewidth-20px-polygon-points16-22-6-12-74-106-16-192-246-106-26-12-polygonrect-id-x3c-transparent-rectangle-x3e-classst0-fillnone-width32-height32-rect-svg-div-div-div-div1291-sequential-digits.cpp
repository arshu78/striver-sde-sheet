class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s="123456789";
        
        for(int i=0;i<s.size();i++)
        {
            string temp="";
            for(int j=i;j<s.size();j++)
            {
                temp+=s[j];
                int a=stoi(temp);
                if(low<=a && a<=high) ans.push_back(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};