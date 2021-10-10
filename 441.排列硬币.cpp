/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int l=1,r=n;
        while(l<r){
            int m=l+(r-l+1)/2;
            if((long long)m*(m+1)<=(long long)2*n)l=m;
            else r=m-1;
        }
        return l;
    }
};
// @lc code=end

