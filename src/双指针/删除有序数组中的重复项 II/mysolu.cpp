#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

/*****************************************以上是include**************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> myMap;
        vector<int> nums_copy;
        for(int i = 0; i < nums.size(); i++){
            auto it = myMap.find(nums[i]);
            if (it != myMap.end()) {
                myMap[nums[i]] ++;
            } 
            else {
                myMap[nums[i]] = 1;
            }
            if(myMap[nums[i]] <= 2){
                nums_copy.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nums_copy.size(); i++){
            nums[i] = nums_copy[i];
        }
        if(nums_copy.size() < nums.size()){
            for(int i = nums_copy.size(); i <= nums.size(); i++){
                nums.pop_back();
            }      
        }
        return nums.size();
    }
};

int main(){
    vector<int> A = {0,0,0,0,0};

    Solution S;
    S.removeDuplicates(A);
    for (int i = 0; i < A.size(); ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}