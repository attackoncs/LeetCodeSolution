/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        s.insert(s.begin(),' ');//反向遍历,加上空格是类似指针加头结点
        int ans=0;
        while(s.back()==' ')s.pop_back();
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]==' ')break;
            else ans++;
        }
        return ans;
    }
};
// @lc code=end

