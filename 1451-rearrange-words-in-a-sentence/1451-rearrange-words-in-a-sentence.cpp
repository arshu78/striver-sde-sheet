class Solution {
public:
    string arrangeWords(string text) {
        priority_queue<pair<int,pair<int,string>>,vector<pair<int,pair<int,string>>>,greater<pair<int,pair<int,string>>>> mini;
        
        string temp="";
        int start=0;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
              //  temp=temp.tolower();
                mini.push({temp.length(),{start,temp}});
                start=i+1;
                temp="";
            }
            else
            temp+=tolower(text[i]);
        }
        
        mini.push({temp.length(),{start,temp}});
        string ans="";
        while(!mini.empty())
        {
            auto it=mini.top();
            mini.pop();
            
            ans+=it.second.second+" ";
        }
        ans[0]=ans[0]-32;
        ans.pop_back();
        return ans;
    }
};