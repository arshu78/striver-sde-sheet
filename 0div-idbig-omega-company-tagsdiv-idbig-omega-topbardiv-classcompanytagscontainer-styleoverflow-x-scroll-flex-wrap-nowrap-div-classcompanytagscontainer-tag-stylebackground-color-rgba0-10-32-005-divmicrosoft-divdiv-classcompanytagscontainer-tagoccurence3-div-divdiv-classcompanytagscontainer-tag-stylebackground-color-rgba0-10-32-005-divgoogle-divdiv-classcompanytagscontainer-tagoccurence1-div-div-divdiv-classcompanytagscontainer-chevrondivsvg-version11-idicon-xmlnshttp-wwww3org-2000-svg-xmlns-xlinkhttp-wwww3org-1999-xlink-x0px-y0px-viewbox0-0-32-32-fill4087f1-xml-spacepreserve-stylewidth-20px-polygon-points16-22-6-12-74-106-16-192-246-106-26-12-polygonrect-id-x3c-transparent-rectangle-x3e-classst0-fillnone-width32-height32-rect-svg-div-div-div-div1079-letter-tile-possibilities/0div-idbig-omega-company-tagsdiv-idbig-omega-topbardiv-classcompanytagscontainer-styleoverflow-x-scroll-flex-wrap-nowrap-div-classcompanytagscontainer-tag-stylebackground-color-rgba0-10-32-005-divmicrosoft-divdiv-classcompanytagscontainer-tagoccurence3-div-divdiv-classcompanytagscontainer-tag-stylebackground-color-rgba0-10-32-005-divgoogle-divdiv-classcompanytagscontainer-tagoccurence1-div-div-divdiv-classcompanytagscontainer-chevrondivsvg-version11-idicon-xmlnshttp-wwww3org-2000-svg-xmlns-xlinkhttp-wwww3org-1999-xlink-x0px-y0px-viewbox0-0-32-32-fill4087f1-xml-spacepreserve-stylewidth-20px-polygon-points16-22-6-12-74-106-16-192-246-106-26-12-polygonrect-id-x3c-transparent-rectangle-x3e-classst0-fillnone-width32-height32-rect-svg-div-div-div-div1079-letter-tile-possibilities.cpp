class Solution {
public:
    void f(int i,string& tiles,string temp,set<string>& st)
    {
        if(temp!="")
        st.insert(temp);
        for(int j=i;j<tiles.size();j++)
        {
            swap(tiles[i],tiles[j]);
            temp.push_back(tiles[i]);
            f(i+1,tiles,temp,st);
            temp.pop_back();
            swap(tiles[i],tiles[j]);
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> st;
        string temp="";
        f(0,tiles,temp,st);
       // for(auto it:st) cout<<it<<" ";
        return st.size();
    }
};