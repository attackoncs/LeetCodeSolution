/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        
        int n=o[0].size();
        int m=o.size();
        vector<int> dp(n,0);
        dp[0]=(o[0][0]==0);//注意将石头放到入口的特殊情况
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(o[i][j]==1){
                    dp[j]=0;
                    continue;//这里是continue而不是break;
                }
                if(j-1>=0&&o[i][j]==0)
                    dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

