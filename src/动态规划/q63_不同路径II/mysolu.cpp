//思路和62差不多，就是加了几条判断语句
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(); // m获得行信息
        int n = obstacleGrid.back().size();// n获得列信息
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        if(obstacleGrid[0][0] == 1)
            return 0;
        for(int i = 1; i < n; i++){ //第一行
            if(obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
            }
            else{
                dp[0][i]  = dp[0][i-1];
            }
        }

        for(int i = 1; i < m; i++){ //第一列
            if(obstacleGrid[i][0] == 1){
                dp[i][0] = 0;
            }
            else{
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j-1] == 1)
                    dp[i][j] = dp[i-1][j];
                
                if(obstacleGrid[i-1][j] == 1)
                    dp[i][j] = dp[i][j-1];
                
                if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1)
                    dp[i][j] = 0;
                
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                
                if(obstacleGrid[i][j-1] == 0 && obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }

            }

        }

        return dp[m-1][n-1];

    }
    
};