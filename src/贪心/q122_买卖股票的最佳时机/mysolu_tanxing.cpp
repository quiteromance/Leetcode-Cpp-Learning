// 思路，使用差分数组，然后加上差分数组里面正值就可以。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1)return 0;
        int def[n-1];
        int sum = 0;
        for(int i = 1; i < n;i++){
            def[i-1] = prices[i]-prices[i-1];
            sum+= max(0,def[i-1]);
        }
        return sum;
    }


};