class Solution {
public:
  
    pair<pair<string,string>,pair<int,int>> f(string &s)
    {
        int amount=0,time=0;
        string name="",city="";
        bool a=0,b=0,c=0,d=0;
        for(int it=0;it<s.size();it++)
        {
            if(a==0)
            {
                name+=s[it];
                if(s[it+1]==',')
                {
                    a=1;
                    it++;
                }
            }
            else if(b==0)
            {
                time=time*10;
                time+=s[it] - '0';
                
                if(s[it+1]==',')
                {
                    b=1;
                    it++;
                }
            }
            else if(c==0)
            {
                amount*=10;
                amount+=s[it] - '0';
                
                if(s[it+1]==',')
                {
                    c=1;
                    it++;
                }
            }
            else
            {
                city+=s[it];
            }
        }
        
        return {{name,city},{amount,time}};
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        int n=transactions.size();
        
       sort(transactions.begin(),transactions.end());
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
           pair<pair<string,string>,pair<int,int>> t1= f(transactions[i]);
            if (t1.second.first >=1000){
                vis[i]=1;
            }
            for (int j=i+1; j<n; j++){
                pair<pair<string,string>,pair<int,int>> t2= f(transactions[j]);
                if ((t1.first.first==t2.first.first) && (abs(t2.second.second-t1.second.second)<=60) && (t1.first.second!=t2.first.second)){
                    vis[i]=1; vis[j]=1;
                }
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1) ans.push_back(transactions[i]); 
        }
        
        return ans;
        
    }
};