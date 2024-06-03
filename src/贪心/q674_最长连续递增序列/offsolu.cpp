/*为了得到最长连续递增序列，可以使用贪心的策略得到尽可能长的连续递增序列。
    做法是使用记录当前连续递增序列的开始下标和结束下标，遍历数组的过程中每次比较相邻元素，
    根据相邻元素的大小关系决定是否需要更新连续递增序列的开始下标。

    具体而言，令 start 表示连续递增序列的开始下标，初始时 start=0，然后遍历数组 nums，进行如下操作。

    如果下标 i>0 且 nums[i]≤nums[i−1]，则说明当前元素小于或等于上一个元素，
    因此 nums[i−1] 和 nums[i]\textit{nums}[i]nums[i] 不可能属于同一个连续递增序列，必须从下标 i 处开始一个新的连续递增序列，
    因此令 start=i。如果下标 i=0 或 nums[i]>nums[i−1]，则不更新 start 的值。
    此时下标范围 [start,i] 的连续子序列是递增序列，其长度为 i−start+1，使用当前连续递增序列的长度更新最长连续递增序列的长度。

*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) {
                start = i;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
