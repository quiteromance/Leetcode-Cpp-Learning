//动态规划
//假设dp[i]存放到第i个元素位置时候递增序列数目的最大值
//那么dp[i]就是max{dp[j]}+1，if nums[i] > nums[j]
//随后最大的dp[i]就是结果

#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> dp(nums.size(), 1);
        if(nums.empty()) return 0;
        int maxLen = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};


