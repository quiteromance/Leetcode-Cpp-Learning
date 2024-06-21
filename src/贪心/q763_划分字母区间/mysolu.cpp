/*
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
返回一个表示每个字符串片段的长度的列表。
示例 1：

输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 

示例 2：

输入：s = "eccbbbbdec"
输出：[10]

*/

// 思路：用 vector<vector<int>> charactor(26,vector<int>(3,-1));来记录26个字母的出现情况以及出现始末位置。然后对所有的区间进行合并，记录合并区间的始末即可。

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> charactor(26,vector<int>(3,-1));
        vector<vector<int>> temp;
        int num;
        for(int i = 0; i < s.length(); i++){
            num = s[i] - 'a';
            if(charactor[num][0] == -1){
                charactor[num][0] = 1;
                charactor[num][1] = i;
                charactor[num][2] = i;
            }
            else{
                charactor[num][2] = i;
            }
        }

        vector<vector<int>> intervals;
        for (const auto& ch : charactor) {
            if (ch[0] != -1) {
                intervals.push_back(ch);
            }
        }

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        });

        vector<int> res;
        int left = intervals[0][1];
        int right = intervals[0][2];

        for(int j = 0; j < intervals.size()-1; j++){
            if(intervals[j+1][1]>right){
                
                res.push_back(intervals[j+1][1]-left);
                left = intervals[j+1][1];
                right = intervals[j+1][2];
            }
            else{
                right = max(right, intervals[j+1][2]);
            }

        }
        res.push_back(s.length()-left);

        return res;
        
        

    }
};