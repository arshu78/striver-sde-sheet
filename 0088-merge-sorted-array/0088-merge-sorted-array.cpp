class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        int cnt=0;
        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[cnt++];
        }
        
         int gap=ceil((n+m)/2.0);
        while(gap>=1)
        {
            int i=0,j=i+gap;
            
            while(j<n+m)
            {
                if(nums1[i]>nums1[j])
                {
                    swap(nums1[i],nums1[j]);
                  
                }
                  i++;
                    j++;
            }
            if(gap==1) break;
           gap=ceil((gap)/2.0);
            
        }
    }
};