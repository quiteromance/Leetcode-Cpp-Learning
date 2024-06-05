// 快速排序

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0 ,nums.size());

    }

    void quick_sort(vector<int> &nums, int l,int r){
        if(l >= r - 1)
            return;
        int first = l, last = r - 1, pivot = nums[first];
        while(first < last){
            while(nums[last] >= pivot && first < last){
                last--;
            }
            nums[first] = nums[last];
            while(nums[first] <= pivot && first < last){
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = pivot;
        quick_sort(nums, l, first);
        quick_sort(nums, first + 1, r);
    }
};