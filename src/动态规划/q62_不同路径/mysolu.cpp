//要注意一下边界条件
//思路是当只有一行或者一列的时候只有1条路径
//如果不是的话就第dp[i][j]就是dp[i-1][j] + dp[i][j-1]
//如果i-1，j-1小于0的话还是1条路径
//时间复杂度O(mn)，空间复杂度O(mn)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        if(m == 1 || n == 1)
            return 1;
        if(m == 0 || n == 0)
            return 0;

        dp[0][1] = 1;
        dp[1][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i - 1 < 0 && j - 1 < 0){
                    dp[i][j] = 1;
                }
                if(i - 1 < 0 && j - 1 >= 0){
                    dp[i][j] = dp[i][j-1];
                }
                if(i - 1 >= 0 && j - 1 < 0){
                    dp[i][j] = dp[i-1][j];
                }
                if(i - 1 >= 0 && j - 1 >= 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};