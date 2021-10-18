/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        long long sum=1;
        int n=num;
        while(n){
            n/=2;
            sum*=2;
        }
        return sum-1-num;
    }
};
// @lc code=end

