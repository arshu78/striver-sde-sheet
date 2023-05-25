class Solution {
public:
    int compress(vector<char>& chars) {
       vector<char> temp;
        chars.push_back('&');
        int cnt=1;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i-1]!=chars[i])
            {
                if(cnt==1)
                {
                    temp.push_back(chars[i-1]);
                }
                else
                {
                   string t=to_string(cnt);
                temp.push_back(chars[i-1]);
                for(auto it:t)
                {
                    temp.push_back(it);
                }  
                }
               
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }
        chars=temp;
        return temp.size();
    }
};