/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<long> res(3,LONG_MIN);//定义long是由于有可能和2^32-1相等
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]>res[0]){
                res[2]=res[1];
                res[1]=res[0];
                res[0]=nums[i];

            }
            else if(nums[i]<res[0]&&nums[i]>res[1]){//这里其实必须加&&，原因是不加，会导致相等的情况出错，加了就排除相等的情况，下同
                res[2]=res[1];
                res[1]=nums[i];
            }
            else if(nums[i]<res[1]&&nums[i]>res[2])res[2]=nums[i];
        }
        if(res[2]==LONG_MIN)return res[0];
        return res[2];
    }
};
// @lc code=end

