/*
由于同一个字母只能出现在同一个片段，显然同一个字母的第一次出现的下标位置和最后一次出现的下标位置必须出现在同一个片段。因此需要遍历字符串，得到每个字母最后一次出现的下标位置。

在得到每个字母最后一次出现的下标位置之后，可以使用贪心的方法将字符串划分为尽可能多的片段，具体做法如下。

    从左到右遍历字符串，遍历的同时维护当前片段的开始下标 start\textit{start}start 和结束下标 end\textit{end}end，初始时 start=end=0\textit{start}=\textit{end}=0start=end=0。

    对于每个访问到的字母 ccc，得到当前字母的最后一次出现的下标位置 endc\textit{end}_cendc​，则当前片段的结束下标一定不会小于 endc\textit{end}_cendc​，因此令 end=max⁡(end,endc)\textit{end}=\max(\textit{end},\textit{end}_c)end=max(end,endc​)。

    当访问到下标 end\textit{end}end 时，当前片段访问结束，当前片段的下标范围是 [start,end][\textit{start},\textit{end}][start,end]，长度为 end−start+1\textit{end}-\textit{start}+1end−start+1，将当前片段的长度添加到返回值，然后令 start=end+1\textit{start}=\textit{end}+1start=end+1，继续寻找下一个片段。

    重复上述过程，直到遍历完字符串。

作者：力扣官方题解
链接：https://leetcode.cn/problems/partition-labels/solutions/455703/hua-fen-zi-mu-qu-jian-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        static int endc[26] = {0};
        for(int i = 0; i < s.length(); i++){
            endc[s[i]-'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> res;
        for(int i = 0; i < s.length(); i++){
            end = max(endc[s[i]-'a'],end);
            if(i == end){
                res.push_back(end-start+1);
                start = end+1;
            }
        }   
        return res;   
    }
};