class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        int arr[26]={0};
        for(auto it:s) arr[it - 'a']++;
        
        priority_queue<pair<int,int>> pq;
        
       for(int i=0;i<26;i++)
       {
           if(arr[i]>0)
           pq.push({i,arr[i]});
       }
        
        string ans;
        
        while(!pq.empty())
        {
            int char1=pq.top().first;
            int freq1=pq.top().second;
            
            pq.pop();
            
            if(ans.size()==0 || ans.back()!=(char) (char1 + 'a'))
            {
                int cnt=min(freq1,repeatLimit);
                freq1-=cnt;
                
                for(int i=0;i<cnt;i++)
                {
                    ans.push_back((char) char1 + 'a');
                }
                if(freq1)
                {
                    pq.push({char1,freq1});
                }
            }
            else
            {
                if(pq.size()==0)break;
                int char2=pq.top().first;
                int freq2=pq.top().second;
                pq.pop();
                ans+=(char) (char2 + 'a');
                
                freq2--;
                if(freq2)
                {
                    pq.push({char2,freq2});
                }
                
                pq.push({char1,freq1});
            }
        }
        
        return ans;
    }
};