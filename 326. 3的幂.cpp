/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        // while(n&&n%3==0){
        //     n/=3;
        // }
        // return n==1;
        return n>0&&1162261467%n == 0;
    }
};
// @lc code=end

