#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*****************************************以上是include**************************************/
class Solution {
public:
    int massage(vector<int>& nums) {
        int max = 0;
        int count = 0;
        process(nums, -2, max, count);
        return max;
    }
    void process(const vector<int>& nums, int index, int & max, int count){
        if(index >= int(nums.size())) {
            max = max > count ? max : count;
            return;
        }
        if(index != -2){
            count += nums[index];
        }
        int tmp = count;
        process(nums, index + 2, max, count);
        count = tmp;
        process(nums, index + 3, max, count);
    }
};

int main(){
    vector<int> nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
    Solution S;
    printf("%d",S.massage(nums));

}

// 超出内存限制