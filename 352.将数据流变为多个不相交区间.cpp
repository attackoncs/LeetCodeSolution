/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
class SummaryRanges {
public:
    map<int,int> intervals;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        //对给定val,需找到区间[l0,r0]使得l0是最大的满足l0<=val的区间，同时需找到区间[l1,r1]使得l1是最小的满足l1>val的区间
        auto interval1=intervals.upper_bound(val);
        auto interval0=(interval1==intervals.begin()?intervals.end():prev(interval1));
        //情况1：l0<=val<=h1
        if(interval0!=intervals.end()&&interval0->first<=val&&val<=interval0->second)return;
        else{
            bool left_aside=(interval0!=intervals.end()&&interval0->second+1==val);
            bool right_aside=(interval1!=intervals.end()&&interval1->first-1==val);
            if(left_aside&&right_aside){
                //情况四：r0+1=val并且l1-1=val
                int left=interval0->first,right=interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(left,right);
            }else if(left_aside){
                //情况二：r0+1=val
                ++interval0->second;
            }else if(right_aside){
                //情况三：l1-1=val
                int right=interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val,right);
            }else{
                //情况五：均不满足
                intervals.emplace(val,val);
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(const auto& [left,right]:intervals){
            ans.push_back({left,right});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

