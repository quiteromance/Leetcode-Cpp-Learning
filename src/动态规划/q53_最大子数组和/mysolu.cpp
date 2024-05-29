//我的方法
//用dp[i]表示nums数组中前i+1个元素的连续子数组的最大和
//当nums[i] >= 0的时候，dp[i]值要么是dp[i-1]，要么是nums一段连续数组（一直到nums[i-1]）的求和
//当nums[i] < 0 的时候，dp[i] = max(dp[i-1],nums[i]);
//一直更新就行
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);//dp[i]用于记录0-i数组中的连续子数组的最大和
        dp[0] = nums[0]; //dp[0]就是第一个数
        int maxSum = nums[0]; //求解得到的最大值
        int sumAll = nums[0]; //到nums[i]数组的和

        int sumSub = min(nums[0],0); //这一段很重要，当nums[0] > 0的时候，如果sumSub不是0而是nums[0]，在第一次更新tmp-sumSub+nums[i]的时候会变成0；
        //当nums[0] < 0的时候，如果sumSub是0而是nums[0]，在第一次更新tmp-sumSub+nums[i]的时候会去掉了第一项

        int index; // index用于记录连续数组的分割点
        for(int i = 1; i < nums.size(); i++){
            int tmp = sumAll;
            sumAll += nums[i];
              
            if(nums[i] >= 0){
                dp[i] = max(dp[i-1], tmp-sumSub+nums[i]);
            }
            else dp[i] = max(dp[i-1],nums[i]);
            maxSum = max(maxSum, dp[i]);

            if(sumAll < sumSub && sumAll < 0){
                index = i;
                sumSub = sumAll;
            }  
        }
        return maxSum;
    }
};