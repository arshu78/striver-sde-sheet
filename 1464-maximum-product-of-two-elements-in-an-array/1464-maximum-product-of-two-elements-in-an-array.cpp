class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        
        for(auto it:nums) pq.push(it-1);
        
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        
        return a * b;
        
        
    }
};