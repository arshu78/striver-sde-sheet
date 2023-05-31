class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
      
        int n=score.size();
        priority_queue<pair<int,int>> pq;
        vector<string> ans(n);
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
          if(score.size()<=3)
        {
              int cnt=0;
            while(!pq.empty())
            {
                if(cnt==0)
                {
                    ans[pq.top().second]="Gold Medal";
                    pq.pop();
                    cnt++;
                }
                else if(cnt==1)
                {
                     ans[pq.top().second]="Silver Medal";
                    pq.pop();
                    cnt++;
                }
                else
                {
                     ans[pq.top().second]="Bronze Medal";
                    pq.pop();
                    cnt++;
                }
            }
              return ans;
        }
        while(!pq.empty())
        {
            int g=pq.top().second;
            pq.pop();
            int s=pq.top().second;
            pq.pop();
            int b=pq.top().second;
            pq.pop();
            
            ans[g]="Gold Medal";
            ans[s]="Silver Medal";
            ans[b]="Bronze Medal";
            break;
        }
        int i=4;
        while(!pq.empty())
        {
            ans[pq.top().second]=to_string(i);
            pq.pop();
            i++;
        }
        return ans;
    }
};