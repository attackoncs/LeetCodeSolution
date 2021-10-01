/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(auto p:paths){
            s.insert(p[0]);
        }
        for(auto p:paths){
            if(!s.count(p[1]))return p[1];
        }
        return "";
    }
};
// @lc code=end

