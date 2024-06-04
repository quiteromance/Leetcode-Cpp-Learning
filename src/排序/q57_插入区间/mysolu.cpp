class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        for(int i = 0;i < intervals.size()-1;i++){
            if(intervals[i][0] > newInterval[0]){
                int index = intervals.size()-1;
                while(index > i){
                    intervals[index] = intervals[index-1];
                    index--;
                }
                intervals[i] = newInterval;
                break;
            }           
        }
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};