#include <iostream>    
#include <stdio.h>   
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen;
        process(nums, 0, 0, 0, maxLen);
        return maxLen;
    }
    
    //创建函数，输入一个nums序列，返回其所有递增序列的最大长度
    //思路是传入当前索引和最大值，每当当前索引大于当前最大值时候，可以选择更新最大值或者不更新，小于就直接不更新，记录所用的跳数然后返回最大跳数。
    //错误：时间太长了
    void process(vector<int>& nums, int index, int curMaxNum, int count, int &maxLen){
        if(index > nums.size() - 1) {
            maxLen = max(maxLen, count);
            return;
        };
        if(nums[index] > curMaxNum){
            process(nums, index + 1, nums[index], count + 1, maxLen);
            process(nums, index + 1, curMaxNum, count , maxLen);
        }
        else{
            process(nums, index + 1, curMaxNum, count, maxLen);
        }
    }
};

int main(void)
{
    vector<int>array = {10,9,2,5,3,7,101,18};
    Solution S;
    printf("%d", S.lengthOfLIS(array));
    return 0;
}