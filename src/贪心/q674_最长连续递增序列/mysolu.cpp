#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int MaxLen = 0;
        int LenOfNum = nums.size()-1;
        int index;
        int count = 1;
        if (LenOfNum == 0) return 1;
        for(int i = 0;i <= LenOfNum - 1; i++){
            index = i;
            while(nums[index+1] > nums[index] && index + 1 <= LenOfNum){
                count++;
                index++;
                if(index + 1 > LenOfNum){
                    break;
                }
            }
            MaxLen = MaxLen < count ? count : MaxLen;
            count = 0;
        }
        return  MaxLen;
    }
};

int main(){
    Solution S;
    vector<int> nums = {1,3,5,4,2,3,4,5};
    S.findLengthOfLCIS(nums);
}