class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for(auto it:tasks)
        {
            mp[it]++;
        }
        
        priority_queue<int> pq;
        for(auto it:mp) pq.push(it.second);
        int ans=0;
        while(!pq.empty())
        {
            int time=0;
            vector<int> temp;
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
                
            }
            
            for(auto it:temp) if(it) pq.push(it);
            
            if(pq.empty()) ans+=time;
            else ans+=n+1;
        }
        return ans;
    }
};