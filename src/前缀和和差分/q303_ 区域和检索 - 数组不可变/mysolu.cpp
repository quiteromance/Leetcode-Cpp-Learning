//如果想在类内初始化数组，必须要在构造函数里面初始化
//如果你把prefix[0] = 0;放在类定义体中，而不是成员函数体内，会导致编译错误：


class NumArray {
public:
    vector<int> prefix;//前缀和数组
    NumArray(vector<int>& nums) {
        prefix.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            prefix.push_back(prefix.back()+nums[i]);
        }       
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */