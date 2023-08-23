class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
       string ans="";
        
        while(pq.size()>=2)
        {
            auto a=pq.top();
            pq.pop();
            auto b=pq.top();
            pq.pop();
            
            ans+=a.second;
            ans+=b.second;
            
            if((a.first-1)>0) pq.push({a.first-1,a.second});
            if((b.first-1)>0) pq.push({b.first-1,b.second});
        }
        
        if(pq.size())
        {
            if(pq.top().first>1) return "";
            ans+=pq.top().second;
        }
        return ans;
    }
};