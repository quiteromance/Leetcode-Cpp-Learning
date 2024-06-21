/*题目描述
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

示例 1:
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:

输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:

输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

*/

// 思路对intervals进行自定义排序，使得区间结尾数小的在前面，这样再次创建一个数组，遍历原数组，将区间不重叠的放入即可

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b) {return a[1] < b[1];});
        vector<vector<int>> temp;
        for(int i = 0;i < intervals.size(); i++){
            if(temp.empty()){
                temp.push_back(intervals[i]);
                count++;
            }
            else{
                if(temp.back()[1] <= intervals[i][0]){
                    temp.push_back(intervals[i]);
                    count++;
                }
            } 
        }
        return intervals.size() - count;
    }
};