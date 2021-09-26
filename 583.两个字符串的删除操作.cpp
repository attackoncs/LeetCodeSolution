class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        //可通过LCS方法计算，最后n+m-2*(dp[n][m]-1)，状态转移方程将min改成max
        //定义代表考虑w1的前i个字符、w2的前j个字符（最终字符串不一定包含w1[i]或w2[j]）时形成相同字符串的最小删除次数。
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //这里不能把它放到双重循环里，否则会有测试用例不过
        // for (int i = 0; i <= n; i++) dp[i][0] = i;
        // for (int j = 0; j <= m; j++) dp[0][j] = j;
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=m;++j){
        //         //这里为了代码简洁这样写，也可写到else中
        //         dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
        //         if(word1[i-1]==word2[j-1]){
        //             dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        //         } 
        //     }
        // }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                //这里为了代码简洁这样写，也可写到else中
                if(i==0||j==0)dp[i][j]=1;
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                    }
                } 
            }
        }
        return n+m-2*(dp[n][m]-1);
    }
};