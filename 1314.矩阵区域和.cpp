/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int m = mat.size(), n = mat[0].size();

        //二维前缀数组,这里我知道将横纵坐标都+1会简洁，但还是硬着头皮写，后面就要考虑非常多的边界条件
        //一不小心就会写错
        vector<vector<int>> sum(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }

        //容斥原理计算矩阵区域和，这里写错了，而且边界条件很容易错
        vector<vector<int>> out(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int row1 = i-k > 0 ? i-k : 0;
                int col1 = j-k > 0 ? j-k : 0;
                int row2 = i+k < m-1 ? i+k : m-1;
                int col2 = j+k < n-1 ? j+k : n-1;
                int x = sum[row1][col1];
                int y = sum[row2 + 1][col2 + 1];
                int a = sum[row1][col2 + 1];
                int b = sum[row2 + 1][col1];
                out[i][j] = y + x - a - b;
            }
        }
        return out;
    }
};

 
// @lc code=end

