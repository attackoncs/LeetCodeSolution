/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if(num==0)return "0";
        if(num<0)num+=1<<32;
        string res;
        while(num){
            int l=num/16;
            int u=num%16;
            char c=(char)(u)+'0';
            if(u>=10)c=(char)(u-10)+'a';
            res.push_back(c);
            num/=10;
        }
        return res;
    }
};
// @lc code=end

