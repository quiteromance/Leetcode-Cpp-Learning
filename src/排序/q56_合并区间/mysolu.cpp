//思路是先排序之后合并

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> temp(intervals);
        merge_process(intervals, 0 ,intervals.size(), temp);
        return sort_process(temp);
    }

    vector<vector<int>> sort_process(vector<vector<int>>& intervals){ //用于合并
        vector<vector<int>> res;
        int i = 1, p = 1;
        int start;
        int end;
        res.push_back({intervals[0][0],intervals[0][1]});
        while(i < intervals.size()){
            if(intervals[i][0] >= res[p-1][0] && intervals[i][0] <= res[p-1][1]){
                start = res[p-1][0];
                end = max(res[p-1][1], intervals[i][1]);
                res.pop_back();
                res.push_back({start, end});
                i++;
            }
            else{
                start = intervals[i][0];
                end = intervals[i][1];
                res.push_back({start, end});
                p++;
            }
        }
        return res;
    }

    void merge_process(vector<vector<int>>& intervals, int l, int r, vector<vector<int>>& temp){ //用于选择排序
        if(l >= r-1)
            return; 
        int mid = l + (r - l) / 2;
        merge_process(intervals, l, mid, temp);
        merge_process(intervals, mid, r, temp);
        int p = l, q = mid, i = l;
        while(p < mid || q < r){
            if(q >= r || (intervals[p][0] < intervals[q][0] && p < mid)){
                temp[i++] = intervals[p++];
            }
            else{
                temp[i++] = intervals[q++];
            }
        }
        for (i = l; i < r; ++i) {
            intervals[i] = temp[i];
        }
    }
};

int main(){
    vector<vector<int>> intervals = {{4,5},{1,4},{0,1}};
    Solution S;
    S.merge(intervals);
}