class Solution {
public:
   int jump(vector<int>& nums) {
	vector<int> dp(size(nums), 10001);
	return solve(nums, dp, 0);
}

int solve(vector<int>& nums, vector<int>& dp, int pos) {
	if(pos >= size(nums) - 1) return 0;
	if(dp[pos] != 10001) return dp[pos];
    int ans=1e8;
	for(int j = 1; j <= nums[pos]; j++)
		ans = min(ans, 1 + solve(nums, dp, pos + j));        
	return dp[pos] = ans;
}
};