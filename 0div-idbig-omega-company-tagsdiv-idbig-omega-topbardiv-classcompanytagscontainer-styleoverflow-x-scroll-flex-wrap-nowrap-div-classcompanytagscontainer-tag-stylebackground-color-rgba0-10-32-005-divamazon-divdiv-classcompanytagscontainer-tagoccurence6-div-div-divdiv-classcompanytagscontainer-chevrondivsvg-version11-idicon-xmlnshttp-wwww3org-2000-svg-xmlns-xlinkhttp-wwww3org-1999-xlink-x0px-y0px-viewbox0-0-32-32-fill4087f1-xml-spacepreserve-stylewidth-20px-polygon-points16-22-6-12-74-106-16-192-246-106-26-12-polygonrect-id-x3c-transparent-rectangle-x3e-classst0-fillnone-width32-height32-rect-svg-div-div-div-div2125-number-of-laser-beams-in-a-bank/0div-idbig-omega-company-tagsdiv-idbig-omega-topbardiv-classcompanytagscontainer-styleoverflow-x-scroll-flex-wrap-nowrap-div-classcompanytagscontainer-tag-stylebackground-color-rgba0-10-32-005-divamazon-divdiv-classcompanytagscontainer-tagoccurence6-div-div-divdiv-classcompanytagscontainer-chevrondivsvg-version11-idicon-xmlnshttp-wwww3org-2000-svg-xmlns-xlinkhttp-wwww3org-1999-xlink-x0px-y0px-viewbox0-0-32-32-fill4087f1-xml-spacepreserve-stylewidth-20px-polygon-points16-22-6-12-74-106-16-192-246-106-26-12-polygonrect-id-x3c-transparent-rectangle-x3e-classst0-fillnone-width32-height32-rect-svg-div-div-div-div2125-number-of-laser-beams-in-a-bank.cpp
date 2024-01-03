class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==1) return 0;
        int n=bank.size();
        
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            string it=bank[i];
            
            for(auto k:it) if(k=='1') v[i]++;
            
          
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
            {
                int j=i-1;
                while(j>=0 && v[j]==0) j--;

                if(j>=0) ans+=(v[i] * v[j]);
            }
        }
        return ans;
    }
};