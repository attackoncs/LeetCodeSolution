/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxs=0;
        vector<int> dp(n,0);
        vector<int> g(n,0);
        for(int i=0;i<n;++i){
            dp[i]=g[i]=1;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                       dp[i]=dp[j] +1;
                       g[i]=g[j];
                    }else if(dp[i]==dp[j]+1){
                        g[i]+=g[j];
                    }
                }
            }
            maxs=max(maxs,dp[i]);
        }
        int res=0;
        for(int i=0;i<n;++i){
            if(dp[i]==maxs)res+=g[i];
        }
        return res;
    }
};
// @lc code=end

