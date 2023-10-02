class Solution {
public:
    string nextP(string n)
    {
        int i;
        for(i=n.size()-2;i>=0;i--)
        {
            if(n[i] - '0'<n[i+1] - '0')
            {
                break;
            }
        }
        
        if(i<0) 
        {
            reverse(n.begin(),n.end());
        }
        else
        {
            int j;
            
           for(j=n.size()-1;j>i;j--)
           {
               if(n[j] > n[i]) break;
           }
            swap(n[i],n[j]);
            
            reverse(n.begin() + i+1,n.end());
        }
        
        return n;
    }
    string getPermutation(int n, int k) {
       
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(i+1);
        }
        for(int i=0;i<k-1;i++)
        {
            next_permutation(temp.begin(),temp.end());
        }
        string ans="";
        
        for(auto it:temp) ans+='0' + it;
        
        return ans;
    }
};