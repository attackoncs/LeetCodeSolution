/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        for(int i=s.size()-1,index=0;i>=0;--i){
            if(s[i]=='-')continue;
            res.push_back(toupper(s[i]));
            ++index;//必须放在if之前，否则会导致最后多个-
            if(index%k==0){
                res.push_back('-');
            }
        }
        //去掉最后多余的-
        if(res.size()&&res.back()=='-')res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

