//要求时间复杂度是O(n)
//一开始使用冒泡排序，冒泡了k次，找到第k个最大的数，这样时间复杂度为O(kn)，超出了时间限制
//选择快速排序，选择第一个数做pivot，进行一次排序以后比较当前枢位置和k哪一个比较大，方便执行递归
//值得注意的是，对于精心构造的数组，这种排序可能效果不会很好，所以需要随机打乱数组

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::random_device rd;  // 用于生成随机数种子
        std::mt19937 g(rd());   // 使用梅森旋转算法作为随机数生成器
        std::shuffle(nums.begin(), nums.end(), g);
        quick_sort(nums, k, 0, nums.size());
        return(nums[nums.size()-k]);
    }

    void quick_sort(vector<int>& nums, int k, int l, int r){
        int first = l, last = r - 1, pivot = nums[first];
        if(l > r - 1) return;
        while(first < last){
            while(first < last && nums[last] >= pivot){
                last--;
            }
            nums[first] = nums[last];
            while(first < last && nums[first] <= pivot){
                first++;
            }
            nums[last] = nums[first]; 
        }
        nums[first] = pivot;
        if(first == nums.size()-k)
            return;
        else if(first > nums.size()-k) 
            quick_sort(nums, k, l, first);
        else{
            quick_sort(nums, k ,first + 1, r);
        }
        
    }
};