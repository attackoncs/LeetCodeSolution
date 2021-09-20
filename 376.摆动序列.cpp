/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> up(n,0);
        vector<int> down(n,0);
        up[0]=down[0]=1;
        for(int i=1;i<n;++i){
            if(nums[i]<nums[i-1]){
                //注意这里由于i和i-1相邻，因此不是down[i-1]+1,
                //而是up[i-1]+1，因为最迟有可能i-1低谷突然上升，下同理不赘述
                down[i]=max(down[i-1],up[i-1]+1);
                up[i]=up[i-1];
            }else if(nums[i]>nums[i-1]){
                up[i]=max(down[i-1]+1,up[i-1]);
                down[i]=down[i-1];
            }else{
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        return max(up[n-1],down[n-1]);
    }
};
// @lc code=end

