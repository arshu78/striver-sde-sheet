class Solution {
public:
    int largestInteger(int num) {
         string s=to_string(num);
        vector<pair<int,char>>odd,even; 
        int i=0,j=0;
        
        for(auto i:s){
            if((i-'0')%2==0)even.push_back({i-'0',i}); 
            else odd.push_back({i-'0',i});
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());
        
        string str="";
        for(auto x:s){
            
            if((x-'0')%2==0){
                str+=even[i].second; 
                i++;
            }else{
             str+=odd[j].second;
             j++;
            }
                
        }
         
        return stoi(str);
    }
};