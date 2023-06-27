class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        int size=arr.size()/2;
        for(auto it:arr)
        {
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        int cnt=0;
        while(!pq.empty())
        {   
                cnt++;
                size-=pq.top();
                if(size<=0) break;
     
            pq.pop();
        }
        return cnt;
    }
};