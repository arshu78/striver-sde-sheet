class Solution {
public:
      vector<int> nsr(vector<int>& arr)
    {
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                ans.push_back(arr.size());
            }
            else if(s.size()>0 && s.top().first<arr[i])
            {
                ans.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=arr[i])
            {
                while(s.size()>0 && s.top().first>=arr[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    ans.push_back(arr.size());
                }
                else
                {
                    ans.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
    
    //nsl of histogram
    vector<int> nsl(vector<int>& arr)
    {
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top().first<arr[i])
            {
                ans.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=arr[i])
            {
                while(s.size()>0 && s.top().first>=arr[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        
        return ans;
    }
    
    int f(vector<int> &height,int n)
    {
        vector<int> left=nsl(height);
        vector<int> right=nsr(height);
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(right[i]-left[i]-1) * height[i]);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> his(m,0);
        if(n==0) return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    his[j]+=1;
                }
                else his[j]=0;
                    
            }
            
            maxi=max(maxi,f(his,m));
        }
        return maxi;
    }
};