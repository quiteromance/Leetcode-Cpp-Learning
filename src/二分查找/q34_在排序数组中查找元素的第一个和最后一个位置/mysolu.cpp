class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> zero = {-1,-1};
        if(nums.empty()) return zero;
        if(target < nums[0] || target > nums.back())
            return zero;
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r= mid - 1;
            }
        }
        if(nums[l]!= target)
            return zero;
        r = l;
        while( r <= nums.size() - 1 && nums[r] == target ){
            r++;
        }
        vector<int> res = {l,r-1};
        return res;
    }
};