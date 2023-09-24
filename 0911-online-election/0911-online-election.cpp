class TopVotedCandidate {
public:
    map<int,int> mp;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int lead=-1;
        this->times=times;
        map<int,int> cnt;
        for(int i=0;i<persons.size();i++)
        {
               
           if(++cnt[persons[i]] >=cnt[lead])
           {
               lead=persons[i];
           }
            mp[times[i]]=lead;
        }
    }
    
    int q(int t) {
      
        return mp[*--upper_bound(times.begin(),times.end(),t)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */