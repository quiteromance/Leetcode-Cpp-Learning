//修改成动态规划，用一个二维数组记录手里有股票和没有股票的两种情况，注意一下初始值dp[0][1]第一天有股票的初始值是-prices[0]。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0][1] = -prices[0];
        for(int i = 1; i < n+1; i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i-1]);//代表手里没有股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i-1]);//代表手里有股票
        }
        return max(dp[n][0],dp[n][1]);
    }


};