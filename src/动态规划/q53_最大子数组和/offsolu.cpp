//事实上可以将dp[i]表示成 “以i结尾的「连续子数组的最大和」”。由于连续数组最大和必然有以i结尾的，所以这样也没有问题
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }

