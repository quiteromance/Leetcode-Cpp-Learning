class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size() - 1;
        int p1 = m - 1,p2 = n - 1;
        for(int i = m + n -1;p2 >= 0 && p1 >=0; i--){
            if(nums1[p1] > nums2[p2]){
                nums1[i] = nums1[p1];
                p1--;
            }
            else{
                nums1[i] = nums2[p2];
                p2--;
            }
        }
        
        for(int i = 0;i <= p2; i++){
            nums1[i] = nums2[i];
        }
        
    }
};