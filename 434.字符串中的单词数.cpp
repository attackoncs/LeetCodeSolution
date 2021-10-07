/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int res=0;
        s.push_back(' ');//模拟指针加头结点
        for(int i=0,j=0;i<s.size()-1;++i){
            if(s[i]!=' '&&s[i+1]==' '){
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

