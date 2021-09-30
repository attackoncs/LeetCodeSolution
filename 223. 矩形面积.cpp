/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //注意看题，是求两个矩形的总面积，而不是公共的矩形面积
        //这里通过投影来求边长，技巧性很强
        int x=max(0,min(bx2,ax2)-max(bx1,ax1));//有可能没公共矩形，所以最大为0，下同
        int y=max(0,min(by2,ay2)-max(by1,ay1));
        //互斥原理，总面积等于两矩形-公共矩形
        return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-x*y;
    }
};
// @lc code=end

