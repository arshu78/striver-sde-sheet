class Solution {
public:
    //super hard question
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0,j=0;
        
        int n=words.size();
        
        while(i<n)
        {
            int linelength=words[i].size();
            j=i+1;
            while(j<n && linelength + words[j].size() + (j-i) <=maxWidth)
            {
                linelength+=words[j].size();
                j++;
            }
            
            int numwords=j-i;
            int numspaces= maxWidth - linelength;
            string line;
            
            if(numwords==1 || j==n)
            {
                line=words[i];
                for(int k=i+1;k<j;k++)
                {
                    line+=' ' + words[k];
                }
                line+=string(maxWidth - line.size(),' ');
            }
            else
            {
                int equalspaces= numspaces / (numwords -1);
                int extraspaces = numspaces % (numwords -1);
                
                line =words[i];
                
                for(int k=i+1;k<j;k++)
                {
                    line+= string(equalspaces , ' ');
                    
                    if(extraspaces  > 0)
                    {
                        line+=' ';
                        extraspaces--;
                    }
                    
                    line+= words[k];
                }
            }
            ans.push_back(line);
            i=j;
            
        }
        
        return ans;
    }
};