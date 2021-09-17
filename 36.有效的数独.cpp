/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //当时是觉得很难通过一次遍历，我也想到定义三个数组，但没想到可以通过数组下标来定义
        //board[i][j]-'0-1下标，因此卡了很久，最后干脆定义一个二维数组，分三次遍历，虽然过了
        //大部分测试用例，但最后还是没完全过，也不知哪里有问题。
        int rows[9][9]={0};
        int columns[9][9]={0};
        int subboxes[3][3][9]={0};
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')continue;
                int index=board[i][j]-'0'-1;
                rows[i][index]++;
                columns[j][index]++;
                subboxes[i/3][j/3][index]++;
                if(rows[i][index]>1||columns[j][index]>1||subboxes[i/3][j/3][index]>1)
                    return false ;
            }
        }
        return true;
    }
};
// @lc code=end

